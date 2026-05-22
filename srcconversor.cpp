#include "srcconversor.hpp"
#include "parser.hpp"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
int Valor_do_caractere(char letra);


char Letra_ou_numero(int numero) {
    if (numero >= 0 && numero <= 9) {
        return '0' + numero;
    }
    return 'A' + (numero - 10);
}

string Decimal_para_outra_base(int numero_decimal, int base_destino) {
    if (numero_decimal == 0) {
        return "0";
    }
    
    string resultado = "";
    cout << endl << "Divisoes sucessivas (Base 10 para base " << base_destino << ")" << endl;
    
    while (numero_decimal > 0) {
        int resto = numero_decimal % base_destino;
        int quociente = numero_decimal / base_destino;
        
        cout << numero_decimal << " a dividir por " << base_destino 
             << " da " << quociente << " com Resto: " << Letra_ou_numero(resto) << endl;
        
        resultado = Letra_ou_numero(resto) + resultado;
        numero_decimal = quociente;
    }
    return resultado;
}

int Outra_base_para_decimal(string texto, int base_origem) {
    int total_decimal = 0;
    int expoente = 0;
    
    cout << endl << "Somatorio posicional (Para Base 10) " << endl;
    for (int i = texto.size() - 1; i >= 0; i--) {
        int valor_do_digito = Valor_do_caractere(texto[i]);
        int resultado_da_potencia = pow(base_origem, expoente);
        int parcela = valor_do_digito * resultado_da_potencia;
        
        total_decimal = total_decimal + parcela;
        
        cout << valor_do_digito << " * " << base_origem << "^" << expoente 
             << " = " << parcela << endl;
             
        expoente = expoente + 1;
    }
    return total_decimal;
}

string binario_para_octal(string binario) {
    while (binario.size() % 3 != 0) {
        binario = "0" + binario;
    }
    string resultado = "";
    for (int i = 0; i < (int)binario.size(); i = i + 3) {
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
    for (int i = 0; i < (int)binario.size(); i = i + 4) {
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
    for (int i = 0; i < (int)octal.size(); i++) {
        int valor = octal[i] - '0';
        
        resultado += ((valor >> 2) & 1) == 1 ? "1" : "0";
        resultado += ((valor >> 1) & 1) == 1 ? "1" : "0";
        resultado += (valor & 1) == 1 ? "1" : "0";
    }
    return resultado;
}

string hexadecimal_para_binario(string hexadecimal) {
    string resultado = "";
    for (int i = 0; i < (int)hexadecimal.size(); i++) {
        int valor = Valor_do_caractere(hexadecimal[i]);
        
        resultado += ((valor >> 3) & 1) == 1 ? "1" : "0";
        resultado += ((valor >> 2) & 1) == 1 ? "1" : "0";
        resultado += ((valor >> 1) & 1) == 1 ? "1" : "0";
        resultado += (valor & 1) == 1 ? "1" : "0";
    }
    return resultado;
}

void Maior_valor_possivel(int total_bits) {
    long long maximo_decimal = pow(2, total_bits) - 1;
    cout << endl << "[F10] Maior valor com " << total_bits << " bits:" << endl;
    cout << "Decimal:     " << maximo_decimal << endl;
    
    long long sobra_octal = maximo_decimal;
    string texto_octal = "";
    while(sobra_octal > 0) {
        texto_octal = Letra_ou_numero(sobra_octal % 8) + texto_octal;
        sobra_octal = sobra_octal / 8;
    }
    cout << "Octal:       " << (texto_octal.empty() ? "0" : texto_octal) << endl;
    
    long long sobra_hex = maximo_decimal;
    string texto_hex = "";
    while(sobra_hex > 0) {
        texto_hex = Letra_ou_numero(sobra_hex % 16) + texto_hex;
        sobra_hex = sobra_hex / 16;
    }
    cout << "Hexadecimal: " << (texto_hex.empty() ? "0" : texto_hex) << endl << endl;
}