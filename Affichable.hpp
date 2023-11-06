/*
Fichier : Affichable.hpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier Affichable.hpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/


#pragma once
#include <iostream>
#include <string>
using namespace std;


class Affichable
{
public:
	~Affichable() {};
	virtual void afficher(ostream& os) = 0;
	virtual void changerCouleur(ostream& os, const string& couleur) = 0;
};