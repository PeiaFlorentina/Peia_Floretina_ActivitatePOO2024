# define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <numeric>
#include<algorithm>
using namespace std;

class Librarie
{
protected:
	string nume;
public:
	Librarie()
	{
		this->nume = "Mihai Eminescu";
	}
// stl : containere(vector, lista), algoritmi si operatori
	Librarie(string nume)
	{
		this->nume = nume;
	}

	virtual string getDenumire()
	{
		return nume;
	}

};

class LibrarieOnline :public Librarie
{
	string site;
public:
	LibrarieOnline() :Librarie("Librarie Online")
	{
		this->site = "www.site.ro";
	}

	LibrarieOnline(string nume, string site) :Librarie(nume)
	{
		this->site = site;
	}

	string getDenumire()
	{
		return nume + "-" + site;
	}


};


int main()
{
	LibrarieOnline lo("Libris", "libris.ro");
	cout << lo.getDenumire() << endl;

	//late binding

	Librarie* lib = new Librarie("Humanitas");

	cout << lib->getDenumire() << endl;


	vector<float> v;
	v.push_back(1.2);
	v.push_back(4.5);
	v.push_back(3.7);
	v.push_back(5.9);

	float s = 0;
	for (int i = 0; i < v.size(); i++)
	{
		s += v[i];
	}


	float suma = accumulate(v.begin(), v.end(), 0);

	if (v.size() != 0) {
		cout << "Media este:" << s / v.size() << endl;
	}
	else
		cout << "nu avem elemente" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}


	list<Librarie*> lista;  // lista cu pointeri la librarie

	lista.push_front(new Librarie());
	lista.push_front(new Librarie("Carturesti"));
	lista.push_front(new LibrarieOnline("Bookzone", "bookzone.ro"));
	lista.push_back(new LibrarieOnline());


	// declaram un iterator

	list<Librarie*> ::iterator it = lista.begin();
	while (it != lista.end())
	{
		cout << (*it)->getDenumire() << endl;
		it++;
	}

	map<int, Librarie> librarii;
	librarii.insert(pair<int, Librarie>(1, Librarie()));
	librarii.insert(pair<int, Librarie >(2, Librarie("Carturesti")));
	librarii.insert(pair< int, Librarie >(3, Librarie("Libris")));
	librarii.insert(pair< int, Librarie >(23, Librarie("Humanitas")));
	librarii.insert(pair<int, Librarie >(3, Librarie("Mihail Sadoveanu")));
	map< int, Librarie> ::iterator iterator= librarii.begin();
	while (iterator != librarii.end())
	{
		cout << iterator->first << "-";
		cout << iterator->second. getDenumire();
		cout << endl;
		iterator++;
	}

	cout << librarii[23].getDenumire() << endl;



	return 0;
}