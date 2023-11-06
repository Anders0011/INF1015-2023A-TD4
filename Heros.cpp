/*
Fichier : Heros.cpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier  Heros.cpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/



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
