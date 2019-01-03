//============================================================================
// Name        : enigma.cpp
// Author      : Tom Connolly
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "plugboard/plugboard.h"
using namespace std;

//define enums
enum Direction {Forward, Backward };

int main(int argc, char* argv[]) {
	cout << argv[1] << endl;

	//access plantext message source
	cout << get_plugboard_translation("hello boyyee") << endl;


	//return 0;
}
