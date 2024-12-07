/********************************************************
 * FILENAME : assento.h
 * DESCRIPTION : Cabeçalho do módulo para definição e manipulação de assentos
 *               em um sistema de reserva de voos.
 *
 * STRUCTURES AND FUNCTIONS :
 * - typedef struct assento : Representa um assento em um voo com atributos como número, código do voo e status.
 * - void registrarAssento() : Registra um novo assento para um voo existente e valida os dados de entrada.
 *
 * INCLUDED FILES :
 * - <string> : Para manipulação de strings no estilo C++.
 * - ../passageiros/passageiros.h : Para manipulação de dados de passageiros.
 * - ../tripulacao/tripulacao.h : Para manipulação de dados de tripulação.
 * - ../voo/voo.h : Para manipulação de dados de voos.
 * - ../reserva/reserva.h : Para manipulação de dados de reservas.
 *
 * NOTES :
 * Este módulo contém a definição da estrutura `assento` e a função `registrarAssento()` 
 * para gerenciar e registrar assentos de voos, incluindo a validação das informações do assento.
 *
 *AUTHOR : Felipe Cury
* START DATE : 23/11/2024
 ********************************************************/

#ifndef ASSENTO_H
#define ASSENTO_H

#include <string>

#include "../passageiros/passageiros.h"
#include "../tripulacao/tripulacao.h"
#include "../voo/voo.h"
#include "../reserva/reserva.h"
#include "assento.h"

using namespace std;

/*
 * Estrutura: assento
 * Objetivo: Representar um assento em um voo.
 *
 * Membros:
 * - numero (int): Número identificador do assento.
 * - codigo_voo (int): Código identificador do voo ao qual o assento pertence.
 * - status (string): Status atual do assento (exemplo: "Livre" ou "Ocupado").
 */
typedef struct assento
{
    int numero;     // Número identificador do assento.
    int codigo_voo; // Código identificador do voo associado.
    string status;  // Status atual do assento.
} assento;

/*
 * Função: registrarAssento
 * Objetivo: Registrar um novo assento para um voo existente.
 *
 * Entradas:
 * - Nenhuma diretamente. Os dados do assento (código do voo e número do assento) são solicitados ao usuário durante a execução.
 *
 * Saídas:
 * - Registra as informações do assento no arquivo "assentos.dat", caso sejam válidas.
 *
 * Retorno:
 * - Não possui retorno.
 *
 * Descrição:
 * A função realiza as seguintes etapas:
 * - Solicita ao usuário o código de um voo e o número de um assento.
 * - Verifica se o código do voo existe e está ativo.
 * - Verifica se o número do assento não está previamente registrado para o voo.
 * - Caso ambas as verificações sejam bem-sucedidas, registra o novo assento no arquivo "assentos.dat".
 */
void registrarAssento();

#endif
