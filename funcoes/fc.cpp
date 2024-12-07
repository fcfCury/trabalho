/********************************************************
 * FILENAME : fc.cpp
 * DESCRIPTION : Implementação de funções auxiliares para validações.
 *
 * PUBLIC FUNCTIONS :
 * - int validaTelefone(std::string &telefone)
 * - int obterUltimoCodigo(const std::string& nomeArquivo)
 * - bool validaData(const std::string &data)
 * - bool validaHorario(const std::string &horario)
 * - bool isNumero(const std::string &str)
 *
 * INCLUDED FILES :
 * - "fc.h" : Declarações de funções e macros.
 * - <iostream>, <fstream>, etc.: Funções auxiliares.
 *
 * NOTES :
 * Este arquivo contém a implementação detalhada das funções declaradas
 * no cabeçalho `fc.h`.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 
 ********************************************************/

#include "fc.h"

#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <limits.h>
#include <sstream>
#include <regex>
#include <string>

using namespace std;

/*
 * Função: validaTelefone
 * Objetivo: Validar o formato de um número de telefone fornecido pelo usuário.
 *
 * Entradas:
 * - telefone (string): O número de telefone a ser validado. O telefone deve ser fornecido no formato (XX)XXXXXXXXX.
 *
 * Saídas:
 * - Retorna 0 se o telefone for válido.
 * - Retorna 1 se o telefone for inválido (quando o formato ou conteúdo não estiver correto).
 *
 * Descrição:
 * Esta função valida se o número de telefone fornecido segue as seguintes regras:
 * 1. Deve começar com um parêntese '(' e terminar com ')'.
 * 2. O código de área (dois primeiros dígitos após '(') deve conter apenas números.
 * 3. Não deve conter espaços ou letras.
 * 4. O número de telefone deve ter entre 8 e 9 dígitos após o código de área.
 *
 * A função retorna 0 se todas as condições forem atendidas, caso contrário, retorna 1 e exibe uma mensagem de erro.
 */
int validaTelefone(std::string &telefone)
{
    cout << "Digite o telefone no formato (XX)XXXXXXXXX: ";
    getline(cin, telefone);

    if (telefone[0] != '(' || telefone[3] != ')')
    {
        cout << "Formato invalido, comece com parenteses.\n";
        return 1;
    }

    if (!isdigit(telefone[1]) || !isdigit(telefone[2]))
    {
        cout << "O codigo de area deve conter apenas numeros.\n";
        return 1;
    }

    for (char c : telefone)
    {
        if (isspace(c))
        {
            cout << "O telefone não pode conter espaços.\n";
            return 1;
        }
        if (isalpha(c))
        {
            cout << "O telefone nao pode conter letras.\n";
            return 1;
        }
    }

    int count = 0;
    for (size_t i = 4; i < telefone.size(); i++)
    {
        if (isdigit(telefone[i]))
            count++;
    }

    if (count < 8 || count > 9)
    {
        cout << "O numero de telefone deve ter entre 8 e 9 digitos.\n";
        return 1;
    }

    return 0;
}

/*
 * Função: obterUltimoCodigo
 * Objetivo: Obter o último número presente em um arquivo, independentemente do formato.
 *
 * Entradas:
 * - nomeArquivo (string): O nome do arquivo que será lido.
 *
 * Saídas:
 * - Retorna o último número encontrado no arquivo (int).
 * - Retorna 0 se o arquivo não puder ser aberto.
 *
 * Descrição:
 * A função lê o arquivo linha por linha, procurando a palavra "Codigo: ". Quando encontrada,
 * extrai o número que aparece em seguida e armazena como o último código encontrado.
 *
 * Exemplo de uso:
 * - Se o arquivo contiver as linhas:
 *   ```
 *   Nome: João
 *   Codigo: 42
 *   Codigo: 56
 *   ```
 *   A função retornará 56.
 */
int obterUltimoCodigo(const string& nomeArquivo)
{
   fstream arquivo;
   string linha;
   string ultimaLinha;

   arquivo.open(nomeArquivo, fstream::in);

   if (!arquivo.is_open()){
    return 0;
   }

   while (getline(arquivo, linha)) {
      if(!linha.empty()) {
        ultimaLinha = linha;
      }
   }

   arquivo.close();

   istringstream stream(ultimaLinha);
   string token;

   int codigo = 0;

   while (getline(stream, token, ',')){
    if (isNumero(token)) {
        codigo = stoi(token);
    }
   }
   
   return codigo;
   
}

/*
 * Função: validaData
 * Objetivo: Validar o formato e a validade de uma data fornecida no formato DD/MM/AAAA.
 *
 * Entradas:
 * - data (string): A data a ser validada.
 *
 * Saídas:
 * - Retorna true se a data for válida.
 * - Retorna false se a data for inválida.
 *
 * Descrição:
 * Esta função verifica se a data segue o formato DD/MM/AAAA e se os valores de dia, mês
 * e ano são válidos. Também considera anos bissextos para fevereiro.
 */
bool validaData(const string &data)
{

    regex formato("\\d{2}/\\d{2}/\\d{4}");
    if (!regex_match(data, formato))
    {
        return false;
    }

    int dia = stoi(data.substr(0, 2));
    int mes = stoi(data.substr(3, 2));
    int ano = stoi(data.substr(6, 4));

    if (mes < 1 || mes > 12)
    {
        return false;
    }

    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        diasPorMes[1] = 29;
    }

    if (dia < 1 || dia > diasPorMes[mes - 1])
    {
        return false;
    }

    return true;
}

/*
 * Função: validaHorario
 * Objetivo: Validar o formato de um horário fornecido no formato HH:MM.
 *
 * Entradas:
 * - horario (string): O horário a ser validado.
 *
 * Saídas:
 * - Retorna true se o horário for válido.
 * - Retorna false se o horário for inválido.
 *
 * Descrição:
 * Esta função verifica se o horário segue o formato HH:MM, onde HH representa as horas
 * (de 0 a 23) e MM representa os minutos (de 0 a 59).
 */
bool validaHorario(const string &horario)
{
    regex formato("\\d{2}:\\d{2}");
    if (!regex_match(horario, formato))
    {
        return false;
    }

    int horas = stoi(horario.substr(0, 2));
    int minutos = stoi(horario.substr(3, 2));
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59)
    {
        return false;
    }

    return true;
}

/*
 * Função: isNumero
 * Objetivo: Verificar se uma string contém apenas dígitos numéricos.
 *
 * Entradas:
 * - str (const string &): A string a ser verificada.
 *
 * Saídas:
 * - Retorna true se todos os caracteres da string forem dígitos.
 * - Retorna false se a string contiver qualquer caractere não numérico.
 *
 * Descrição:
 * Esta função percorre cada caractere da string fornecida e verifica se ele é um dígito
 * utilizando a função isdigit(). Se algum caractere não for um dígito, a função retorna false.
 * Caso contrário, retorna true, indicando que a string contém apenas caracteres numéricos.
 */
bool isNumero(const string &str)
{

    for (char const &c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}