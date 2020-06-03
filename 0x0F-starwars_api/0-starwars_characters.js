#!/usr/bin/node

const request = require('request');
try {
  const args = process.argv.slice(2);
  const url = 'http://swapi-api.hbtn.io/api/films/' + args[0];

  request(url, async function (err, res, body) {
    if (err || res.statusCode !== 200) {
      console.log(err);
    } else {
      const myList = JSON.parse(body).characters;
      for (const urlChar of myList) {
        const respChar = await new Promise((resolve, reject) => {
          request(urlChar, (error, response, html) => {
            if (error || res.statusCode !== 200) {
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
} catch (catchErr) {
  console.log(catchErr);
}
