INSERT INTO IncidentInformation(IncidentID, IncidentDescription) VALUES  (12, "Mass Flooding");

INSERT INTO LocationType(LocationTypeID, Address) VALUES (12, "456 Sherwood Forest Blvd, Baton Rouge LA");

INSERT INTO ScheduleInformation(ScheduleInformationID, ScheduleType, DateTime, LocationTypeID) VALUES (12, "EstimatedArrival", "2016-08-01T13:50:00", 12);

INSERT INTO AssignmentInformation(AssignmentInformationID, Quantity) VALUES (12, 2);

INSERT INTO Resource(ResourceID, Name) VALUES (002, "Boat");

INSERT INTO ResponseTypeLookup(ResponseTypeID, Description) VALUES (12, "Accept");

INSERT INTO ResponseInformation(PrecedingResourceInfoElementID, ResponseTypeID) VALUES (002, 12);

INSERT INTO ResourceInformation(ResourceInfoElementID, Resource, AssignmentInformationID, ScheduleInformationID) VALUES (002, 002, 12, 12);

INSERT INTO ResourceMessage(MessageID, SentDateTime, MessageContentType,
MessageDescription, OriginatingMessageID, PrecedingMessageID, IncidentID, ContactInformationID, ResourceInfoElementID) VALUES ("f1d68924-dac5-499a-be35-c70e40433884", "2016-08-01T13:40:00", "ResponseToRequestResource", "Mass Flooding - boat resource sent to requester", "23e5f51b-9df2-46dc-9ab4-0f94e48dd57e", "23e5f51b-9df2-46dc-9ab4-0f94e48dd57e", 12, 2, 002);
