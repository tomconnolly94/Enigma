#pragma once
#include "Plugboard.h"
#include "Rotor.h"
#include "EnigmaConfiguration.h"
#include "Mirror.h"

using namespace std;

class EnigmaMachine {
public:
	EnigmaMachine(EnigmaConfiguration enigaConfig);
	char get_translation(char letter);

private:
	Plugboard plugboard;
	Rotor rotor1;
	Rotor rotor2;
	Rotor rotor3;
	Mirror mirror;
};