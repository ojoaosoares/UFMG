#include "aluno.hpp"
#include <iostream>
#include <list>
#include <limits>
#include <string>

using namespace std;

bool comparaAlunosPorNome(Aluno& aluno1, Aluno& aluno2) {
    return aluno1.getNome() < aluno2.getNome();
}

int main() {

    list <Aluno> alunos;
    string nome;
    int matricula, nota;

    while (true)
    {
        getline(cin,nome);
        if(nome == "END") break;
        cin >>  matricula;
        Aluno aluno(nome,matricula);

        while (true)
        {   
            cin >> nota;
            if(nota == - 1) break;
            aluno.adicionarNota(nota);
        }   
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        alunos.push_back(aluno);
    }
    
    alunos.sort(comparaAlunosPorNome);
    for (list<Aluno>::iterator it = alunos.begin(); it != alunos.end(); it++)
        it->imprimirResumo();
    
}