#!/usr/bin/node

const request = require('request');
try {
  const peli = process.argv.slice(2);
  const url = 'https://swapi-api.hbtn.io/api/films/' + peli[0];
  request(url, async function (err, res, body) {
    if (err || res.statusCode !== 200) {
      console.log(err);
    } else {
      const myList = JSON.parse(body).characters;
      for (const urlChar of myList) {
	    const respChar = await new Promise((resolve, reject) => {
          request(urlChar, (error, response, html) => {
		    if (error || response.statusCode !== 200) {
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
