#include "Dice.h"

Dice::Dice()
{
	m_numberOfsides = 6;
	for(int i = 0; i < m_numberOfsides; i++)
	{
		m_numberOnEachSide.push_back(make_pair(i+1,i+1));
	}
}
Dice::Dice(int Numsides)
{
	m_numberOfsides = Numsides;
	for(int i = 0; i < m_numberOfsides; i++)
	{
		m_numberOnEachSide.push_back(make_pair(i+1,i+1));
	}
}
void Dice::SetDiceName(string dicename)
{
	m_diceName = dicename;
}

string Dice::GetDiceName()
{
	return m_diceName;
}

void Dice::SetNumberOfSides(int val)
{
	m_numberOfsides = val;
}

int Dice::GetNumberOfSides()
{
	return m_numberOfsides;
}

void Dice::SetLoadedSide(int side, int val)
{
	m_loadedSide = make_pair(side, val);
}

void Dice::GetLoadedSide(pair<int, int> &loadedside)
{
	loadedside = m_loadedSide;
}