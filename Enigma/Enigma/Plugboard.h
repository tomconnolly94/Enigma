#pragma once
#include <iostream>
#include <map>

using namespace std;

class Plugboard {
public:
	Plugboard(map<char, char> customPlugboardConfig);
	char get_translation(char letter);

private:
	map<char, char> plugboardConfig;
};