#pragma once
#include <iostream>
#include <map>

using namespace std;

namespace Components {
	class Plugboard {
	public:
		Plugboard(map<char, char> customPlugboardConfig);
		void get_translation(char *letter);

	private:
		map<char, char> plugboardConfig;
	};
}