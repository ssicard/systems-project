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

CREATE TABLE progDB.ResourceInformation
(
ResourceInfoElementID varchar(255),
ResponseInformation varchar(255),
Resource varchar(255),
AssignmentInformation varchar(255),
ScheduleInformation varchar(255),
 PRIMARY KEY (ResourceInfoElementID),
 FOREIGN KEY (ResponseInformation) REFERENCES ResponseInformation(PrecedingResourceInfoElementID),
 FOREIGN KEY (Resource) REFERENCES Resource(ResourceID),
 FOREIGN KEY (ScheduleInformation) REFERENCES ScheduleInformation(IncidentID)

)

CREATE TABLE progDB.ResponseInformation
(
PrecedingResourceInfoElementID varchar(255),
ResponseType int, 
ReasonCode int,
ResponseReason varchar(255),
 PRIMARY KEY (PrecedingResourceInfoElementID),
 FOREIGN KEY (ReasonCode) REFERENCES ValueListType(ValueListID)
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
 FOREIGN KEY (ResponsibleParty) REFERENCES Resource(ResourceID),
 FOREIGN KEY (OwnershipInformation) REFERENCES Resource(ResourceID),
 FOREIGN KEY (ResourceStatus) REFERENCES Resource(ResourceID)

)

CREATE TABLE progDB.OwnershipInformation
(
Owner varchar(255),
OwningJurisdiction varchar(255),
HomeDispatch varchar(255),
HomeUnit varchar(255),
 PRIMARY KEY (Owner)
)

CREATE TABLE progDB.ResourceStatus
(
InventoryRefreshDateTime dateTime,
DeploymentStatus int,
Availability varchar(255),
HomeUnit varchar(255),
 PRIMARY KEY (InventoryRefreshDateTime),
 FOREIGN KEY (DeploymentStatus) REFERENCES ValueListType(ValueListID)

)

CREATE TABLE progDB.AssignmentInstructions
(
ModeOfTransportation varchar(255),
NavigationInstructions varchar(255),
ReportingInstructions varchar(255),
 PRIMARY KEY (ModeOfTransportation)
)

CREATE TABLE progDB.ScheduleInformation
(
ScheduleType varchar(255), 
DateTime dateTime,
Location varchar(255),
 PRIMARY KEY (ScheduleType)
 FOREIGN KEY (Location) REFERENCES LocationType(LocationTypeID)

)

CREATE TABLE progDB.ContactInformationType
(
ContactInformationID int,
ContactDescription varchar(255),
ContactRole int,
ContactLocation int,
AdditionalContactInformation int,
 PRIMARY KEY (ContactInformationID)
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


