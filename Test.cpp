#include "Test.h"
#include "Apartament.h"
#include "Repo.h"
#include <cstring>
#include <cassert>


void testGets() {
	char* name = new char[1 + strlen("gas")];
	strcpy_s(name, 1 + strlen("gas"), "gas");
	Apartament apt = Apartament(name);
	assert(strcmp(apt.getName(), "gas") == 0);

}


void testSets() {
	char* name = new char[1 + strlen("gas")];
	strcpy_s(name, 1 + strlen("gas"), "gas");

	Apartament apt = Apartament(name);

	name = new char[1 + strlen("water")];
	strcpy_s(name, 1 + strlen("water"), "water");

	apt.setName(name);

	assert(strcmp(apt.getName(), "water") == 0);

}


void testRepo() {
	Repo r = Repo();
	char* name1 = new char[1 + strlen("gas")];
	strcpy_s(name1, 1 + strlen("gas"), "gas");
	Apartament apt1 = Apartament(name1);
	r.addApartments(apt1);

	char* name2 = new char[1 + strlen("water")];
	strcpy_s(name2, 1 + strlen("water"), "water");
	Apartament apt2 = Apartament(name2);
	r.addApartments(apt2);

	assert(r.getSize() == 2);
	assert(r.getAll()[0] == apt1);
	assert(r.getAll()[1] == apt2);
}