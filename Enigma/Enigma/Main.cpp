#include <iostream>
#include <map>
#include "EnigmaMachine.h"
#include "EnigmaConfiguration.h"

using namespace std;
EnigmaConfiguration enigmaConfig;

// main() is where program execution begins.
int main() {


    EnigmaConfiguration enigmaConfig
    {
        { {'a', 'f'}, {'g', 'w'}, {'b', 'c'} },
        "bqcshvurlemyjnkigwoadxzfpt",
        "ncjvghmuakofpiqbwetldzrsxy",
        "ofctxirdmgeabkynphlwuzsqjv"
    };
    
    EnigmaMachine enigmaMachine1(enigmaConfig);

    char input1 = 'a';

    char output1 = enigmaMachine1.get_translation(input1);

    cout << "Input: " << input1 << endl;
    cout << "Output: " << output1 << endl;



    EnigmaMachine enigmaMachine2(enigmaConfig);

    char input2 = 'o';

    char output2 = enigmaMachine2.get_translation(input2);

    cout << "Input: " << input2 << endl;
    cout << "Output: " << output2 << endl;

    return 0;
}