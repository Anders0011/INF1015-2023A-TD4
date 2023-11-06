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