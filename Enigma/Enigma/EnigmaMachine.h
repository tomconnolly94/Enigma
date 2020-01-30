#pragma once

using namespace std;

class EnigmaMachine {
public:
	EnigmaMachine(EnigmaConfiguration enigmaConfig);
	char get_translation(char letter);

private:
	Plugboard plugboard;
};