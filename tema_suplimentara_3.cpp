#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<string>
// plafar



class Medicament
{

private:

	static int contor;
	const int id;
	char* denumire;
	float   pret;

public:



	//set 

	static void setContor(int c) {
		if (c >= 0) {
			Medicament::contor = c;
		}
	}

	void setDenumire(const char* den)
	{
		if (strlen(den) > 2) {
			delete[] this->denumire;
			this->denumire = new char[strlen(den) + 1];
			strcpy(this->denumire, den);
		}
	}

	void setPret(float p) {
		if (p >= 0) {
			this->pret = p;
		}
	}


	// get 

	char* getDenumire() {
		return this->denumire;
	}

	float getPret() {
		return this->pret;
	}

	int getId() {
		return this->id;
	}


	static int getNrMedicamente() {
		return Medicament::contor;
	}


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



	Medicament(const Medicament& s) :id(contor++)
	{
		this->denumire = new char[strlen(s.denumire) + 1];
		strcpy(this->denumire, s.denumire);
		this->pret = s.pret;

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
	friend void setMarestePret(Medicament& m, float marire);

};
int Medicament::contor = 0;

void setMarestePret(Medicament& m, float marire) {
	m.pret += marire;
}


class Farmacist
{

private:
	const int id;
	string nume;
	static string denumireFarmacie;
	int nrLuni;
	float* bonusuriPerLuna;

public:

	static void setDenumireFarmacie(string  d) {
		if (d.length() >= 2) {
			Farmacist::denumireFarmacie = d;
		}
	}

	void setNume(string n) {
		if (n.length() > 2) {
			this->nume = n;
		}
	}

	void setNrLuni(int n, float* b) {
		if (n > 0 && b != NULL) {
			this->nrLuni = n;
			delete[] this->bonusuriPerLuna;
			this->bonusuriPerLuna = new float[n];
			for (int i = 0; i < n; i++) {
				this->bonusuriPerLuna[i] = b[i];
			}
		}
	}

	//get
	int getNrLuni() {
		return this->nrLuni;

	}

	float* getBonusuri() {
		return this->bonusuriPerLuna;
	}

	static string getFarmacie() {
		return Farmacist::denumireFarmacie;
	}

	string getNume() {
		return this->nume;
	}

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
	Farmacist(const Farmacist& s) :id(s.id)
	{
		this->nume = s.nume;
		this->nrLuni = s.nrLuni;
		this->bonusuriPerLuna = new float[s.nrLuni];
		for (int i = 0; i < s.nrLuni; i++) {
			this->bonusuriPerLuna[i] = s.bonusuriPerLuna[i];
		}

	}

	Farmacist(int idd, string num) :id(idd)
	{
		this->nume = num;
		this->nrLuni = 0;
		this->bonusuriPerLuna = NULL;

	}


};
string Farmacist::denumireFarmacie = "Dona";


class Client
{
private:
	const int anNastere;// 1995
	static int anCurent;// 2023
	char* nume;
	int puncteFidelitate;

public:

	static void setAnCurent(int ac) {
		if (ac >= 0) {
			Client::anCurent = ac;
		}
	}

	void setNume(const char* n)
	{
		if (strlen(n) > 2) {
			delete[] this->nume;
			this->nume = new char[strlen(n) + 1];
			strcpy(this->nume, n);
		}
	}

	void setPuncteFidelitate(int  p) {
		if (p >= 0) {
			this->puncteFidelitate = p;
		}
	}
	//get\

	int getAnNastere() {
		return this->anNastere;
	}
	static int getAnCurent() {
		return Client::anCurent;
	}
	char* getNume() {
		return this->nume;
	}
	int getPuncteFidelitate() {
		return this->puncteFidelitate;
	}

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

	Client(const Client& s) :anNastere(s.anNastere)
	{
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);
		this->puncteFidelitate = s.puncteFidelitate;

	}

	Client(const char* num, int ann) :anNastere(ann)
	{
		this->nume = new char[strlen(num) + 1];
		strcpy(this->nume, num);
		this->puncteFidelitate = 0;

	}
	friend int getVarsta(Client& c);

};
int Client::anCurent = 2023;


int getVarsta(Client& c) {
	return Client::anCurent - c.anNastere;
}



int main()
{



	Medicament m;
	Client c;
	Farmacist f;



	Medicament m1("paracetamol", 23);
	Client c1("alexandru", 1992, 232);
	Farmacist f1(1, "alina", 2, new float[2] {5.4f, 6.6f});

	Medicament m2("aspirina");
	Client c2("irina", 1992);
	Farmacist f2(1, "Alina");



	cout << "Nr de medicamente este: " << Medicament::getNrMedicamente() << endl;
	Farmacist::schimbaDenumire("Medicamentul Paracetamol");
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

	m.setDenumire("ibugrip");
	m.setPret(23.3f);
	Medicament::setContor(0);

	cout << m.getDenumire() << endl;
	cout << m.getId() << endl;
	cout << Medicament::getNrMedicamente() << endl;
	cout << m.getPret() << endl;


	f.setDenumireFarmacie("DaciaFarm");
	f.setNrLuni(2, new float[2] {4.5f, 3.4f});
	f.setNume("Toma");

	cout << f.getNume() << endl;
	cout << Farmacist::getFarmacie() << endl;
	for (int i = 0; f.getNrLuni(); i++) {
		cout << f.getBonusuri()[i] << endl;
	}



	Client::setAnCurent(2025);
	c.setNume("Marian");
	c.setPuncteFidelitate(123);

	cout << Client::getAnCurent() << endl;
	cout << c.getAnNastere() << endl;
	cout << c.getNume() << endl;
	cout << c.getPuncteFidelitate() << endl;


	//functii globale prietene cu clasele cleint si medicament
	setMarestePret(m, 12.2f);
	cout << "Varsta este " << getVarsta(c) << endl;


	return 0;
}