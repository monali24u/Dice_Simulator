========================================================================
    CONSOLE APPLICATION : DiceSimulator Program Overview
========================================================================
/////////////////////////////////////////////////////////////////////////////
Building application on terminal with g++

Compile - 
	g++ -std=c++11 -o main *.cpp
Execute -
    main
/////////////////////////////////////////////////////////////////////////////
Important Notes
1) main.cpp - This is the main application start source file.
2) DiceDataFile.txt - This is the input file. This file needs to be kept with other source files
3) The program is designed to use more than two dices for extensibility. So adding any number of dices to the input file should work.
4) The program is designed such that a dice can have any number of sides and the sides can have any values for extensibility. 
   As of now the default values have been set to six for number of sides and the value of the dice is 1 to 6
	
/////////////////////////////////////////////////////////////////////////////
Module 1 :- DiceSimulator
DiceSimulator controls the workflow of the application. It is the center of application.
It manages the file parser module and the dice engine module.

Files - 
DiceSimulator.h
DiceSimulator.cpp
Dice.h
Dice.cpp
Utility.h

/////////////////////////////////////////////////////////////////////////////
Module 2 :- FileParser
FileParser opens a input file and reads key, values pairs.

Files - 
FileParser.h
FileParser.cpp

/////////////////////////////////////////////////////////////////////////////
Module 3 :- DiceEngine
DiceEngine summarizes the results of each dice and the percentages that each side came up.

Files - 
DiceEngine.h
DiceEngine.cpp

/////////////////////////////////////////////////////////////////////////////
