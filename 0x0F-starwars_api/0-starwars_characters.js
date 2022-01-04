#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const url = 'https://swapi-api.htbn.io/api/films/${filmId}';

request(url, async (err, res, body) =>
  { (err) =>
        console.log(err);
  }
  for (const characters = JSON.parse(body).characters){
    await new Promise((resolve, reject) => {
      request(characters, (err, res, body) => {
        if (err) {
          reject(err);
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
