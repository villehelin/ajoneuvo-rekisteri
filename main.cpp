#include "Sovellus.h"

int main() {


	// TODO: Sovellus kaatuu kun haetaan poiestetaan taipoistetaan autoa jota ei ole olemassa
	// TODO: Sovellus kaatuu tyhmistä syötteistä
	// TODO: Sovellus tulostaa virheellisen syötteen syötteiden perään turhaan 

	Sovellus rekisteri("B");
	rekisteri.aja();

	system("pause");
	return EXIT_SUCCESS;
}