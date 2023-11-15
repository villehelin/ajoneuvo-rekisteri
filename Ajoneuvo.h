#pragma once
#include<string>
#include"Auto.h"
#include<vector>
#include<functional>
using std::string; using std::vector; using std::function;

class Ajoneuvo
{
public:
	static shared_ptr<Ajoneuvo> getInstance();


	Ajoneuvo();
	Ajoneuvo(const string& luokka);
	~Ajoneuvo();

	void setLuokka(const string& luokka);
	string getLuokka() const;

	void lisaaAuto();
	void tulostaAutot();
	void haeAuto();
	void poistaAuto();
	void paivitaAuto();

	void lisaaKuuntelija(function<void(const string&)> aObserver);

private:
	static shared_ptr<Ajoneuvo> instance;
	vector<function<void(const string&)>> observers;

	string luokka_;
	vector<shared_ptr<Auto>> autot;

	int etsiAutoIndeksi() const;
	shared_ptr<Auto> etsiAuto();

};