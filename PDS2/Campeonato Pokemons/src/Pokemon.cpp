#include "Pokemon.hpp"

Pokemon::Pokemon(const std::string nome, const std::string tipo_ataque, const double forca_ataque) : 
_nome(nome), _tipo_ataque(tipo_ataque),_forca_ataque(forca_ataque), _energia(100) {}

Pokemon::~Pokemon() {}

const std::string Pokemon::getNome() const {
    return this->_nome;
}

const std::string Pokemon::getTipoAtaque() const {
    return this->_tipo_ataque;
}

const double Pokemon::getForcaAtaque() const {
    return this->_forca_ataque;
}

const double Pokemon::getErnegia() const {
    return this->_energia;
}

void Pokemon::falar_nome() const {
    std::cout << this->getNome() << "!" << std::endl;
}

void Pokemon::falar_tipo_ataque() const {
    std::cout << this->getTipoAtaque() << "!" << std::endl;
}

void Pokemon::imprimir_status() const {
    this->falar_nome();
    std::cout << "Energia: " << this->getErnegia() << std::endl;
}

void Pokemon::imprimir_informacoes() const {
    std::cout << "Pokemon: " << this->getNome() << std::endl;
    std::cout << "Tipo ataque: " << this->getTipoAtaque() << std::endl;
    std::cout << "Dano: " << this->calcular_dano() << std::endl;
    std::cout << "Energia: " << this->getErnegia() << std::endl;
}

void Pokemon::atacar(Pokemon* outro_pokemon) const {
    this->falar_nome();
    this->falar_tipo_ataque();
    double dano = calcular_dano();
    std::cout << "Dano: " << dano << std::endl;
    outro_pokemon->receber_dano(dano);
}


void Pokemon::receber_dano(double valor_dano) {
    
    if(valor_dano >= this->getErnegia()) {
        std::cout << this->getNome() << " morreu!" << std::endl;
        this->_energia = 0;
    }

    else this->_energia = this->getErnegia() - valor_dano;
}