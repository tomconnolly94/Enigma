#pragma once

using namespace std;

class Mirror {
public:
	Mirror();
	char get_translation(char letter);
private:
	map<char, char> mirror_mappings;
};