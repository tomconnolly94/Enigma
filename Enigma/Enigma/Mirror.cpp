#include <iostream>
#include <string>
#include <map>
#include "Mirror.h"
#include "Globals.h"

using namespace std;

Mirror::Mirror() {

	for (size_t i = 0; i < alphabet.size(); ++i)
	{
		mirror_mappings[alphabet[i]] = reverse_alphabet[i];
	};
}

char Mirror::get_translation(char letter)
{

	cout << "Mirror: " << letter << " >> " << mirror_mappings[letter] << endl;
	return mirror_mappings[letter];
}