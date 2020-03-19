#include "Apartament.h"
#include <string>
#include <iostream>

using namespace std;

/*
	Desc: Create an apartament
	In: -
	Out: An instance of Apartament
*/
Apartament::Apartament() {
	cout << "default constructor " << endl;
	this->name = NULL;
}


/*
	Desc: Create an apartament
	In: A name
	Out: An instance (with info) of Apartament
*/
Apartament::Apartament(char* name) {
	cout << "constructor with param " << endl;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}


/*
	Desc: Create an apartament using info from another apartament
	In: an apartaemnt a
	Out: An instance of Apartament with info from a
*/
Apartament::Apartament(const Apartament& a) {
	cout << "copy constructor " << endl;
	this->name = new char[strlen(a.name) + 1];
	strcpy_s(this->name, strlen(a.name) + 1, a.name);
}


/*
	Desc: Distroy an apartament
	In: An apartament
	Out: - (destructor)
*/
Apartament::~Apartament() {
	if (this->name != NULL) {
		cout << "destructor of product " << name << endl;
		delete[] this->name;
		this->name = NULL;
	}
}


/*
	Desc: Acces a name of an apartament
	In: an apartament
	Out: The name
*/
char* Apartament::getName() {
	return this->name;
}


/*
	Desc: Change the name of an apartament
	In: An apartament and a name
	Out: The apartament with changed name
*/
void Apartament::setName(char* name) {
	if (name) {
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}



Apartament& Apartament::operator=(const Apartament& a) {
	this->setName(a.name);
	return *this;
}


/*
	Desc: Verify if 2 apartament are equal
	In: An apartament
	Out: result
*/
bool Apartament:: operator==(const Apartament& a) {
	return strcmp(this->name, a.name) == 0;
}


