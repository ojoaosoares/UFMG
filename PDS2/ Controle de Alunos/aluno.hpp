#ifndef ALUNO_H
#define ALUNO_H
#include <string>
#include <vector>

class Aluno {
    private:
        std::string nome;
        int numero_matricula;
        std::vector<int> notas;
    public:
        Aluno(std::string nome, int matricula);
        ~Aluno();
        int getMatricula();
        std::string getNome();
        void setNome(std::string nome);
        void setMatricula(int matricula);
        void adicionarNota(int nota);
        void imprimirNotas();
        float calcularMediaNotas();
        int retornarNotaMaxima();
        void imprimirResumo();
        

};



#endif
