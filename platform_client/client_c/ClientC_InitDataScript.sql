INSERT INTO IncidentInformation(IncidentID, IncidentDescription) 
VALUES  (0,"Hurricane Percy"), 
		(1, "Tornado Dorothy"), 
		(2,"Great Flood of 2016");

INSERT INTO Funding(FundCode, FundingInfo) 
VALUES  ("0", "fundinginfosample"), 
		("125", "State"),
		("50", "Federal"),
		("75", "Private");

INSERT INTO AssignmentInformation(AssignmentInformationID, Quantity, PriceQuote,
OrderID) 
VALUES  (0, "10", "$16000", 42),
		(1, "30", "$600", 20),
		(2, "1", "$40000", 13);

INSERT INTO ScheduleInformation(ScheduleInformationID, DateTime) 
VALUES  (0, "2018-11-06"),
		(1, "2018-11-07"),
		(2, "2018-11-05");

INSERT INTO Resource(ResourceID, NAME, Description) 
VALUES  (0, "truck", "pick up trucks"),
		(1, "firetruck", "large firetrucks"),
		(2, "water", "water by the gallon"),
		(3, "wood", "planks of 2 x 4");

INSERT INTO ResourceInformation(ResourceInfoElementID, Resource, 
AssignmentInformationID, ScheduleInformationID) 
VALUES  (0, 0, 0, 0),
		(1, 2, 1, 1),
		(2, 1, 2, 2);

INSERT INTO ContactInformationType(ContactInformationID, ContactDescription)
VALUES  (0, "clienta"),
		(1, "clientb"),
		(2, "clientc");

INSERT INTO ResourceMessage(MessageID, SentDateTime, MessageContentType,
MessageDescription, OriginatingMessageID, IncidentID, FundCode,
ContactInformationID, ResourceInfoElementID) 
VALUES (0, "2018-11-05", "json", "resource request", 0, 0, "0", 2, 0),
	   (1, "2018-11-05", "json", "resource request", 1, 2, "75", 2, 1),
	   (2, "2018-11-06", "json", "resource request", 2, 1, "50", 2, 2);
