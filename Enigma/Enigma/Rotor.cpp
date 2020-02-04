#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include "Rotor.h"
#include "Globals.h"

using namespace std;

Rotor::Rotor(string target_order, int _rotor_index)
{
	for(size_t i = 0; i < alphabet.size(); ++i)
	{
		forward_rotor_mappings[alphabet[i]] = target_order[i];
		reverse_rotor_mappings[target_order[i]] = alphabet[i];
	};
	rotation_index = original_rotation_index = pow(26, _rotor_index - 1);
	rotor_index = _rotor_index;
}

void Rotor::dump_mappings() 
{
	map<char, char>::iterator it;
	for (it = forward_rotor_mappings.begin(); it != forward_rotor_mappings.end(); it++)
	{
		cout << it->first << " ---> " << it->second << " " << endl;
	}
	cout << endl;
}

void Rotor::increment_mappings() 
{
	if (rotation_index <= 1) {

		cout << "Increment triggered on rotor: " << rotor_index << endl;

		char previous_value = 'X';

		for (map<char, char>::iterator it = forward_rotor_mappings.begin(); it != forward_rotor_mappings.end(); ++it)
		{
			char current_value = it->second;
			forward_rotor_mappings[it->first] = previous_value;
			previous_value = current_value;
		}

		forward_rotor_mappings[forward_rotor_mappings.begin()->first] = previous_value;

		previous_value = 'X';

		for (map<char, char>::reverse_iterator rev_it = reverse_rotor_mappings.rbegin(); rev_it != reverse_rotor_mappings.rend(); ++rev_it)
		{
			char current_value = rev_it->second;
			reverse_rotor_mappings[rev_it->first] = previous_value;
			previous_value = current_value;
		}

		reverse_rotor_mappings[reverse_rotor_mappings.end()->first] = previous_value;

		rotation_index = original_rotation_index;
	}

	cout << "rotor_index: " << rotor_index << ", rotation_index: " << rotation_index;
	cout << endl;

	--rotation_index;
}

char Rotor::get_forward_translation(char letter)
{
	char translation = forward_rotor_mappings[letter];
	return translation;
}

char Rotor::get_reverse_translation(char letter)
{
	char translation = reverse_rotor_mappings[letter];
	increment_mappings();
	return translation;
}