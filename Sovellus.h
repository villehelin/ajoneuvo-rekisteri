#pragma once
#include<string>
using std::string;

class Sovellus
{
public:
	Sovellus();
	Sovellus(const string& luokka);
	~Sovellus();
	void setLuokka(const string& luokka);
	string getLuokka() const;

	void aja();

private:
	string tulostaValikko() const;
	string luokka_;
};

