#!/usr/bin/python3
# Count keywords in hot Reddit articles.
import requests


def count_words(subreddit, word_list, after=None, counts=None):
    """Print sorted keyword counts from a subreddit's hot articles."""
    if counts is None:
        counts = {}

    if not isinstance(subreddit, str) or not subreddit:
        return

    for word in word_list:
        word = word.lower()
        if word not in counts:
            counts[word] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "python:count_it:v1.0 (by /u/student)"}
    params = {"limit": 100, "after": after}

    try:
        response = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False
        )
    except requests.RequestException:
        return

    if response.status_code != 200:
        return

    try:
        data = response.json().get("data", {})
    except (ValueError, AttributeError):
        return

    children = data.get("children", [])

    for child in children:
        title = child.get("data", {}).get("title", "").lower()
        words = title.split()

        for word in word_list:
            keyword = word.lower()
            counts[keyword] += words.count(keyword)

    next_after = data.get("after")

    if next_after:
        return count_words(
            subreddit, word_list, next_after, counts
        )

    results = [
        (word, count)
        for word, count in counts.items()
        if count > 0
    ]

    results.sort(key=lambda item: (-item[1], item[0]))

    for word, count in results:
        print("{}: {}".format(word, count))
