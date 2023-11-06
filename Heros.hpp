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