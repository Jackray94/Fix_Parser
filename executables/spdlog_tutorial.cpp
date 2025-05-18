#include "spdlog/sinks/basic_file_sink.h"
#include <memory>
#include <our_project/LibraryX/tools.h>
#include <spdlog/spdlog.h>
#include <external/protobuf/apple.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////PART 1 - using the default logger provided by spdlog//////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// int main()
// {
//   //spdlog::default_logger() returns a shared pointer of type spdlog::logger
//   //set_level() sets the default level as name suggests
//   spdlog::default_logger()->set_level(spdlog::level::trace);
//
//   spdlog::trace("TRACE"); // LogLevel: TRACE
//   spdlog::debug("DEBUG"); // LogLevel: DEBUG
//   //Only INFO and down will be printed because of the default log level
//   spdlog::info("INFO"); // LogLevel: INFO
//   spdlog::warn("WARN"); // LogLevel: WARN
//   spdlog::error("ERROR"); // LogLevel: ERROR
//   spdlog::critical("CRITICAL"); // LogLevel: CRITICAL
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////



/*
  * redo above but using a custom logger called MyLogger by creating a std::shared_ptr<spdLog::logger> 
  * - the constructor will take a const * char that is the name of the logger - i.e., "myLogger"
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////PART 2 - creating a custom logger, in place of the default one////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// int main()
// {
//   std::shared_ptr<spdlog::logger> myLogger = std::make_shared<spdlog::logger>("myLogger");
//   myLogger->set_level(spdlog::level::trace);
//
//   myLogger->log(spdlog::level::trace, "TRACE");
//   myLogger->log(spdlog::level::debug, "DEBUG");
//   myLogger->log(spdlog::level::info, "INFO");
//   myLogger->log(spdlog::level::warn, "WARNING");
//   myLogger->log(spdlog::level::err, "ERROR");
//   myLogger->log(spdlog::level::critical, "CRITICAL");
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  * In part 2 when buildling nothing will happen becuase myLogger has no custom logging sinks attached. A logging sink is sort of like
  * the unit responsible for displaying a message or processing it. 
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////PART 3 - created a logging sink to use with the custom logger/////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <spdlog/sinks/stdout_color_sinks.h>
// #include <vector>
// int main()
// {
//   std::shared_ptr<spdlog::logger> myLogger = std::make_shared<spdlog::logger>("myLogger");
//   myLogger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_st>());
//
//   myLogger->set_level(spdlog::level::trace);
//   myLogger->log(spdlog::level::trace, "TRACE");
//   myLogger->log(spdlog::level::debug, "DEBUG");
//   myLogger->log(spdlog::level::info, "INFO");
//   myLogger->log(spdlog::level::warn, "WARNING");
//   myLogger->log(spdlog::level::err, "ERROR");
//   myLogger->log(spdlog::level::critical, "CRITICAL");
//   return 0;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  * We will want to have different kind of sinks that just the stdout sink in part 3.
  * This one uses a basic file sink for a debug log file sink and a error log file sink. And also inlcudes the console log sink from part 5.
*/
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
// /////////////////////////PART 4 - using a file system sink ////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <spdlog/sinks/stdout_color_sinks.h>
// #include <vector>
// int main()
// {
//   auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
//   auto errorLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("error.log");
//   errorLogFileSink->set_level(spdlog::level::warn);
//   auto debugLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("debug.log");
//   debugLogFileSink->set_level(spdlog::level::debug);
//
//   std::shared_ptr<spdlog::logger> myLogger = std::make_shared<spdlog::logger>("myLogger");
//   myLogger->sinks().push_back(consoleSink);
//   myLogger->sinks().push_back(errorLogFileSink);
//   myLogger->sinks().push_back(debugLogFileSink);
//
    //optionally I could add the customization patterns to the logger - get the flags from spdlog github readme
    // myLogger->set_pattern("enter flags here");
//   myLogger->set_level(spdlog::level::trace);
//
//   myLogger->log(spdlog::level::trace, "TRACE");
//   myLogger->log(spdlog::level::debug, "DEBUG");
//   myLogger->log(spdlog::level::info, "INFO");
//   myLogger->log(spdlog::level::warn, "WARNING");
//   myLogger->log(spdlog::level::err, "ERROR");
//   myLogger->log(spdlog::level::critical, "CRITICAL");
//   return 0;
// }
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////
// ///////////////////////////////////////////////////////////////////////////////////////////////////////


/*
  * Realistically we can't just pass myLogger to every function, so we can have better logger management
  * registering our logger
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////PART 5 - logger management/////// ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include <spdlog/sinks/stdout_color_sinks.h>
#include <vector>
int main()
{
  auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  auto errorLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("error.log");
  errorLogFileSink->set_level(spdlog::level::warn);
  auto debugLogFileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("debug.log");
  debugLogFileSink->set_level(spdlog::level::debug);

  std::shared_ptr<spdlog::logger> myLogger = std::make_shared<spdlog::logger>("main");
  myLogger->sinks().push_back(consoleSink);
  myLogger->sinks().push_back(errorLogFileSink);
  myLogger->sinks().push_back(debugLogFileSink);

  std::shared_ptr<spdlog::logger> dbgLogger = std::make_unique<spdlog::logger>("debug");
  dbgLogger->sinks().push_back(consoleSink);

  //optionally I could add the customization patterns to the logger - get the flags from spdlog github readme
  // myLogger->set_pattern("enter flags here");
  myLogger->set_level(spdlog::level::trace);
  dbgLogger->set_level(spdlog::level::trace);

  spdlog::set_default_logger(myLogger);
  spdlog::register_logger(dbgLogger);

  myLogger->log(spdlog::level::trace, "TRACE");
  myLogger->log(spdlog::level::debug, "DEBUG");
  myLogger->log(spdlog::level::info, "INFO");
  myLogger->log(spdlog::level::warn, "WARNING");
  myLogger->log(spdlog::level::err, "ERROR");
  myLogger->log(spdlog::level::critical, "CRITICAL");

  spdlog::get("debug")->warn("This is console only");
  ///////protobuf test:////////
  WriteAndReadThing("BinaryAddressBook.txt");
  return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////
