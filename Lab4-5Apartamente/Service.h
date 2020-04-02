#pragma once
#include "Repo.h"


class Service {
private:
	Repo repoApartament;
public:
	/*int getCurrentApt();
	void addCurrentAptCheltuiala(int nrApt, int sum, char* type);*/
	void addCheltuiala(int nrApt, int sum, char* type);
	Apartament* getAll();
	void deleteElemByNrApt(int nrApt);
	void deleteElemByAptInterval(int nrApt1, int nrApt2);
	void deleteElemByType(char* type);
	void inlocuire(int nrApt, int newSum, char* type);
	void getElemByNr(int nrApt, Apartament apartments[], int& resultlen);
	void getElemByCond1(int nr, Apartament apartments[], int& resultlen);
	void getElemByCond2(int nr, Apartament apartments[], int& resultlen);
	int sumElemByType(char* type);
	int maxSumApt(int nrApt);
	void sortBySumAndTypeDesc(char* type, Apartament apartments[], int& resultlen);
	void filterByType(char* type);
	void filterByCond(int nr);
	int getSizeRepo();
};
