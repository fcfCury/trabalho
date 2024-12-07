/********************************************************
 * FILENAME : voo.h
 * DESCRIPTION : Declaração da estrutura e função para a gestão de dados de um voo.
 *
 * FUNCTION :
 * - void registraVoo() : Coleta e registra os dados de um voo em um arquivo de texto.
 *
 * INCLUDED FILES :
 * - <string> : Para manipulação de strings.
 *
 * NOTES :
 * Esta estrutura armazena informações detalhadas sobre um voo, incluindo código, nome, data, hora,
 * origem, destino, status, tarifa e códigos dos membros da tripulação e do avião. A função `registraVoo`
 * é usada para registrar um voo no sistema.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 26/11/2024
 ********************************************************/

#ifndef VOO_H
#define VOO_H

#include <string> // Inclui a biblioteca para usar o tipo 'string'

using namespace std; // Para usar std::string

/*
 * STRUCTURE: voo
 * PURPOSE: Representar um voo com suas características e detalhes.
 *
 * DESCRIPTION:
 * Esta estrutura armazena as informações de um voo, incluindo um código único de identificação, o nome do voo,
 * data e hora, locais de origem e destino, status, tarifa e códigos dos membros da tripulação e do avião.
 */
typedef struct voo
{
    int codigo;              /**< Código do voo (número único para cada voo). */
    string nome;             /**< Nome do voo (ex: nome do operador ou do voo). */
    string data;             /**< Data do voo no formato DD/MM/AAAA. */
    string hora;             /**< Hora do voo no formato HH:MM. */
    string origem;           /**< Local de origem do voo. */
    string destino;          /**< Local de destino do voo. */
    string status;           /**< Status do voo (ativo/inativo). */
    float tarifa;            /**< Preço do voo. */
    int codigo_aviao;        /**< Código único do avião associado ao voo. */
    int codigo_piloto;       /**< Código único do piloto do voo. */
    int codigo_copiloto;     /**< Código único do copiloto do voo. */
    int codigo_comissario;   /**< Código único do comissário de bordo do voo. */
} voo; // Definindo 'voo' como um tipo de estrutura

/*
 * FUNCTION: registraVoo
 * PURPOSE: Registrar os dados de um voo.
 *
 * DESCRIPTION:
 * Esta função permite que as informações de um voo sejam coletadas e registradas em um arquivo de texto
 * para serem armazenadas no sistema de gerenciamento de voos.
 */
void registraVoo();

#endif // VOO_H
