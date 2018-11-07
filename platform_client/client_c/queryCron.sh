#!/bin/bash

MYSQL_USER=platform
MYSQL_PASS=mySUPERsecurepassword1234
MYSQL_HOST=10.10.173.120
QUERY="SELECT * FROM clientDB.ResourceMessage WHERE SentDateTime > ${LAST_CHECK};"
UPDATE_DB="INSERT INTO progDB.IncidentInformation 
				SELECT IncidentID, IncidentDescription 
				FROM clientcDB.ResourceMessage, clientcDB.IncidentInformation 
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK} 
					AND clientcDB.ResourceMessage.IncidentID = clientcDB.IncidentInformation.ID; 
			 INSERT INTO progDB.Funding
				SELECT FundCode, FundingInfo
				FROM clientcDB.ResourceMessage, clientcDB.Funding
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK} 
					AND clientcDB.ResourceMessage.FundCode = clientcDB.Funding.FundCode; 
			 INSERT INTO progDB.AssignmentInformation
				SELECT AssingmentInformationID, Quantity, Restrictions, AnticipatedFunction, PriceQuote, OrderID, AssignmentInstrctionsID
				FROM clientcDB.ResourceMessage, clientcDB.AssignmentInformation, clientcDB.ResourceInformation
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK} 
					AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoElementID
					AND clientcDB.ResourceInformation.AssignmentInformationID = clientcDB.AssignmentInformation.AssignmentInformationID; 
			 INSERT INTO progDB.ScheduleInformation
				SELECT ScheduleInformationID, LocationTypeID
				FROM clientcDB.ResourceMessage, clientcDB.ScheduleInformation, clientcDB.ResourceInformation
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK} 
					AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoelementID 
					AND clientcDB.ResourceInformation.ScheduleInformationID = clientcDB.ScheduleInformation.ScheduleInformationID; 
			 INSERT INTO progDB.Resource
				SELECT ResourceID, TypeStructureID, TypeInfoID, KeywordID, ResponsiblePartyID, OwnershipInformationID, ResourceStatusID
				FROM clientcDB.ResourceMessage, clientcDB.Resource
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK} 
					AND clientcDB.ResourceMessage.ResourceInfoElementID = clientcDB.ResourceInformation.ResourceInfoelementID 
					AND clientcDB.ResourceInformation.Resource = clientcDB.Resource.ResourceID; 
			 INSERT INTO progDB.ResourceMessage
				SELECT MessageID, IncidentID, RecalledMessageID, FundCode, ContactInformationID, ResourceInfoElementID
				FROM clientcDB.ResourceMessage, clientcDB.ResourceMessage
				WHERE clientcDB.ResourceMessage.SentDateTime > ${LAST_CHECK}";

mysql -u${MYSQL_USER} -p${MYSQL_PASS} -h${MYSQL_HOST} < ${QUERY}
