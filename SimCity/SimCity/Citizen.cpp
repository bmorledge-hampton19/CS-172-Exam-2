// I affirm that all code given below was written solely by me, Ben Morledge-Hampton,
// and that any help I received adhered to the rules stated for this exam.

// Pre-Processor Directives
#include "Citizen.h"

Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	// Read all the given variables into the private properties for citizen.
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->color = color;
}

Citizen::Citizen(Citizen * citizen)
{
	// Read all the private properties from the given citizen into the properties for the citizen being created.
	id = citizen->getId();
	firstName = citizen->getFirstName();
	lastName = citizen->getLastName();
	color = citizen->getFavoriteColor();
}

string Citizen::getFirstName()
{
	return firstName;
}

string Citizen::getLastName()
{
	return lastName;
}

int Citizen::getId()
{
	return id;
}

string Citizen::getFavoriteColor()
{
	return color;
}

void Citizen::setFavoriteColor(string color)
{

	this->color = color;

}
