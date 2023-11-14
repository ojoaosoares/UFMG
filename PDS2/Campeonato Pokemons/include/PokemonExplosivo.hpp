#ifndef POKEMON_EXPLOSIVO_H
#define POKEMON_EXPLOSIVO_H

#include "Pokemon.hpp"

class PokemonExplosivo : public Pokemon {
    protected: 
        double _temperatura_explosao;
    public:
        PokemonExplosivo(const std::string, const std::string, const double, const double);
        virtual void falar_tipo_ataque() const override;
        const virtual double calcular_dano() const override;
        const double ataque_explosivo() const;
};



#endif