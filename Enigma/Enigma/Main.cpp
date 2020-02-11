#include <iostream>
#include <map>
#include <chrono>
#include "EnigmaMachine.h"
#include "EnigmaConfiguration.h"
#include "OutputAnalyser.h"

// main() is where program execution begins.
int main() {

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

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

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[nanoseconds]" << std::endl; // 57832

    return 0;
}