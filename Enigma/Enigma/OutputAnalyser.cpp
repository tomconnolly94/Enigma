#include <iostream>
#include "OutputAnalyser.h"
#include "EnigmaMachine.h"

using namespace std;

namespace Analysis {
    OutputAnalyser::OutputAnalyser() {}

    void OutputAnalyser::run_analysis(string cleartext, string ciphertext) {

        bool conflict_found = false;

        //compare sets of letters at the same index between the plaintext and ciphertext to ensure none are the same
        for (size_t char_index = 0; char_index < cleartext.size(); ++char_index) {
            if (cleartext[char_index] == ciphertext[char_index]) {
                conflict_found = true;
                cout << endl;
                cout << "conflict found!" << endl;
                cout << cleartext[char_index] << " is the same as " << ciphertext[char_index] << " at index: " << char_index << endl;
            }
        }

        if (!conflict_found) {
            cout << "no conflict found!" << endl;
            cout << endl;
        }

        cout << "Input: " << cleartext << endl;
        cout << "Output: " << ciphertext << endl;
        cout << endl;
    }
}
