#pragma once
#include "Personnage.hpp"

class Vilain : virtual public Personnage
{
public:
    Vilain() = default;
	Vilain(string nom, string titre, string objectif);
	virtual void afficher(ostream& os) override;
	const string& getObjectif() const;
private:
	string objectif_;
};