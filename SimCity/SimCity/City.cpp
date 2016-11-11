// I affirm that all code given below was written solely by me, Ben Morledge-Hampton,
// and that any help I received adhered to the rules stated for this exam.

// Pre-Processor Directives
#include "City.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// A function which, given a string passed by reference, returns the first full phrase in the string before a space and also removes that phrase and space from the string.
string getFirstPhrase(string& phrases) {

	// Find the single phrase before the space to be returned, and assign to a variable to be returned after the original string has been truncated.
	// This is done by finding a substring with a length determined by the position of the first space character.
	string singlePhrase = phrases.substr(0, phrases.at(' '));

	// Remove the phrase and space from the given string.
	phrases.erase(0, phrases.at(' ') + 1);

	// Return the phrase.
	return singlePhrase;

}

City::City(string cityName)
{

	ifstream restorer; // An input stream to read in saved data for the city, if it exists.
	string line; // The current line in the file being accessed.  Will be modified to eventually contain only parts of the line.

	// Give the city the name given for the city, and create the filename as [cityName].txt

	this->cityName = cityName;
	fileName = cityName + ".txt";

	// Attempt to open the file with the given name.
	restorer.open(fileName.c_str());

	// Make sure the file exists before moving on.  If it doesn't, don't worry about creating it now.  It will be created when the city's data is saved as the city is destroyed.

	if (!restorer.fail()) {

		// Read in one line at a time until eof.
		while (getline(restorer, line)) {

			// Add a citizen to the citizens vector.  The citizens parameters are given by the current line in the file, and isolated through the getFirstPhrase function.
			citizens->push_back(Citizen(stoi(getFirstPhrase(line)), getFirstPhrase(line), getFirstPhrase(line), getFirstPhrase(line)));

		}

	}

}

City::~City()
{

	ofstream saver; // An output stream to save the data for citizens for the city.

	// Open the output stream and read each citizens's parameters, seperated by spaces, into the file.  (One line for each student)

	saver.open(fileName.c_str());

	// Run this loop once for every citizen in the students vector, ensuring that they are all saved!
	for (int i = 0; i < citizens->size(); i++) {

		// Output the current citizen's parameters, seperated by spaces, and ended with a newline.
		saver << to_string((*citizens)[i].getId()) << " " << (*citizens)[i].getFirstName() << " " << (*citizens)[i].getLastName() << " " << (*citizens)[i].getFavoriteColor() << " " << endl;

	}

	// Now that the data has been saved, delete the vector that was allocated to the heap.
	delete citizens;

}

string City::getCityName()
{
	return cityName;
}

int City::populationSize()
{
	// Derive the size from the vector, and return it.
	return citizens->size();
}

Citizen * City::getCitizenAtIndex(int index)
{
	// Returns the reference to the citizen at the specified index from the vector.
	return &(*citizens)[index];
}

void City::addCitizen(Citizen * citizen)
{
	// Using the DEREFERENCED properties of the citizen, not the citizen itself (as this will be deleted), create a new citizen and add it to the vector.
	// But guess what!  I just realized that the Citizen class has a constructor for this!  Woo-hoo! Let's use that.
	citizens->push_back(Citizen(citizen));
}

Citizen * City::getCitizenWithId(int id)
{
	
	// Systematically check every citizen in the vector for the one with the given id.
	for (int i = 0; i < citizens->size(); i++) {
		// If the id matches, return the pointer to that student.
		if ((*citizens)[i].getId() == id) return &((*citizens)[i]);
	}

	// If no citizen was found with the given id, return a null pointer, and let the user know that no citizen was found.
	cout << "No citizen with ID " << id << " was found." << endl;
	return nullptr;
	
}

vector<Citizen*> City::getCitizensForFavoriteColor(string Color)
{

	vector <Citizen*> sameFavoriteColorCitizens;  //The vector to be returned that will contain all of the citizens with a given favorite color.

	// Systematically check every citizen in the vector for the ones with the given favorite color.
	for (int i = 0; i < citizens->size(); i++) {

		// Add the citizen's pointer to the vector if their favorite color matches.
		if ((*citizens)[i].getFavoriteColor() == Color) sameFavoriteColorCitizens.push_back(&((*citizens)[i]));

	}

	return vector<Citizen*>();
}
