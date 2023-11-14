#include <iostream>
#include <list>
#include <iterator>

const char ADICIONAR = 'A';
const char REMOVER = 'R';
const char CONTADOR = 'C';
const char PESQUISAR = 'P';
const char IMPRIMIR_TODOS_ELEMENTOS= 'L';
const char FINALIZAR = 'E';

class Object {
    
    private:
        static int numero_objetos;
        static int proximo_id;
        int id;
    
    public:
        static int getNumeroObjetos();
        Object();
        ~Object();
        int getId();
        Object * getEndereco();
        void ImprimirInformacoes();
        
};

int Object::numero_objetos = 0;
int Object::proximo_id = 1;

int Object::getNumeroObjetos() {
    return Object::numero_objetos;
}

Object::Object(): id(Object::proximo_id++) {
    Object::numero_objetos++;
}

Object::~Object() {
    Object::numero_objetos--;
}

int Object::getId() {
    return this->id;
}

Object * Object::getEndereco() {
    return this;
}

void Object::ImprimirInformacoes() {
    std::cout << this->getId() << " " << this->getEndereco() << std::endl;
}



int main() {

    char comando;
    std::list<Object*> lista_objetos;
    while (true) {

        std::cin >> comando;

        if(comando == FINALIZAR) break;
        
        if(comando == ADICIONAR) {
            Object * novo_objeto = new Object;
            lista_objetos.push_back(novo_objeto);
            novo_objeto->ImprimirInformacoes();
        }

        if(comando == REMOVER) {

            Object * ponteiro = (*lista_objetos.begin());

            if(ponteiro == nullptr) std::cout << "ERRO" << std::endl;
            
            else {
                ponteiro->ImprimirInformacoes();
                delete (ponteiro);
                lista_objetos.pop_front();
            }
        }

        if(comando == CONTADOR) std::cout << Object::getNumeroObjetos() << std::endl;
        
        if(comando == PESQUISAR) {
            
            int indice_objeto;
            std::cin >> indice_objeto;

            if(indice_objeto < 1 || indice_objeto > lista_objetos.size()) std::cout << "ERRO" << std::endl;

            else {
                std::list<Object*>::iterator it = lista_objetos.begin();

                for (int i = 1;  i < indice_objeto; i++)
                    it++;

                (*it)->ImprimirInformacoes();
            }
            
        }

        if (comando == IMPRIMIR_TODOS_ELEMENTOS)
            for (std::list<Object*>::iterator it = lista_objetos.begin(); it != lista_objetos.end() ; it++)
                (*it)->ImprimirInformacoes();
    }
}
