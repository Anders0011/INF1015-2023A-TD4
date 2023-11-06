#include <iostream>
#include "Personnage.hpp"

Personnage::Personnage(string nom, string titre) : nom_(nom), titre_(titre) {}

void Personnage::afficher(ostream& os) {
	os << "Nom : " << nom_ << "\nParution : " << titre_ << endl;
}

void Personnage::changerCouleur(ostream& os, const string& couleur) {
	if (couleur == "Rouge")
		os << "\033[91m";
	else if (couleur == "Bleu")
		os << "\033[94m";
	else if (couleur == "Magenta")
		os << "\033[95m";
	else if (couleur == "Vert")
		os << "\033[92m";
	else
		os << "\033[0m";
}

const string& Personnage::getNom() const { 
	return nom_; 
}

const string& Personnage::getTitre() const { 
	return titre_; 
}

