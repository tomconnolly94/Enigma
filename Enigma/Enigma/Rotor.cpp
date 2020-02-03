#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include "Rotor.h"
#include "Globals.h"

using namespace std;

Rotor::Rotor(string target_order)
{
	for(size_t i = 0; i < alphabet.size(); ++i)
	{
		rotor_mappings[alphabet[i]] = target_order[i];
	};
}

void Rotor::dump_mappings() 
{
	map<char, char>::iterator it;
	for (it = rotor_mappings.begin(); it != rotor_mappings.end(); it++)
	{
		cout << it->first << " ---> " << it->second << " " << endl;
	}
	cout << endl;
}

void Rotor::increment_mappings() 
{
	map<char, char>::iterator it;
	char previous_value = 'X';


	for (it = rotor_mappings.begin(); it != rotor_mappings.end(); ++it)
	{
		char current_value = it->second;
		rotor_mappings[it->first] = previous_value;
		previous_value = current_value;
	}

	rotor_mappings[rotor_mappings.begin()->first] = previous_value;
}

char Rotor::get_translation(char letter) 
{
	char translation = rotor_mappings[letter];
	//increment_mappings();
	cout << letter << " >> " << translation << endl;
	return translation;
}