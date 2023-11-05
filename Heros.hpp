#pragma once
#include "Personnage.hpp"
#include <vector>

class Heros : virtual public Personnage
{
public:
    Heros() = default;
    Heros(string nom, string titre, string ennemi, vector<string> liste) :
        Personnage(nom, titre), ennemi_(ennemi), listeAllies_(liste)
        {}
    virtual void afficher(ostream& os) override {
        Personnage::afficher(os);
        os << "\nEnnemi : " << ennemi_ << "\nAlliés : \n";
        for (int i = 0; i < listeAllies_.size(); i++)
            os << "\t" << listeAllies_[i] << "\n";
    }
    //virtual void changerCouleur(ostream& os, const string& couleur) override;
    const string& getEnnemi() const { return ennemi_; };
    const vector<string> getListeAllies() const { return listeAllies_; };
private:
	vector<string> listeAllies_;
	string ennemi_;
};