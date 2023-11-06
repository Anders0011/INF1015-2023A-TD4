#pragma once
#include "Personnage.hpp"

class Vilain : virtual public Personnage
{
public:
    Vilain() = default;
    Vilain(string nom, string titre, string objectif) :
		Personnage(nom, titre), objectif_(objectif) 
		{}
	virtual void afficher(ostream& os) override {
		Personnage::afficher(os);
		os << "\nObjectif : " << objectif_ << endl;
	}
	const string& getObjectif() const { return objectif_; };
private:
	string objectif_;
};