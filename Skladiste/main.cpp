#include <iostream>
#include "Ostava.h"
int glavniMeni() {
	int izbor;
	cout << "1. Unesi stvar\n";
	cout << "2. Uzmi stvar\n";
	cout << "3. Pretraga stvari\n";
	cout << "4. Ispis ostave\n";
	cout << "5. Kraj\n";
	do {
		cout << "Izbor: ";
		cin >> izbor;
	} while (izbor < 1 || izbor>5);
	cin.ignore();
	return izbor;
}

int main() {
	Ostava o;
	system("cls");
	int izbor;
	do {
		izbor = glavniMeni();
		switch (izbor) {
		case 1:
			o.spremiStvar();
			break;
		case 2:
			o.uzmiStvar();
			break;
		case 3:
			o.pretragaStvari();
			break;
		case 4:
			o.ispisOstave();
			break;
		default:
			break.
		}
	} while (izbor != 5);
}