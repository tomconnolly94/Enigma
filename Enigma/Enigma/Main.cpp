#include <iostream>
#include <map>
#include "Plugboard.h"
#include "Rotor.h"
#include "EnigmaMachine.h"
using namespace std;


struct EnigmaConfiguration {
    map<char, char> plugboardConfig;
    string rotor1Config;
    string rotor2Config;
    string rotor3Config;
};

// main() is where program execution begins.
int main() {

    EnigmaConfiguration enigmaConfig;
    enigmaConfig.plugboardConfig = { {'a', 'f'}, {'g', 'w'}, {'b', 'c'} };
    enigmaConfig.rotor1Config = "bqcshvurlemyjnkigwoadxzfpt";
    enigmaConfig.rotor2Config = "ncjvghmuakofpiqbwetldzrsxy";
    enigmaConfig.rotor3Config = "ofctxirdmgeabkynphlwuzsqjv";

    
    EnigmaMachine enigmaMachine(enigmaConfig);

    return 0;
}