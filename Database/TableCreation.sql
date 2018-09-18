CREATE TABLE progDB.ContactRoleLookup
(
ContactRoleID int,
Description varchar(255),
 PRIMARY KEY (ContactRole),
)

CREATE TABLE progDB.RadioElement
(
RadioElementID int,
RadioType varchar(255),
RadioChannel varchar(255),
 PRIMARY KEY (RadioElementID)
)

CREATE TABLE progDB.LocationType
(
LocationTypeID int,
LocationDescription varchar(255),
Address varchar(255),
TargetArea varchar(255),
 PRIMARY KEY (LocationTypeID)
)

CREATE TABLE progDB.ValueListType
(
ValueListID int,
ValueListURN varchar(255),
ValueType varchar(255),
 PRIMARY KEY (ValueListID)
)

CREATE TABLE progDB.TypeInfoType
(
TypeInfoID int,
ChildInfo varchar(255),
 PRIMARY KEY (TypeInfoID)
)



CREATE TABLE progDB.IncidentInformation
(
IncidentID varchar(255),
IncidentDescription varchar(255),
 PRIMARY KEY (IncidentID)
)

CREATE TABLE progDB.MessageRecall
(
RecalledMessageID varchar(255),
RecallType varchar(255),
 PRIMARY KEY (RecalledMessageID)
)

CREATE TABLE progDB.Funding
(
FundCode varchar(255),
FundingInfo varchar(255),
 PRIMARY KEY (FundCode)
)





CREATE TABLE progDB.ResponseTypeLookup
(
ResponseTypeID int,
Description varchar(255),
 PRIMARY KEY (ResponseTypeID),
)


CREATE TABLE progDB.OwnershipInformation
(
OwnershipInformationID int,
Owner varchar(255),
OwningJurisdiction varchar(255),
HomeDispatch varchar(255),
HomeUnit varchar(255),
 PRIMARY KEY (OwnershipInformationID)
)

CREATE TABLE progDB.ResourceStatus
(
ResourceStatusID int,
InventoryRefreshDateTime dateTime,
DeploymentStatus int,
Availability varchar(255),
HomeUnit varchar(255),
 PRIMARY KEY (ResourceStatusID),
 FOREIGN KEY (DeploymentStatus) REFERENCES ValueListType(ValueListID)

)

CREATE TABLE progDB.AssignmentInstructions
(
AssignmentInstructionsID int,
ModeOfTransportation varchar(255),
NavigationInstructions varchar(255),
ReportingInstructions varchar(255),
 PRIMARY KEY (AssignmentInstructionsID)
)

CREATE TABLE progDB.AssignmentInformation
(
AssignmentInformationID int,
Quantity varchar(255),
Restrictions varchar(255),
AnticipatedFunction varchar(255),
PriceQuote varchar(255),
OrderID varchar(255),
AssignmentInstructions varchar(255),
 PRIMARY KEY (AssignmentInformationID),
 FOREIGN KEY (AssignmentInstructions) REFERENCES AssignmentInstructions(AssignmentInstructionsID)
)

CREATE TABLE progDB.ScheduleInformation
(
ScheduleInformationID int,
ScheduleType varchar(255), 
DateTime dateTime,
Location varchar(255),
 PRIMARY KEY (ScheduleInformationID)
 FOREIGN KEY (Location) REFERENCES LocationType(LocationTypeID)

)

CREATE TABLE progDB.ContactInformationType
(
ContactInformationID int,
ContactDescription varchar(255),
ContactRole int,
ContactLocation int,
AdditionalContactInformation varchar(255),
 PRIMARY KEY (ContactInformationID)
 FOREIGN KEY (ContactRole) REFERENCES ContactRoleLookup(ContactRoleID)
 FOREIGN KEY (ContactLocation) REFERENCES LocationType(LocationTypeID)

)

CREATE TABLE progDB.ResponseInformation
(
PrecedingResourceInfoElementID varchar(255),
ResponseType int, 
ReasonCode int,
ResponseReason varchar(255),
 PRIMARY KEY (PrecedingResourceInfoElementID),
 FOREIGN KEY (ReasonCode) REFERENCES ValueListType(ValueListID),
 FOREIGN KEY (ResponseType) REFERENCES ResponseTypeLookup(ResponseTypeID)
)

CREATE TABLE progDB.Resource
(
ResourceID varchar(255),
Name varchar(255),
TypeStructure int,
TypeInfo int,
Keyword int,
Description varchar(255),
Credentials varchar(255),
Certifications varchar(255),
SpecialRequirements varchar(255),
ResponsibleParty int,
OwnershipInformation varchar(255),
ResourceStatus varchar(255),
 PRIMARY KEY (ResourceID),
 FOREIGN KEY (TypeStructure) REFERENCES ValueListType(ValueListID),
 FOREIGN KEY (TypeInfo) REFERENCES Resource(ResourceID),
 FOREIGN KEY (Keyword) REFERENCES ValueListType(ValueListID),
 FOREIGN KEY (ResponsibleParty) REFERENCES ContactInformationType(ContactInformationTypeID),
 FOREIGN KEY (OwnershipInformation) REFERENCES OwnershipInformation(OwnershipInformationID),
 FOREIGN KEY (ResourceStatus) REFERENCES ResourceStatus(ResourceStatusID)

)

CREATE TABLE progDB.ResourceInformation
(
ResourceInfoElementID varchar(255),
ResponseInformation varchar(255),
Resource varchar(255),
AssignmentInformation int,
ScheduleInformation varchar(255),
 PRIMARY KEY (ResourceInfoElementID),
 FOREIGN KEY (ResponseInformation) REFERENCES ResponseInformation(PrecedingResourceInfoElementID),
 FOREIGN KEY (Resource) REFERENCES Resource(ResourceID),
 FOREIGN KEY (AssignmentInformation) REFERENCES AssignmentInformation(AssignmentInformationID),
 FOREIGN KEY (ScheduleInformation) REFERENCES ScheduleInformation(ScheduleInformationID)
)

CREATE TABLE progDB.ResourceMessage
(
MessageID varchar(255),
SentDateTime dateTime,
MessageContentType varchar(255),
MessageDescription varchar(255),
OriginatingMessageID varchar(255),
PrecedingMessageID varchar(255),
IncidentInformation varchar(255),
MessageRecall varchar(255),
Funding varchar(255),
ContactInformation int,
ResourceInformation varchar(255),
 PRIMARY KEY (MessageID),
 FOREIGN KEY (IncidentInformation) REFERENCES IncidentInformation(IncidentID),
 FOREIGN KEY (MessageRecall) REFERENCES MessageRecall(RecalledMessageID),
 FOREIGN KEY (Funding) REFERENCES Funding(FundCode),
 FOREIGN KEY (ContactInformation) REFERENCES ContactInformationType(ContactInformationID),
 FOREIGN KEY (ResourceInformation) REFERENCES ResourceInformation(ResourceInfoElementID)
)


