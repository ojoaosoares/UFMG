#ifndef POKEMON_ELETRICO_H
#define POKEMON_ELETRICO_H

#include "Pokemon.hpp"

class PokemonEletrico : public Pokemon {
    protected: 
        double _potencia_raio;
    public:
        PokemonEletrico(const std::string, const std::string, const double, const double);
        virtual void falar_tipo_ataque() const override;
        const virtual double calcular_dano() const override;
        const double ataque_eletrico() const;
};



#endif