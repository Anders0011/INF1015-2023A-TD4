/*
Fichier : Vilain.cpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier  Vilain.cpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/

#include <iostream>
#include "Vilain.hpp"

Vilain::Vilain(string nom, string titre, string objectif) :
	Personnage(nom, titre), objectif_(objectif)
{}

void Vilain::afficher(ostream& os) {
	Personnage::afficher(os);
	os << "\nObjectif : " << objectif_ << endl;
}

const string& Vilain::getObjectif() const { return objectif_; };
