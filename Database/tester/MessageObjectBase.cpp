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


#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "progDB"

#include "MessageObjectBase.h"


MessageObjectBase::MessageObjectBase() {

}

void MessageObjectBase::getFromDatabase() {

}

void MessageObjectBase::insertIntoDatabase() {

}

bool MessageObjectBase::areFieldsValid() {
    if(this->MessageProperties.MessageID == 3){
        //required
        if(this->ResourceMessage.MessageID == null){
            throw "Resource Message Not implimented";
            return false;
        }
    }else if(this->MessageProperties.MessageID > 0){
        //optional
        if(this->ResourceMessage.MessageID != null){
            //if a forign key ref, call check
        }

    }
    //etc
}

bool MessageObjectBase::getResourceMessage(string MessageObjectName) {

}
