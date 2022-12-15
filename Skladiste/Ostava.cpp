#include <iostream>
#include "Ostava.h"

using namespace std;

Ostava::Ostava() {
	cout << "Unesite kapacitet ostave: ";
	cin >> this->maxBrStvari;
	cin.ignore();
	cout << "Ostava kreirana!\n";
}

void Ostava::setMaxBrStvari() {
	unique_ptr<int>broj = make_unique<int>(0);
	cout << "Unesite za koliko zelite prosiriti ostavu: ";
	cin >> *broj;
	cin.ignore();
	this->maxBrStvari += *broj;
}

int Ostava::getMaxBrStvari() {
	return this->maxBrStvari;
}

vector<Stvar>& Ostava::getStvari() {
	return this->stvari;
}

void Ostava::spremiStvar() {
	if (this->getMaxBrStvari() == Stvar::brStvari) {
		cout << "Ostava je puna!\n";
	}
	else {
		Stvar temp;
		temp.unesiStvar();
		bool ima = false;
		for (auto& i : this->stvari) {
			if (strcmpi(i.getNaziv(), temp.getNaziv()) == 0) {
				ima = true;
				if (temp.getKolicina() + Stvar::brStvari > this->getMaxBrStvari()) {
					cout << "Nije moguce spremiti " << temp.getKolicina() << " " << temp.getNaziv() << " u osatvu!\n";
					int slobodno = this->getMaxBrStvari() - Stvar::brStvari;
					i.povecajKolicinu(slobodno);
					cout << "Spremljeno je samo " << slobodno << " " << temp.getNaziv() << " u ostavu!\n";
					Stvar::brStvari = this->getMaxBrStvari();
				}
				else {
					i.povecajKolicinu(temp.getKolicina());
					cout << "Spremljeno je " << temp.getKolicina() << " " << temp.getNaziv() << " u ostavu!\n";
					Stvar::brStvari += temp.getKolicina();
				}
				break;
			}
		}
		if (!ima) {
			if (temp.getKolicina() + Stvar::brStvari > this->getMaxBrStvari()) {
				cout << "Nije moguce spremiti " << temp.getKolicina() << " " << temp.getNaziv() << " u ostavu!\n";
				int viska = Stvar::brStvari + temp.getKolicina() - this->getMaxBrStvari();
				temp.smanjiKolicinu(viska);
				cout << "Spremljeno je samo " << viska << " " << temp.getNaziv() << " u ostavu!\n";
				this->getStvari().push_back(temp);
				Stvar::brStvari = this->getMaxBrStvari();
			}
			else {
				this->getStvari().push_back(temp);
				cout << "Spremljeno je " << temp.getKolicina() << " " << temp.getNaziv() << " u osatvu!\n";
				Stvar::brStvari += temp.getKolicina();
			}
		}
	}
}

void Ostava::uzmiStvar() {
	if (this->stvari.size() == 0) {
		cout << "Ostava je prazna!\n";
	}
	else {
		this->ispisOstave();
		char stvar[50];
		cout << "Unesite stvar za uzeti: ";
		cin.getline(stvar, 50);
		bool ima = false;
		for (int i = 0; i < this->stvari.size(); i++) {
			if (strcmpi(this->stvari[i].getNaziv(), stvar) == 0) {
				ima = true;
				int kol;
				do {
					cout << "Unesite kolicinu za uzeti: ";
					cin >> kol;
				} while (kol<1 || kol>this->stvari[i].getKolicina());
				this->stvari[i].smanjiKolicinu(kol);
				Stvar::brStvari -= kol;
				if (this->stvari[i].getKolicina() == 0) {
					this->stvari.erase(this->stvari.begin() + i);
				}
				break;
			}
		}
		if (!ima) {
			cout << stvar << " ne postoji u ostavi\n";
		}
	}
}

void Ostava::ispisOstave() {
	if (this->stvari.size() == 0) {
		cout << "Ostava je prazna!\n";
	}
	else {
		cout << "Stvar\t\tKolicina\n";
		cout << "--------------------------------\n";
		for (auto& i : this->stvari) {
			cout << i.getNaziv() << "\t\t" << i.getKolicina() << endl;
		}
		cout << "--------------------------------\n";
		cout << "Ukupno:\t\t" << Stvar::brStvari << "\\" << this->getMaxBrStvari() << endl;
	}
}

void Ostava::pretragaStvari() {
	if (this->stvari.size() == 0) {
		cout << "Ostava je prazna!\n";
	}
	else {
		this->ispisOstave();
		char stvar[50];
		cout << "Unesite stvar za pretragu: ";
		cin.getline(stvar, 50);
		bool ima = false;
		for (int i = 0; i < this->stvari.size(); i++) {
			if (strcmpi(this->stvari[i].getNaziv(), stvar) == 0) {
				ima = true;
				cout << "U ostavi ima " << this->stvari[i].getKolicina() << " " << stvar << endlM
					break;
			}
		}
		if (!ima) {
			cout << "Nije pronadjena " << stvar << " u ostavi!\n";
		}
	}
}