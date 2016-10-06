
//Helper class for intermediate data operations

#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>
#include<map>

using namespace std;

//Intermediate data structure to pass data from parser to simulator 
struct DiceProperities
{
   string diceName;
   vector<pair<int, int>> m_loadedSide;
};

//Intermediate data structure to store each throw of the dice
struct ThrowDisplay
{
   int throwNo;
   vector<pair<string, int>> m_throwresult;
};

//Intermediate data structure to store the random throw of each side of dice to calculate percentage
struct PercentageDisplay
{
	string diceName;
	map<int, int> m_percentageResult;

	//default constructor for six sided dice 
	PercentageDisplay()
	{
       for(int i = 1; i <= 6; i++)
	   {
		   m_percentageResult.insert(make_pair(i, 0));
	   }
	}

	//If the sides are more or less than six
	PercentageDisplay(int numsides)
	{
       for(int i = 1; i <= numsides; i++)
	   {
		   m_percentageResult.insert(make_pair(i, 0));
	   }
	}
};

#endif