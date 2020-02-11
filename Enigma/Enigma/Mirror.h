#pragma once

using namespace std;

namespace Components {
	class Mirror {
	public:
		Mirror();
		void get_translation(char *letter);
	private:
		map<char, char> mirror_mappings;
	};
}