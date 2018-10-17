#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>


#include "mysql_connection.h"
#include "mysql_driver.h"
#include "driver.h"
#include "exception.h"
#include "resultset.h"
#include "statement.h"
#include "prepared_statement.h"

#include "MessageObjectBase.h"


MessageObjectBase::MessageObjectBase() {

}

void MessageObjectBase::getFromDatabase() {

}

void MessageObjectBase::insertIntoDatabase() {

}

bool MessageObjectBase::areFieldsValid() {
    return false;
}
