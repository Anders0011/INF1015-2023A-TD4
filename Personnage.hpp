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
    virtual void changerCouleur(ostream& os, const string& couleur) override {
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
    const string& getNom() const { return nom_; };
    const string& getTitre() const { return titre_; };
private:
    string nom_;
    string titre_;
};