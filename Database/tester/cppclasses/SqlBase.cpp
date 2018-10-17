// #ifndef SQLBASE_H
// #define SQLBASE_H
// class SqlBase {
//    public:
//       virtual void getFromDatabase() {
//          throw "Unimplimented";
//       }
//       virtual void insertIntoDatabase() {
//          throw "Unimplimented";
//       }
//       virtual bool areFieldsValid(){
//          throw "Unimplimented";
//       }
// #define EXAMPLE_HOST "tcp://127.0.0.1:3306"
// #define EXAMPLE_USER "root"
// #define EXAMPLE_PASS "password"
// #define EXAMPLE_DB "progDB"

// };

// #endif

   // try {
      
   //    // ...
   //    sql::Connection *con;
   //    sql::PreparedStatement  *prep_stmt
   //    // ...

   //    prep_stmt = con->prepareStatement("INSERT INTO test(id, label) VALUES (?, ?)");

   //    prep_stmt->setInt(1, 1);
   //    prep_stmt->setString(2, "a");
   //    prep_stmt->execute();

   //    prep_stmt->setInt(1, 2);
   //    prep_stmt->setString(2, "b");
   //    prep_stmt->execute();

   //    delete prep_stmt;
   //    delete con;

   // } catch (sql::SQLException &e) {
   //    cout << "# ERR: SQLException in " << __FILE__;
   //    cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
   //      /* what() (derived from std::runtime_error) fetches error message */
   //    cout << "# ERR: " << e.what();
   //    cout << " (MySQL error code: " << e.getErrorCode();
   //    cout << ", SQLState: " << e.getSQLState() << " )" << endl;

   //    return;
   // }
