#include "Test.h"
#include "Apartament.h"
#include "Repo.h"
#include "Service.h"
#include <cstring>
#include <cassert>
#include <iostream>

using namespace std;


void testApartament() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Apartament apt1(1,1, 100, type1);
	Apartament apt2(2,1, 100, type1);
	assert(apt1.getNrApt() == 1);
	assert(apt1.getSum() == 100);
	assert(strcmp(apt1.getType(), "apa") == 0);
	assert(apt1 == apt2);

	apt1.setNrApt(5);
	apt1.setSum(200);
	apt1.setType(type2);
	assert(apt1.getNrApt() == 5);
	assert(apt1.getSum() == 200);
	assert(strcmp(apt1.getType(), "gaz") == 0);

	delete[] type1;
	delete[] type2;
}



void testRepo() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Apartament apt1(1,1, 100, type1);
	Apartament apt2(2,2, 150, type2);

	Repo repositoryApt;
	repositoryApt.addApartments(apt1);
	repositoryApt.addApartments(apt2);
	assert(repositoryApt.getSize() == 2);
	assert(repositoryApt.getAll()[0] == apt1);
	assert(repositoryApt.getAll()[1] == apt2);

	delete[] type1;
	delete[] type2;
}


/*
void testStergere() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Service serviceApt;
	serviceApt.addCheltuiala(11, 100, type1);
	serviceApt.addCheltuiala(12, 150, type2);
	serviceApt.addCheltuiala(13, 120, type2);
	serviceApt.addCheltuiala(11, 130, type1);
	serviceApt.addCheltuiala(14, 180, type2);
	serviceApt.addCheltuiala(15, 350, type2);
	serviceApt.addCheltuiala(16, 100, type1);

	serviceApt.deleteElemByAptInterval(12, 14);
	assert(serviceApt.getAll()[0].getNrApt() == 11);
	assert(serviceApt.getAll()[1].getNrApt() == 11);
	assert(serviceApt.getAll()[2].getNrApt() == 15);
	assert(serviceApt.getAll()[3].getNrApt() == 16);

	serviceApt.deleteElemByNrApt(11);
	assert(serviceApt.getAll()[0].getNrApt() == 15);
	assert(serviceApt.getAll()[1].getNrApt() == 16);

	serviceApt.deleteElemByType(type2);
	assert(serviceApt.getAll()[0].getNrApt() == 16);
	
	delete[] type1;
	delete[] type2;
}


void testConditii() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Service serviceApt;
	serviceApt.addCheltuiala(11, 100, type1);
	serviceApt.addCheltuiala(12, 150, type2);
	serviceApt.addCheltuiala(13, 120, type2);
	serviceApt.addCheltuiala(14, 180, type2);
	serviceApt.addCheltuiala(15, 350, type2);
	serviceApt.addCheltuiala(16, 100, type1);

	Apartament result[100];
	int resultlen = 0;
	serviceApt.getElemByCond1(140, result, resultlen);
	assert(resultlen == 3);
	assert(result[0].getNrApt() == 12);
	assert(result[1].getNrApt() == 14);
	assert(result[2].getNrApt() == 15);

	serviceApt.getElemByCond2(100, result, resultlen);
	assert(resultlen == 2);
	assert(result[0].getNrApt() == 11);
	assert(result[1].getNrApt() == 16);

	delete[] type1;
	delete[] type2;
}


void testProprietati() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Service serviceApt;
	serviceApt.addCheltuiala(11, 100, type1);
	serviceApt.addCheltuiala(12, 150, type2);
	serviceApt.addCheltuiala(12, 120, type2);
	serviceApt.addCheltuiala(14, 180, type2);
	serviceApt.addCheltuiala(15, 350, type2);
	serviceApt.addCheltuiala(16, 100, type1);

	int sum = serviceApt.sumElemByType(type1);
	assert(sum == 200);
	int max = serviceApt.maxSumApt(12);
	assert(max == 150);

	delete[] type1;
	delete[] type2;

}


void testSortari() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Service serviceApt;
	serviceApt.addCheltuiala(11, 100, type1);
	serviceApt.addCheltuiala(12, 150, type2);
	serviceApt.addCheltuiala(12, 120, type2);
	serviceApt.addCheltuiala(14, 180, type2);
	serviceApt.addCheltuiala(15, 350, type2);
	serviceApt.addCheltuiala(16, 150, type1);

	Apartament result[100];
	int resultlen;
	serviceApt.sortBySumAndTypeDesc(type1, result, resultlen);
	assert(resultlen == 2);
	assert(result[0].getNrApt() == 16);
	assert(result[0].getSum() == 150);
	assert(result[1].getNrApt() == 11);
	assert(result[1].getSum() == 100);

	delete[] type1;
	delete[] type2;
}


void testFiltrari() {
	char* type1 = new char[20];
	char* type2 = new char[20];
	strcpy_s(type1, strlen("apa") + 1, "apa");
	strcpy_s(type2, strlen("gaz") + 1, "gaz");
	Service serviceApt;
	serviceApt.addCheltuiala(11, 100, type1);
	serviceApt.addCheltuiala(12, 150, type2);
	serviceApt.addCheltuiala(13, 120, type2);
	serviceApt.addCheltuiala(14, 180, type2);
	serviceApt.addCheltuiala(15, 350, type2);
	serviceApt.addCheltuiala(16, 150, type1);

	serviceApt.filterByType(type1);
	assert(serviceApt.getAll()[0].getNrApt() == 11);
	assert(serviceApt.getAll()[1].getNrApt() == 16);
	assert(serviceApt.getSizeRepo() == 2);

	serviceApt.filterByCond(140);
	assert(serviceApt.getAll()[0].getNrApt() == 16);
	assert(serviceApt.getSizeRepo() == 1);

	delete[] type1;
	delete[] type2;
}
*/

