#include "Ajoneuvo.h"
#include<iostream>
#include<memory>
using std::cout; using std::endl; using std::make_shared; using namespace std; using std::getline; using std::cin;

shared_ptr<Ajoneuvo> Ajoneuvo::instance = nullptr;

shared_ptr<Ajoneuvo> Ajoneuvo::getInstance()
{
	if (!instance) {
		instance = shared_ptr<Ajoneuvo>(new Ajoneuvo());
	}

	return instance;
}

Ajoneuvo::Ajoneuvo() : luokka_{}
{
}

Ajoneuvo::Ajoneuvo(const string & luokka) :luokka_{ luokka }
{
}


Ajoneuvo::~Ajoneuvo()
{
}

void Ajoneuvo::setLuokka(const string & luokka)
{
	luokka_ = luokka;
}

string Ajoneuvo::getLuokka() const
{
	return luokka_;
}

void Ajoneuvo::lisaaAuto()
{
	string merkki, malli, valmistusvuosi, rekisterinumero;

	cout << "Anna merkki: ";
	getline(cin, merkki);
	cout << "Anna malli: ";
	getline(cin, malli);
	cout << "Anna valmistusvuosi: ";
	getline(cin, valmistusvuosi);
	
	cout << "Anna rekisterinumero: ";
	getline(cin, rekisterinumero);



	autot.push_back(make_shared<Auto>( merkki, malli, valmistusvuosi, rekisterinumero ));

	for (auto f : observers) {
		f(rekisterinumero);
	}
}

void Ajoneuvo::tulostaAutot()
{
	for (const shared_ptr<Auto>& h : autot) {
		cout << "*********ajoneuvon " << h << " tiedot***********" << endl;
		h->tulostaTiedot();
	}
}

void Ajoneuvo::haeAuto()
{
	shared_ptr<Auto> xAuto = etsiAuto();
	if (xAuto >= 0) {
		cout << "*********ajoneuvon " << xAuto << " tiedot***********" << endl;
		xAuto->tulostaTiedot();
	}
}

void Ajoneuvo::poistaAuto()
{
	int indeksi = etsiAutoIndeksi();
	if (indeksi >= 0)
	{
		autot.erase(autot.begin() + indeksi);
	}
	else
		cout << "autoa ei loytynyt! " << endl;
}

void Ajoneuvo::paivitaAuto()
{
	shared_ptr<Auto> xAuto = etsiAuto();
	if (xAuto >= 0)
	{
		string valinta;
		string merkki, malli, valmistusvuosi, rekisterinumero;
		do
		{
			cout << endl;
			cout << "Mita tietoa autosta muutetaan? " << endl;
			cout << " 1) Merkki" << endl;
			cout << " 2) Malli" << endl;
			cout << " 3) Valmistusvuosi" << endl;
			cout << " 4) Rekisterinumero" << endl;
			cout << " 0) Palaa takaisin" << endl << endl;
			cout << "Anna valintasi: ";
			getline(cin, valinta);
			if (valinta == "1")
			{
				cout << "Anna uusi merkki: ";
				getline(cin, merkki);
				xAuto->setMerkki(merkki);
			}
			else if (valinta == "2")
			{
				cout << "Anna uusi malli: ";
				getline(cin, malli);
				xAuto->setMalli(malli);
			}
			else if (valinta == "3")
			{
				cout << "Anna uusi valmistusvuosi: ";
				getline(cin, valmistusvuosi);
				xAuto->setValmistusvuosi(valmistusvuosi);
			}
			else if (valinta == "4")
			{
				cout << "Anna uusi rekisterinumero: ";
				getline(cin, rekisterinumero);
				xAuto->setRekisterinumero(rekisterinumero);

			}
			else if (valinta == "0")
			{

			}
			else
			{
				cout << "Virheellinen valinta! " << endl;
			}

		} while (valinta != "0");
	}
	else
		cout << "autoa ei loytynyt! " << endl;
}

void Ajoneuvo::lisaaKuuntelija(function<void(const string&)> aObserver)
{
	observers.push_back(aObserver);
}

int Ajoneuvo::etsiAutoIndeksi() const
{
	string rekisterinumero;
	cout << "Anna rekisterinumero: ";
	getline(cin, rekisterinumero);

	for (unsigned int i = 0; i < autot.size(); i++) {
		if (rekisterinumero == autot[i]->getRekisterinumero()) {
			return i;
		}
	}
	return -1;
}

shared_ptr<Auto> Ajoneuvo::etsiAuto()
{
	string reksiterinumero;
	cout << "Anna rekisterinumero: ";
	getline(cin, reksiterinumero);

	for (shared_ptr<Auto>& h : autot) {
		if (h->getRekisterinumero() == reksiterinumero) {
			return h;
		}
	}
	return nullptr;
}
