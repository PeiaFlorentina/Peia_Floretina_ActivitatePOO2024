#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
 using namespace std;

 class Carte
 {
 public:
	 int nrPagini;
	 float pretCarte;
	 string denumireCarte;
	 static float TVA;
	 const int anAparitie;

	 Carte() : anAparitie(2002)
	 {
		 this->nrPagini = 122;
		 this->pretCarte = 35;
		 this->denumireCarte = "TIC";
		 
	 }

	 Carte(int nrPagini, float pretCarte, string denumireCarte, int anAparitie) : anAparitie(anAparitie)
	 {
		 this->nrPagini = nrPagini;
		 this->pretCarte = pretCarte;
		 this->denumireCarte = denumireCarte;
	 }




	 void afisare()
	 {
		 cout << "nrPagini: " << this->nrPagini << endl;
		 cout << "Pret:" << this->pretCarte << endl;
		 cout << "Denumire Carte: " << this->denumireCarte << endl;
		 cout << "TVA : " << this->TVA << endl;
		 cout << "Anul aparitiei : " << this->anAparitie << endl;
	 }

	 float pretMediuPagina()
	 {
		 float pret_mediu;
		 pret_mediu = this->nrPagini / this->pretCarte;
		 return pret_mediu;
	 }

 };

 float Carte::TVA = 0.19;
 



 int main()
 {
	 Carte c1;
	 c1.afisare();

	 Carte c2(12, 22, "IT", 2014);
	 c2.afisare();

	 Carte* pointer = new Carte(200, 45, "Economie", 2000);
	 pointer->afisare();
	 cout << "pretul per pagina este: " << pointer->pretMediuPagina() << endl;
	 delete pointer;

 }
