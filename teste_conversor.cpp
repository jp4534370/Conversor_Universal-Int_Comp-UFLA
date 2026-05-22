#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <cstdlib>

using namespace std;

char Letra_ou_numero(int numero) {
    if (numero >= 0 and numero <= 9) {
        return '0' + numero;
    }
    return 'A' +(numero - 10);
}

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
    return -1;
}

bool Texto_e_valido(string texto, int base) {
    for (int i = 0; i <(int) texto.size(); i++) {
        char caractere = texto[i];
        int valor = Valor_do_caractere(caractere);
        if (valor == -1 or valor >= base) {
            return false;
        }
    }
    return true;
}

string Decimal_para_outra_base(int numero_decimal, int base_destino) {
    if (numero_decimal == 0) {
        return "0";
    }
    string resultado = "";
    while (numero_decimal > 0) {
        int resto = numero_decimal % base_destino;
        int quociente = numero_decimal / base_destino;
        resultado = Letra_ou_numero(resto) + resultado;
        numero_decimal = quociente;
    }
    return resultado;
}

int Outra_base_para_decimal(string texto, int base_origem) {
    int total_decimal = 0;
    int expoente = 0;
    for (int i = texto.size() - 1; i >= 0; i--) {
        int valor_do_digito = Valor_do_caractere(texto[i]);
        int resultado_da_potencia = pow(base_origem, expoente);
        int parcela = valor_do_digito * resultado_da_potencia;
        total_decimal = total_decimal + parcela;
        expoente = expoente + 1;
    }
    return total_decimal;
}

string binario_para_octal(string binario) {
    while (binario.size() % 3 != 0) {
        binario = "0" + binario;
    }
    string resultado = "";
    for (int i = 0; i <(int) binario.size(); i = i + 3) {
        int b2 = binario[i] - '0';
        int b1 = binario[i+1] - '0';
        int b0 = binario[i+2] - '0';
        int soma = (b2 * 4) + (b1 * 2) + b0;
        resultado = resultado + Letra_ou_numero(soma);
    }
    return resultado;
}

string binario_para_hexadecimal(string binario) {
    while (binario.size() % 4 != 0) {
        binario = "0" + binario;
    }
    string resultado = "";
    for (int i = 0; i <(int) binario.size(); i = i + 4) {
        int b3 = binario[i] - '0';
        int b2 = binario[i+1] - '0';
        int b1 = binario[i+2] - '0';
        int b0 = binario[i+3] - '0';
        int soma = (b3 * 8) + (b2 * 4) + (b1 * 2) + b0;
        resultado = resultado + Letra_ou_numero(soma);
    }
    return resultado;
}

string octal_para_binario(string octal) {
    string resultado = "";
    for (int i = 0; i <(int) octal.size (); i++) {
        int valor = octal[i] - '0';
        if (((valor >> 2) & 1) == 1) resultado += "1"; else resultado += "0";
        if (((valor >> 1) & 1) == 1) resultado += "1"; else resultado += "0";
        if ((valor & 1) == 1)        resultado += "1"; else resultado += "0";
    }
    return resultado;
}

string hexadecimal_para_binario(string hexadecimal) {
    string resultado = "";
    for (int i = 0; i <(int) hexadecimal.size() ; i++) {
        int valor = Valor_do_caractere(hexadecimal[i]);
        if (((valor >> 3) & 1) == 1) resultado += "1"; else resultado += "0";
        if (((valor >> 2) & 1) == 1) resultado += "1"; else resultado += "0";
        if (((valor >> 1) & 1) == 1) resultado += "1"; else resultado += "0";
        if ((valor & 1) == 1)        resultado += "1"; else resultado += "0";
    }
    return resultado;
}

int main() {
    cout << "Iniciando a suite de testes automatizados..." << endl;
    int testes_passados = 0;
    
    assert(Letra_ou_numero(5) == '0' + 5);                   
    assert(Letra_ou_numero(10) == 'A');                      
    assert(Letra_ou_numero(15) == 'F');                      
    assert(Valor_do_caractere('5') == 5);                    
    assert(Valor_do_caractere('a') == 10);                   
    assert(Valor_do_caractere('F') == 15);                   
    assert(Valor_do_caractere('G') == -1);                   
    testes_passados += 7;

    
    assert(Texto_e_valido("1010", 2) == true);               
    assert(Texto_e_valido("1020", 2) == false);              
    assert(Texto_e_valido("755", 8) == true);                
    assert(Texto_e_valido("785", 8) == false);               
    assert(Texto_e_valido("99", 10) == true);                
    assert(Texto_e_valido("1A3f", 16) == true);              
    assert(Texto_e_valido("1G3", 16) == false);              
    testes_passados += 7;
    
    assert(Decimal_para_outra_base(0, 2) == "0");            
    assert(Decimal_para_outra_base(13, 2) == "1101");        
    assert(Decimal_para_outra_base(64, 8) == "100");         
    assert(Decimal_para_outra_base(255, 16) == "FF");        
    testes_passados += 4;

    assert(Outra_base_para_decimal("1101", 2) == 13);        
    assert(Outra_base_para_decimal("100", 8) == 64);         
    assert(Outra_base_para_decimal("FF", 16) == 255);        
    assert(Outra_base_para_decimal("ff", 16) == 255);        
    testes_passados += 4;
    
    assert(binario_para_octal("111001") == "71");            
    assert(binario_para_octal("10") == "2");                 
    assert(octal_para_binario("71") == "111001");            
        
    assert(binario_para_hexadecimal("11111010") == "FA");    
    assert(binario_para_hexadecimal("1") == "1");            
    assert(hexadecimal_para_binario("FA") == "11111010");    
    assert(hexadecimal_para_binario("fa") == "11111010");    
    testes_passados += 7;

    string ponte_oct_hex = octal_para_binario("71"); 
    assert(binario_para_hexadecimal(ponte_oct_hex) == "0039"); 
    
    string ponte_hex_oct = hexadecimal_para_binario("FA");
    assert(binario_para_octal(ponte_hex_oct) == "372");      
    testes_passados += 2;
    
    assert(Decimal_para_outra_base(1234, 10) == "1234");    
    testes_passados += 1;
    
    cout << "===========================================" << endl;
    cout << " SUCESSO! Todos os " << testes_passados << " casos de teste passaram." << endl;
    cout << "===========================================" << endl;

    return 0;
}

