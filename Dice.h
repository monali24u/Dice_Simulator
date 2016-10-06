
//class representing the properities and functions of a Dice

#ifndef DICE_H_
#define DICE_H_

#include <vector>
#include <string>

using namespace std;

class Dice
{
	private:
		string m_diceName;
		int m_numberOfsides;
		vector<pair<int, int>> m_numberOnEachSide;  //connects side to number(basecase (1,1)(2,2)(3,3)(4,4)(5,5)(6,6))
		pair<int, int> m_loadedSide;                //connects loadedSide to loadAmount

	public:
		Dice();
		Dice(int Numsides);
		void SetDiceName(string dicename);
		string GetDiceName();
		void SetNumberOfSides(int val);
		int GetNumberOfSides();
		void SetLoadedSide(int side, int val);
		void GetLoadedSide(pair<int, int> &loadedside);
};

#endif