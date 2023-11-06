/*
Fichier : Heros.hpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier Heros.hpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/


#pragma once
#include "Personnage.hpp"
#include <vector>

class Heros : virtual public Personnage
{
public:
    Heros() = default;
    Heros(string nom, string titre, string ennemi, vector<string> liste);
    virtual void afficher(ostream& os) override;
    const string& getEnnemi() const;
    const vector<string> getListeAllies() const;
private:
	vector<string> listeAllies_;
	string ennemi_;
};