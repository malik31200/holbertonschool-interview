Requirements
General
Allowed editors: vi, vim, emacs
All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
All your files should end with a new line
The first line of all your files should be exactly #!/usr/bin/python3
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the PEP 8 style (version 1.7.x)
You are not allowed to import any module
All modules and functions must be documented
All your files must be executable
Tasks
0. Rain
Given a list of non-negative integers representing the heights of walls with unit width 1, as if viewing the cross-section of a relief map, calculate how many square units of water will be retained after it rains.

Prototype: def rain(walls)
walls is a list of non-negative integers.
Return: Integer indicating total amount of rainwater retained.
Assume that the ends of the list (before index 0 and after index walls[-1]) are not walls, meaning they will not retain water.
If the list is empty return 0.
jesse@ubuntu:~/$ cat 0_main.py
#!/usr/bin/python3
"""
0_main
"""
rain = __import__('0-rain').rain

if __name__ == "__main__":
    walls = [0, 1, 0, 2, 0, 3, 0, 4]
    print(rain(walls))
    walls = [2, 0, 0, 4, 0, 0, 1, 0]
    print(rain(walls))

jesse@ubuntu:~/$ 
jesse@ubuntu:~/$ ./0_main.py
6
6
jesse@ubuntu:~/$ 
Visual representation of the walls [0, 1, 0, 2, 0, 3, 0, 4]

Screen Shot 2021-04-21 at 8.23.40 PM.png

Visual representation of the walls [2, 0, 0, 4, 0, 0, 1, 0]

Screen Shot 2021-04-21 at 8.24.18 PM.png

Repo:

GitHub repository: holbertonschool-interview
Directory: rain
File: 0-rain.py