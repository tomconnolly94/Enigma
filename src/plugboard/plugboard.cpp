/*
 * plugboard.cpp
 *
 *  Created on: 11 Dec 2018
 *      Author: tom
 */
#include "plugboard.h"
#include <map>
#include <string>
using std::string;
#include <cstdlib>
#include <iostream>

string get_plugboard_translation(const char* input){
	return "hello";
}

std::map<char, char> get_plugboard_mappings(){

	std::map<char, char> original_mapping = {
		{ 'A', 'W' },
		{ 'G', 'O' },
		{ 'Y', 'B' }
	};

	std::map<char, char> mapping;
	std::map<char, char>::iterator it;

	for ( it = original_mapping.begin(); it != original_mapping.end(); it++ ){

		mapping.insert(std::pair<char,char>(it->first, it->second));
		mapping.insert(std::pair<char,char>(it->second, it->first));
	};

	return mapping;
};
