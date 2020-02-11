#pragma once
#include "Plugboard.h"
#include "Rotor.h"
#include "EnigmaConfiguration.h"
#include "Mirror.h"

using namespace std;

class EnigmaMachine {
public:
	EnigmaMachine(EnigmaConfiguration enigaConfig);
	string get_translation(string letter);
	string scrub_spaces(string input);

private:
	components::Plugboard plugboard;
	components::Rotor rotor1;
	components::Rotor rotor2;
	components::Rotor rotor3;
	components::Mirror mirror;
};