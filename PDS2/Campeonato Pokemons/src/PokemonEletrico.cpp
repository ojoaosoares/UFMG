#include "PokemonEletrico.hpp"

PokemonEletrico::PokemonEletrico(const std::string nome, const std::string tipo_ataque, const double forca_ataque, const double potencia_raio) : 
Pokemon::Pokemon(nome, tipo_ataque, forca_ataque), _potencia_raio(potencia_raio) {}

void PokemonEletrico::falar_tipo_ataque() const {
    Pokemon::falar_tipo_ataque();
    std::cout << "Bzzzz!" << std::endl;
}

const double PokemonEletrico::calcular_dano() const {
    return this->ataque_eletrico();
}

const double PokemonEletrico::ataque_eletrico() const {
    return this->_forca_ataque * this->_potencia_raio;
}