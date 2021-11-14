#!/usr/bin/node

const request = requre('request');

const movieId = process.argv[2] + '/';
const url = 'https://swapi-api.htbn.io/api/films/';

request(url + movieId, async function (err, res, body) {
  if (err) return console.error(err);

  const charurl = JSON.parse(body).characters;

  for (const char of charurl) {
    await new Promise(function (resolve, reject) {
      request(char, function (err, res, body) {
        if (err) return console.error(err);

        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});