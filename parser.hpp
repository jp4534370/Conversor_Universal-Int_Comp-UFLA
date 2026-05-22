#ifndef PARSER_HPP
#define PARSER_HPP

#include <string>

// Transforma um caractere no seu valor numerico de 0 a 15
int Valor_do_caractere(char letra);

// Checa se todos os digitos sao validos para essa base
bool Texto_e_valido(std::string texto, int base);

#endif