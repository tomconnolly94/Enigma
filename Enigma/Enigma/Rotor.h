#pragma once
#include <iostream>
using namespace std;

namespace Components {
	class Rotor {
	public:
		Rotor(string target_order, int rotor_index);
		void dump_mappings();
		void get_forward_translation(char *letter);
		void get_reverse_translation(char *letter);

	private:
		map<char, char> forward_rotor_mappings;
		map<char, char> reverse_rotor_mappings;
		void increment_mappings();
		int rotation_index;
		int original_rotation_index;
		int rotor_index;
	};
}