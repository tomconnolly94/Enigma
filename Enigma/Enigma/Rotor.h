#pragma once
#include <iostream>
using namespace std;

namespace components {
	class Rotor {
	public:
		Rotor(string target_order, int rotor_index);
		void dump_mappings();
		char get_forward_translation(char letter);
		char get_reverse_translation(char letter);

	private:
		map<char, char> forward_rotor_mappings;
		map<char, char> reverse_rotor_mappings;
		void increment_mappings();
		int rotation_index;
		int original_rotation_index;
		int rotor_index;
	};
}