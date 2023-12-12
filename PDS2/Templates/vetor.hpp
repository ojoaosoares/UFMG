#ifndef VETOR_HPP
#define VETOR_HPP

#include <stdexcept>
#include <iostream>


template<typename T> class Vetor {
    
    private:
        int size, ultima_posicao;
        T * array;

    public:
        Vetor(int n) : size(n), ultima_posicao(0), array(new T[size]) {}

        Vetor(Vetor& copia) : size(copia.getSize()), ultima_posicao(size -1), array(new T[size]) {
            
            for (int i = 0; i < size; i++)
                array[i] = copia.array[i];
        }

        ~Vetor() {
            delete[] array;
        }

        const int getSize() const {
            return this->size;
        }


        const void SetElemento(int x, T item) {
            array[x] = item;
        }

        const T GetElemento(int x) const {
            return array[x];
        }

        const void AdicionaElemento (T item) {
            SetElemento(ultima_posicao++,item);
        }

        void Imprime() {

            for (int i = 0; i < size; i++)
                std::cout << GetElemento(i) << " ";
        
            std::cout << std::endl;
        }



};


#endif