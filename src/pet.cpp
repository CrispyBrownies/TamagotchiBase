// Stephen Chen
// Created: 5/5/2022
// Main file for handle pet behaviors

#include <iostream>
#include <string>
#include <any>
#include <map>

using namespace std;

class Pet {
	private:
		int id;
		string name;
		int age;
		int health;
		int hunger;
		int happiness;
		int sickness; // This is a hidden value, if it hits 100, pet becomes sick
		bool alive;
		bool sick;

		int ageRate;
		int hungerRate;
		int happinessRate;
		int sicknessRate;

		void updatePetStats() {

			// Update the pets stats by change rate
			age += ageRate;
			hunger -= hungerRate;
			happiness -= happinessRate;
			sickness += sicknessRate;
			health = (int)(0.7f * (100-sickness) + 0.1f * happiness + 0.2f * hunger); // 70% sickness, 10% happiness, 20% hunger

			capValue(&age, 100);
			capValue(&hunger, 100);
			capValue(&happiness, 100);
			capValue(&sickness, 100);
			capValue(&health, 100);

			checkSick();
		}

		// Caps the value to between 0 and max
		void capValue(int* val, int max) {
			if (*val > max) {
				*val = max;
			}
			if (*val < 0) {
				*val = 0;
			}
		}

		// Checks if the pet is sick, the pet only gets sick at 100 and becomes healthy at 0
		void checkSick() {
			if (sickness == 100) {
				sick = true;
			}
			if (sickness == 0) {
				sick = false;
			}
		}

	public:

		void process() {
			updatePetStats();
		}

		// Constructor for new pets
		Pet(int id, string name) {
			this->id = id;
			this->name = name;
			age = 0;
			hunger = 100;
			happiness = 100;
			sickness = 0;
			alive = true;
			sick = false;

			ageRate = 1;
			hungerRate = 1;
			happinessRate = 1;
			sicknessRate = 1;
		}

		// Constructor for existing pets
		Pet(map<string, any> props) {
			id = any_cast<int>(props["id"]);
			name = any_cast<string>(props["name"]);
			age = any_cast<int>(props["age"]);
			hunger = any_cast<int>(props["hunger"]);
			health = any_cast<int>(props["health"]);
			happiness = any_cast<int>(props["happiness"]);
			sickness = any_cast<int>(props["sickness"]);
			alive = any_cast<bool>(props["alive"]);
			sick = any_cast<bool>(props["sick"]);

			ageRate = any_cast<int>(props["ageRate"]);
			hungerRate = any_cast<int>(props["hungerRate"]);
			happinessRate = any_cast<int>(props["happinessRate"]);
			sicknessRate = any_cast<int>(props["sicknessRate"]);
		}

		// For debug and testing purposes
		void printPetStats() {
			cout << "Pet Name: " << name << endl;
			cout << "Health: " << health << endl;
			cout << "Hunger: " << hunger << endl;
			cout << "Happiness: " << happiness << endl;
			cout << "Sickness: " << sickness << endl;
			cout << "Sick: " << sick << endl;
			cout << "-------------------------------" << endl;
		}

		// Packages pet stats into map object
		map<string, any> packagePet() {
			map<string, any> props;
			props = {
				{"id", id},
				{"name", string(name)},
				{"age", age},
				{"hunger", hunger},
				{"health", health},
				{"happiness", happiness},
				{"sick", sick},
				{"alive", alive},
				{"ageRate", ageRate},
				{"hungerRate", hungerRate},
				{"happinessRate", happinessRate},
				{"sicknessRate", sicknessRate},
			};
			return props;
		}

		// Getters
		// For debug use, would not be used in operation 
		int getAge() {
			return age;
		}
		int getHealth() {
			return health;
		}
		int gethunger() {
			return hunger;
		}
		int getSickness() {
			return sickness;
		}
		int getHappiness() {
			return happiness;
		}
		bool getSick() {
			return sick;
		}
		string getName() {
			return name;
		}
		int getID() {
			return id;
		}
		bool getAlive() {
			return alive;
		}

		// Setters
		// These return object ptrs so they can be called in succession
		// For debug use, would not be used in operation
		Pet* setAge(int age) {
			this->age = age;
			return this;
		}
		Pet* setHealth(int health) {
			this->health = health;
			return this;
		}
		Pet* sethunger(int hunger) {
			this->hunger = hunger;
			return this;
		}
		Pet* setSickness(int sickness) {
			this->sickness = sickness;
			return this;
		}
		Pet* setHappiness(int happiness) {
			this->happiness = happiness;
			return this;
		}
		Pet* setSick(bool sick) {
			this->sick = sick;
			return this;
		}
		Pet* setName(string name) {
			this->name = name;
			return this;
		}
		Pet* setID(int id) {
			this->id = id;
			return this;
		}


};
