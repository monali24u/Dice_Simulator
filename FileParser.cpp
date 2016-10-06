#include <fstream>
#include <string.h>
#include <stdio.h>
#include "DiceSimulator.h"
#include "Utility.h"
#include "FileParser.h"

using namespace std;

void FileParser::ParseFile(string FilePath, DiceSimulator *ptr_DS)
{
	vector<DiceProperities> dp_vec;
	string line;
	ifstream myfile (FilePath);
	if (myfile.is_open())
	{
		while(getline(myfile,line))
		{
			string str = line;
			char strarry[1024];
			strcpy(strarry, str.c_str());
			char *cstr;
			cstr = strtok(strarry,"=");
			if(cstr != NULL)
			{
				string tempStr(cstr);
				if(tempStr.compare("NumRolls") == 0)
				{
					cstr = strtok(NULL, "=");
					while(cstr != NULL)
					{	
						string tempNum(cstr);
						string::size_type sz;   
						int NumRolls = stoi(tempNum, &sz);
						ptr_DS->SetNumberOfThrows(NumRolls);
						cstr = strtok(NULL, "=");
					}
				}
				else if(tempStr.compare("Die") == 0)
				{
					//There is a bug when more than one loadedside/amount are used
					int loadedAmount;
					int loadedSide;
					DiceProperities dp;
					cstr = strtok(NULL, "=");
					if(cstr != NULL)
					{
						string tempName(cstr);
						dp.diceName = tempName;
						//This is for loadedside
						getline (myfile,line);
						string str = line;
						char strarry[1024];
						strcpy(strarry, str.c_str());
						char *cstr;
						cstr = strtok(strarry,"=");
						if(cstr != NULL)
						{
							string tempStr(cstr);
							if(tempStr.compare("LoadedSide") == 0)
							{
								cstr = strtok(NULL, "=");
								if(cstr != NULL)
								{	
									string tempSNum(cstr);
									string::size_type sz;   
									loadedSide = stoi(tempSNum, &sz);
								}
							}							
						}
						//This is for loadedamount
						getline (myfile,line);
						str = line;
						strcpy(strarry, str.c_str());
						cstr = strtok(strarry,"=");
						if(cstr != NULL)
						{
							string tempStr(cstr);
							if(tempStr.compare("LoadAmount") == 0)
							{
								cstr = strtok(NULL, "=");
								if(cstr != NULL)
								{	
									string tempSNum(cstr);
									string::size_type sz;   
									loadedAmount = stoi(tempSNum, &sz);
								}
							}							
						}
					}
					dp.m_loadedSide.push_back(make_pair(loadedSide, loadedAmount));
					dp_vec.push_back(dp);
				}
			}
		}
	}
	myfile.close();

	//set this dat on DiceController
	ptr_DS->SetDiceContainer(dp_vec);
}
