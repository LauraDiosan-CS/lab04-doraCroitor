#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}


Repo::~Repo() {
	this->n = 0;
}


void Repo::addApartments(Apartament a) {
	this->apartments[this->n++] = a;
}


Apartament* Repo::getAll() {
	return this->apartments;
}


int Repo::getSize() {
	return this->n;
}