#!/usr/bin/node

const request = require('request');
const filmId = process.argv[2];
const url = 'https://swapi-api.htbn.io/api/films/${filmId}';

request(url, async (err, res, body) {
  if (error) {
    console.log(error);
  } else {
    const allchar = JSON.parse(body).characters;
    for (const char of allchar) {
      const res = await new Promise((resolve, reject) => {
        request(char, (error, res, body2) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(body2).name);
          }
        });
      });
      console.log(res);
    }
  }
});
