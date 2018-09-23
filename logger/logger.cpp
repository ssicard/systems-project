#include <iostream>
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctime>

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
  const string LogLevelNames[3] = { "ALL","INFO","ERROR" };
  const char* m_path_name = "./log/";
  string m_info_file = "log/LogInfo.txt";
  string m_error_file = "log/LogError.txt";
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
public:
  Logger(LogLevel level, LogMode mode) 
  : m_level{level}, 
    m_mode{mode}
  {
    if (m_mode == DEBUG) {
      cout << " [ Logger initialized as debug mode ] " << std::endl;
    } else {
      if(!log_dir_check(m_path_name)){
        system("mkdir log");
      } 
      m_log_info.open(m_info_file.c_str(), std::ofstream::out | std::ofstream::app);
      m_log_errors.open(m_error_file.c_str(), std::ofstream::out | std::ofstream::app); 
    }
  }
  ~Logger()
  {
    m_log_info.close();
    m_log_errors.close();
  }
  void log(LogLevel level, string message)
  {
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
};
