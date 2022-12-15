#pragma once
#include "Stvar.h"
#include <vector>

class Ostava {
private:
	vector<Stvar> stvari;
	int maxBrStvari;

public:
	Ostava();
	void setMaxBrStvari();
	int getMaxBrStvari();
	vector<Stvar>& getStvari();
	void spremiStvar();
	void uzmiStvar();
	void ispisOstave();
	void pretragaStvari();
	~Ostava() = default;
};