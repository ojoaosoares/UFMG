#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>


class Pokemon {
    protected:
        std::string _nome;
        std::string _tipo_ataque;
        double _forca_ataque; 
        double _energia;
    public:
        Pokemon(const std::string, const std::string, const double);
        virtual ~Pokemon();
        const std::string getNome() const;
        const std::string getTipoAtaque() const;
        const double getForcaAtaque() const;
        const double getErnegia() const;
        void falar_nome() const;
        virtual void falar_tipo_ataque() const;
        void imprimir_status() const;
        void imprimir_informacoes() const;
        const virtual double calcular_dano() const = 0;
        void atacar(Pokemon* ) const;
        void receber_dano(double );
};







#endif