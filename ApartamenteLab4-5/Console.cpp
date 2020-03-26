#include "Console.h"
#include <iostream>

using namespace std;

void Console::meniu() {
	cout << " Apartamente \n";
	cout << "1. Adaugare apartament \n";
	cout << "2. Eliminare/Inlocuire \n";
	cout << "3. Listeare de apartamente cu anumite proprietati \n";
	cout << "4. Caracteristici \n";
	cout << "5. Filtrari \n";
	cout << "6. Undo \n";
	cout << "a. Afisare \n";
	cout << "x. Iesire \n";
}


/*
	Citeste un nr de la tastatura
*/
int Console::readInt() {
	int n;
	cout << "Introdu un numar: ";
	cin >> n;
	return n;
}


/*
	Citeste suma
*/
int Console::readSum() {
	int s;
	cout << "Introdu suma: ";
	cin >> s;
	return s;
}


/*
	Citeste o optiune care e string
*/
char Console::readOp() {
	char op;
	cout << "Alege o optiune: ";
	cin >> op;
	return op;
}


/*
	Citeste un tip de cheltuiala
*/
char* Console::readCuvant() {
	char s[100];
	cout << "Introdu un tip de cheltuiala: ";
	cin >> s;
	char* p = new char[strlen(s) + 1];
	strcpy_s(p, strlen(s) + 1, s);
	return p;
}


/*
	Afiseaza apartamentele
*/
void Console::showApartamente() {
	Apartament* apartments = this->serviceApt.getAll();
	for (int i = 0; i < this->serviceApt.getSizeRepo(); i++)
		cout << apartments[i];
}


/*
	Adauga un apartament
*/
void Console::addApartament() {
	int nrApt = readInt();
	int sum = readSum();
	char* type = readCuvant();
	this->serviceApt.addCheltuiala(nrApt, sum, type);
}


/*
	Sterge un apartament dupa numarul lui
*/
void Console::deleteNrApartament() {
	int nrApt = readInt();
	this->serviceApt.deleteElemByNrApt(nrApt);
}


/*
	Sterge apartamentele dintr-un interval de apartamente
*/
void Console::deleteAptInterval() {
	int nrApt1 = readInt();
	int nrApt2 = readInt();
	this->serviceApt.deleteElemByAptInterval(nrApt1, nrApt2);
}


/*
	Sterge apartamentele cu un tip dat de cheltuiala
*/
void Console::deleteAptType() {
	char* type = readCuvant();
	this->serviceApt.deleteElemByType(type);
}


/*
	Inlocuieste suma 
*/
void Console::inlocuire() {
	int nrApt = readInt();
	int newSum = readInt();
	char* type = readCuvant();
	this->serviceApt.inlocuire(nrApt, newSum, type);
}


/*
	Afiseaza nr de apartamente
*/
void Console::showLungime(int n, Apartament apartments[]) {
	for (int i = 0; i < n; i++) {
		cout << apartments[i];
		cout << "\n";
	}
}


/*
	Afiseaza apartamnetele care au numarul dat
*/


void Console::showAptNr() {
	int nrApt = readInt();
	Apartament show[100];
	int resultlen = 0;
	this->serviceApt.getElemByNr(nrApt, show, resultlen);
	this->showLungime(resultlen, show);
}


/*
	Afiseaza apartamentele care respecta conditia 1
*/
void Console::showCond1() {
	int sum = readSum();
	Apartament show[100];
	int resultlen = 0;
	this->serviceApt.getElemByCond1(sum, show, resultlen);
	this->showLungime(resultlen, show);
}


/*
	Afiseaza apartamentele care respecta conditia 2
*/
void Console::showCond2() {
	int sum = readSum();
	Apartament show[100];
	int resultlen = 0;
	this->serviceApt.getElemByCond1(sum, show, resultlen);
	this->showLungime(resultlen, show);
}


/*
	Afiseaza suma totala a apartamentelor cu un tip dat
*/
void Console::maxSumType() {
	char* type = readCuvant();
	int sumTotala = this->serviceApt.sumElemByType(type);
	cout << "Suma apartamentelor la " << type << " este" << sumTotala << endl;
}


/*
	Afiseaza cea mai mare suma a unui apartment dat
*/
void Console::maxAptSum() {
	int nrApt = readInt();
	int max = this->serviceApt.maxSumApt(nrApt);
	cout << " Cea mai mare cheltuiala a apartamentului " << nrApt << " este" << max << endl;
}


/*
	Sorteaza desc apt cu un tip dat
*/
void Console::sortTypeDesc() {
	char* type = readCuvant();
	int resultlen = 0;
	Apartament show[100];
	this->serviceApt.sortBySumAndTypeDesc(type, show, resultlen);
	this->showLungime(resultlen, show);
}


/*
	Filtreaza apartamentele dupa tipul lor
*/
void Console::filterType() {
	char* type = readCuvant();
	this->serviceApt.filterByType(type);
}


/*
	Filtreaza apartamentele dupa o conditie data
*/
void Console::filterCond() {
	int sum = readInt();
	this->serviceApt.filterByCond(sum);
}


int Console::console() {
	while (true) {
		meniu();
		char op = readOp();

		if (op == '1') {
			this->addApartament();
		}

		else if (op == '2') {
			cout << "a. Eliminare dupa numarul apartamentului. \n";
			cout << "b. Eliminare apartamente dintr-un interval de apartamente. \n";
			cout << "c. Eliminare apartamente dupa tipul lor. \n";
			cout << "d. Inlocuire. \n";
			char op2 = readOp();
			if (op2 == 'a')
				this->deleteNrApartament();
			else if (op2 == 'b')
				this->deleteAptInterval();
			else if (op2 == 'c')
				this->deleteAptType();
			else if (op2 == 'd')
				this->inlocuire();
		}

		else if (op == '3') {
			cout << "a. Listeaza apartamentele dupa numar. \n";
			cout << "b. Listeaza apartamentele cu suma mai mare decat o valoare data. \n";
			cout << "c. Listeaza apartamentele cu suma egala cu o valoare data. \n";
			char op2 = readOp();
			if (op2 == 'a') {
				this->showAptNr();
			}
			else if (op2 == 'b') {
				this->showCond1();
			}
			else if (op2 == 'c') {
				this->showCond2();
			}
		}

		else if (op == '4') {
			cout << "a. Afiseaza suma totala a cheltuielilor cu un anumit tip pentru toate apartamentele. \n";
			cout << "b. Afseaza cea mai valoroasa cheltuiala a unui apartament. \n";
			cout << "c. Ordoneaza descrescator cheltuielile cu un anumit tip a tuturor apartamentelo. \n";
			char op2 = readOp();
			if (op2 == 'a') {
				this->maxSumType();
			}
			else if (op2 == 'b') {
				this->maxAptSum();
			}
			else if (op2 == 'c') {
				this->sortTypeDesc();
			}
		}

		else if (op == '5') {
			cout << "a. Filtreaza apartamentele dupa tipul lor. \n";
			cout << "b. Pastreaza apartamentele cu suma mai mica decat o valoare data. \n";
			char op2 = readOp();
			if (op2 == 'a') {
				this->filterType();
			}
			else if (op2 == 'b') {
				this->filterCond();
			}
		}

		else if (op == 'a') {
			this->showApartamente();
		}

		else if (op == 'x')
			return 0;
	}
}
