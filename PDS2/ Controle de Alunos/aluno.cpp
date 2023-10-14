#include "aluno.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

Aluno::Aluno(std::string nome, int matricula) {
    setNome(nome);
    setMatricula(matricula);
}

Aluno::~Aluno() {
    this->notas.clear();
}

int Aluno::getMatricula() {
    return this->numero_matricula;
}

std::string Aluno::getNome() {
    return this->nome;
}

void Aluno::setMatricula(int matricula) {
    this->numero_matricula = matricula;
}


void Aluno::setNome(std::string nome) {
    this->nome = nome;
}

void Aluno::adicionarNota(int nota) {
    this->notas.push_back(nota);
}

void Aluno::imprimirNotas() {
    for (std::vector<int>::iterator it = this->notas.begin(); it != this->notas.end(); it++) 
        std::cout << *it << " " ;
    std::cout << std::endl;
    
}

float Aluno::calcularMediaNotas() {
    float somatorio = 0;
    for (std::vector<int>::iterator it = this->notas.begin(); it != this->notas.end() ; it++)
        somatorio += *it;
    
    return somatorio/notas.size();
}

int Aluno::retornarNotaMaxima() {
    
    return *std::max_element(this->notas.begin(),this->notas.end());
}

void Aluno::imprimirResumo() {
    
    std::cout << this->getMatricula() << " " <<this->getNome() << " ";
    this->imprimirNotas();
    std::cout <<  std::fixed << std::setprecision(2) << this->calcularMediaNotas() << " " << this->retornarNotaMaxima() << std::endl;
}