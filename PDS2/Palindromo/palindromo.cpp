#include <iostream>
#include <string>

int palindromo(std::string s) {
    int i = 0, j = s.length() - 1;

    while(i < j) 
        if(s[i++] != s[j--]) return 0;
    
    return 1;

}

int main() {

    std::string palavra;
    std::getline (std::cin,palavra);

    
    if(palindromo(palavra)) std::cout << "SIM";
    else std::cout << "NAO";

}