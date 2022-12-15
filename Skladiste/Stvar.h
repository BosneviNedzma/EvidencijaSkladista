#pragma once

class Stvar {
private:
	char naziv[50];
	int kolicina;

public:
	static int brStvari;
	Stvar();
	void setNaziv();
	void setKolicina();
	char* getNaziv();
	int getKolicina();
	void unesiStvar();
	void povecajKolicinu(int a);
	void smanjiKolicinu(int a);
	static void trenutnoBrStvari();
	~Stvar() = default;
};
