#include "HeapInt.hpp"

HeapInt::HeapInt() : inteiro(new int(0)) {}

HeapInt::HeapInt(const int& n) : inteiro(new int(n)) {}

HeapInt::HeapInt(const HeapInt &copia) : inteiro(new int(copia.getInteiro())) {}

HeapInt::~HeapInt() {
    delete inteiro;
}

const int HeapInt::getInteiro() const{
    return *(this->inteiro);
}

HeapInt& HeapInt::operator=(const int& copia) {
    *(this->inteiro) = copia;
    return *this;
}

HeapInt& HeapInt::operator=(const HeapInt& copia) {
    *(this->inteiro) = copia.getInteiro();
    return *this;
}

HeapInt HeapInt::operator+(const HeapInt& copia) const {
    HeapInt resultado(this->getInteiro() + copia.getInteiro());
    return resultado;
}
HeapInt HeapInt::operator-(const HeapInt& copia) const {
    HeapInt resultado(this->getInteiro() - copia.getInteiro());
    return resultado;
}

bool HeapInt::operator==(const HeapInt& copia) const {
    return this->getInteiro() == copia.getInteiro();
}   

std::ostream& operator<<(std::ostream& os, const HeapInt& copia) {
    return os << copia.getInteiro();
}

std::istream& operator>>(std::istream& is, HeapInt& copia) {
    return is >> *(copia.inteiro);
}