#!/bin/bash

#====== Set clientc variables ======
MYSQL_CLIENTC_USER="platform"
MYSQL_CLIENTC_PASS="psql-password1234"
MYSQL_HOST="172.31.19.66"
MYSQL_CLIENTCDUMP="mysqldump -u ${MYSQL_CLIENTC_USER} -p${MYSQL_CLIENTC_PASS} -h ${MYSQL_HOST}"
MYSQL_CLIENTC="mysql -u ${MYSQL_CLIENTC_USER} -p${MYSQL_CLIENTC_PASS} -h ${MYSQL_HOST}"

#====== Set platform variables ======
MYSQL_PLATFORM_USER=root
MYSQL_PLATFORM_PASS=password
MYSQL_PLAT="mysql -u ${MYSQL_PLATFORM_USER} -p${MYSQL_PLATFORM_PASS}"
LAST_CHECK=${LAST_CLIENTC_CHECK}

#====== Actual Script ======
${MYSQL_CLIENTCDUMP} clientcDB > clientcDB.sql
${MYSQL_PLAT} -e "DROP DATABASE IF EXISTS clientcDB;"
${MYSQL_PLAT} -e "CREATE DATABASE clientcDB;"
${MYSQL_PLAT} clientcDB < clientcDB.sql
NEW_MESSAGES_TALLY=$(${MYSQL_PLAT} -ss -e "SELECT COUNT(*) FROM clientcDB.ResourceMessage WHERE clientcDB.ResourceMessage.SentDateTime > '${LAST_CHECK}';")
if [ "$NEW_MESSAGES_TALLY" -eq 0 ]
then 
   echo "No new messages from clientc"
else
   ${MYSQL_PLAT} -e "INSERT INTO progDB.IncidentInformation SELECT DISTINCT(IncidentInformation.IncidentID), IncidentDescription FROM clientcDB.ResourceMessage, clientcDB.IncidentInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.IncidentID = clientcDB.IncidentInformation.IncidentID; 
			 
INSERT INTO progDB.Funding SELECT DISTINCT(Funding.FundCode), FundingInfo FROM clientcDB.ResourceMessage, clientcDB.Funding WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.FundCode = clientcDB.Funding.FundCode; 

INSERT INTO progDB.AssignmentInformation SELECT DISTINCT(AssignmentInformation.AssignmentInformationID), Quantity, Restrictions, AnticipatedFunction, PriceQuote, OrderID, AssignmentInstructionsID FROM clientcDB.ResourceMessage, clientcDB.AssignmentInformation, clientcDB.ResourceInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID AND clientcDB.ResourceInformation.AssignmentInformationID = clientcDB.AssignmentInformation.AssignmentInformationID; 
			 
INSERT INTO progDB.ScheduleInformation(ScheduleInformationID, LocationTypeID) SELECT DISTINCT(ScheduleInformation.ScheduleInformationID), LocationTypeID FROM clientcDB.ResourceMessage, clientcDB.ScheduleInformation, clientcDB.ResourceInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID AND clientcDB.ResourceInformation.ScheduleInformationID = clientcDB.ScheduleInformation.ScheduleInformationID; 

INSERT INTO progDB.Resource(ResourceID, TypeStructureID, TypeInfoID, KeywordID, ResponsiblePartyID, OwnershipInformationID, ResourceStatusID) SELECT DISTINCT(Resource.ResourceID), TypeStructureID, TypeInfoID, KeywordID, ResponsiblePartyID, OwnershipInformationID, ResourceStatusID FROM clientcDB.ResourceMessage, clientcDB.Resource, clientcDB.ResourceInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID AND clientcDB.ResourceInformation.Resource = clientcDB.Resource.ResourceID; 

INSERT INTO progDB.ResourceInformation(ResourceInfoElementID, ResponseInformation, Resource, AssignmentInformationID, ScheduleInformationID) SELECT DISTINCT(ResourceInformation.ResourceInfoElementID), ResponseInformation, Resource, AssignmentInformationID, ScheduleInformationID FROM clientcDB.ResourceMessage, clientcDB.ResourceInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK} AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID; 

INSERT INTO progDB.ResourceMessage(MessageID, SentDateTime, IncidentID, RecalledMessageID, FundCode, ContactInformationID, ResourceInfoElementID) SELECT DISTINCT(ResourceMessage.MessageID), SentDateTime, IncidentID, RecalledMessageID, FundCode, ContactInformationID, ResourceInfoElementID FROM clientcDB.ResourceMessage WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CLIENTC_CHECK};"
fi
export LAST_CLIENTC_CHECK=2018-11-06
