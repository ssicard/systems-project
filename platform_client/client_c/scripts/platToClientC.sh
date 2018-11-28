#!/bin/bash
#
# This file is meant to be run as a cron job on the platform server. It aims to
# get all new messages from platform and load into the clientc database. This
# client must handle updating thier system themselves.
# 

#====== Set clientc variables ======
MYSQL_CLIENTC_USER="platform"
MYSQL_CLIENTC_PASS="psql-password1234"
MYSQL_HOST="172.31.19.66"
MYSQL_CLIENTC="mysql -u ${MYSQL_CLIENTC_USER} -p${MYSQL_CLIENTC_PASS} -h ${MYSQL_HOST}"

#====== Set platform variables ======
MYSQL_PLATFORM_USER=root
MYSQL_PLATFORM_PASS=password
MYSQL_PLATDUMP="mysqldump -u ${MYSQL_PLATFORM_USER} -p${MYSQL_PLATFORM_PASS}"
MYSQL_PLAT="mysql -u ${MYSQL_PLATFORM_USER} -p${MYSQL_PLATFORM_PASS}"
LAST_CHECK=${LAST_PLAT_CHECK}

#====== Actual Script ======
${MYSQL_PLATDUMP} progDB > progDB.sql
scp progDB.sql ubuntu@ip-172-31-19-66:~/
${MYSQL_CLIENTC} -e "DROP DATABASE IF EXISTS progDB;"
${MYSQL_CLIENTC} -e "CREATE DATABASE progDB;"
${MYSQL_CLIENTC} progDB < progDB.sql
NEW_MESSAGES_TALLY=$(${MYSQL_CLIENTC} -ss -e "SELECT COUNT(*) FROM progDB.ResourceMessage, progDB.ResourceInformation, progDB.Resource WHERE SentDateTime > '${LAST_CHECK}' AND ResourceMessage.ResourceInfoElementID = ResourceInformation.ResourceInfoElementID AND ResourceInformation.Resource = Resource.ResourceID AND Resource.ResponsiblePartyID <> 2;")
if [ "$NEW_MESSAGES_TALLY" -eq 0 ]
then 
   echo "No new messages from platform"
else
   ${MYSQL_CLIENTC} -e "INSERT INTO clientcDB.IncidentInformation SELECT DISTINCT(IncidentInformation.IncidentID), IncidentDescription FROM progDB.ResourceMessage, progDB.IncidentInformation WHERE progDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND progDB.ResourceMessage.IncidentID = progDB.IncidentInformation.IncidentID; 
			 
INSERT INTO clientcDB.Funding SELECT DISTINCT(Funding.FundCode), FundingInfo FROM progDB.ResourceMessage, progDB.Funding WHERE progDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND progDB.ResourceMessage.FundCode = progDB.Funding.FundCode; 

INSERT INTO clientcDB.AssignmentInformation SELECT DISTINCT(AssignmentInformation.AssignmentInformationID), Quantity, Restrictions, AnticipatedFunction, PriceQuote, OrderID, AssignmentInstructionsID FROM progDB.ResourceMessage, progDB.AssignmentInformation, progDB.ResourceInformation WHERE progDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND progDB.ResourceMessage.ResourceInfoElementID = progDB.ResourceInformation.ResourceInfoElementID AND progDB.ResourceInformation.AssignmentInformationID = progDB.AssignmentInformation.AssignmentInformationID; 
			 
INSERT INTO clientcDB.ScheduleInformation(ScheduleInformationID, LocationTypeID) SELECT DISTINCT(ScheduleInformation.ScheduleInformationID), LocationTypeID FROM progDB.ResourceMessage, progDB.ScheduleInformation, progDB.ResourceInformation WHERE progDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND progDB.ResourceMessage.ResourceInfoElementID = progDB.ResourceInformation.ResourceInfoElementID AND progDB.ResourceInformation.ScheduleInformationID = progDB.ScheduleInformation.ScheduleInformationID; 

INSERT INTO clientcDB.Resource(ResourceID, TypeStructureID, TypeInfoID, KeywordID, ResponsiblePartyID, OwnershipInformationID, ResourceStatusID) SELECT DISTINCT(Resource.ResourceID), TypeStructureID, TypeInfoID, KeywordID, ResponsiblePartyID, OwnershipInformationID, ResourceStatusID FROM progDB.ResourceMessage, progDB.Resource, progDB.ResourceInformation WHERE progDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND progDB.ResourceMessage.ResourceInfoElementID = progDB.ResourceInformation.ResourceInfoElementID AND progDB.ResourceInformation.Resource = progDB.Resource.ResourceID; 

INSERT INTO clientcDB.ResourceInformation(ResourceInfoElementID, ResponseInformation, Resource, AssignmentInformationID, ScheduleInformationID) SELECT DISTINCT(ResourceInformation.ResourceInfoElementID), ResponseInformation, Resource, AssignmentInformationID, ScheduleInformationID FROM clientcDB.ResourceMessage, clientcDB.ResourceInformation WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK} AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID; 

INSERT INTO clientcDB.ResourceMessage(MessageID, SentDateTime, MessageContentType, MessageDescription, OriginatingMessageID, IncidentID, RecalledMessageID, FundCode, ContactInformationID, ResourceInfoElementID) SELECT DISTINCT(ResourceMessage.MessageID), SentDateTime, MessageContentType, MessageDescription, OriginatingMessageID, IncidentID, RecalledMessageID, FundCode, ContactInformationID, ResourceInfoElementID FROM clientcDB.ResourceMessage WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_PLAT_CHECK};"
fi
#TODO last plat check
