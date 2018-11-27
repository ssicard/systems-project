const express = require('express');
const bodyParser = require('body-parser');
const mysql = require('mysql');
const app = express();
const port = process.env.PORT || 5000;
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: true }));
app.use(function(req,res,next){
	res.header("Access-Control-Allow-Origin","*");
	res.header("Access-Control-Allow-Headers","Origin,X-Requested-With,Content-Type,Accept");
	next();
});
app.get('/api/logs', (req, res) => {
     console.log("am i hittin here");
     const connection = mysql.createConnection({
         host: 'localhost',
         port: '3306',
         user: 'root',
         password: 'password',
         database: 'progDB'
     });
     connection.connect();
	let jsonres = {};    
 connection.query('SELECT MessageID, SentDateTime, MessageDescription, RecalledMessageID, ContactDescription FROM ResourceMessage, ContactInformationType WHERE ResourceMessage.ContactInformationID = ContactInformationType.ContactInformationID;', function(error, results, fields){
         if(error) console.log(error);
	 console.log(results);
         const jsonResults = {};
	 jsonres = results;
         //format results into proper JSON format below.
         //res.send(jsonResults);
	res.send(jsonres);
	connection.end();
     });
    //this is sample data to simulate how interact with the mysql should behave.
}); 

app.listen(port, () => console.log(`Listening on port ${port}`));
