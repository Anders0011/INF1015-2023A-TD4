#pragma once
#include "Affichable.hpp"

class Personnage : virtual public Affichable
{
public:
    Personnage() = default;
    Personnage(string nom, string titre) : nom_(nom), titre_(titre) {}
    virtual void afficher(ostream& os) override {
        os << "Nom : " << nom_ << "\nParution : " << titre_ << endl;
    }
    //virtual void changerCouleur(ostream& os, const string& couleur) override;
    const string& getNom() const { return nom_; };
    const string& getTitre() const { return titre_; };
private:
    string nom_;
    string titre_;
};