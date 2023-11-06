/*
Fichier : VilainHeros.hpp
Auteurs : Elias Ladaa (2212727), Ayoub Issiakhem (2216575) et Anders Antoine (2252046)
Description : Le fichier VilainHeros.hpp du TD4 pour le cours de inf1015.
Date : Le 5 novembre 2023
*/


#pragma once
#include "Vilain.hpp"
#include "Heros.hpp"

class VilainHeros : public Vilain, public Heros
{
public:
    VilainHeros() = default;
    VilainHeros(const Vilain& vilain, const Heros& heros);
    virtual void afficher(ostream& os) override;
    virtual ~VilainHeros() = default;
private:
    Vilain vilain_;
    Heros heros_;
};