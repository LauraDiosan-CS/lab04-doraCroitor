#pragma once
#include <ostream>
using namespace std;

class Apartament {
private:
	char* name;
public:
	Apartament();
	Apartament(char* name);
	Apartament(const Apartament& a);
	~Apartament();
	char* getName();
	void setName(char* name);
	Apartament& operator=(const Apartament& a);  //ii da lui a1 toate lui a2
	bool operator==(const Apartament& a);   //verifica daca 2 sunt egale
	  
};

