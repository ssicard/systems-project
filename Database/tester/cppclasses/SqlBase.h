#pragma once

class SqlBase {
   public:
      void getFromDatabase();
      void insertIntoDatabase();
      bool areFieldsValid();
class SqlBase {
   public:
      virtual void getFromDatabase() {
         throw "Unimplimented";
      }
      virtual void insertIntoDatabase() {
         throw "Unimplimented";
      }
      virtual bool areFieldsValid(){
         throw "Unimplimented";
      }
>>>>>>> database2
#define EXAMPLE_HOST "tcp://127.0.0.1:3306"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "progDB"

};