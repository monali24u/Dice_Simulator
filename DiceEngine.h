
//Class for summarizing the results of each dice and the percentages that each side came up. 

#ifndef DICEENGINE_H_
#define  DICEENGINE_H_

class DiceSimulator;

class DiceEngine
{
	public:
		//Execute each throw of the dice and print out each die's result.
		void CalculateDiceResult(DiceSimulator *ptr_DS);

		//Summarize each dice's throw result and display the percentage of each side
		void CalculateThrows(DiceSimulator *ptr_DS, vector<ThrowDisplay> &result_vec, vector<PercentageDisplay> &percent_vec);
};

#endif