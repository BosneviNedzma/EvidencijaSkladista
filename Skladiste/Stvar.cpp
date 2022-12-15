#include <cstring>
#include <iostream>
#include "Stvar.h"

int Stvar::brStvari = 0;

Stvar::Stvar() {
	strcpy(this->naziv; "Nova stvar");
	this->kolicina = 0;
}

void Stvar::setNaziv() {
	cout << "Unesite naziv stvari: ";
	cin.getline(this->naziv, 50);
}

void Stvar::setKolicina() {
	cout << "Unesite kolicinu stvari: ";
	cin >> this->kolicina;
	cin.ignore();
}

char* Stvar::getNaziv() {
	return this->naziv;
}

int Stvar::getKolicina() {
	return this->kolicina;
}

void Stvar::unesiStvar() {
	cout << "Unos stvari\n";
	this->setNaziv();
	this->setKolicina();
}

void Stvar::povecajKolicinu(int a) {
	this->kolicina += a;
}

void Stvar::smanjiKolicinu(int a) {
	this->kolicina -= a;
}

void Stvar::trenutnoBrStvari() {
	cout << "Na stanju je trenutno " << Stvar::brStvari << " stvari.\n";
}