#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Medicament 
{

public:

	static int contor;
	const int id;
	char* denumire;
	float   pret;



	Medicament() :id(contor++)
	{
		this->denumire = new char[strlen("na") + 1];
		strcpy(this->denumire, "na");
		this->pret = 0;

	}

	Medicament(const char* den, float p) :id(contor++)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->pret = p;

	}


	Medicament(const char* den) :id(contor++)
	{
		this->denumire = new char[strlen(den) + 1];
		strcpy(this->denumire, den);
		this->pret = 0;

	}


	void afisare() {
		cout << "ID " << this->id << endl;
		cout << "Denumire: " << this->denumire << endl;
		cout << "Pret " << this->pret << endl;
	}

	~Medicament() {
		contor--;
		delete[] this->denumire;
	}

	static void setMaresteContor(Medicament& m, float marire) {
		m.contor += marire;
	}

};
int Medicament::contor = 0;


class Farmacist
{

public:
	const int id;
	string nume;
	static string denumireFarmacie;
	int nrLuni;
	float* bonusuriPerLuna;


	void afisare() {
		cout << "ID " << this->id << endl;
		cout << "Nume  : " << this->nume << endl;
		cout << "nr luni  " << this->nrLuni << endl;
		for (int i = 0; i < this->nrLuni; i++) {
			cout << "In luna " << i + 1 << " a luat bonus de" << this->bonusuriPerLuna[i] << " RON" << endl;
		}
	}

	~Farmacist() {
		delete[] this->bonusuriPerLuna;
	}

	static void schimbaDenumire(string den) {
		Farmacist::denumireFarmacie = den;
	}

	Farmacist() :id(0)
	{
		this->nume = "na";
		this->nrLuni = 0;
		this->bonusuriPerLuna = NULL;

	}


	Farmacist(int idd, string num, int nrl, float* bo) :id(idd)
	{
		this->nume = num;
		this->nrLuni = nrl;
		this->bonusuriPerLuna = new float[nrl];
		for (int i = 0; i < nrl; i++) {
			this->bonusuriPerLuna[i] = bo[i];
		}

	}
	Farmacist(int idd, string num) :id(idd)
	{
		this->nume = num;
		this->nrLuni = 12;
		this->bonusuriPerLuna = new float[nrLuni];
		for (int i = 0; i < nrLuni; i++) {
			this->bonusuriPerLuna[i] = bonusuriPerLuna[i];
		}

	}


};
string Farmacist::denumireFarmacie = "Dona";




class Client
{
public:
	const int anNastere;
	static int anCurent;
	char* nume;
	int puncteFidelitate;


	void afisare() {
		cout << "Varsta " << Client::anCurent - this->anNastere << endl;
		cout << "Nume client: " << this->nume << endl;
		cout << "Pucnte " << this->puncteFidelitate << endl;
	}

	static void incrementareAn() {
		Client::anCurent++;
	}


	~Client() {
		delete[] this->nume;
	}

	Client() :anNastere(1950)
	{
		this->nume = new char[strlen("na") + 1];
		strcpy(this->nume, "na");
		this->puncteFidelitate = 0;

	}

	Client(const char* num, int ann, int p) :anNastere(ann)
	{
		this->nume = new char[strlen(num) + 1];
		strcpy(this->nume, num);
		this->puncteFidelitate = p;

	}


	Client(const char* num, int ann) :anNastere(ann)
	{
		this->nume = new char[strlen(num) + 1];
		strcpy(this->nume, num);
		this->puncteFidelitate = 0;

	}


};
int Client::anCurent = 2023;




int main()// programul principal 
{

	Medicament m;
	Client c;
	Farmacist f;



	Medicament m1("paracetamol", 23);
	Client c1("alexandru", 1992, 232);
	Farmacist f1(1, "alina", 2, new float[2] {5.4f, 6.6f});

	Medicament m2("aspirina");
	Client c2("irina", 1992);
	Farmacist f2(1,"Alina");


	Farmacist::schimbaDenumire(" Medicamentul paracetamol");
	Client::incrementareAn();


	m.afisare();
	m1.afisare();
	m2.afisare();

	c.afisare();
	c1.afisare();
	c2.afisare();

	f.afisare();
	f1.afisare();
	f2.afisare();


	return 0;
}