#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {

    map<int,map<int, string>> logs;
    map <int, string> log_diario;
    string comando;
    int dia= 1, id_log =0;


    while (true)
    {
        cin >> comando;

        if(comando == "END") {
            break;
        } 
        else if(comando == "LOG") {
            logs.insert(pair<int,map<int,string>>(dia,log_diario));
            log_diario.clear();
            dia++;
            id_log = 0;
        }

        else if(comando == "DEL") {
            log_diario.clear();
            id_log = 0;
        }
            

        else if(comando == "CLS") {
            logs.clear();
            dia = 1;
            id_log = 0;
        }

        else
            log_diario[id_log++] = comando;
               
    }

    map<int,map<int, string>>::iterator it;
    map <int, string>::iterator usuarios;
    for (it = logs.begin(); it != logs.end(); it++) {
        cout << it->first << " " << it->second.size() << " ";
        for (usuarios = it->second.begin(); usuarios != it->second.end(); usuarios++)
            cout << usuarios->second << " ";

        
        cout << endl;
        
    }
    
    
}