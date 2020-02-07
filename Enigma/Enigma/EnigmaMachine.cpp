#include <map>
#include "EnigmaMachine.h"
#include "Plugboard.h"
#include <algorithm>

using namespace std;

EnigmaMachine::EnigmaMachine(EnigmaConfiguration enigmaConfig) : 
    plugboard(enigmaConfig.plugboardConfig),
    rotor1(enigmaConfig.rotor1Config, 1),
    rotor2(enigmaConfig.rotor2Config, 2),
    rotor3(enigmaConfig.rotor3Config, 3)
{}

string EnigmaMachine::get_translation(string input_phrase) {

    input_phrase = this->scrub_spaces(input_phrase);

    string output_phrase = "";

    for (char& character : input_phrase) {
        character = plugboard.get_translation(character);
        character = rotor1.get_forward_translation(character);
        character = rotor2.get_forward_translation(character);
        character = rotor3.get_forward_translation(character);
        character = mirror.get_translation(character);
        character = rotor3.get_reverse_translation(character);
        character = rotor2.get_reverse_translation(character);
        character = rotor1.get_reverse_translation(character);
        character = plugboard.get_translation(character);
        output_phrase += character;
    }
    return output_phrase;
}

string EnigmaMachine::scrub_spaces(string input) {

    // remove all spaces from the string before processing
    input.erase(
        remove_if(
            input.begin(),
            input.end(),
            ::isspace),
        input.end()
    );
    return input;
}