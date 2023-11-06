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
