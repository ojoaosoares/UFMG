#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define NUMBERS_START 48
#define NUMBERS_END 57
#define LOWER_ALPHABET_START 97
#define LOWER_ALPHABET_END 122

using namespace std;


bool is_alphanumeric(char c) {
    if(((c >= NUMBERS_START  && c <= NUMBERS_END) || (c >= NUMBERS_END  && c <= LOWER_ALPHABET_END))) return true;
    return false;
}

int main() {
    string frase;
    getline (cin,frase);
    vector<string> palavras;
    map <string, int> quantidade_palavras;
    
    int start = 0, end = 0;
    
    
    bool trocar = false;

 
    for (string::iterator it = frase.begin(); it != frase.end(); it++) {
        
        frase[end] = tolower(frase[end]);

        if(!is_alphanumeric(frase[end]) && !trocar) {
            palavras.push_back(frase.substr(start,(end - start)));
            trocar =  true;
        }

        else if(is_alphanumeric(frase[end]) && trocar) {
            start = end;
            trocar = false;
        }   

        else if((it + 1) == frase.end()) 
            palavras.push_back(frase.substr(start,(end - start)));
        


        end++;
    }

    for (string palavra : palavras) 
        if(quantidade_palavras.find(palavra) == quantidade_palavras.end()) {
            quantidade_palavras[palavra] = count(palavras.begin(),palavras.end(),palavra);
        }

    
    for (map<string,int>::iterator it = quantidade_palavras.begin(); it != quantidade_palavras.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
       
    


    
}