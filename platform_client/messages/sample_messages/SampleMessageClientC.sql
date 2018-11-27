INSERT INTO ScheduleInformation(ScheduleInformationID, DateTime) VALUES  (3, "2018-11-08");

INSERT INTO ResourceInformation(ResourceInfoElementID, Resource, 
AssignmentInformationID, ScheduleInformationID) VALUES (3, 3, 1, 3);

INSERT INTO ResourceMessage(MessageID, SentDateTime, MessageContentType,
MessageDescription, OriginatingMessageID, IncidentID, FundCode,
ContactInformationID, ResourceInfoElementID) 
VALUES (3, "2018-11-07", "ResourceRequest", "sample message, delete me", 3, 0, "125", 2, 0),
	   (4, "2018-11-07", "ResourceRequest", "sample message, delete me", 4, 0, "75", 2, 1),
	   (5, "2018-11-07", "ResourceRequest", "sample message, delete me", 5, 2, "50", 2, 2);
