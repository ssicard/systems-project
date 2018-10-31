#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctime>
#include <sstream>

using std::string;
using std::cout;
using std::ofstream;

class Logger
{
public:
  enum LogLevel { ALL, INFO, ERROR };
  enum LogMode { NORMAL, DEBUG };
private:
  LogLevel m_level;
  LogMode m_mode;
  ofstream m_log_info;
  ofstream m_log_errors;  
  ofstream m_log_to;
  ofstream m_log_from;
  const string LogLevelNames[3] = { "ALL","INFO","ERROR" };
  string m_path_name = "./log/";
  string m_info_file_path = "log/LogInfo.txt";
  string m_error_file_path = "log/LogError.txt";
  string m_to_path{""};
  string m_from_path{""};
  string m_date{""};
  string m_prev_date{""};
  string m_year{""};
  string m_month{""};
  time_t m_current_time = time(0); 
  bool log_dir_check(const char* path){
    struct stat info;
    if(stat( path, &info ) != 0)
        return 0;
    else if(info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
  }
  void check_m_date(){
    std::time_t current;
    std::tm* info;
    char buf[25];
    std::time(&current);
    info = std::localtime(&current);
    std::strftime(buf, 25, "%Y%m%d", info);
    std::stringstream ss;
    ss << buf;
    ss >> m_date;
    m_year = m_date.substr(0,4);
    m_month = m_date.substr(4,2);
  }
  void open_log_file(){
    if(!log_dir_check(m_path_name.c_str())){
      string command = "mkdir -p " + m_path_name;
      std::cout << command << std::endl;
      system(command.c_str());
    }
    m_log_info.open(m_info_file_path.c_str(), std::ofstream::out | std::ofstream::app);
    m_log_errors.open(m_error_file_path.c_str(), std::ofstream::out | std::ofstream::app);
  }
  void check_and_update_date_path(){
    check_m_date();
    if (m_date != m_prev_date){ // got a new date
      m_log_info.close();
      m_log_errors.close();
      m_path_name = "log/" + m_year + "/" + m_month + "/";
      m_info_file_path = m_path_name + m_date + "_Info.txt";
      m_error_file_path = m_path_name + m_date + "_Error.txt";
      m_to_path = m_path_name + m_date;
      m_from_path = m_path_name + m_date;
      open_log_file();
    }
    m_prev_date = m_date; 
  }
public:
  Logger(LogLevel level, LogMode mode) 
  : m_level{level}, 
    m_mode{mode}
  {
    if (m_mode == DEBUG) {
      cout << " [ Logger initialized as debug mode ] " << std::endl;
    } else {  
      check_and_update_date_path();
    }
  }
  ~Logger()
  {
    m_log_info.close();
    m_log_errors.close();
  }
  void log(LogLevel level, const string& message){
    char* dt = ctime(&m_current_time);
    if (m_mode == DEBUG){
      switch (level){
        case INFO:
          cout << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break;
        case ERROR:
          cout << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break;
        case ALL:
          cout << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          cout << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break;
        default:
          m_log_errors << "[" << LogLevelNames[ERROR] << "]: " << dt << " wrong log level invoked, message: " << message << std::endl;
          break;
      }
    } else {
      check_and_update_date_path();
      switch (level){
        case INFO:
          m_log_info  << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break; 
        case ERROR:
          m_log_errors << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break;
        case ALL:
          m_log_errors << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          m_log_info << "[" << LogLevelNames[level] << "]: " << dt << message << std::endl;
          break; 
        default:
          m_log_errors << "[" << LogLevelNames[ERROR] << "]: " << dt << "wrong log level invoked, message: " << message << std::endl;
          break; 
      }
    }
  }
  void log_message_from(const string& from, const string& message){
    char* dt = ctime(&m_current_time);
    check_and_update_date_path();
    m_from_path += "_from_" + from;
    m_log_from.open(m_from_path.c_str(), std::ofstream::out | std::ofstream::app);
    m_log_from  << dt << message << std::endl;
    m_log_from.close();
  }
  void log_message_to(const string& to, const string& message){
    char* dt = ctime(&m_current_time);
    check_and_update_date_path();
    m_to_path += "_to_" + to;
    m_log_to.open(m_to_path.c_str(), std::ofstream::out | std::ofstream::app);
    m_log_to << dt << message << std::endl;
    m_log_to.close();
  }
};

/*
int main(){
  Logger l (Logger::ALL, Logger::NORMAL);
  l.log(Logger::INFO, "info test");
  l.log(Logger::ERROR, "err test");
  string message = "hi babe";
  l.log_message_from("nam", message);
  l.log_message_to("chaneo", message); 
}
*/

