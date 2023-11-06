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
	 os << "Mission spéciale : " << vilain_.getObjectif() + " dans le monde de\n" + heros_.getTitre() << endl;
 }
