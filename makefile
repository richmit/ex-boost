##
# @file      makefile
# @author    Mitch Richling <https://www.mitchr.me/>
# @Copyright Copyright 2003 by Mitch Richling.  All rights reserved.
# @brief     Build a few boost examples.@EOL
# @Std       GNUmake

# Fix for local needs
CXX      = g++
CXXFLAGS = -Wall -std=c++11

# Some platforms suffix boost libraries with -mt...
#MT = -mt

# Uncomment to build all when make file changes
SPECDEP=makefile

# Put targets here
TARGETS = tokenExample boostRandEx format splitWithSplitAlgo splitWithTokenizer intervalA 

all : $(TARGETS)
	@echo Make Complete

clean :
	rm -rf a.out *~ *.bak $(TARGETS)
	@echo Make Complete

#BOOSTIP = -I/opt/local/include
#BOOSTLP = -L/opt/local/lib

tokenExample : tokenExample.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) tokenExample.cpp -o tokenExample

progOptions : progOptions.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) progOptions.cpp $(BOOSTLP) -lboost_program_options$(MT) -o progOptions

boostRandEx : boostRandEx.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) boostRandEx.cpp -o boostRandEx $(BOOSTLP)

format : format.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) format.cpp -o format

intervalA : intervalA.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) intervalA.cpp -o intervalA

splitWithSplitAlgo : splitWithSplitAlgo.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) splitWithSplitAlgo.cpp -o splitWithSplitAlgo

splitWithTokenizer : splitWithTokenizer.cpp $(SPECDEP)
	$(CXX) $(CXXFLAGS) $(BOOSTIP) splitWithTokenizer.cpp -o splitWithTokenizer
