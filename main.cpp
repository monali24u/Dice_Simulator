#include<string>
#include "DiceSimulator.h"

using namespace std;

int main()
{
	//DiceSimulator is responsible for controlling all the operations of the simulator
	DiceSimulator ds_Obj;
	//Run the simulator
	ds_Obj.SimulateRolls();

	return 0;
}
