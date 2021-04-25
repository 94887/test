const isIp = require('is-ip')
const prompt = require('prompt')
const binaryIp = require('binary-ip');

prompt.start();
prompt.get(['IP'], function (err, result) {
    if (err) { return onErr(err); }
        console.log("Enter IP Address")
        if(isIp(result.IP)){
            console.log("Correct", binaryIp(result.IP))
        }if(!isIp(result.IP)) {
            console.log("Please enter a Valid IP address");
        }
});

//SINCE NODE JS WORKS ASYNCHRONOULSY WE CAN'T USE WHILE(true) FOR MAKING LOOP ALONG WITH PROMPT FUNCTION, IT WOULD BE POSSIBLE IF WE ARE TAKING VALUES IN JSON FORMAT FROM FRONTEND INSTEAD OF TAKING FROM TERMINAL

//I AM SHARING THE SAME METHOD TO FINDING THE VALID IP IN CPP WITH INFINITE LOOP UNTIL USER ENTERS THE CORRECT VALUE