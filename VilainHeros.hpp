#pragma once
#include "Vilain.hpp"
#include "Heros.hpp"

class VilainHeros : public Vilain, public Heros
{
public:
    VilainHeros() = default;
    VilainHeros(const Vilain& vilain, const Heros& heros) :
        vilain_(vilain), heros_(heros)
        {}
    virtual void afficher(ostream& os) override {
        os << "Nom : " << vilain_.getNom() << "-" << heros_.getNom() <<
            "\nParution : " << vilain_.getTitre() << " - " << heros_.getTitre() <<
            "\nObjectif : " << vilain_.getObjectif() << 
            "\nEnnemi : " << heros_.getEnnemi() << "\nAlliés : \n";
            for (int i = 0; i < heros_.getListeAllies().size(); i++)
                os << "\t" << heros_.getListeAllies()[i] << "\n";
            os << "Mission spéciale : " << getMission() << endl;
    }
    const string& getMission() const { 
        return vilain_.getObjectif() + " dans le monde de " + heros_.getTitre(); 
    }
    virtual ~VilainHeros() = default;
private:
    Vilain vilain_;
    Heros heros_;
};