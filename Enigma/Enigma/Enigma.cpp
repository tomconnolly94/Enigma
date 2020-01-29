#include <iostream>
#include <map>
#include "Plugboard.h"
#include "Rotor.h"
using namespace std;

// main() is where program execution begins.
int main() {
    
    //config plugboard
    map<char, char> plugboardConfig = { {'a', 'f'}, {'g', 'w'}, {'b', 'c'} };
    Plugboard plugboard(plugboardConfig);

    //init rotors
    Rotor rotor1("bqcshvurlemyjnkigwoadxzfpt");
    Rotor rotor2("ncjvghmuakofpiqbwetldzrsxy");
    Rotor rotor3("ofctxirdmgeabkynphlwuzsqjv");

    rotor1.dump_mappings();
    cout << "a translates to: " << rotor1.get_translation('a') << endl;
    rotor1.dump_mappings();
    cout << "a translates to: " << rotor1.get_translation('a') << endl;
    rotor1.dump_mappings();

    return 0;
}