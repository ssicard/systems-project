#include "ResourceStatus.h"

/*
ResourceStatus::ResourceStatus(int resourceStatusID = -1)
{
	this->ResourceStatusID = resourceStatusID;
}


ResourceStatus::ResourceStatus()
{
	this->ResourceStatusID = -1;
}

ResourceStatus::~ResourceStatus()
{
}
*/

void ResourceStatus::getFromDatabase() {

	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;
		sql::ResultSet *res;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("SELECT `ResourceStatusID`, `InventoryRefreshDateTime`, `DeploymentStatus`, `Availability`, `HomeUnit` FROM `ResourceStatus` WHERE `ResourceStatusID` = ?");

		prep_stmt->setInt(1, this->ResourceStatusID);
		
		res = prep_stmt->executeQuery();

		while (res->next()) {
			this->ResourceStatusID = res->getInt("ResourceStatusID");
			this->_InventoryRefreshDateTime = res->getString("InventoryRefreshDateTime");
			this->DeploymentStatus = res->getInt("DeploymentStatus");
			this->Availability = res->getString("Availability");
			this->HomeUnit= res->getString("HomeUnit");
		}

		this->_DeploymentStatus.ValueListID = this->DeploymentStatus;

		this->_DeploymentStatus.getFromDatabase();

		delete res;
		delete stmt;
		delete prep_stmt;
		delete con;

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		return;
	}
}

void ResourceStatus::insertIntoDatabase() {
	if (this->DeploymentStatus != -1) {
		this->_DeploymentStatus.ValueListID = this->DeploymentStatus;
		this->_DeploymentStatus.insertIntoDatabase();
	}

	try {
		sql::Connection *con;
		sql::PreparedStatement *prep_stmt;
		sql::mysql::MySQL_Driver *driver;
		sql::Statement *stmt;

		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect(EXAMPLE_HOST, EXAMPLE_USER, EXAMPLE_PASS);
		stmt = con->createStatement();
		stmt->execute("USE " EXAMPLE_DB);

		prep_stmt = con->prepareStatement("INSERT INTO `ResourceStatus` (`ResourceStatusID`, `InventoryRefreshDateTime`, `DeploymentStatus`, `Availability`, `HomeUnit`) VALUES (?,?,?,?,?)");
		prep_stmt->setInt(1, this->ResourceStatusID);
		prep_stmt->setString(2, this->_InventoryRefreshDateTime);
		prep_stmt->setInt(3, this->DeploymentStatus);
		prep_stmt->setString(4, this->Availability);
		prep_stmt->setString(5, this->HomeUnit);

		prep_stmt->execute();

		delete stmt;
		delete prep_stmt;
		delete con;

	} catch (sql::SQLException &e) {
		std::cout << "# ERR: SQLException in " << __FILE__;
		std::cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << std::endl;
		std::cout << "# ERR: " << e.what();
		std::cout << " (MySQL error code: " << e.getErrorCode();
		std::cout << ", SQLState: " << e.getSQLState() << " )" << std::endl;

		return;
	}
}

bool ResourceStatus::areFieldsValid() {
	return false;
}
