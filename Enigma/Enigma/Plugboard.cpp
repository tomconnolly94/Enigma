#include <iostream>
#include "Plugboard.h"
#include <map>;
using namespace std;
 
Plugboard::Plugboard(map<char, char> customPlugboardConfig)
{
	plugboardConfig = customPlugboardConfig;

	//add reverse mappings
	map<char, char>::iterator it;
	for (it = plugboardConfig.begin(); it != plugboardConfig.end(); it++)
	{
		plugboardConfig[it->second] = it->first;
	}
}

char Plugboard::get_translation(char letter) 
{
	map<char, char>::iterator result_iterator = plugboardConfig.find(letter);

	if (result_iterator != plugboardConfig.end())
	{
		//element found;
		return result_iterator->second;
	}
	return letter;
}