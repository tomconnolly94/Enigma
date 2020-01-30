#include "EnigmaMachine.h"
#include <map>
#include "Plugboard.h"
#include "Rotor.h"
#include "Mirror.h"
#include "Main.cpp"

using namespace std;

EnigmaMachine::EnigmaMachine(EnigmaConfiguration enigmaConfig) : 
    plugboard(enigmaConfig.plugboardConfig),
    /*rotor1(enigmaConfig.rotor1Config),
    rotor2(enigmaConfig.rotor2Config),
    rotor3(enigmaConfig.rotor3Config)*/
{}

char EnigmaMachine::get_translation(char letter) {
    letter = plugboard.get_translation(letter);
/*
    letter = rotor1.get_translation(letter);
    letter = rotor2.get_translation(letter);
    letter = rotor3.get_translation(letter);
    
    letter = mirror.get_translation(letter);

    letter = rotor3.get_translation(letter);
    letter = rotor2.get_translation(letter);
    letter = rotor1.get_translation(letter);

    letter = plugboard.get_translation(letter);*/

    return letter;
}