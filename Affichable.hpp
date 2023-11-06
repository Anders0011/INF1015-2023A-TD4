#pragma once
#include <iostream>
#include <string>
using namespace std;


class Affichable
{
public:
	//Affichable() = default;
	~Affichable() {};
	virtual void afficher(ostream& os) = 0;
	virtual void changerCouleur(ostream& os, const string& couleur) = 0;
	//friend ostream& operator<< (ostream& os, const Affichable& affichage);
};