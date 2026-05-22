#ifndef CONVERSOR_HPP
#define CONVERSOR_HPP

#include <string>

char Letra_ou_numero(int numero);
std::string Decimal_para_outra_base(int numero_decimal, int base_destino);
int Outra_base_para_decimal(std::string texto, int base_origem);
std::string binario_para_octal(std::string binario);
std::string binario_para_hexadecimal(std::string binario);
std::string octal_para_binario(std::string octal);
std::string hexadecimal_para_binario(std::string hexadecimal);
void Maior_valor_possivel(int total_bits);

#endif