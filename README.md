# Enigma
A C++ implementation of Scherbius' Enigma three rotor Enigma machine

## Implementation
* An OO C++ approach was adopted, creating classes for each of the components described in the original Enigma machine. 
* The rotor mappings are configurable using the EnigmaConfiguration object.
* An analysis module was added to ensure that properties and requirements of the original Enigma machine hold true, for example the assertion that a letter cannot be mapped to itself, or the symmetric encryption qualities. 


## Usage

* A vcxproj file is included for easy loading into Visual Studio.
* Hit the "Start" button in Visual Studio to compile and run the program.
* The program can of course also be compiled with other compilers like g++.


## To do

* Add unit tests to reduce the possibility of regression issues after future development
* Add a configuration with rotor mappings exactly like an existing Enigma so the encryption can be reproduced with online Emulators.
* Expand functionality by allowing more rotors and rotor swapping.
