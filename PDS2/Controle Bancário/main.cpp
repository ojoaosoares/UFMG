#include "Banco.hpp"

int main() {

    Banco *banco = new Banco();
    char comando;
    int valor, id, dest;
    string nome;

    while(1) {
        cin >> comando;
        
        if(comando == 'F') break;
        
        switch (comando) {
        case 'C':
            cin >> id >> nome;
            if(banco->criar_conta(id,nome)) cout << "Conta criada" << endl;
            else cout << "ERRO: conta repetida" << endl;
            break;
        case 'D':
            cin >> id >> valor;
            if(banco->pesquisa(id)) {
                banco->pesquisa(id)->deposito(valor);
                cout << "deposito efetuado" << endl;
            }

            else cout << "ERRO: conta inexistente" << endl;
            break;
        case 'S':
            cin >> id >> valor;
            if(banco->pesquisa(id)) {
                banco->pesquisa(id)->saque(valor);
                cout << "saque efetuado" << endl;
            }

            else cout << "ERRO: conta inexistente" << endl;
            break;
        case 'P': 
            cin >> id >> dest >> valor;
            if(banco->pesquisa(id) && banco->pesquisa(dest)) {
                banco->pesquisa(id)->pix(banco->pesquisa(dest),valor);
                cout << "pix efetuado" << endl;
            }

            else cout << "ERRO: conta inexistente" << endl;
            break;

        case 'I': 
            banco->lista_contas();
            break;

        default:
            break;
        }
    }



}