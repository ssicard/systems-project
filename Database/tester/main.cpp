#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>


#include <jdbc/mysql_connection.h> 
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
//#include "MessageObjectBase.cpp"

#include "cppclasses/AssignmentInformation.h"
#include "cppclasses/AssignmentInstructions.h"
#include "cppclasses/ContactInformationType.h"
#include "cppclasses/ContactRoleLookup.h"
#include "cppclasses/Funding.h"
#include "cppclasses/IncidentInformation.h"
#include "cppclasses/LocationType.h"
#include "cppclasses/MessageProperties.h"
#include "cppclasses/MessagePropertiesLookup.h"
#include "cppclasses/MessageRecall.h"
#include "cppclasses/OwnershipInformation.h"
#include "cppclasses/RadioElement.h"
#include "cppclasses/Resource.h"
#include "cppclasses/ResourceInformation.h"
#include "cppclasses/ResourceMessage.h"
#include "cppclasses/ResourceStatus.h"
#include "cppclasses/ResponseInformation.h"
#include "cppclasses/ResponseTypeLookup.h"
#include "cppclasses/ScheduleInformation.h"
#include "cppclasses/TypeInfoType.h"
#include "cppclasses/ValueListType.h"

int main() {
	std::cout << "Connector/C++ tutorial framework..." << std::endl;

	/*
	AssignmentInstructions* a_instr = new AssignmentInstructions(1);
	a_instr->ModeOfTransportation = "ambulance";
	a_instr->NavigationInstructions = "left right left right";
	a_instr->ReportingInstructions = "report report";

	a_instr->insertIntoDatabase();

	a_instr->ModeOfTransportation = "";

	a_instr->getFromDatabase();
	std::cout << "Mode of transportation: " << a_instr->ModeOfTransportation << std::endl;
	*/

	
	/*
	AssignmentInformation* a = new AssignmentInformation(2);
	a->Quantity = "1";
	a->Restrictions = "restrictions string";
	a->AnticipatedFunction = "anticipated function string";
	a->PriceQuote = "price quote string";
	a->OrderID = "aaaa11111zzzzzz";
	a->AssignmentInstructionsID = 1;

	a->insertIntoDatabase();

	a->OrderID = "";
	a->Quantity = "";

	a->getFromDatabase();
	std::cout << "OrderID: " << a->OrderID << std::endl;
	std::cout << "Quantity: " << a->Quantity << std::endl;
	std::cout << "Assignment Instructions ModeOfTransportation: " << a->_AssignmentInstructions.ModeOfTransportation << std::endl;
	*/

	/*
	
	ContactRoleLookup* c;
	c = new ContactRoleLookup(10);
	c->Description = "This is a description test";

	std::cout << c->Description << std::endl;
	c->insertIntoDatabase();
	c->Description = "";

	c->getFromDatabase();
	std::cout << "int is " << c->ContactRoleID << std::endl;
	std::cout << "description is " << c->Description << std::endl;
	*/

	/*
	Funding* f;
	f = new Funding("this is annother test");
	f->FundingInfo = "this is a fund info test"; 
	f->insertIntoDatabase();
	f->FundingInfo = "";
	f->getFromDatabase();
	std::cout << "Before printf\n";
	// printf("%s\n", f->FundingInfo);
	std::cout << "Funding info " << f->FundingInfo << std::endl;
	*/

	/*	
	IncidentInformation ii{"Incident information test"};
	ii.IncidentDescription = "This is a test description";

	ii.insertIntoDatabase();

	ii.IncidentDescription = "";

	ii.getFromDatabase();

	std::cout << "Incident Description: " << ii.IncidentDescription << std::endl;
	*/

	/*
	LocationType l{1};
	l.LocationDescription = "This is a location description";
	l.Address = "This is an address? Not really.";
	l.TargetArea = "This is a target area";

	l.insertIntoDatabase();

	l.LocationDescription = l.Address = l.TargetArea = "";
	
	l.getFromDatabase();
	std::cout << "Location Description: " << l.LocationDescription << std::endl;
	std::cout << "Address: " << l.Address << std::endl;
	std::cout << "Target Area: " << l.TargetArea << std::endl;
	*/

	/*	
	ContactInformationType cit{2};
	cit.ContactDescription = "This is a test description";
	cit.ContactRole = 10;
	cit.ContactLocationID = 1;
	cit.AdditionalContactInformation = "This is test additional contact information";

	cit.insertIntoDatabase();
	
	cit.ContactDescription = "";
	cit.ContactRole = 0;
	cit.ContactLocationID = 0;
	cit.AdditionalContactInformation = "";

	cit.getFromDatabase();

	std::cout << "Contact Description: " << cit.ContactDescription << std::endl;
	std::cout << "Contact Role: " << cit.ContactRole << std::endl;
	std::cout << "ContactLocationID: " << cit.ContactLocationID << std::endl;
	std::cout << "AdditionalContactInformation: " << cit.AdditionalContactInformation << std::endl;
	std::cout << "CIT.ContactRole Description: " << cit._ContactRoleLookup.Description << std::endl;
	std::cout << "CIT.Location Description: " << cit._ContactLocation.LocationDescription << std::endl;
	*/

	/*	
	MessagePropertiesLookup mpl{4};
	mpl.RequirementDesc = "Description test";

	mpl.insertIntoDatabase();

	mpl.RequirementDesc = "";

	mpl.getFromDatabase();

	std::cout << "RequirementDesc: " << mpl.RequirementDesc << std::endl;
	*/
	
	/*
	MessageProperties mp{17, "Request Resource (Test)"};
	mp.Location = 2;
	mp.DateTime = 2;
	mp.MessagePropertyLookupID = 4;

	mp.insertIntoDatabase();

	mp.MessageTypeName = "none";
	mp.Location = 3;
	mp.DateTime = 6;
	mp.MessagePropertyLookupID = 0;

	mp.getFromDatabase();

	std::cout << "Message Type Name: " << mp.MessageTypeName << std::endl;
	std::cout << "Location: " << mp.Location << std::endl;
	std::cout << "DateTime: " << mp.DateTime << std::endl;

	std::cout << "RequirementDesc: " << mp.messagePropertiesLookup.RequirementDesc << std::endl;
	*/

	/*
	MessageRecall mr{"Recalled ID test"};
	mr.RecallType = "Recall type test";

	mr.insertIntoDatabase();

	mr.RecallType = "";

	mr.getFromDatabase();

	std::cout << "RecallType: " << mr.RecallType << std::endl;
	*/

	/*
	OwnershipInformation oi{1};
	oi.Owner = "Test owner";
	oi.OwningJurisdiction = "Test jurisdiction";
	oi.HomeDispatch = "Test Dispatch";
	oi.HomeUnit = "Test unit";

	oi.insertIntoDatabase();

	
	oi.Owner = "";
	oi.OwningJurisdiction = "";
	oi.HomeDispatch = "";
	oi.HomeUnit = "";

	oi.getFromDatabase();
	std::cout << "Owner: " << oi.Owner << std::endl;
	std::cout << "OwningJurisdiction: " << oi.OwningJurisdiction << std::endl;
	std::cout << "HomeDispatch: " << oi.HomeDispatch << std::endl;
	std::cout << "HomeUnit: " << oi.HomeUnit << std::endl;
	*/

	/*
	RadioElement re{1};
	re.RadioType = "Type test";
	re.RadioChannel = "Channel test";

	re.insertIntoDatabase();

	re.RadioType = "";
	re.RadioChannel = "";

	re.getFromDatabase();
	std::cout << "RadioType: " << re.RadioType << std::endl;
	std::cout << "RadioChannel: " << re.RadioChannel << std::endl;
	*/

	/*	
	ScheduleInformation si{1};
	si.ScheduleType = "Schedule type test";
	si.DateTime = "2018/10/20 12:00:00";
	si.LocationTypeID = 1;

	si.insertIntoDatabase();

	si.ScheduleType = "";
	si.DateTime = "";
	si.LocationTypeID = 0;

	si.getFromDatabase();

	std::cout << "Schedule Type: " << si.ScheduleType << std::endl;
	std::cout << "DateTime: " << si.DateTime << std::endl;
	std::cout << "LocationDescription: " << si._Location.LocationDescription << std::endl;
	*/

	/*
	TypeInfoType tit{1};
	tit.ChildInfo = "Child info test";

	tit.insertIntoDatabase();

	tit.ChildInfo = "";

	tit.getFromDatabase();

	std::cout << "Child info: " << tit.ChildInfo << std::endl;
	*/

	/*
	ValueListType vlt{1};
	vlt.ValueListURN = "URN test";
	vlt.ValueType = "Value type test";

	vlt.insertIntoDatabase();

	vlt.ValueListURN = "";
	vlt.ValueType = "";

	vlt.getFromDatabase();
	std::cout << "ValueListURN: " << vlt.ValueListURN << std::endl;
	std::cout << "ValueType: " << vlt.ValueType << std::endl;
	*/

	/*	
	ResourceStatus rs{1};
	rs.InventoryRefreshDateTime = "2018/10/20 12:00:00";
	rs.DeploymentStatus = 1;
	rs.Availability = "Availability test";
	rs.HomeUnit = "Home unit test";

	rs.insertIntoDatabase();

	rs.InventoryRefreshDateTime = "";
	rs.DeploymentStatus = 1;
	rs.Availability = "";
	rs.HomeUnit = "";

	rs.getFromDatabase();

	std::cout << "InventoryRefreshDateTime: " << rs.InventoryRefreshDateTime << std::endl;
	std::cout << "DeploymentStatus: " << rs.DeploymentStatus << std::endl;
	std::cout << "Availability: " << rs.Availability << std::endl;
	std::cout << "HomeUnit: " << rs.HomeUnit << std::endl;
	std::cout << "Deployment status value list URN: " << rs._DeploymentStatus.ValueListURN << std::endl;
	*/

	
	Resource r{"Resource test id"};
	r.NAME = "Test name";
	r.TypeStructureID = 1;
	r.TypeInfoID = 1;
	r.KeywordID = 1;
	r.Description = "test description";
	r.Credentials = "test credentials";
	r.Certifications = "test certifications";
	r.SpecialRequirements = "test special requirements";
	r.ResponsiblePartyID = 1;
	r.OwnershipInformationID = 1;
	r.ResourceStatusID = 1;

	r.insertIntoDatabase();

	r.NAME = "";
	r.TypeStructureID = 0;
	r.TypeInfoID = 0;
	r.KeywordID = 0;
	r.Description = "";
	r.Credentials = "";
	r.Certifications = "";
	r.SpecialRequirements;
	r.ResponsiblePartyID = 0;
	r.OwnershipInformationID = 0;
	r.ResourceStatusID = 0;

	r.getFromDatabase();

	std::cout << "NAME: " << r.NAME << std::endl;
	std::cout << "Description: " << r.Description << std::endl;
	std::cout << "Credentials: " << r.Credentials << std::endl;
	std::cout << "Certifications: " << r.Certifications << std::endl;
	std::cout << "Special requirements: " << r.SpecialRequirements << std::endl;
	std::cout << "Type structure ValueListURN: " << r._TypeStructure.ValueListURN << std::endl;
	std::cout << "TypeInfo ChildInfo: " << r._TypeInfo.ChildInfo << std::endl;
	std::cout << "Keyword valueListURN: " << r._Keyword.ValueListURN << std::endl;
	std::cout << "Responsible Party Contact Description: " << r._ResponsibleParty.ContactDescription << std::endl;
	std::cout << "ResponsibleParty.ContactRole.Description: " << r._ResponsibleParty._ContactRoleLookup.Description << std::endl;
	std::cout << "ResponsibleParty.ContactLocation.Address: " << r._ResponsibleParty._ContactLocation.Address << std::endl;
	std::cout << "OwnershipInformation.Owner: " << r._OwnershipInformation.Owner << std::endl;
	std::cout << "ResourceStatus.Availability: " << r._ResourceStatus.Availability << std::endl;
	std::cout << "ResourceStatus._DeploymentStatys.ValueListURN: " << r._ResourceStatus._DeploymentStatus.ValueListURN << std::endl;
	

	/*
	ResponseTypeLookup rtl{1};
	rtl.Description = "Test description";

	rtl.insertIntoDatabase();

	rtl.Description = "";

	rtl.getFromDatabase();

	std::cout << "Description: " << rtl.Description << std::endl;
	*/

	/*	
	ResponseInformation resi{"Resource information test"};
	resi.ResponseTypeID = 1;
	resi.ReasonCodeID = 1;
	resi.ResponseReason = "Response reason test";

	resi.insertIntoDatabase();

	resi.ResponseTypeID = 0;
	resi.ReasonCodeID = 0;
	resi.ResponseReason = "";

	resi.getFromDatabase();

	std::cout << "Reaponse reason: " << resi.ResponseReason << std::endl;
	std::cout << "Reason Code valueListURN: " << resi._ReasonCode.ValueListURN << std::endl;
	std::cout << "Reaponse Type Description: " << resi._ResponseType.Description << std::endl;
	*/	

	/*
	ResourceInformation ri{"Resource information test"};
	ri.ResponseInformationID = "Resource information test";
	ri.ResourceID = "Resource test id";
	ri.AssignmentInformationID = 1;
	ri.ScheduleInformationID = 1;

	ri.insertIntoDatabase();

	ri.ResponseInformationID = "";
	ri.ResourceID = "";
	ri.AssignmentInformationID = 0;
	ri.ScheduleInformationID = 0;

	ri.getFromDatabase();

	std::cout << "Response information ID: " << ri.ResponseInformationID << std::endl;
	std::cout << "Response Reason: " << ri._ResponseInformation.ResponseReason << std::endl;
	std::cout << "Response Reason valueListURN: " << ri._ResponseInformation._ReasonCode.ValueListURN << std::endl;
	std::cout << "Response type description: " << ri._ResponseInformation._ResponseType.Description << std::endl;
	std::cout << "Resource NAME: " << ri._Resource.NAME << std::endl;
	std::cout << "Assignment Order ID: " << ri._AssignmentInformation.OrderID << std::endl;
	std::cout << "Schedule informatioe Type: " << ri._ScheduleInformation.ScheduleType << std::endl;
	std::cout << "Schedule location: " << ri._ScheduleInformation._Location.Address << std::endl;	
	*/

	/*
	ResourceMessage rm{"messageID"};
	rm.SentDateTime = "2018/10/20 12:00:00";
	rm.MessageContentType = "Test message content type";
	rm.MessageDescription = "Test message description";
	rm.OriginatingMessageID = "Test originating message ID";
	rm.PrecedingMessageID = "Test preceding message id"; 
	rm.IncidentID = "Incident information test";
	rm.RecalledMessageID = "Recalled ID test";
	rm.FundCode = "Funding Code Test";
	rm.ContactInformationID = 1;
	rm.ResourceInfoElementID = "Resource information test";

	rm.insertIntoDatabase();

	rm.SentDateTime = "";
	rm.MessageContentType = "";
	rm.MessageDescription = "";
	rm.OriginatingMessageID = "";
	rm.PrecedingMessageID = ""; 
	rm.IncidentID = "";
	rm.RecalledMessageID = "";
	rm.FundCode = "";
	rm.ContactInformationID = 0;
	rm.ResourceInfoElementID = "";

	rm.getFromDatabase();

	std::cout << "DataTime: " << rm.SentDateTime << std::endl;
	std::cout << "MessageContentType: " << rm.MessageContentType << std::endl;
	std::cout << "Message Description: " << rm.MessageDescription << std::endl;
	std::cout << "Incident description: " << rm._IncidentInformation.IncidentDescription << std::endl;
	std::cout << "Message Recall type: " << rm._MessageRecall.RecallType << std::endl;
	std::cout << "Funding Info: " << rm._Funding.FundingInfo << std::endl;
	std::cout << "Contact Description: " << rm._ContactInformationType.ContactDescription << std::endl;
	std::cout << "Resource name: " << rm._ResourceInformation._Resource.NAME << std::endl;
	*/

	return EXIT_SUCCESS;
}
