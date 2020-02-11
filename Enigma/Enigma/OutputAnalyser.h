#pragma once
#include <string>
using namespace std;

namespace Analysis {
	class OutputAnalyser {
	public:
		OutputAnalyser();
		void run_analysis(string cleartext, string ciphertext);
	};
}