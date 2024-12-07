/********************************************************
 * FILENAME : passageiros.h
 * DESCRIPTION : Cabeçalho do módulo para gerenciamento de passageiros.
 *
 * STRUCTS :
 * - struct passageiro : Representa os dados pessoais e de fidelidade de um passageiro.
 *
 * PUBLIC FUNCTIONS :
 * - void registrarPassageiro() : Solicita e registra os dados de um novo passageiro.
 *
 * INCLUDED FILES :
 * - <string> : Para manipulação de strings no estilo C++.
 *
 * NOTES :
 * Este módulo define a estrutura de dados `passageiro` e a função pública 
 * `registrarPassageiro()` que permite a entrada e armazenamento de dados 
 * dos passageiros em um arquivo persistente.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 22/11/2024
 ********************************************************/

#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include <string> // Para manipulação de strings no estilo C++

using namespace std;

/*
 * Estrutura: passageiro
 * Objetivo: Representar um passageiro com seus dados pessoais e informações de fidelidade.
 *
 * Membros:
 * - codigo (int): Código único para cada passageiro, utilizado como identificador.
 * - nome (string): Nome completo do passageiro.
 * - endereco (string): Endereço residencial do passageiro.
 * - telefone (string): Número de telefone de contato do passageiro.
 * - fidelidade (char): Indica se o passageiro é fiel ao programa de fidelidade (s para sim, n para não).
 * - pontos_fidelidade (int): Número de pontos de fidelidade acumulados pelo passageiro.
 */
typedef struct passageiro
{
    int codigo;            // Código único para cada passageiro
    string nome;           // Nome do passageiro
    string endereco;       // Endereço do passageiro
    string telefone;       // Telefone do passageiro
    char fidelidade;       // Indica se o passageiro é fiel (s/n)
    int pontos_fidelidade; // Número de pontos de fidelidade do passageiro
} passageiro;              // 'passageiro' é o nome da estrutura, representando um passageiro

/*
 * Função: registrarPassageiro
 * Objetivo: Solicitar e registrar os dados de um novo passageiro no sistema.
 *
 * Entradas:
 * - Nenhuma diretamente. A função solicita as informações do passageiro durante sua execução.
 *
 * Saídas:
 * - Registra os dados do passageiro em um arquivo persistente.
 *
 * Descrição:
 * A função coleta os dados do passageiro, como nome, endereço, telefone e informações de fidelidade,
 * e os armazena em um arquivo para futuros usos. A função inclui validação de entrada e atribui um
 * código único ao passageiro.
 */
void registrarPassageiro();  // Função que solicita e registra os dados de um passageiro

#endif
