/********************************************************
 * FILENAME : fc.h
 * DESCRIPTION : Módulo para validações diversas.
 *
 * PUBLIC FUNCTIONS :
 * - int validaTelefone(std::string &telefone)
 * - int obterUltimoCodigo(const std::string& nomeArquivo)
 * - bool validaData(const std::string &data)
 * - bool validaHorario(const std::string &horario)
 * - bool isNumero(const std::string &str)
 *
 * INCLUDED FILES :
 * - <string> : Manipulação de strings no estilo C++.
 *
 * NOTES :
 * Este módulo contém funcionalidades para validação de entradas, 
 * incluindo números de telefone, datas, horários e extração de códigos numéricos.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 
 ********************************************************/

#ifndef FC_H
#define FC_H

#include <string> // Para usar std::string

using namespace std;

/*
 * Função: validaTelefone
 * Objetivo: Validar o telefone em formato específico.
 *
 * Entradas:
 * - telefone (string&): Uma referência para a string que contém o número de telefone a ser validado.
 *
 * Saídas:
 * - Retorna um inteiro (0 ou 1), onde 1 indica que o telefone é válido e 0 que é inválido.
 */
int validaTelefone(string &telefone);

/*
 * Função: obterUltimoCodigo
 * Objetivo: Obter o último código presente em um arquivo.
 *
 * Entradas:
 * - nomeArquivo (const string&): O nome do arquivo onde o último código será buscado.
 *
 * Saídas:
 * - Retorna o último código encontrado no arquivo (um número inteiro).
 */
int obterUltimoCodigo(const string &nomeArquivo);

/*
 * Função: validaData
 * Objetivo: Validar a data no formato DD/MM/AAAA.
 *
 * Entradas:
 * - data (const string&): Uma string que representa a data a ser validada.
 *
 * Saídas:
 * - Retorna um valor booleano (true ou false), onde true indica que a data é válida e false que é inválida.
 */
bool validaData(const string &data);

/*
 * Função: validaHorario
 * Objetivo: Validar o horário no formato HH:MM.
 *
 * Entradas:
 * - horario (const string&): Uma string que representa o horário a ser validado.
 *
 * Saídas:
 * - Retorna um valor booleano (true ou false), onde true indica que o horário é válido e false que é inválido.
 */
bool validaHorario(const string &horario);


/*
 * Função: isNumero
 * Objetivo: Verificar se uma string contém apenas dígitos numéricos.
 *
 * Entradas:
 * - str (const string&): Uma string a ser verificada.
 *
 * Saídas:
 * - Retorna um valor booleano (true ou false), onde true indica que a string contém apenas números e false que contém outros caracteres.
 *
 * Descrição:
 * A função percorre cada caractere da string e verifica se todos são dígitos numéricos.
 * Se encontrar algum caractere que não seja numérico, retorna false. Caso contrário, retorna true.
 */
bool isNumero (const string& str);

#endif // FC_H
