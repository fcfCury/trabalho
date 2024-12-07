/********************************************************
 * Arquivo: pesquisa.h
 * Objetivo: Declaração de funções de pesquisa de passageiros e tripulantes.
 *
 * Descrição:
 * Este cabeçalho contém as declarações das funções `pesquisarPassageiro()` e
 * `pesquisarTripulacao()`. Ambas as funções permitem que o usuário busque
 * informações sobre passageiros e tripulantes em arquivos de dados ("passageiros.dat"
 * e "tripulantes.dat", respectivamente), com base em um código ou nome. As funções
 * retornam os dados encontrados ou uma mensagem de "não encontrado" se a pesquisa falhar.
 *
 * Estruturas e Funções:
 * - void pesquisarPassageiro()
 *   Pesquisa e exibe as informações de um passageiro por código ou nome.
 * - void pesquisarTripulacao()
 *   Pesquisa e exibe as informações de um tripulante por código ou nome.
 *
 * Dependências:
 * - <iostream> : Para entrada e saída de dados.
 * - <cstdio> : Para funções de manipulação de entrada/saída em C.
 * - <string> : Para manipulação de strings.
 * - <cctype> : Para funções de verificação de caracteres.
 * - <cstring> : Para manipulação de strings em estilo C.
 * - <fstream> : Para manipulação de arquivos de entrada/saída.
 * - <sstream> : Para manipulação de strings de fluxo.
 * - <queue> : Para uso de filas (não utilizado diretamente, mas incluído por compatibilidade).
 * - "../tripulacao/tripulacao.h" : Para manipulação de dados de tripulantes.
 * - "../passageiros/passageiros.h" : Para manipulação de dados de passageiros.
 * - "../funcoes/fc.h" : Para uso de funções auxiliares, como `isNumero`.
 *
 * AUTHOR : Felipe Cury
 * START DATE : 23/11/2024
 ********************************************************/

#ifndef PESQUISA_H
#define PESQUISA_H

/**
 * Função: pesquisarPassageiro
 * 
 * Objetivo: Realizar a pesquisa de um passageiro por código ou nome em um arquivo de texto.
 * 
 * Descrição:
 * Esta função solicita ao usuário um código ou nome de passageiro. Se o input for um código numérico,
 * a função busca o código no arquivo "passageiros.dat" e imprime os detalhes do passageiro. Se for um nome,
 * a função busca todas as ocorrências do nome e exibe os dados relacionados até encontrar um separador de seção.
 * 
 * Entradas:
 * - Nenhuma entrada direta, recebe input do usuário via console.
 * 
 * Saídas:
 * - Exibe as informações do passageiro encontrado ou uma mensagem de "não encontrado" se a pesquisa falhar.
 */
void pesquisarPassageiro();

/**
 * Função: pesquisarTripulacao
 * 
 * Objetivo: Realizar a pesquisa de um tripulante por código ou nome em um arquivo de texto.
 * 
 * Descrição:
 * Esta função solicita ao usuário um código ou nome de tripulante. Se o input for um código numérico,
 * a função busca o código no arquivo "tripulantes.dat" e imprime os detalhes do tripulante. Se for um nome,
 * a função busca todas as ocorrências do nome e exibe os dados relacionados até encontrar um separador de seção.
 * 
 * Entradas:
 * - Nenhuma entrada direta, recebe input do usuário via console.
 * 
 * Saídas:
 * - Exibe as informações do tripulante encontrado ou uma mensagem de "não encontrado" se a pesquisa falhar.
 */
void pesquisarTripulacao();

#endif // PESQUISA_H
