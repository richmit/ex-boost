#include "boost/program_options.hpp"

#include <iostream>
#include <string>

int main(int argc, char** argv)
{
  try {
    /** Define and parse the program options */
    namespace po = boost::program_options;
    po::options_description poCmdLineOptDesc("Options");
    poCmdLineOptDesc.add_options()
      ("help,h",                                 "Print help and exit")
      ("verbose,V",   po::value<std::string>(),  "Set verbosity level")
      ("version",                                "Print version and exit")
      ("dir",         po::value<std::string>(),  "Directory to traverse")                  // positional arg
      ;
    po::positional_options_description poCmdLinePosDesc;
    poCmdLinePosDesc.add("dir", -1);

    po::variables_map poCmdLineVarMap;
    try {

      po::store(po::command_line_parser(argc, argv).options(poCmdLineOptDesc).positional(poCmdLinePosDesc).run(), poCmdLineVarMap);

      /** --help,h */
      if ( poCmdLineVarMap.count("help") ) {
        std::cout << "Command Line Help: " << std::endl;
        std::cout << poCmdLineOptDesc      << std::endl;
        return 0;
      }

      if (poCmdLineVarMap.count("verbose")) {
        std::cout << "Verbose Level: " << poCmdLineVarMap["verbose"].as<std::string>() << std::endl;
      }

      if (poCmdLineVarMap.count("dir")) {
        std::cout << "Directory: " << poCmdLineVarMap["dir"].as<std::string>() << std::endl;
      }

       // throws on error, so do after help in case there are any problems
      po::notify(poCmdLineVarMap);
    } catch(po::error& e) {
      std::cerr << "ERROR Processing Command Line Arguments: " << e.what() << std::endl << std::endl;
      std::cerr << poCmdLineOptDesc << std::endl;
      return 1;
    }

    // application code here //

  } catch(std::exception& e) {
    std::cerr << "Unhandled Exception reached the top of main: "
              << e.what() << ", application will now exit" << std::endl;
    return 2;

  }

  return 0;

} // main
