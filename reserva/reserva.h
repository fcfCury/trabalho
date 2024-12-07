/*
 * Arquivo: reserva.h
 * Objetivo: Declaração de estruturas e funções relacionadas a reservas de assentos em voos.
 *
 * Descrição:
 * Este cabeçalho inclui a definição da estrutura `reserva` que armazena informações sobre uma reserva de assento em um voo.
 * Além disso, declara funções para registrar e baixar reservas, facilitando a gestão de reservas de passageiros.
 */

#ifndef RESERVA_H
#define RESERVA_H

#include <string>            // Para usar std::string
#include "../passageiros/passageiros.h"     // Para a classe ou estrutura relacionada a passageiros
#include "../tripulacao/tripulacao.h"      // Para a classe ou estrutura relacionada à tripulação
#include "../voo/voo.h"             // Para a classe ou estrutura relacionada a voos
#include "../assento/assento.h"         // Para a classe ou estrutura relacionada a assentos

using namespace std;

/*
 * Estrutura: reserva
 * Objetivo: Representar uma reserva de assento em um voo.
 *
 * Descrição:
 * Esta estrutura armazena as informações necessárias para identificar uma reserva, incluindo o código do voo,
 * o código do passageiro e o número do assento reservado.
 */
typedef struct reserva
{
    int codigo_voo;            // Código identificador do voo.
    int codigo_passageiro;     // Código identificador do passageiro que fez a reserva.
    int numero_assento;        // Número do assento reservado.
} reserva;

/*
 * Função: registrarReserva
 * Objetivo: Registrar uma nova reserva de assento em um voo.
 *
 * Descrição:
 * Esta função permite que uma nova reserva seja criada, verificando a disponibilidade do assento e do voo,
 * e associando a reserva ao passageiro.
 */
void registrarReserva();

/*
 * Função: baixarReserva
 * Objetivo: Cancelar uma reserva existente de assento em um voo.
 *
 * Descrição:
 * Esta função permite a remoção de uma reserva, liberando o assento reservado e atualizando o status do voo
 * e do passageiro, conforme necessário.
 */
void baixarReserva();

#endif // RESERVA_H
