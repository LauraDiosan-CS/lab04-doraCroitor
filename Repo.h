#pragma once
#include "Apartament.h"

class Repo {
private:
	Apartament apartments[20];
	int n;
public:
	Repo();
	~Repo();
	void addApartments(Apartament a);
	Apartament* getAll();
	int getSize();
};
