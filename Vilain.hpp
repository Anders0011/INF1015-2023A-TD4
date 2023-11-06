/*
Fichier : Vilain.hpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier Vilain.hpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/


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