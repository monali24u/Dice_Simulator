#include <sstream>
#include <iostream>
#include "DiceSimulator.h"
#include "DiceEngine.h"
#include "Utility.h"

using namespace std;

void DiceEngine::CalculateDiceResult(DiceSimulator *ptr_DS)
{
	ThrowDisplay t_default;
	vector<ThrowDisplay> result_vec(ptr_DS->GetNumberOfThrows(), t_default);

	PercentageDisplay p_default;
	vector<PercentageDisplay> percent_vec(ptr_DS->GetNumberOfDices(), p_default);

	//generate random dice result
	CalculateThrows(ptr_DS, result_vec, percent_vec);
}
//
void DiceEngine::CalculateThrows(DiceSimulator *ptr_DS, vector<ThrowDisplay> &result_vec, vector<PercentageDisplay> &percent_vec)
{
	vector<Dice> newDiceVec = ptr_DS->GetDiceContainer();
	int DiceCount = newDiceVec.size();

	for(int j = 0; j < DiceCount; j++)
	{
		Dice obj = newDiceVec.at(j);
		int random;
		std::pair<int, int> LoadedDice;
		obj.GetLoadedSide(LoadedDice);
		int LoadedSide = LoadedDice.first;
		int LoadAmount = LoadedDice.second;
		int size = obj.GetNumberOfSides() + (LoadAmount - 1);

		//For calculation of percentage
		percent_vec[j].diceName = obj.GetDiceName();

		//number of rolls = 10
		for(int i = 0; i < ptr_DS->GetNumberOfThrows(); i++)
		{
			//For calculation of output
			result_vec[i].throwNo = i + 1;

			//generate numbers between 1-6 randomly
			int value;
			random = (rand() % size) + 1;

			if(random <= LoadedSide)
			{
				value = random;	
			}
			else if(random > LoadedSide && (random <= (LoadedSide + LoadAmount - 1)))
			{
				value = LoadedSide;
			}
			else if((random > (LoadedSide + LoadAmount - 1)) && random <= size)
			{
				value = (random - LoadAmount) + 1;
			}
			result_vec[i].m_throwresult.push_back(make_pair(obj.GetDiceName(), value));
			
			//upadate map for the results
			map<int, int>::iterator it;
			it = percent_vec[j].m_percentageResult.find(value);
			if(it != percent_vec[j].m_percentageResult.end())
			{
				it->second = it->second + 1;
			}

		}
	}

	//Print the Throw results
	for(int i = 0; i < ptr_DS->GetNumberOfThrows(); i++)
	{
		string resstr;
		int size = result_vec[i].m_throwresult.size();
		for(int j = 0; j < size; j++)
		{
			pair<string, int> temp = result_vec[i].m_throwresult.at(j);
			stringstream ss;
			ss << temp.second;
			string str = ss.str();
			string comma = ", ";
			if(j == size - 1)
				comma = "";
			resstr = resstr + temp.first + " rolled a " + str + comma;
		}
		cout<<"Throw "<<result_vec[i].throwNo<<" : "<<resstr<<endl;
	}

	//Print Percentage results
	for(int m = 0; m < ptr_DS->GetNumberOfDices(); m++)
	{
		cout<<endl;
		cout<<percent_vec[m].diceName<<" "<<"Statistics for "<<ptr_DS->GetNumberOfThrows()<<" rolls:"<<endl;

		int size = percent_vec[m].m_percentageResult.size();
		for(int n = 1; n <= size; n++)
		{
			int val = percent_vec[m].m_percentageResult[n];
			int divider = ptr_DS->GetNumberOfThrows();
			int Result = ((val*100)/divider);
			cout<<"Side "<<n<<": "<<Result<<"%"<<endl;
		}
	}

}

