#pragma once
#include <ostream>
using namespace std;

class Apartament {
private:
	int nrApt, sum;
	char* type;
public:
	Apartament();
	Apartament(int nrApt, int sum, char* type);
	Apartament(const Apartament& a);
	~Apartament();
	int getNrApt();
	int getSum();
	char* getType();
	void setNrApt(int nrApt);
	void setSum(int sum);
	void setType(char* type);
	Apartament& operator=(const Apartament& a);  //ii da lui a1 toate lui a2
	bool operator==(const Apartament& a);   //verifica daca 2 sunt egale
	friend ostream& operator<<(ostream& os, const Apartament& a);
};

