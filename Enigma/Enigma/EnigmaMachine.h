#pragma once
#include "Plugboard.h"
#include "Rotor.h"
#include "EnigmaConfiguration.h"
#include "Mirror.h"

using namespace std;

class EnigmaMachine {
public:
	EnigmaMachine(DataStructures::EnigmaConfiguration enigaConfig);
	string get_translation(string letter);
	string scrub_spaces(string input);

private:
	Components::Plugboard plugboard;
	Components::Rotor rotor1;
	Components::Rotor rotor2;
	Components::Rotor rotor3;
	Components::Mirror mirror;
};