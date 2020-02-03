#pragma once
#include <iostream>
using namespace std;

class Rotor {
public:
	Rotor(string target_order);
	void dump_mappings();
	char get_translation(char letter);

private:
	map<char, char> rotor_mappings;
	void increment_mappings();
};