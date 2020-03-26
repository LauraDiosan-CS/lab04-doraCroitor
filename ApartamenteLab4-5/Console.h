#pragma once
#include "Service.h"


class Console {
private:
	Service serviceApt;
public:
	void meniu();
	int console();
	int readInt();
	int readSum();
	char readOp();
	char* readCuvant();
	void showApartamente();
	void addApartament();
	void deleteNrApartament();
	void deleteAptInterval();
	void deleteAptType();
	void inlocuire();
	void showAptNr();
	void showCond1();
	void showCond2();
	void showLungime(int n, Apartament apartments[]);
	void maxSumType();
	void maxAptSum();
	void sortTypeDesc();
	void filterType();
	void filterCond();

};