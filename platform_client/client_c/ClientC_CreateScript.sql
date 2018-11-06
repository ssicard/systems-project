-- phpMyAdmin SQL Dump
-- version 4.6.6deb5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Sep 19, 2018 at 12:43 PM
-- Server version: 5.7.23-0ubuntu0.18.04.1
-- PHP Version: 7.2.10-0ubuntu0.18.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `progDB`
--
CREATE DATABASE IF NOT EXISTS `clientcDB` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `clientcDB`;

-- --------------------------------------------------------

--
-- Table structure for table `AssignmentInformation`
--

CREATE TABLE `AssignmentInformation` (
  `AssignmentInformationID` int(11) NOT NULL,
  `Quantity` varchar(255) DEFAULT NULL,
  `Restrictions` varchar(255) DEFAULT NULL,
  `AnticipatedFunction` varchar(255) DEFAULT NULL,
  `PriceQuote` varchar(255) DEFAULT NULL,
  `OrderID` varchar(255) DEFAULT NULL,
  `AssignmentInstructionsID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `AssignmentInformation`:
--   `AssignmentInstructionsID`
--       `AssignmentInstructions` -> `AssignmentInstructionsID`
--

-- --------------------------------------------------------

--
-- Table structure for table `AssignmentInstructions`
--

CREATE TABLE `AssignmentInstructions` (
  `AssignmentInstructionsID` int(11) NOT NULL,
  `ModeOfTransportation` varchar(255) DEFAULT NULL,
  `NavigationInstructions` varchar(255) DEFAULT NULL,
  `ReportingInstructions` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `AssignmentInstructions`:
--

-- --------------------------------------------------------

--
-- Table structure for table `ContactInformationType`
--

CREATE TABLE `ContactInformationType` (
  `ContactInformationID` int(11) NOT NULL,
  `ContactDescription` varchar(255) DEFAULT NULL,
  `ContactRole` int(11) DEFAULT NULL,
  `ContactLocationID` int(11) DEFAULT NULL,
  `AdditionalContactInformation` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ContactInformationType`:
--   `ContactRole`
--       `ContactRoleLookup` -> `ContactRoleID`
--   `ContactLocationID`
--       `LocationType` -> `LocationTypeID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ContactRoleLookup`
--

CREATE TABLE `ContactRoleLookup` (
  `ContactRoleID` int(11) NOT NULL,
  `Description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ContactRoleLookup`:
--

--
-- Dumping data for table `ContactRoleLookup`
--

INSERT INTO `ContactRoleLookup` (`ContactRoleID`, `Description`) VALUES
(1, 'Sender'),
(2, 'Requester'),
(3, 'SubjectMatterExpert'),
(4, 'Approver'),
(5, 'RespondingOrg'),
(6, 'Owner');

-- --------------------------------------------------------

--
-- Table structure for table `Funding`
--

CREATE TABLE `Funding` (
  `FundCode` varchar(255) NOT NULL,
  `FundingInfo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `Funding`:
--

-- --------------------------------------------------------

--
-- Table structure for table `IncidentInformation`
--

CREATE TABLE `IncidentInformation` (
  `IncidentID` varchar(255) NOT NULL,
  `IncidentDescription` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `IncidentInformation`:
--

-- --------------------------------------------------------

--
-- Table structure for table `LocationType`
--

CREATE TABLE `LocationType` (
  `LocationTypeID` int(11) NOT NULL,
  `LocationDescription` varchar(255) DEFAULT NULL,
  `Address` varchar(255) DEFAULT NULL,
  `TargetArea` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `LocationType`:
--

-- --------------------------------------------------------

--
-- Table structure for table `MessageProperties`
--

CREATE TABLE `MessageProperties` (
  `id` int(11) NOT NULL,
  `MessageTypeName` varchar(255) NOT NULL,
  `MessageID` tinyint(4) NOT NULL DEFAULT '0',
  `SentDateTime` tinyint(4) NOT NULL DEFAULT '0',
  `MessageContentType` tinyint(4) NOT NULL DEFAULT '0',
  `MessageDescription` tinyint(4) NOT NULL DEFAULT '0',
  `OriginatingMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `PrecedingMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `Incident Information` tinyint(4) NOT NULL DEFAULT '0',
  `MessageRecall` tinyint(4) NOT NULL DEFAULT '0',
  `Funding` tinyint(4) NOT NULL DEFAULT '0',
  `ContactInformation` tinyint(4) NOT NULL DEFAULT '0',
  `Resource Information` tinyint(4) NOT NULL DEFAULT '0',
  `IncidentID` tinyint(4) NOT NULL DEFAULT '0',
  `IncidentDescription` tinyint(4) NOT NULL DEFAULT '0',
  `RecalledMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `RecallType` tinyint(4) NOT NULL DEFAULT '0',
  `FundCode` tinyint(4) NOT NULL DEFAULT '0',
  `FundingInfo` tinyint(4) NOT NULL DEFAULT '0',
  `ResourceInfoElementID` tinyint(4) NOT NULL DEFAULT '0',
  `Response Information` tinyint(4) NOT NULL DEFAULT '0',
  `Resource` tinyint(4) NOT NULL DEFAULT '0',
  `AssignmentInformation` tinyint(4) NOT NULL DEFAULT '0',
  `ScheduleInformation` tinyint(4) NOT NULL DEFAULT '0',
  `PrecedingResourceInfoElementID` tinyint(4) NOT NULL DEFAULT '0',
  `ResponseType` tinyint(4) NOT NULL DEFAULT '0',
  `ReasonCode` tinyint(4) NOT NULL DEFAULT '0',
  `ResponseReason` tinyint(4) NOT NULL DEFAULT '0',
  `ResourceID` tinyint(4) NOT NULL DEFAULT '0',
  `Name` tinyint(4) NOT NULL DEFAULT '0',
  `TypeStructure` tinyint(4) NOT NULL DEFAULT '0',
  `TypeInfo` tinyint(4) NOT NULL DEFAULT '0',
  `Keyword` tinyint(4) NOT NULL DEFAULT '0',
  `Description` tinyint(4) NOT NULL DEFAULT '0',
  `Credentials` tinyint(4) NOT NULL DEFAULT '0',
  `Certifications` tinyint(4) NOT NULL DEFAULT '0',
  `SpecialRequirements` tinyint(4) NOT NULL DEFAULT '0',
  `ResponsibleParty` tinyint(4) NOT NULL DEFAULT '0',
  `OwnershipInformation` tinyint(4) NOT NULL DEFAULT '0',
  `Resource Status` tinyint(4) NOT NULL DEFAULT '0',
  `Owner` tinyint(4) NOT NULL DEFAULT '0',
  `OwningJurisdiction` tinyint(4) NOT NULL DEFAULT '0',
  `HomeDispatch` tinyint(4) NOT NULL DEFAULT '0',
  `HomeUnit` tinyint(4) NOT NULL DEFAULT '0',
  `InventoryRefreshDateTime` tinyint(4) NOT NULL DEFAULT '0',
  `DeploymentStatus` tinyint(4) NOT NULL DEFAULT '0',
  `Availability` tinyint(4) NOT NULL DEFAULT '0',
  `Quantity` tinyint(4) NOT NULL DEFAULT '0',
  `Restrictions` tinyint(4) NOT NULL DEFAULT '0',
  `AnticipatedFunction` tinyint(4) NOT NULL DEFAULT '0',
  `PriceQuote` tinyint(4) NOT NULL DEFAULT '0',
  `OrderID` tinyint(4) NOT NULL DEFAULT '0',
  `Assignment Instructions` tinyint(4) NOT NULL DEFAULT '0',
  `ModeOfTransportation` tinyint(4) NOT NULL DEFAULT '0',
  `NavigationInstructions` tinyint(4) NOT NULL DEFAULT '0',
  `ReportingInstructions` tinyint(4) NOT NULL DEFAULT '0',
  `ScheduleType` tinyint(4) NOT NULL DEFAULT '0',
  `DateTime` tinyint(4) NOT NULL DEFAULT '0',
  `Location` tinyint(4) NOT NULL DEFAULT '0',
  `MessagePropertyLookupID` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `MessageProperties`:
--   `MessagePropertyLookupID`
--       `MessagePropertiesLookup` -> `RequirementType`
--

--
-- Dumping data for table `MessageProperties`
--

INSERT INTO `MessageProperties` (`id`, `MessageTypeName`, `MessageID`, `SentDateTime`, `MessageContentType`, `MessageDescription`, `OriginatingMessageID`, `PrecedingMessageID`, `Incident Information`, `MessageRecall`, `Funding`, `ContactInformation`, `Resource Information`, `IncidentID`, `IncidentDescription`, `RecalledMessageID`, `RecallType`, `FundCode`, `FundingInfo`, `ResourceInfoElementID`, `Response Information`, `Resource`, `AssignmentInformation`, `ScheduleInformation`, `PrecedingResourceInfoElementID`, `ResponseType`, `ReasonCode`, `ResponseReason`, `ResourceID`, `Name`, `TypeStructure`, `TypeInfo`, `Keyword`, `Description`, `Credentials`, `Certifications`, `SpecialRequirements`, `ResponsibleParty`, `OwnershipInformation`, `Resource Status`, `Owner`, `OwningJurisdiction`, `HomeDispatch`, `HomeUnit`, `InventoryRefreshDateTime`, `DeploymentStatus`, `Availability`, `Quantity`, `Restrictions`, `AnticipatedFunction`, `PriceQuote`, `OrderID`, `Assignment Instructions`, `ModeOfTransportation`, `NavigationInstructions`, `ReportingInstructions`, `ScheduleType`, `DateTime`, `Location`, `MessagePropertyLookupID`) VALUES
(1, 'Request Resource', 3, 3, 3, 2, 3, 0, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 0, 3, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 3, 2, 2, 0),
(2, 'ResponseTo Request Resource', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 2, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 0, 2, 2, 2, 2, 3, 2, 2, 0),
(3, 'Requisition Resource', 3, 3, 3, 2, 3, 2, 2, 2, 3, 3, 3, 1, 1, 3, 3, 1, 1, 3, 0, 3, 3, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2, 2, 0, 0, 0, 3, 2, 2, 2, 0, 2, 2, 2, 2, 3, 2, 2, 0),
(4, 'Commit Resource', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 0, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(5, 'Request Information', 3, 3, 3, 3, 3, 2, 2, 2, 2, 3, 2, 1, 1, 3, 3, 1, 1, 3, 0, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(6, 'ResponseTo RequestInformation', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 2, 1, 1, 3, 3, 1, 1, 3, 2, 2, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(7, 'Offer Unsolicited Resource', 3, 3, 3, 2, 3, 0, 2, 2, 0, 3, 3, 1, 1, 3, 3, 0, 0, 3, 0, 3, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 3, 2, 2, 0),
(8, 'Release Resource', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 2, 3, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(9, 'Request Return', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 0, 3, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(10, 'ResponseTo Request Return', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 2, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 1, 1, 2, 2, 0, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(11, 'Request Quote', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 2, 3, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2, 2, 0, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 3, 2, 2, 0),
(12, 'ResponseTo Request Quote', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 2, 2, 2, 2, 3, 2, 2, 0),
(13, 'Request Resource Deployment Status', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 0, 3, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 1, 2, 2, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(14, 'Report Resource Deployment Status', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 2, 2, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0),
(15, 'Request Extended Deployment Duration', 3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 0, 3, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 2, 2, 0),
(16, 'ResponseTo Request Extended Deployment Duration', 3, 3, 3, 2, 3, 3, 2, 2, 2, 3, 3, 1, 1, 3, 3, 1, 1, 3, 3, 1, 2, 2, 3, 3, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 0);

-- --------------------------------------------------------

--
-- Table structure for table `MessagePropertiesLookup`
--

CREATE TABLE `MessagePropertiesLookup` (
  `RequirementType` int(11) NOT NULL DEFAULT '0',
  `RequirementDesc` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `MessagePropertiesLookup`:
--

--
-- Dumping data for table `MessagePropertiesLookup`
--

INSERT INTO `MessagePropertiesLookup` (`RequirementType`, `RequirementDesc`) VALUES
(0, 'N/A'),
(1, 'C'),
(2, 'O'),
(3, 'R');

-- --------------------------------------------------------

--
-- Table structure for table `MessageRecall`
--

CREATE TABLE `MessageRecall` (
  `RecalledMessageID` varchar(255) NOT NULL,
  `RecallType` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `MessageRecall`:
--

-- --------------------------------------------------------

--
-- Table structure for table `OwnershipInformation`
--

CREATE TABLE `OwnershipInformation` (
  `OwnershipInformationID` int(11) NOT NULL,
  `Owner` varchar(255) DEFAULT NULL,
  `OwningJurisdiction` varchar(255) DEFAULT NULL,
  `HomeDispatch` varchar(255) DEFAULT NULL,
  `HomeUnit` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `OwnershipInformation`:
--

-- --------------------------------------------------------

--
-- Table structure for table `Resource`
--

CREATE TABLE `Resource` (
  `ResourceID` varchar(255) NOT NULL,
  `NAME` varchar(255) DEFAULT NULL,
  `TypeStructureID` int(11) DEFAULT NULL,
  `TypeInfoID` int(11) DEFAULT NULL,
  `KeywordID` int(11) DEFAULT NULL,
  `Description` varchar(255) DEFAULT NULL,
  `Credentials` varchar(255) DEFAULT NULL,
  `Certifications` varchar(255) DEFAULT NULL,
  `SpecialRequirements` varchar(255) DEFAULT NULL,
  `ResponsiblePartyID` int(11) DEFAULT NULL,
  `OwnershipInformationID` int(11) DEFAULT NULL,
  `ResourceStatusID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `Resource`:
--   `TypeStructureID`
--       `ValueListType` -> `ValueListID`
--   `TypeInfoID`
--       `TypeInfoType` -> `TypeInfoID`
--   `KeywordID`
--       `ValueListType` -> `ValueListID`
--   `ResponsiblePartyID`
--       `ContactInformationType` -> `ContactInformationID`
--   `OwnershipInformationID`
--       `OwnershipInformation` -> `OwnershipInformationID`
--   `ResourceStatusID`
--       `ResourceStatus` -> `ResourceStatusID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ResourceInformation`
--

CREATE TABLE `ResourceInformation` (
  `ResourceInfoElementID` varchar(255) NOT NULL,
  `ResponseInformation` varchar(255) DEFAULT NULL,
  `Resource` varchar(255) DEFAULT NULL,
  `AssignmentInformationID` int(11) DEFAULT NULL,
  `ScheduleInformationID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ResourceInformation`:
--   `ResponseInformation`
--       `ResponseInformation` -> `PrecedingResourceInfoElementID`
--   `Resource`
--       `Resource` -> `ResourceID`
--   `AssignmentInformationID`
--       `AssignmentInformation` -> `AssignmentInformationID`
--   `ScheduleInformationID`
--       `ScheduleInformation` -> `ScheduleInformationID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ResourceMessage`
--

CREATE TABLE `ResourceMessage` (
  `MessageID` varchar(255) NOT NULL,
  `SentDateTime` datetime DEFAULT NULL,
  `MessageContentType` varchar(255) DEFAULT NULL,
  `MessageDescription` varchar(255) DEFAULT NULL,
  `OriginatingMessageID` varchar(255) DEFAULT NULL,
  `PrecedingMessageID` varchar(255) DEFAULT NULL,
  `IncidentID` varchar(255) DEFAULT NULL,
  `RecalledMessageID` varchar(255) DEFAULT NULL,
  `FundCode` varchar(255) DEFAULT NULL,
  `ContactInformationID` int(11) DEFAULT NULL,
  `ResourceInfoElementID` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ResourceMessage`:
--   `IncidentID`
--       `IncidentInformation` -> `IncidentID`
--   `RecalledMessageID`
--       `MessageRecall` -> `RecalledMessageID`
--   `FundCode`
--       `Funding` -> `FundCode`
--   `ContactInformationID`
--       `ContactInformationType` -> `ContactInformationID`
--   `ResourceInfoElementID`
--       `ResourceInformation` -> `ResourceInfoElementID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ResourceStatus`
--

CREATE TABLE `ResourceStatus` (
  `ResourceStatusID` int(11) NOT NULL,
  `InventoryRefreshDateTime` datetime DEFAULT NULL,
  `DeploymentStatus` int(11) DEFAULT NULL,
  `Availability` varchar(255) DEFAULT NULL,
  `HomeUnit` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ResourceStatus`:
--   `DeploymentStatus`
--       `ValueListType` -> `ValueListID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ResponseInformation`
--

CREATE TABLE `ResponseInformation` (
  `PrecedingResourceInfoElementID` varchar(255) NOT NULL,
  `ResponseTypeID` int(11) DEFAULT NULL,
  `ReasonCodeID` int(11) DEFAULT NULL,
  `ResponseReason` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ResponseInformation`:
--   `ReasonCodeID`
--       `ValueListType` -> `ValueListID`
--   `ResponseTypeID`
--       `ResponseTypeLookup` -> `ResponseTypeID`
--

-- --------------------------------------------------------

--
-- Table structure for table `ResponseTypeLookup`
--

CREATE TABLE `ResponseTypeLookup` (
  `ResponseTypeID` int(11) NOT NULL,
  `Description` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ResponseTypeLookup`:
--

-- --------------------------------------------------------

--
-- Table structure for table `ScheduleInformation`
--

CREATE TABLE `ScheduleInformation` (
  `ScheduleInformationID` int(11) NOT NULL,
  `ScheduleType` varchar(255) DEFAULT NULL,
  `DateTime` datetime DEFAULT NULL,
  `LocationTypeID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ScheduleInformation`:
--   `LocationTypeID`
--       `LocationType` -> `LocationTypeID`
--

-- --------------------------------------------------------

--
-- Table structure for table `TypeInfoType`
--

CREATE TABLE `TypeInfoType` (
  `TypeInfoID` int(11) NOT NULL,
  `ChildInfo` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `TypeInfoType`:
--

-- --------------------------------------------------------

--
-- Table structure for table `ValueListType`
--

CREATE TABLE `ValueListType` (
  `ValueListID` int(11) NOT NULL,
  `ValueListURN` varchar(255) DEFAULT NULL,
  `ValueType` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- RELATIONS FOR TABLE `ValueListType`:
--

--
-- Indexes for dumped tables
--

--
-- Indexes for table `AssignmentInformation`
--
ALTER TABLE `AssignmentInformation`
  ADD PRIMARY KEY (`AssignmentInformationID`),
  ADD KEY `AssignmentInstructionsID` (`AssignmentInstructionsID`);

--
-- Indexes for table `AssignmentInstructions`
--
ALTER TABLE `AssignmentInstructions`
  ADD PRIMARY KEY (`AssignmentInstructionsID`);

--
-- Indexes for table `ContactInformationType`
--
ALTER TABLE `ContactInformationType`
  ADD PRIMARY KEY (`ContactInformationID`),
  ADD KEY `ContactRole` (`ContactRole`),
  ADD KEY `ContactLocationID` (`ContactLocationID`);

--
-- Indexes for table `ContactRoleLookup`
--
ALTER TABLE `ContactRoleLookup`
  ADD PRIMARY KEY (`ContactRoleID`);

--
-- Indexes for table `Funding`
--
ALTER TABLE `Funding`
  ADD PRIMARY KEY (`FundCode`);

--
-- Indexes for table `IncidentInformation`
--
ALTER TABLE `IncidentInformation`
  ADD PRIMARY KEY (`IncidentID`);

--
-- Indexes for table `LocationType`
--
ALTER TABLE `LocationType`
  ADD PRIMARY KEY (`LocationTypeID`);

--
-- Indexes for table `MessageProperties`
--
ALTER TABLE `MessageProperties`
  ADD PRIMARY KEY (`id`),
  ADD KEY `MessagePropertyLookupID` (`MessagePropertyLookupID`);

--
-- Indexes for table `MessagePropertiesLookup`
--
ALTER TABLE `MessagePropertiesLookup`
  ADD PRIMARY KEY (`RequirementType`);

--
-- Indexes for table `MessageRecall`
--
ALTER TABLE `MessageRecall`
  ADD PRIMARY KEY (`RecalledMessageID`);

--
-- Indexes for table `OwnershipInformation`
--
ALTER TABLE `OwnershipInformation`
  ADD PRIMARY KEY (`OwnershipInformationID`);

--
-- Indexes for table `Resource`
--
ALTER TABLE `Resource`
  ADD PRIMARY KEY (`ResourceID`),
  ADD KEY `TypeStructureID` (`TypeStructureID`),
  ADD KEY `TypeInfoID` (`TypeInfoID`),
  ADD KEY `KeywordID` (`KeywordID`),
  ADD KEY `ResponsiblePartyID` (`ResponsiblePartyID`),
  ADD KEY `OwnershipInformationID` (`OwnershipInformationID`),
  ADD KEY `ResourceStatusID` (`ResourceStatusID`);

--
-- Indexes for table `ResourceInformation`
--
ALTER TABLE `ResourceInformation`
  ADD PRIMARY KEY (`ResourceInfoElementID`),
  ADD KEY `ResponseInformation` (`ResponseInformation`),
  ADD KEY `Resource` (`Resource`),
  ADD KEY `AssignmentInformationID` (`AssignmentInformationID`),
  ADD KEY `ScheduleInformationID` (`ScheduleInformationID`);

--
-- Indexes for table `ResourceMessage`
--
ALTER TABLE `ResourceMessage`
  ADD PRIMARY KEY (`MessageID`),
  ADD KEY `IncidentID` (`IncidentID`),
  ADD KEY `RecalledMessageID` (`RecalledMessageID`),
  ADD KEY `FundCode` (`FundCode`),
  ADD KEY `ContactInformationID` (`ContactInformationID`),
  ADD KEY `ResourceInfoElementID` (`ResourceInfoElementID`);

--
-- Indexes for table `ResourceStatus`
--
ALTER TABLE `ResourceStatus`
  ADD PRIMARY KEY (`ResourceStatusID`),
  ADD KEY `DeploymentStatus` (`DeploymentStatus`);

--
-- Indexes for table `ResponseInformation`
--
ALTER TABLE `ResponseInformation`
  ADD PRIMARY KEY (`PrecedingResourceInfoElementID`),
  ADD KEY `ReasonCodeID` (`ReasonCodeID`),
  ADD KEY `ResponseTypeID` (`ResponseTypeID`);

--
-- Indexes for table `ResponseTypeLookup`
--
ALTER TABLE `ResponseTypeLookup`
  ADD PRIMARY KEY (`ResponseTypeID`);

--
-- Indexes for table `ScheduleInformation`
--
ALTER TABLE `ScheduleInformation`
  ADD PRIMARY KEY (`ScheduleInformationID`),
  ADD KEY `LocationTypeID` (`LocationTypeID`);

--
-- Indexes for table `TypeInfoType`
--
ALTER TABLE `TypeInfoType`
  ADD PRIMARY KEY (`TypeInfoID`);

--
-- Indexes for table `ValueListType`
--
ALTER TABLE `ValueListType`
  ADD PRIMARY KEY (`ValueListID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `MessageProperties`
--
ALTER TABLE `MessageProperties`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
--
-- Constraints for dumped tables
--

--
-- Constraints for table `AssignmentInformation`
--
ALTER TABLE `AssignmentInformation`
  ADD CONSTRAINT `AssignmentInformation_ibfk_1` FOREIGN KEY (`AssignmentInstructionsID`) REFERENCES `AssignmentInstructions` (`AssignmentInstructionsID`);

--
-- Constraints for table `ContactInformationType`
--
ALTER TABLE `ContactInformationType`
  ADD CONSTRAINT `ContactInformationType_ibfk_1` FOREIGN KEY (`ContactRole`) REFERENCES `ContactRoleLookup` (`ContactRoleID`),
  ADD CONSTRAINT `ContactInformationType_ibfk_2` FOREIGN KEY (`ContactLocationID`) REFERENCES `LocationType` (`LocationTypeID`);

--
-- Constraints for table `MessageProperties`
--
ALTER TABLE `MessageProperties`
  ADD CONSTRAINT `MessageProperties_ibfk_1` FOREIGN KEY (`MessagePropertyLookupID`) REFERENCES `MessagePropertiesLookup` (`RequirementType`);

--
-- Constraints for table `Resource`
--
ALTER TABLE `Resource`
  ADD CONSTRAINT `Resource_ibfk_1` FOREIGN KEY (`TypeStructureID`) REFERENCES `ValueListType` (`ValueListID`),
  ADD CONSTRAINT `Resource_ibfk_2` FOREIGN KEY (`TypeInfoID`) REFERENCES `TypeInfoType` (`TypeInfoID`),
  ADD CONSTRAINT `Resource_ibfk_3` FOREIGN KEY (`KeywordID`) REFERENCES `ValueListType` (`ValueListID`),
  ADD CONSTRAINT `Resource_ibfk_4` FOREIGN KEY (`ResponsiblePartyID`) REFERENCES `ContactInformationType` (`ContactInformationID`),
  ADD CONSTRAINT `Resource_ibfk_5` FOREIGN KEY (`OwnershipInformationID`) REFERENCES `OwnershipInformation` (`OwnershipInformationID`),
  ADD CONSTRAINT `Resource_ibfk_6` FOREIGN KEY (`ResourceStatusID`) REFERENCES `ResourceStatus` (`ResourceStatusID`);

--
-- Constraints for table `ResourceInformation`
--
ALTER TABLE `ResourceInformation`
  ADD CONSTRAINT `ResourceInformation_ibfk_1` FOREIGN KEY (`ResponseInformation`) REFERENCES `ResponseInformation` (`PrecedingResourceInfoElementID`),
  ADD CONSTRAINT `ResourceInformation_ibfk_2` FOREIGN KEY (`Resource`) REFERENCES `Resource` (`ResourceID`),
  ADD CONSTRAINT `ResourceInformation_ibfk_3` FOREIGN KEY (`AssignmentInformationID`) REFERENCES `AssignmentInformation` (`AssignmentInformationID`),
  ADD CONSTRAINT `ResourceInformation_ibfk_4` FOREIGN KEY (`ScheduleInformationID`) REFERENCES `ScheduleInformation` (`ScheduleInformationID`);

--
-- Constraints for table `ResourceMessage`
--
ALTER TABLE `ResourceMessage`
  ADD CONSTRAINT `ResourceMessage_ibfk_1` FOREIGN KEY (`IncidentID`) REFERENCES `IncidentInformation` (`IncidentID`),
  ADD CONSTRAINT `ResourceMessage_ibfk_2` FOREIGN KEY (`RecalledMessageID`) REFERENCES `MessageRecall` (`RecalledMessageID`),
  ADD CONSTRAINT `ResourceMessage_ibfk_3` FOREIGN KEY (`FundCode`) REFERENCES `Funding` (`FundCode`),
  ADD CONSTRAINT `ResourceMessage_ibfk_4` FOREIGN KEY (`ContactInformationID`) REFERENCES `ContactInformationType` (`ContactInformationID`),
  ADD CONSTRAINT `ResourceMessage_ibfk_5` FOREIGN KEY (`ResourceInfoElementID`) REFERENCES `ResourceInformation` (`ResourceInfoElementID`);

--
-- Constraints for table `ResourceStatus`
--
ALTER TABLE `ResourceStatus`
  ADD CONSTRAINT `ResourceStatus_ibfk_1` FOREIGN KEY (`DeploymentStatus`) REFERENCES `ValueListType` (`ValueListID`);

--
-- Constraints for table `ResponseInformation`
--
ALTER TABLE `ResponseInformation`
  ADD CONSTRAINT `ResponseInformation_ibfk_1` FOREIGN KEY (`ReasonCodeID`) REFERENCES `ValueListType` (`ValueListID`),
  ADD CONSTRAINT `ResponseInformation_ibfk_2` FOREIGN KEY (`ResponseTypeID`) REFERENCES `ResponseTypeLookup` (`ResponseTypeID`);

--
-- Constraints for table `ScheduleInformation`
--
ALTER TABLE `ScheduleInformation`
  ADD CONSTRAINT `ScheduleInformation_ibfk_1` FOREIGN KEY (`LocationTypeID`) REFERENCES `LocationType` (`LocationTypeID`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
