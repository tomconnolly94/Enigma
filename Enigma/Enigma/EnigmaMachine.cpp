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

    cout << "before space remove: " << endl;
    cout << input_phrase << endl;
    input_phrase.erase(
        remove_if(
            input_phrase.begin(), 
            input_phrase.end(), 
            ::isspace), 
        input_phrase.end()
    );
    cout << "after space remove: " << endl;
    cout << input_phrase << endl;

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