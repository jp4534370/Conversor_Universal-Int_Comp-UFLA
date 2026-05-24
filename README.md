# Conversor Universal de Bases

Projeto em C++ para converter números inteiros entre as bases 2, 8, 10 e 16.

## Visão geral

O projeto oferece:

- conversões diretas entre bases binária, octal, decimal e hexadecimal;
- conversões indiretas via binário para octal e hexadecimal;
- validação de texto de entrada para impedir valores inválidos;
- cálculo do maior valor representável por um número de bits.

O objetivo é suportar os casos de uso comuns em introdução à computação e a representação posicional de números.

## Link para o vídeo:

- https://youtu.be/1sXVHC9gdpk

## Estrutura do repositório

- `srcmain.cpp` - código do menu interativo e lógica de uso do usuário.
- `srcconversor.cpp` / `srcconversor.hpp` - funções de conversão entre bases.
- `srcparser.cpp` / `parser.hpp` - validação de digitos e tradução de caracteres em valores numéricos.
- `test_conversor.cpp` - programa de teste automático com 30 casos.
- `README.md` - documentação do projeto.

## Funções principais

### Conversão e validação

- `char Letra_ou_numero(int numero)`
  - converte valores 0–15 em caracteres `0`–`9` e `A`–`F`.

- `std::string Decimal_para_outra_base(int numero_decimal, int base_destino)`
  - converte um número decimal para base 2, 8 ou 16 usando divisões sucessivas.

- `int Outra_base_para_decimal(std::string texto, int base_origem)`
  - converte um valor em base 2, 8 ou 16 para decimal usando somatório posicional.

- `std::string binario_para_octal(std::string binario)`
  - converte binário para octal agrupando em blocos de 3 bits.

- `std::string binario_para_hexadecimal(std::string binario)`
  - converte binário para hexadecimal agrupando em blocos de 4 bits.

- `std::string octal_para_binario(std::string octal)`
  - converte cada dígito octal em 3 bits binários.

- `std::string hexadecimal_para_binario(std::string hexadecimal)`
  - converte cada dígito hexadecimal em 4 bits binários.

- `void Maior_valor_possivel(int total_bits)`
  - calcula e imprime o maior valor representável em decimal, octal e hexadecimal para um número de bits.

### Validação

- `bool Texto_e_valido(std::string texto, int base)`
  - retorna `true` apenas se todos os caracteres do texto são válidos para a base informada.
  - aceita letras minúsculas e maiúsculas para dígitos hexadecimais.

## Conversões suportadas no menu

O programa principal permite:

- base 2 → base 8
- base 2 → base 16
- base 8 → base 2
- base 16 → base 2
- base 8 → base 16 (via binário)
- base 16 → base 8 (via binário)
- base 10 → base 2, 8 ou 16
- base 2, 8 ou 16 → base 10

## Exemplo de uso

1. Compile o programa principal:

```cmd
cd "c:\Users\jp453\OneDrive\Documentos\UFLA\Introdução a Computação\Conversor_Universal-Int_Comp-UFLA"
g++ -std=c++17 srcmain.cpp srcconversor.cpp srcparser.cpp -o conversor.exe
```

2. Execute:

```cmd
conversor.exe
```

3. Escolha uma opção:

- `1` para converter um número entre bases;
- `2` para ver o maior valor possível para uma quantidade de bits;
- `3` para sair.

4. Em uma conversão, informe:

- valor inteiro;
- base de origem (`2`, `8`, `10` ou `16`);
- base de destino (`2`, `8`, `10` ou `16`).

> Exemplos válidos:
>
> - `1011` em base 2
> - `17` em base 8
> - `255` em base 10
> - `1F` em base 16

## Testes automatizados

O arquivo `test_conversor.cpp` contém 30 verificações para as funções de conversão e validação.

### Como compilar os testes

```cmd
g++ -std=c++17 srcconversor.cpp srcparser.cpp test_conversor.cpp -o test_conversor.exe
```

### Como executar os testes

```cmd
.\test_conversor.exe
```

### Resultado esperado

Se todos os casos estiverem corretos, o programa mostra:

```txt
PASSOU: Todos os 30 testes passaram.
```

Durante a execução, cada teste imprime o seu índice e o nome do caso em português:

```txt
Executando teste 1: Valor_do_caractere('0') == 0 ... OK
```

Se algum teste falhar, ele exibirá `FALHA` no fim da linha do teste e, ao final, mostrará quantos testes falharam.

## Requisitos

- Compilador C++ compatível com C++17 (por exemplo, `g++`, `clang++` ou Visual Studio).
- Sistema Windows (o exemplo usa caminhos `cmd`, mas o código é portátil).

## Observações importantes

- O projeto não usa bibliotecas externas além da STL padrão.
- A entrada válida para base hexadecimal inclui `0`–`9`, `A`–`F` e `a`–`f`.
- O programa trata apenas números inteiros não negativos.

## Possíveis melhorias

- adicionar suporte a base 3, 5, 7, 12 ou outras bases arbitrárias;
- permitir conversão de números negativos;
- separar a lógica de impressão da lógica de cálculo para facilitar testes unitários;
- criar um `Makefile` ou script de build.

## Estrutura do código

- `srcmain.cpp` - controle do menu e fluxo de conversão.
- `srcconversor.cpp` - implementa as rotinas de conversão.
- `srcparser.cpp` - implementa a validação de entrada e o mapeamento de caracteres.
- `test_conversor.cpp` - conjunto de testes para validar as funções.

## Como contribuir

1. Faça uma cópia do projeto ou crie um clone.
2. Altere ou adicione funções em `srcconversor.cpp` e `srcconversor.hpp`.
3. Atualize `srcparser.cpp` se precisar de novas regras de validação.
4. Adicione novos testes em `test_conversor.cpp`.
5. Compile e execute `test_conversor.exe` antes de aceitar as mudanças.
