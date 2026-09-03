#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(movieUrl, (error, response, body) => {
  if (error) {
    console.error(error);
    return;
  }

  if (response.statusCode !== 200) {
    console.error(`Request failed with status code ${response.statusCode}`);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  const printCharacter = (index) => {
    if (index === characters.length) {
      return;
    }

    request(characters[index], (characterError, characterResponse, characterBody) => {
      if (characterError) {
        console.error(characterError);
        return;
      }

      if (characterResponse.statusCode !== 200) {
        console.error(`Request failed with status code ${characterResponse.statusCode}`);
        return;
      }

      const character = JSON.parse(characterBody);
      console.log(character.name);
      printCharacter(index + 1);
    });
  };

  printCharacter(0);
});
