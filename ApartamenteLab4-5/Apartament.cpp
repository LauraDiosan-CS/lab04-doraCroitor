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
	//cout << "default constructor " << endl;
	this->nrApt = 0;
	this->sum = 0;
	this->type = NULL;
}


/*
	Desc: Create an apartament
	In: A type
	Out: An instance (with info) of Apartament
*/
Apartament::Apartament(int nrApt, int sum,char* type) {
	//cout << "constructor with param " << endl;
	this->nrApt = nrApt;
	this->sum = sum;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}


/*
	Desc: Create an apartament using info from another apartament
	In: an apartaemnt a
	Out: An instance of Apartament with info from a
*/
Apartament::Apartament(const Apartament& a) {
	//cout << "copy constructor " << endl;
	this->nrApt = a.nrApt;
	this->sum = a.sum;
	this->type = new char[strlen(a.type) + 1];
	strcpy_s(this->type, strlen(a.type) + 1, a.type);
}


/*
	Desc: Distroy an apartament
	In: An apartament
	Out: - (destructor)
*/
Apartament::~Apartament() {
	if (this->type != NULL) {
		//cout << "destructor of product " << nrApt << endl;
		delete[] this->type;
		this->type = NULL;
	}
}


/*
	Desc: Acces a nrApt of an apartament
	In: an apartament
	Out: The nrApt
*/
int Apartament::getNrApt() {
	return this->nrApt;
}


/*
	Desc: Acces a sum of an apartament
	In: An apt
	Out: The sum
*/
int Apartament::getSum() {
	return this->sum;
}


/*
	Desc: Acces a type of an apartament
	In: an apartament
	Out: The type
*/
char* Apartament::getType() {
	return this->type;
}


/*
	Desc: Change the nrApt
	In: An apt and a nr
	Out:The apt with changed nr
*/
void Apartament::setNrApt(int nrApt) {
	this->nrApt = nrApt;
}


/*
	Desc: Change the sum
	In: An apt an a sum
	Out: The apt with changed sum
*/
void Apartament::setSum(int sum) {
	this->sum = sum;
}


/*
	Desc: Change the type of an apartament
	In: An apartament and a type
	Out: The apartament with changed type
*/
void Apartament::setType(char* type) {
	if (this->type != NULL) {
		delete[] this->type;
	}

	if (type != NULL) {
		this->type = new char[strlen(type) + 1];
		strcpy_s(this->type, strlen(type) + 1, type);
	}
	else
		this->type = NULL;
}



Apartament& Apartament::operator=(const Apartament& a) {
	this->setNrApt(a.nrApt);
	this->setSum(a.sum);
	this->setType(a.type);
	return *this;
}


/*
	Desc: Verify if 2 apartament are equal
	In: An apartament
	Out: result
*/
bool Apartament:: operator==(const Apartament& a) {
	return strcmp(this->type, a.type) == 0;
}


ostream& operator<<(ostream& os, const Apartament& a) {
	os << " Apartament cu numarul: " << a.nrApt << " ,cu suma de bani: " << a.sum << " ,si tipul : " << a.type << "\n";
	return os;
}

