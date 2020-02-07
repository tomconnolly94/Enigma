#include <iostream>
#include <map>
#include "EnigmaMachine.h"
#include "EnigmaConfiguration.h"
#include "OutputAnalyser.h"

using namespace std;
EnigmaConfiguration enigmaConfig;

// main() is where program execution begins.
int main() {
    OutputAnalyser outputAnalyser;

    EnigmaConfiguration enigmaConfig
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

    cout << "Input: " << input1 << endl;
    cout << "Output: " << output1 << endl;
    cout << endl;

    EnigmaMachine enigmaMachine2(enigmaConfig);

    string output2 = enigmaMachine2.get_translation(output1);

    outputAnalyser.run_analysis(output1, output2);

    cout << "Input: " << output1 << endl;
    cout << "Output: " << output2 << endl;

    //analysis
    for (size_t i = 0; i < input1.size(); ++i)
    {
        if (input1[i] == ' ') continue;
        cout << input1[i] << " came out as " << output1[i] << endl;
    };

    return 0;
}