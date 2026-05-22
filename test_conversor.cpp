#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include "srcconversor.hpp"
#include "parser.hpp"

static int total_testes = 0;
static int testes_passados = 0;

bool executar_teste(const std::string& nome, bool condicao) {
    int indice_teste = total_testes + 1;
    std::cout << "Executando teste " << indice_teste << ": " << nome << " ... ";
    ++total_testes;
    if (condicao) {
        ++testes_passados;
        std::cout << "OK\n";
        return true;
    }
    std::cout << "FALHA\n";
    return false;
}

std::string capturar_saida(const std::function<void()>& fn) {
    std::streambuf* old_buf = std::cout.rdbuf();
    std::ostringstream oss;
    std::cout.rdbuf(oss.rdbuf());
    fn();
    std::cout.rdbuf(old_buf);
    return oss.str();
}

int main() {
    // Valor_do_caractere
    executar_teste("Valor_do_caractere('0') == 0", Valor_do_caractere('0') == 0);
    executar_teste("Valor_do_caractere('A') == 10", Valor_do_caractere('A') == 10);
    executar_teste("Valor_do_caractere('F') == 15", Valor_do_caractere('F') == 15);
    executar_teste("Valor_do_caractere('a') == 10", Valor_do_caractere('a') == 10);

    // Texto_e_valido
    executar_teste("Texto_e_valido(1011, 2) == true", Texto_e_valido("1011", 2));
    executar_teste("Texto_e_valido(102, 2) == false", !Texto_e_valido("102", 2));
    executar_teste("Texto_e_valido(17, 8) == true", Texto_e_valido("17", 8));
    executar_teste("Texto_e_valido(8, 8) == false", !Texto_e_valido("8", 8));
    executar_teste("Texto_e_valido(1F, 16) == true", Texto_e_valido("1F", 16));
    executar_teste("Texto_e_valido(1g, 16) == false", !Texto_e_valido("1g", 16));

    // Decimal_para_outra_base
    {
        std::string resultado;
        capturar_saida([&](){ resultado = Decimal_para_outra_base(0, 2); });
        executar_teste("Decimal_para_outra_base(0, 2) == 0", resultado == "0");
    }
    {
        std::string resultado;
        capturar_saida([&](){ resultado = Decimal_para_outra_base(255, 16); });
        executar_teste("Decimal_para_outra_base(255, 16) == FF", resultado == "FF");
    }
    {
        std::string resultado;
        capturar_saida([&](){ resultado = Decimal_para_outra_base(73, 8); });
        executar_teste("Decimal_para_outra_base(73, 8) == 111", resultado == "111");
    }
    {
        std::string resultado;
        capturar_saida([&](){ resultado = Decimal_para_outra_base(42, 2); });
        executar_teste("Decimal_para_outra_base(42, 2) == 101010", resultado == "101010");
    }
    {
        std::string resultado;
        capturar_saida([&](){ resultado = Decimal_para_outra_base(16, 16); });
        executar_teste("Decimal_para_outra_base(16, 16) == 10", resultado == "10");
    }

    // Outra_base_para_decimal
    {
        int valor;
        capturar_saida([&](){ valor = Outra_base_para_decimal("101010", 2); });
        executar_teste("Outra_base_para_decimal(101010, 2) == 42", valor == 42);
    }
    {
        int valor;
        capturar_saida([&](){ valor = Outra_base_para_decimal("111", 8); });
        executar_teste("Outra_base_para_decimal(111, 8) == 73", valor == 73);
    }
    {
        int valor;
        capturar_saida([&](){ valor = Outra_base_para_decimal("FF", 16); });
        executar_teste("Outra_base_para_decimal(FF, 16) == 255", valor == 255);
    }
    {
        int valor;
        capturar_saida([&](){ valor = Outra_base_para_decimal("1f", 16); });
        executar_teste("Outra_base_para_decimal(1f, 16) == 31", valor == 31);
    }

    // binario_para_octal
    executar_teste("binario_para_octal(101) == 5", binario_para_octal("101") == "5");
    executar_teste("binario_para_octal(1011) == 13", binario_para_octal("1011") == "13");
    executar_teste("binario_para_octal(000) == 0", binario_para_octal("000") == "0");

    // binario_para_hexadecimal
    executar_teste("binario_para_hexadecimal(1111) == F", binario_para_hexadecimal("1111") == "F");
    executar_teste("binario_para_hexadecimal(101010) == 2A", binario_para_hexadecimal("101010") == "2A");

    // octal_para_binario
    executar_teste("octal_para_binario(7) == 111", octal_para_binario("7") == "111");
    executar_teste("octal_para_binario(17) == 001111", octal_para_binario("17") == "001111");

    // hexadecimal_para_binario
    executar_teste("hexadecimal_para_binario(F) == 1111", hexadecimal_para_binario("F") == "1111");
    executar_teste("hexadecimal_para_binario(1A) == 00011010", hexadecimal_para_binario("1A") == "00011010");

    // Maior_valor_possivel output
    {
        std::string saida = capturar_saida([&](){ Maior_valor_possivel(1); });
        executar_teste("Maior_valor_possivel(1) contem 1 em decimal, octal e hexadecimal", saida.find("Decimal:") != std::string::npos && saida.find("Octal:") != std::string::npos && saida.find("Hexadecimal:") != std::string::npos && saida.find("1") != std::string::npos);
    }
    {
        std::string saida = capturar_saida([&](){ Maior_valor_possivel(4); });
        executar_teste("Maior_valor_possivel(4) contem 15 decimal, 17 octal e F hexadecimal", saida.find("15") != std::string::npos && saida.find("17") != std::string::npos && saida.find("F") != std::string::npos);
    }

    if (testes_passados == total_testes) {
        std::cout << "PASSOU: Todos os " << testes_passados << " testes passaram." << std::endl;
        return 0;
    }
    std::cout << "FALHA: " << (total_testes - testes_passados) << " de " << total_testes << " testes falharam." << std::endl;
    return 1;
}
