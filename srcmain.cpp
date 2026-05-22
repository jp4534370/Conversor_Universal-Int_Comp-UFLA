#include <iostream>
#include <string>
#include "parser.hpp"
#include "srcconversor.hpp"

using namespace std;

int main() {
    int opcao = 0;

    while (opcao != 3) {
        cout << "1. Fazer uma conversao de base" << endl;
        cout << "2. Ver os maiores valores possiveis (F10)" << endl;
        cout << "3. Sair do programa" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        
        if (opcao == 1) {
            string texto_digitado;
            int base_de_origem, base_de_destino;
            
            cout << "Digite o valor inteiro: ";
            cin >> texto_digitado;

            cout << "Qual a base desse valor? (2, 8, 10, 16): ";
            cin >> base_de_origem;

            cout << "Para qual base quer converter? (2, 8, 10, 16): ";
            cin >> base_de_destino;
            
            // Validação usando o módulo parser
            if (!Texto_e_valido(texto_digitado, base_de_origem)) {
                cout << "Voce digitou expressoes invalidas para conversao!" << endl << endl;
                continue;
            }
            
            string Resultado_final = "";
            
            // Conversões diretas e indiretas usando o módulo conversor
            if (base_de_origem == 2 && base_de_destino == 8) {
                Resultado_final = binario_para_octal(texto_digitado);
            } 
            else if (base_de_origem == 2 && base_de_destino == 16) {
                Resultado_final = binario_para_hexadecimal(texto_digitado);
            } 
            else if (base_de_origem == 8 && base_de_destino == 2) {
                Resultado_final = octal_para_binario(texto_digitado);
            } 
            else if (base_de_origem == 16 && base_de_destino == 2) {
                Resultado_final = hexadecimal_para_binario(texto_digitado);
            } 
            else if (base_de_origem == 8 && base_de_destino == 16) {
                string texto_binario_ponte = octal_para_binario(texto_digitado);
                Resultado_final = binario_para_hexadecimal(texto_binario_ponte);
            } 
            else if (base_de_origem == 16 && base_de_destino == 8) {
                string texto_binario_ponte = hexadecimal_para_binario(texto_digitado);
                Resultado_final = binario_para_octal(texto_binario_ponte);
            } 
            else {
                int numero_decimal = 0;
                
                if (base_de_origem == 10) {
                    for(int i = 0; i < (int)texto_digitado.size(); i++) {
                        numero_decimal = (numero_decimal * 10) + (texto_digitado[i] - '0');
                    }
                } 
                else {
                    numero_decimal = Outra_base_para_decimal(texto_digitado, base_de_origem);
                }
                
                if (base_de_destino == 10) {
                    cout << endl << "Resultado Final : " << numero_decimal << endl << endl;
                    continue;
                } 
                else {
                    Resultado_final = Decimal_para_outra_base(numero_decimal, base_de_destino);
                }
            }
            
            cout << endl << "Resultado Final : " << Resultado_final << endl << endl;
            
        } 
        else if (opcao == 2) {
            int bits;
            cout << "Digite a quantidade de bits: ";
            cin >> bits;
            Maior_valor_possivel(bits);
        }
    }

    return 0;
}