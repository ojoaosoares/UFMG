#ifndef HEAPINT_HPP
#define HEAPINT_HPP

#include <iostream>

class HeapInt
{
private:
    int* inteiro;
public:
    // Construtores
    HeapInt();
    HeapInt(const int& n);
    HeapInt(const HeapInt &copia);
    // Destrutor
    ~HeapInt();

    //Metodos
    const int getInteiro() const;

    // Sobrecarga de operadores;
    HeapInt& operator=(const int& copia);
    HeapInt& operator=(const HeapInt& copia);
    HeapInt operator+(const HeapInt& copia) const;
    HeapInt operator-(const HeapInt& copia) const;
    bool operator==(const HeapInt& copia) const;
    friend std::istream& operator>>(std::istream& i, HeapInt& inteiro);    
    

};


std::ostream& operator<<(std::ostream& o, const HeapInt& inteiro);



#endif