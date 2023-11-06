/*
Fichier : VilainHeros.cpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier  VilainHeros.cpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/

#include <iostream>
#include "VilainHeros.hpp"

 VilainHeros::VilainHeros(const Vilain& vilain, const Heros& heros) :
        vilain_(vilain), heros_(heros)
        {}

void VilainHeros::afficher(ostream& os) {
	 os << "Nom : " << vilain_.getNom() << "-" << heros_.getNom() <<
		 "\nParution : " << vilain_.getTitre() << "-" << heros_.getTitre() <<
		 "\nObjectif : " << vilain_.getObjectif() <<
		 "\nEnnemi : " << heros_.getEnnemi() << "\nAlliés : \n";
	 for (int i = 0; i < heros_.getListeAllies().size(); i++)
		 os << "\t" << heros_.getListeAllies()[i] << "\n";
	 os << "Mission spéciale : " << vilain_.getObjectif() + "\ndans le monde de " + heros_.getTitre() << endl;
 }
