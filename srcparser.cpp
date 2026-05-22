#define PARSER_CPP
#include <string>
using namespace std;

int Valor_do_caractere(char letra) {
    if (letra >= 'a' and letra <= 'z') {
        letra = letra - 32; 
    }
    if (letra >= '0' and letra <= '9') {
        return letra - '0';
    }
    if (letra >= 'A' and letra <= 'F') {
        return letra - 'A' + 10;
    }
    return -1; // Caractere nao valido
}

bool Texto_e_valido(string texto, int base) {
    for (int i = 0; i < (int)texto.size(); i++) {
        char caractere = texto[i];
        int valor = Valor_do_caractere(caractere);
        
        if (valor == -1 or valor >= base) {
            return false;
        }
    }
    return true;
}