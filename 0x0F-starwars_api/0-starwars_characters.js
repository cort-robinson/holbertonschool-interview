#!/usr/bin/node
request = require('request');


request('https://swapi-api.hbtn.io/api/films/' + process.argv[2], function (error, response, body) {
    if (!error && response.statusCode == 200) {
        characterUrls = JSON.parse(body).characters;
        for (url of characterUrls) {
            request(url, function (error, response, body) {
                if (!error && response.statusCode == 200) {
                    console.log(JSON.parse(body).name);
                }
            });
        }
    };
});
