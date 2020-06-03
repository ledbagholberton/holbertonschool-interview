#!/usr/bin/node

const request = require('request');
const args = process.argv.slice(2);
const url = 'http://swapi-api.hbtn.io/api/films/' + args[0];

request(url, async function (err, res, body) {
  if (err) {
    console.log(err);
  } else {
    const myList = JSON.parse(body).characters;
    for (const urlChar of myList) {
      const respChar = await new Promise((resolve, reject) => {
        request(urlChar, (error, response, html) => {
          if (error) {
            reject(error);
          } else {
            resolve(JSON.parse(html).name);
          }
        });
      });
      console.log(respChar);
    }
  }
});
