# Setting up the CLIENTC Machine:
## create users
### create clientc user
	CREATE USER 'clientc'@'localhost' IDENTIFIED BY 'sql-password1234';
	GRANT ALL PRIVILEGES ON *.* TO 'clientc'@'localhost';
### create platform user
	CREATE USER 'platform'@'%' IDENTIFIED BY 'psql-password1234';
	GRANT ALL PRIVILEGES ON clientcDB.* TO 'platform'@'%';

## create clientc database
	These files can be found at systems-project/platform_client/client_c

	Creates the database and adds initial data
	mysql -u clientc -p < ClientC_CreateScript.sql
	mysql -u clientc -p 'clientcDB' < ClientC_InitDataScript.sql

	Updates with a message
	mysql -u clientc -p < ClientC_UpdateDataScript.sql 

# Running the scripts:
## platToClientC.sql
Takes the information from platform and sends messages sent by active clients 
and other passive clients to clientc. 

## clientcToPlat.sql
Takes the information from the passive client and sends the messages to the 
platform so it may send to active clients.
