#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.htbn.io/api/people/'.concat(process.argv[2]);

request(url, function (err, res, body) {
  const characters = JSON.parse(body).characters;

  for (let i = 0; i < characters.length; ++i) {
    request(characters[i], function (err, res, body) {
      console.log(JSON.parse(body).name);
    });
  }
});
