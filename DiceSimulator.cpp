#include "DiceSimulator.h"
#include "FileParser.h"
#include "DiceEngine.h"

void DiceSimulator::SimulateRolls()
{
	//Parse the file
	FileParser fpObj;
	fpObj.ParseFile(m_FileName, this);

	//generate random numbers for dice with loaded side
	DiceEngine deObj;
	deObj.CalculateDiceResult(this);

}
void DiceSimulator::SetNumberOfDices(int val)
{
	m_numberOfDices = val;
}

int DiceSimulator::GetNumberOfDices()
{
	return m_numberOfDices;
}

void DiceSimulator::SetNumberOfThrows(int val)
{
	m_numberOfThrows = val;
}

int DiceSimulator::GetNumberOfThrows()
{
	return m_numberOfThrows;
}

void DiceSimulator::SetDiceContainer(vector<DiceProperities> diceContainerProperties)
{
	m_diceContainer.clear();
	int size = diceContainerProperties.size();
	SetNumberOfDices(size);
	for(int i = 0; i < size; i++)
	{
		Dice dc;
		DiceProperities dp = diceContainerProperties[i];
		dc.SetDiceName(dp.diceName);
		int loadedsize = dp.m_loadedSide.size();
		for(int j = 0; j < loadedsize; j++)
			dc.SetLoadedSide(dp.m_loadedSide[j].first, dp.m_loadedSide[j].second);
		m_diceContainer.push_back(dc);
	}
	
}

vector<Dice> DiceSimulator::GetDiceContainer()
{
		return m_diceContainer;
}


//constructor
DiceSimulator::DiceSimulator()
{
	m_FileName = "./DiceDataFile.txt"; 
}

