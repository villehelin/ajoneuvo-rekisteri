#include "Auto.h"
#include<iostream>
using std::cout; using std::endl; using std::getline; using std::cin;

int Auto::auto_count_ = 0;

Auto::Auto() : merkki_{ "" }, malli_{ "" }, valmistusvuosi_{ "0" }, rekisterinumero_{ nullptr }
{
	auto_count_++;
}

Auto::Auto(const string & merkki, const string & malli, const string & valmistusvuosi) : merkki_{ merkki }, malli_{ malli }, valmistusvuosi_{ valmistusvuosi }, rekisterinumero_{ nullptr }
{
	auto_count_++;
}

Auto::Auto(const string & merkki, const string & malli, const string & valmistusvuosi, const string & rekisterinumero) : merkki_{ merkki }, malli_{ malli }, valmistusvuosi_{ valmistusvuosi }, rekisterinumero_{ rekisterinumero }
{
	auto_count_++;
}


Auto::Auto(const Auto & aAuto) : merkki_{ aAuto.merkki_ }, malli_{ aAuto.malli_ }, valmistusvuosi_{ aAuto.valmistusvuosi_ }, rekisterinumero_{ aAuto.rekisterinumero_}
{
	auto_count_++;
}

Auto::~Auto()
{
	auto_count_--;
}

void Auto::setMerkki(const string & merkki)
{
	merkki_ = merkki;
}

void Auto::setMalli(const string & malli)
{
	malli_ = malli;
}

void Auto::setValmistusvuosi(const string & valmistusvuosi)
{
	valmistusvuosi_ = valmistusvuosi;
}

void Auto::setRekisterinumero(const string & rekisterinumero)
{
	rekisterinumero_ = rekisterinumero;
}

string Auto::getMerkki() const
{
	return merkki_;
}

string Auto::getMalli() const
{
	return malli_;
}

string Auto::getValmistusvuosi() const
{
	return valmistusvuosi_;
}

string Auto::getRekisterinumero() const
{
	return rekisterinumero_;
}


void Auto::tulostaTiedot()
{
	cout << "merkki: " << merkki_ << endl;
	cout << "malli: " << malli_ << endl;
	cout << "valmistusvuosi: " << valmistusvuosi_ << endl;
	cout << "rekisterinumero: " << rekisterinumero_ << endl;
}
