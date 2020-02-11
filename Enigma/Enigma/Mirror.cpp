#include <iostream>
#include <string>
#include <map>
#include "Mirror.h"
#include "Globals.h"

using namespace std;

namespace Components {
	Mirror::Mirror() {

		for (size_t i = 0; i < alphabet.size(); ++i)
		{
			mirror_mappings[alphabet[i]] = reverse_alphabet[i];
		};
	}

	void Mirror::get_translation(char *letter)
	{
		*letter = mirror_mappings[*letter];
	}
}