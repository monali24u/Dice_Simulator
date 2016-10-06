
//Class for managing the Dice module, the file parser module and the dice engine module

#ifndef DICESIMULATOR_H_
#define DICESIMULATOR_H_

#include <vector>
#include <string>
#include "Utility.h"
#include "Dice.h"

using namespace std;

class Dice;

class DiceSimulator
{
	private:
		int m_numberOfDices;		//how many dices(basecase 2 dices)
		int m_numberOfThrows;		//how many times the dices are thrown
		string m_FileName;

	protected:
		vector<Dice> m_diceContainer; //This is the Dice Holder which holds data for number of dices

	public:
		void SimulateRolls();		  //starts the roll of dices
		void SetNumberOfDices(int val);
		int GetNumberOfDices();
		void SetNumberOfThrows(int val);
		int GetNumberOfThrows();
		void SetDiceContainer(vector<DiceProperities> diceContainer);
		vector<Dice> GetDiceContainer();

		//Constructor
		DiceSimulator();
};

#endif