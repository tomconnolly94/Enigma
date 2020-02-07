#pragma once
#include <string>
using namespace std;

class OutputAnalyser {
public:
	OutputAnalyser();
	void run_analysis(string cleartext, string ciphertext);
};