#include <iostream>
#include <map>

using namespace std;
#ifndef E_C
#define E_C
namespace DataStructures {
    struct EnigmaConfiguration {
        map<char, char> plugboardConfig;
        string rotor1Config;
        string rotor2Config;
        string rotor3Config;
    };
}
#endif
