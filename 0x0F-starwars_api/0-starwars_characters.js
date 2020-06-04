#!/usr/bin/node

const request = require('request');
try {
  const peli = process.argv.slice(2);
  const url = 'https://swapi-api.hbtn.io/api/films/' + peli[0];
  request(url, async function (err, res, body) {
    if (err || res.statusCode !== 200) {
<<<<<<< HEAD
      console.log(err);
    } else {
      const myList = JSON.parse(body).characters;
      for (const urlChar of myList) {
        const respChar = await new Promise((resolve, reject) => {
          request(urlChar, (errChar, respChar, bodyChar) => {
            if (errChar || respChar.statusCode !== 200) {
              reject(errChar);
            } else {
              resolve(JSON.parse(bodyChar).name);
            }
          });
        });
        console.log(respChar);
      }
=======
	    console.log(err);
    } else {
	    const myList = JSON.parse(body).characters;
	    for (const urlChar of myList) {
        const respChar = await new Promise((resolve, reject) => {
		    request(urlChar, (err_char, resp_char, body_char) => {
            if (err_char || resp_char.statusCode !== 200) {
			    reject(error);
            } else {
			    resolve(JSON.parse(body_char).name);
            }
		    });
        });
        console.log(respChar);
	    }
>>>>>>> e75607ce4e457bcd420fbc7d7f0b05aadf5f2871
    }
  });
} catch (catchErr) {
  console.log(catchErr);
}
