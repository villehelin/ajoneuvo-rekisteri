#pragma once
#include <string>
#include<memory>
using std::string; using std::shared_ptr;

 

class Auto
{
public:
	Auto();
	Auto(const string& merkki, const string& malli, const string& valmistusvuosi);
	Auto(const string& merkki, const string& malli, const string& valmistusvuosi, const string& rekisterinumero);
	Auto(const Auto& aAuto);
	~Auto();

	void setMerkki(const string& merkki);
	void setMalli(const string& malli);
	void setValmistusvuosi(const string& valmistusvuosi);
	void setRekisterinumero(const string& rekisterinumero);

	string getMerkki() const;
	string getMalli() const;
	string getValmistusvuosi() const;
	string getRekisterinumero() const;


	void tulostaTiedot();
private:
	string merkki_;
	string malli_;
	string valmistusvuosi_;
	string rekisterinumero_;

	static int auto_count_;
};

