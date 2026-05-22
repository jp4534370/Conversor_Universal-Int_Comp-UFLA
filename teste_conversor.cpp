#include <iostream>
#include <string>
#include "srcconversor.hpp"
#include "parser.hpp"

int total_tests = 0;
int failed_tests = 0;

void expect_equal(const std::string& name, const std::string& got, const std::string& want) {
    total_tests++;
    if (got != want) {
        failed_tests++;
        std::cout << "FAIL: " << name << " got='" << got << "' want='" << want << "'\n";
    }
}

void expect_equal(const std::string& name, int got, int want) {
    total_tests++;
    if (got != want) {
        failed_tests++;
        std::cout << "FAIL: " << name << " got=" << got << " want=" << want << "\n";
    }
}

void expect_equal(const std::string& name, char got, char want) {
    total_tests++;
    if (got != want) {
        failed_tests++;
        std::cout << "FAIL: " << name << " got='" << got << "' want='" << want << "'\n";
    }
}

int main() {
    expect_equal("Letra_ou_numero(0)", Letra_ou_numero(0), '0');
    expect_equal("Letra_ou_numero(10)", Letra_ou_numero(10), 'A');

    expect_equal("Decimal_para_outra_base(0, 2)", Decimal_para_outra_base(0, 2), "0");
    expect_equal("Decimal_para_outra_base(10, 2)", Decimal_para_outra_base(10, 2), "1010");
    expect_equal("Decimal_para_outra_base(31, 16)", Decimal_para_outra_base(31, 16), "1F");
    expect_equal("Decimal_para_outra_base(1000, 8)", Decimal_para_outra_base(1000, 8), "1750");
    expect_equal("Decimal_para_outra_base(255, 16)", Decimal_para_outra_base(255, 16), "FF");

    expect_equal("Outra_base_para_decimal(1010, 2)", Outra_base_para_decimal("1010", 2), 10);
    expect_equal("Outra_base_para_decimal(17, 8)", Outra_base_para_decimal("17", 8), 15);
    expect_equal("Outra_base_para_decimal(FF, 16)", Outra_base_para_decimal("FF", 16), 255);
    expect_equal("Outra_base_para_decimal(1A3, 16)", Outra_base_para_decimal("1A3", 16), 419);
    expect_equal("Outra_base_para_decimal(777, 8)", Outra_base_para_decimal("777", 8), 511);

    expect_equal("binario_para_octal(0)", binario_para_octal("0"), "0");
    expect_equal("binario_para_octal(1)", binario_para_octal("1"), "1");
    expect_equal("binario_para_octal(101010)", binario_para_octal("101010"), "52");
    expect_equal("binario_para_octal(1101)", binario_para_octal("1101"), "15");
    expect_equal("binario_para_octal(001001)", binario_para_octal("001001"), "11");

    expect_equal("binario_para_hexadecimal(1111)", binario_para_hexadecimal("1111"), "F");
    expect_equal("binario_para_hexadecimal(1010)", binario_para_hexadecimal("1010"), "A");
    expect_equal("binario_para_hexadecimal(1001110)", binario_para_hexadecimal("1001110"), "4E");
    expect_equal("binario_para_hexadecimal(0001)", binario_para_hexadecimal("0001"), "1");
    expect_equal("binario_para_hexadecimal(11111111)", binario_para_hexadecimal("11111111"), "FF");

    expect_equal("octal_para_binario(0)", octal_para_binario("0"), "000");
    expect_equal("octal_para_binario(7)", octal_para_binario("7"), "111");
    expect_equal("octal_para_binario(17)", octal_para_binario("17"), "001111");
    expect_equal("octal_para_binario(123)", octal_para_binario("123"), "001010011");
    expect_equal("octal_para_binario(755)", octal_para_binario("755"), "111101101");

    expect_equal("hexadecimal_para_binario(0)", hexadecimal_para_binario("0"), "0000");
    expect_equal("hexadecimal_para_binario(1)", hexadecimal_para_binario("1"), "0001");
    expect_equal("hexadecimal_para_binario(A)", hexadecimal_para_binario("A"), "1010");
    expect_equal("hexadecimal_para_binario(1F)", hexadecimal_para_binario("1F"), "00011111");
    expect_equal("hexadecimal_para_binario(DEAD)", hexadecimal_para_binario("DEAD"), "1101111010101101");

    expect_equal("Texto_e_valido(1010, 2)", Texto_e_valido("1010", 2) ? 1 : 0, 1);
    expect_equal("Texto_e_valido(19, 8)", Texto_e_valido("19", 8) ? 1 : 0, 0);
    expect_equal("Texto_e_valido(1F, 16)", Texto_e_valido("1F", 16) ? 1 : 0, 1);
    expect_equal("Texto_e_valido(G1, 16)", Texto_e_valido("G1", 16) ? 1 : 0, 0);

    expect_equal("roundtrip octal->binario->hexadecimal", binario_para_hexadecimal(octal_para_binario("17")), "F");
    expect_equal("roundtrip hex->binario->octal", binario_para_octal(hexadecimal_para_binario("1F")), "37");
    expect_equal("roundtrip decimal->base16->decimal", Outra_base_para_decimal(Decimal_para_outra_base(123, 16), 16), 123);

    if (failed_tests == 0) {
        std::cout << "PASS: All " << total_tests << " tests passed." << std::endl;
        return 0;
    }

    std::cout << "FAIL: " << failed_tests << " of " << total_tests << " tests failed." << std::endl;
    return 1;
}
