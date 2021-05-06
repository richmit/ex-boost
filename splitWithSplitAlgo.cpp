// -*- Mode:C++; Coding:us-ascii-unix; fill-column:132 -*-
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
   @file      splitWithSplitAlgo.cpp
   @author    Mitch Richling <https://www.mitchr.me>
   @Copyright Copyright 2013 by Mitch Richling.  All rights reserved.
   @brief     Split a string with boost split.@EOL
   @Keywords  
   @Std       C++98

*/

//----------------------------------------------------------------------------------------------------------------------------------

#include <string>                                                        /* C++ strings             C++11    */
#include <vector>                                                        /* STL vector              C++11    */ 
#include <iostream>                                                      /* C++ iostream            C++11    */

#include <boost/algorithm/string/split.hpp>                              /* Split Strings           Boost    */
#include <boost/algorithm/string/classification.hpp>                     /* Char Classes            Boost    */

int main(int argc, char* argv[]) {

  std::vector<std::string> feilds;
  boost::split(feilds, "aa,b,cccc,d,ee,f,g,,h", boost::is_any_of(","), boost::token_compress_off);

  for(std::vector<std::string>::iterator curFeild=feilds.begin(); curFeild!=feilds.end(); ++curFeild)
    std::cout << "\"" << *curFeild << "\"" <<  std::endl;
}
