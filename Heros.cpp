#include <iostream>
#include "Heros.hpp"

Heros::Heros(string nom, string titre, string ennemi, vector<string> liste) :
	Personnage(nom, titre), ennemi_(ennemi), listeAllies_(liste)
{}

void Heros::afficher(ostream& os)  {
	Personnage::afficher(os);
	os << "\nEnnemi : " << ennemi_ << "\nAlliés : \n";
	for (int i = 0; i < listeAllies_.size(); i++)
		os << "\t" << listeAllies_[i] << "\n";
}

const string& Heros::getEnnemi() const { 
	return ennemi_; 
}

const vector<string> Heros::getListeAllies() const { 
	return listeAllies_; 
}
