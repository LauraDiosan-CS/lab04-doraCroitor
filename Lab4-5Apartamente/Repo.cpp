#include "Repo.h"

Repo::Repo() {
	this->n = 0;
	
}


Repo::~Repo() {
	this->n = 0;
	
}


Repo::Repo(Apartament apartments[], int n) {
	this->n = n;
	for (int i = 0; i < n; i++)
		this->apartments[i] = apartments[i];
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


void Repo::setSize(int n) {
	this->n = n;
}

/*
void Repo::update(int id, int newNrApt, int newSum, char* newType) {
	for (int i = 0; i < this->getSize(); i++)
	{
		if (id == this->apartments[i].getId()) {
			this->apartments[i].setNrApt(newNrApt);
			this->apartments[i].setSum(newSum);
			this->apartments[i].setType(newType);
		}
	}
}


void Repo::deleteApt(int id) {
	int lungime = this->getSize();
	for (int i = 0; i < this->getSize(); i++) {
		if (id == this->apartments[i].getId()) {
			for (int j = i; j < this->getSize(); j++) {
				this->apartments[i] = this->apartments[i + 1];
			}
			lungime--;
			i--;
		}
	}
}*/

void Repo::stergere(Apartament a) {
	int poz = this->cautare(a);
	int lungime = this->getSize();
	if (poz != -1) {
		for (int i = poz; i < lungime - 1; i++)
			this->apartments[i] = this->apartments[i + 1];
		this->apartments[lungime - 1] = Apartament();
		this->setSize(lungime - 1);
	}
}


int Repo::cautare(const Apartament& a) {
	for (int i = 0; i < this->getSize(); i++) {
		if (this->apartments[i] == a)
			return i;
	}
	return -1;
}


Repo& Repo::operator=(Repo& r) {
	this->n = 0;
	for (int i = 0; i < this->n; i++)
		this->addApartments(r.getAll()[i]);
	return *this;
}