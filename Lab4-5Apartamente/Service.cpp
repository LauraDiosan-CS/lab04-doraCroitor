#include "Service.h"


/*
	Desc: Adauga o cheltuiala pentru un apartament
	In: nrApt - nr apartamentului, int
		sum - suma, int
		type - tipul de ccheltuiala, char
	Out:
	ex. adauga 25 gaz 100 - adauga pentru apartamentul 25 o cheltuiala in valaore de 100 RON pentru gaz
*/
void Service::addCheltuiala(int nrApt, int sum, char* type) {
	Apartament newApt(nrApt, sum, type);
	this->repoApartament.addApartments(newApt);
}


/*
	Desc: Afiseaza toate apartamentele
	In: 
	Out: 
*/
Apartament* Service::getAll() {
	return this->repoApartament.getAll();
}


/*
	Desc: Elimina toate cheltuielile unui apartament
	In: nrApt - nr apartamentului ce trebuie eliminat, int
	Out: 
	ex. eliminare 15 - se elimina toate cheltuielile apartamentului 15 
*/
void Service::deleteElemByNrApt(int nrApt) {
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getNrApt() == nrApt) {
			this->repoApartament.stergere(this->getAll()[i]);
			i--;
		}
	}
}


/*
	Desc: Elimina toate cheltuielile apartamentelor dintr-un interval de apartamente
	In: nrApt1 - primul apartament, int
		nrApt2 - ultimul apartament, int
	Out:
	ex. eliminare 5 la 10 - se elimina toate cheltuielile apartamentelor 5, 6, ..., 10
*/
void Service::deleteElemByAptInterval(int nrApt1, int nrApt2) {
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getNrApt() >= nrApt1 && this->getAll()[i].getNrApt() <= nrApt2) {
			this->repoApartament.stergere(this->getAll()[i]);
			i--;
		}
	}
}


/*
	Desc: Elimina toate cheltuielile cu un anumit tip de la toate apt
	In: type - tipul, char
	Out: 
	ex. eliminare gaz - se elimina toate cheltuielile cu gazul de la toate apartamentele 
*/
void Service::deleteElemByType(char* type) {
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (strcmp(this->getAll()[i].getType(), type) == 0) {
			this->repoApartament.stergere(this->getAll()[i]);
			i--;
		}
	}
}


/*
	Desc: Inlocuieste suma veche de la un apartament 
	In: nrApt - nr apt care trebuie modificat, int
		newSum - suma noua, int
		type - tipul apartamentului, char
	Out:
	ex. inlocuire 12 gaz cu 2000 - se inlocuieste suma veche a cheltuielii cu gazul de la apartamentul 12 cu suma 2000
*/
void Service::inlocuire(int nrApt, int newSum, char* type) {
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getNrApt() == nrApt && strcmp(this->getAll()[i].getType(), type) == 0) {
			this->getAll()[i].setSum(newSum);
		}
	}
}


/*
	Desc: Toate apartamentele cu un nr dat
	In: nrApt - nr apt, int
		apartments[] - lista, Apartament
		resultlen - lungime, int
	Out:
	listeaza apartamentele cu un numar dat
*/
void Service::getElemByNr(int nrApt, Apartament apartments[], int& resultlen) {
	resultlen = 0;
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getNrApt() == nrApt)
			apartments[resultlen++] = this->getAll()[i];
	}
}


/*
	Desc: Toate apartamentele cu suma mai mica decat o valoare data
	In: nr - valoare, int
		apartments[] - lista, Apartament
		resultlen - lungime, int
	Out:
	ex. listeaza > 100 - afiseaza cheltuielile in valoare mai mare de 100 RON pentru toate apartamentele 
*/
void Service::getElemByCond1(int nr, Apartament apartments[], int& resultlen) {
	resultlen = 0;
	Apartament* aux1 = this->getAll();
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (aux1[i].getSum() >= nr) {

			Apartament aux = aux1[i];
			apartments[resultlen++] = aux;
		}
	}
}


/*
	Desc: Toate apt cu suma egala cu o val data
	In: nr - valoare, int
		apartments[] - lista, Apartament
		resultlen - lungime, int
	Out:
	ex. listeaza = 60 - afiseaza cheltuielile in valoare de 60 RON pentru toate apartamentele 
*/
void Service::getElemByCond2(int nr, Apartament apartments[], int& resultlen) {
	resultlen = 0;
	Apartament* aux1 = this->getAll();
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (aux1[i].getSum() == nr) {

			Apartament aux = aux1[i];
			apartments[resultlen++] = aux;
		}
	}
}


/*
	Desc: Suma tutror cheltuielilor de un anumit tip
	In: type - tipul, char
	Out: 
	ex. sum gaz - afiseaza suma totala a cheltuielilor cu gazul pentru toate apartamentele
*/
int Service::sumElemByType(char* type) {
	int suma = 0;
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (strcmp(this->getAll()[i].getType(), type) == 0)
			suma += this->getAll()[i].getSum();
	}
	return suma;
}


/*
	Desc: Cea mai mare suma de la un apartament dat
	In: nrApt - nr apt, int
	Out: max - suma maxima, int
	ex. max 15 - afiseaza cea mai valoroasa cheltuiala a apartamentului 15 
*/

int Service::maxSumApt(int nrApt) {
	int max = -1;
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getNrApt() == nrApt) {
			if (this->getAll()[i].getSum() >= max) {
				max = this->getAll()[i].getSum();
			}
		}
	}
	return max;
}


/*
	Desc: Ord desc apt dupa un anumit tip
	In: type - tiupul, char
		apartments[] - lista, Apartament
		resultlen - lungime, int
	Out:
	ex. sorteaza gaz - ordoneaza descrescator cheltuielile cu gazul a tuturor apartamentelor 
*/
void Service::sortBySumAndTypeDesc(char* type, Apartament apartments[], int& resultlen) {
	int ok = 1;
	resultlen = 0;
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (strcmp(this->getAll()[i].getType(), type) == 0) {
			apartments[resultlen++] = this->getAll()[i];
		}
	}
	while (ok == 1) {
		ok = 0;
		for (int i = 0; i < resultlen - 1; i++) {
			if (apartments[i].getSum() < apartments[i + 1].getSum()) {
				Apartament aux;
				aux = apartments[i];
				apartments[i] = apartments[i + 1];
				apartments[i + 1] = aux;
				ok = 1;
			}
		}
	}
}


/*
	Desc: Pastreaza doar cheltuielile de un anumit tip
	In: type - tipul , char
	Out:
	ex. filtru gaz - se pastreaza doar cheltuielile pentru gaz
*/
void Service::filterByType(char* type) {
	for (int i = 0; i < this->repoApartament.getSize(); i++)
	{
		if (strcmp(this->getAll()[i].getType(), type) != 0)
		{
			this->repoApartament.stergere(this->getAll()[i]);
			i--;
		}
	}
	/*int i = 0;
	while (i < this->repoApartament.getSize()) {
		if (strcmp(this->getAll()[i].getType(), type) != 0)
		{
			this->repoApartament.stergere(this->getAll()[i]);

		}
		else
			i++;
	}*/
}


/*
	Desc: Lungimea lui repo
	In:
	Out:
*/
int Service::getSizeRepo() {
	return this->repoApartament.getSize();
}


/*
	Desc: Pastreaza doar cheltuielile cu o val mai mica decat una data
	In: nr - valoare, int
	Out:
	ex. filtru 100 - se pastreaza doar cheltuielile cu valoare mai mica decat 100 
*/
void Service::filterByCond(int nr) {
	
	for (int i = 0; i < this->repoApartament.getSize(); i++) {
		if (this->getAll()[i].getSum() >= nr) {
			this->repoApartament.stergere(this->getAll()[i]);
			i--;
		}
	}

	/*int i = 0;
	while (i < this->repoApartament.getSize()) {
		if (this->getAll()[i].getSum() >= nr)
			this->repoApartament.stergere(this->getAll()[i]);
		else
			i++;

	}*/
}
