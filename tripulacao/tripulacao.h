/********************************************************
 * FILENAME : tripulacao.h
 * DESCRIPTION : Declaração da estrutura e função para gerenciamento de dados da tripulação de um voo.
 *
 * STRUCTS :
 * - struct tripulacao : Representa um membro da tripulação de um voo, com suas informações pessoais e de contato.
 *
 * PUBLIC FUNCTIONS :
 * - void registraTripulacao() : Permite registrar os dados de um membro da tripulação.
 *
 * INCLUDED FILES :
 * - <string> : Para manipulação de strings no estilo C++.
 *
 * NOTES :
 * Este cabeçalho define a estrutura de dados `tripulacao`, que armazena informações como código de identificação,
 * nome, cargo e telefone de um membro da tripulação. Também inclui a declaração de uma função para registrar novos
 * membros da tripulação.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 22/11/2024
 ********************************************************/

#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include <string> // Para manipulação de strings no estilo C++

using namespace std;

/*
 * Estrutura: tripulacao
 * Objetivo: Representar um membro da tripulação de um voo.
 *
 * Descrição:
 * Esta estrutura armazena as informações de um membro da tripulação, incluindo:
 * - código (int): Código único de identificação do membro.
 * - nome (string): Nome do membro da tripulação.
 * - cargo (string): Cargo ocupado pelo membro da tripulação (ex: Piloto, Copiloto, Comissário de Bordo, etc.).
 * - telefone (string): Número de telefone de contato do membro da tripulação.
 */
typedef struct tripulacao
{
    int codigo;      // Código único para cada membro da tripulação.
    string nome;     // Nome do membro da tripulação.
    string cargo;    // Cargo do membro da tripulação (ex: Piloto, Copiloto, Comissário, etc.).
    string telefone; // Número de telefone do membro da tripulação.
} tripulacao;        // 'tripulacao' é o nome da estrutura, representando um membro da tripulação.

/*
 * Função: registraTripulacao
 * Objetivo: Registrar os dados de um membro da tripulação.
 *
 * Descrição:
 * Esta função solicita os dados de um membro da tripulação (nome, cargo, telefone) e os armazena em um arquivo
 * de texto persistente. Essa função é usada para incluir novos membros na lista de tripulantes.
 */
void registraTripulacao();

#endif
