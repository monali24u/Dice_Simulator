
//Class for Opening a file and read key, values pairs (i.e. key=value)

#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <string>

using namespace std;

class DiceSimulator;

class FileParser
{
	public:
		FileParser(){}
		void ParseFile(string FilePath, DiceSimulator *ptr_DS); //Parse the given input file
};

#endif