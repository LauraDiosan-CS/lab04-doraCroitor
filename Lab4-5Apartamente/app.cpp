#include "Apartament.h"
#include "Repo.h"
#include "Test.h"
#include "Console.h"
#include <iostream>

using namespace std;

int main() {
	testApartament();
	testRepo();
	testConditii();
	testFiltrari();
	testProprietati();
	testSortari();
	testStergere();
	
	Console c;
	c.console();
	return 0;
}