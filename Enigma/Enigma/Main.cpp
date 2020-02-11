#include <iostream>
#include <map>
#include "EnigmaMachine.h"
#include "EnigmaConfiguration.h"
#include "OutputAnalyser.h"

using namespace std;

// main() is where program execution begins.
int main() {
    Analysis::OutputAnalyser outputAnalyser;

    DataStructures::EnigmaConfiguration enigmaConfig
    {
        { {'a', 'f'}, {'g', 'w'}, {'b', 'c'} },
        "bqcshvurlemyjnkigwoadxzfpt",
        "ncjvghmuakofpiqbwetldzrsxy",
        "ofctxirdmgeabkynphlwuzsqjv"
    };
    
    EnigmaMachine enigmaMachine1(enigmaConfig);

    string raw_input1 = "hello my name is tom it is nice to meet you how have you been i have been great it has been so long since we have seen each other";
    string input1 = enigmaMachine1.scrub_spaces(raw_input1);
    string output1 = enigmaMachine1.get_translation(input1);

    outputAnalyser.run_analysis(input1, output1);

    EnigmaMachine enigmaMachine2(enigmaConfig);

    string output2 = enigmaMachine2.get_translation(output1);

    outputAnalyser.run_analysis(output1, output2);

    return 0;
}