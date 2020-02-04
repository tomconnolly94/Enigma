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

    string input1 = "hello my name is tom it is nice to meet you how have you been i have been great it has been so long since we have seen each other";
    string output1 = enigmaMachine1.get_translation(input1);

    cout << "Input: " << input1 << endl;
    cout << "Output: " << output1 << endl;



    EnigmaMachine enigmaMachine2(enigmaConfig);

    string output2 = enigmaMachine2.get_translation(output1);

    cout << "Input: " << output1 << endl;
    cout << "Output: " << output2 << endl;

    return 0;
}