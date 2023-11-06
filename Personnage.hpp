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