#ifndef POKEMON_AQUATICO_H
#define POKEMON_AQUATICO_H

#include "Pokemon.hpp"

class PokemonAquatico : public Pokemon {
    protected: 
        double _litros_jato;
    public:
        PokemonAquatico(const std::string, const std::string, const double, const double);
        virtual void falar_tipo_ataque() const override;
        const virtual double calcular_dano() const override;
        const double ataque_aquatico() const;
};



#endif