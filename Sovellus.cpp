#include "Sovellus.h"
#include"Ajoneuvo.h"
#include<iostream>
using std::cout; using std::endl; using std::getline; using std::cin;



Sovellus::Sovellus() : luokka_{}
{
}

Sovellus::Sovellus(const string & luokka) : luokka_{ luokka }
{
}


Sovellus::~Sovellus()
{
}

void Sovellus::setLuokka(const string & luokka)
{
	luokka_ = luokka;
}

string Sovellus::getLuokka() const
{
	return luokka_;
}

void Sovellus::aja()
{
	auto ajoneuvo = Ajoneuvo::getInstance();


	auto ajoneuvoKuuntelijaLamda = [](const string& rekisterinumero) {
		cout << "Tama on lamda, joka huomasi ajoneuvon " << rekisterinumero << " lisaamisen.." << endl;
	};

	ajoneuvo->lisaaKuuntelija(ajoneuvoKuuntelijaLamda);

	string valinta;
	cout << "Tervetuloa " << luokka_ << " -ajoneuvoluokan rekisteriin!" << endl;
	do
	{
		valinta = tulostaValikko();
		if (valinta == "1") // lisää
		{
			ajoneuvo->lisaaAuto();
		}
		if (valinta == "2") // tulosta tiedot
		{
			ajoneuvo->tulostaAutot();
		}
		if (valinta == "3") // hae tiedot
		{
			ajoneuvo->haeAuto();
		}
		if (valinta == "4") // poista tiedot
		{
			ajoneuvo->poistaAuto();
		}
		if (valinta == "5") // muokkaa tietoja
		{
			ajoneuvo->paivitaAuto();
		}
//		if (valinta == "6") // järjeteletiedot
//		{
//
//		}
		else if (valinta == "0")
		{

		}
		else
		{
			cout << "Virheellinen valinta! " << endl;
		}
	} while (valinta != "0");
}

string Sovellus::tulostaValikko() const
{
	// lisätä lisää, hakea, poistaa, muokata ja järjestää  
	string valinta;
	cout << " 1) Lisaa auto" << endl;
	cout << " 2) Tulosta autot" << endl;
	cout << " 3) Hae auto" << endl;
	cout << " 4) Poista auto" << endl;
	cout << " 5) Moukkaa auto" << endl;
//	cout << " 6) Jarjesta autot" << endl;
	cout << " 0) Lopeta" << endl;
	cout << "Anna valintasi: ";
	getline(cin, valinta);
	return valinta;

}
