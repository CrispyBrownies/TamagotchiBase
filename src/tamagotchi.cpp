// Stephen Chen
// Created: 5/5/2022
// Main file for the Tamagotchi game

#include <iostream>
#include <map>
#include <string>
#include <any>
#include "pet.cpp"

using namespace std;

// Class to handle all game aspects
class Tamagotchi {

	private:
		bool exit;
		bool testMode = true;

	public:

		// Creates game
		void init() {
			if (testMode) {
				map<string, any> testProp = {
					{"id",1111},
					{"name", string("Test Pet")},
					{"health", 100},
					{"hunger", 100},
					{"happiness", 100},
					{"age", 0},
					{"sickness", 0},
					{"sick", false},
					{"alive", true},
					{"hungerRate", 1},
					{"happinessRate", 1},
					{"sicknessRate", 1},
					{"ageRate", 1}
				};

				Pet testPet = Pet(testProp);
				testPet.printPetStats();
				testPet.process();
				testPet.printPetStats();

			}
		}

		// Game loop
		void loop() {
			while (!exit) {
				// Continue game
			}
		}

		void doExit() {
			//Saves pet info into files
			exit = true;
		}
};

int main() {
	cout << "Hello Tamagotchi" << endl;
	Tamagotchi game = Tamagotchi();
	game.init();

	return 0;
}

