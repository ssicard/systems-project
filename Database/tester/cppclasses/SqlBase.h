#ifndef SQLBASE_H
#define SQLBASE_H
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
#define EXAMPLE_HOST "tcp://127.0.0.1:3306"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "password"
#define EXAMPLE_DB "progDB"

};

#endif