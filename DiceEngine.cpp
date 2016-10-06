
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

//Input - Dice data and number of throws
//Output - dice outcome and percentages

//Data is passed by referance. 
//For each dice check the loadedside=loadedAmount pair, and find default size (Basecase Die1, loadedside=3, loadedAmount= 2)
//Make up imaginary array consisting of sides of the dice other than loadedside. Now Add the loadedside, loadedAmount number of times.
//All the sides will be considered in order.
//Resultant imaginary array will be [1, 2, 3, 3, 4, 5, 6] with index from 0 to 6(For Basecase input - default size will be((6 + 2 - 1) = 7)).
// std::rand() function generates random values between two numbers.
// For this example the range to randwill be bewtween 1 and default size. 
//For each throw using std::rand() function and default size random array index is generated.
//value at the index is the result of the throw.
//Note - An actual array need not be created. Since the frequency of loadedside is known,
//the actual values at the array can be calculated without using a actual array
//Since additional loadedside valve is added loadedAmount times, the probability occurance of the loaded side is more likely.


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

