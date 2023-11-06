/*
Fichier : Personnage.hpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier Personnage.hpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/


#pragma once
#include "Affichable.hpp"

class Personnage : virtual public Affichable
{
public:
    Personnage() = default;
    Personnage(string nom, string titre);
    virtual void afficher(ostream& os) override;
    virtual void changerCouleur(ostream& os, const string& couleur) override;
    const string& getNom() const;
    const string& getTitre() const;
private:
    string nom_;
    string titre_;
};