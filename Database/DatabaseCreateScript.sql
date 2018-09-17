-- phpMyAdmin SQL Dump
-- version 4.6.6deb5
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Sep 17, 2018 at 01:25 AM
-- Server version: 5.7.23-0ubuntu0.18.04.1
-- PHP Version: 7.2.7-0ubuntu0.18.04.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `progDB`
--
CREATE DATABASE IF NOT EXISTS `progDB` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `progDB`;

-- --------------------------------------------------------

--
-- Table structure for table `MessageProperties`
--

CREATE TABLE `MessageProperties` (
  `id` int(11) NOT NULL,
  `MessageID` tinyint(4) NOT NULL DEFAULT '0',
  `SentDateTime` tinyint(4) NOT NULL DEFAULT '0',
  `MessageContentType` tinyint(4) NOT NULL DEFAULT '0',
  `MessageDescription` tinyint(4) NOT NULL DEFAULT '0',
  `OriginatingMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `PrecedingMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `Incident_Information` tinyint(4) NOT NULL DEFAULT '0',
  `MessageRecall` tinyint(4) NOT NULL DEFAULT '0',
  `Funding` tinyint(4) NOT NULL DEFAULT '0',
  `ContactInformation` tinyint(4) NOT NULL DEFAULT '0',
  `Resource_Information` tinyint(4) NOT NULL DEFAULT '0',
  `IncidentID` tinyint(4) NOT NULL DEFAULT '0',
  `IncidentDescription` tinyint(4) NOT NULL DEFAULT '0',
  `RecalledMessageID` tinyint(4) NOT NULL DEFAULT '0',
  `RecallType` tinyint(4) NOT NULL DEFAULT '0',
  `FundCode` tinyint(4) NOT NULL DEFAULT '0',
  `FundingInfo` tinyint(4) NOT NULL DEFAULT '0',
  `ResourceInfoElementID` tinyint(4) NOT NULL DEFAULT '0',
  `Response_Information` tinyint(4) NOT NULL DEFAULT '0',
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
  `Location` tinyint(4) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `MessagePropertiesLookup`
--

CREATE TABLE `MessagePropertiesLookup` (
  `RequirementType` int(11) NOT NULL DEFAULT '0',
  `RequirementDesc` varchar(25) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `MessagePropertiesLookup`
--

INSERT INTO `MessagePropertiesLookup` (`RequirementType`, `RequirementDesc`) VALUES
(0, 'N/A'),
(1, 'C'),
(2, 'O'),
(3, 'R');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `MessageProperties`
--
ALTER TABLE `MessageProperties`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `MessagePropertiesLookup`
--
ALTER TABLE `MessagePropertiesLookup`
  ADD PRIMARY KEY (`RequirementType`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;