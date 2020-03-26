#pragma once
#include "Apartament.h"

class Repo {
private:
	Apartament apartments[100];
	int n;
public:
	Repo();
	~Repo();
	Repo(Apartament apartments[], int n);
	void addApartments(Apartament a);
	Apartament* getAll();
	int getSize();
	void setSize(int n);
	void stergere(Apartament a);
	int cautare(const Apartament& a);
	Repo& operator=(Repo& r);
};
