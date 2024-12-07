/********************************************************
* FILENAME : assentos.cpp
* DESCRIPTION : Implementação das funções para gerenciamento de assentos de voos, incluindo verificação 
* de existência de voos, verificação de assentos reservados e registro de novos assentos em um arquivo.
*
* PUBLIC FUNCTIONS :
* - bool verificarVoo(int codigoVoo)
* - bool verificarAssento(int codigoVoo, int numeroAssento)
* - void registrarAssento()
*
* INCLUDED FILES :
* - <iostream> : Para entrada e saída de dados.
* - <cstdio> : Para funções de entrada e saída em C.
* - <string> : Para manipulação de strings.
* - <fstream> : Para operações com arquivos.
* - <vector> : Para trabalhar com coleções de dados.
* - <sstream> : Para manipulação de strings formatadas.
* - <climits> : Para valores máximos e mínimos de tipos básicos.
* - "../voo/voo.h" : Cabeçalho contendo a estrutura de voo.
* - "assento.h" : Cabeçalho contendo a estrutura de assento.
*
* NOTES :
* Este módulo implementa as funcionalidades necessárias para 
* verificar voos, verificar assentos e registrar novos assentos
* em arquivos.
*
* AUTHOR : Felipe Cury
* START DATE : 23/11/2024
********************************************************
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <climits>

#include "../voo/voo.h"
#include "assento.h"

using namespace std;
fstream arquivo;
assento a;
char loop;

/*
 * Função: verificarVoo
 * Objetivo: Verificar se um voo com o código fornecido está registrado no arquivo "voos.dat".
 *
 * Parâmetros:
 * - codigoVoo (int): O código do voo a ser verificado.
 *
 * Retorno:
 * - true: Se o voo com o código fornecido for encontrado e estiver com status "Ativo".
 * - false: Se o voo não for encontrado, estiver com outro status, ou se ocorrer erro ao abrir o arquivo.
 *
 * Descrição:
 * A função abre o arquivo "voos.dat" e busca pelo código do voo fornecido. Se o código for encontrado e 
 * o status do voo for "Ativo", a função retorna true. Caso contrário, retorna false.
 */
bool verificarVoo(int codigoVoo)
{
    ifstream arquivo("voos.dat");

    string linha;
    vector<voo> voar;
    while (getline(arquivo, linha))
    {
        string codigo, tarifa, codigo_aviao, codigo_piloto, codigo_copiloto, codigo_comissario;
        stringstream ss(linha);
        voo v;
        getline(ss, tarifa, ',');
        getline(ss, v.data, ',');
        getline(ss, v.hora, ',');
        getline(ss, v.origem, ',');
        getline(ss, v.destino, ',');
        getline(ss, codigo_aviao, ',');
        getline(ss, codigo_piloto, ',');
        getline(ss, codigo_copiloto, ',');
        getline(ss, codigo_comissario, ',');
        getline(ss, v.status, ',');
        getline(ss, codigo, ',');

        v.tarifa = stoi(tarifa);
        v.codigo_aviao = stoi(codigo_aviao);
        v.codigo_piloto = stoi(codigo_piloto);
        v.codigo_copiloto = stoi(codigo_copiloto);
        v.codigo_comissario = stoi(codigo_comissario);
        v.codigo = stoi(codigo);

        voar.push_back(v);
    }
    arquivo.close();

    for (const voo &v : voar)
    {
        if (v.codigo == codigoVoo)
        {
            if (v.status == "Ativo")
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

/*
 * Função: verificarAssento
 * Objetivo: Verificar se um assento com o número fornecido já está registrado para um voo específico.
 *
 * Entradas:
 * - codigoVoo (int): O código do voo associado ao assento.
 * - numeroAssento (int): O número do assento a ser verificado.
 *
 * Saidas:
 * - true: Se o assento com o número fornecido estiver registrado para o voo especificado.
 * - false: Se o assento não estiver registrado ou se ocorrer erro ao abrir o arquivo.
 *
 * Descrição:
 * A função abre o arquivo "assentos.dat" e busca pelo código do voo e número do assento fornecidos. Se ambos
 * forem encontrados, a função retorna true. Caso contrário, retorna false.
 */
bool verificarAssento(int codigoVoo, int numeroAssento)
{
    ifstream assentos("assentos.dat");
    if (!assentos.is_open())
    {
        cerr << "Erro ao abrir o arquivo assentos.dat!" << endl;
        return false;
    }

    string linha;
    vector<assento> assentar;
    while (getline(arquivo, linha))
    {
        string numero, codigo_voo;
        assento a;
        stringstream ss(linha);

        getline(ss, numero, ',');
        getline(ss, codigo_voo, ',');
        getline(ss, a.status, ',');

        a.numero = stoi(numero);
        a.codigo_voo = stoi(codigo_voo);

        assentar.push_back(a);
    }
    assentos.close();

    for (const assento &t : assentar)
    {
        if (a.numero == numeroAssento)
        {
            if (a.codigo_voo == codigoVoo)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

/*
 * Função: registrarAssento
 * Objetivo: Registrar um novo assento para um voo existente no arquivo "assentos.dat".
 *
 * Entradas:
 * - Nenhuma diretamente. Os dados são solicitados ao usuário durante a execução.
 *
 * Saidas:
 * - Nenhum (função void).
 * 
 * Descrição:
 * Esta função solicita ao usuário:
 * 1. O código de um voo.
 *    - Verifica se o voo existe utilizando a função `verificarVoo`.
 * 2. O número do assento.
 *    - Verifica se o assento já está registrado para o voo utilizando a função `verificarAssento`.
 * 3. Se os dados forem válidos:
 *    - Registra as informações do assento no arquivo "assentos.dat" com o status "Livre".
 *
 * A função também oferece ao usuário a opção de registrar outro assento ou encerrar o processo.
 */
void registrarAssento()
{
    do
    {
        cin.ignore();

        cout << "Digite o codigo do voo: ";
        scanf("%d", &a.codigo_voo);

        if (!verificarVoo(a.codigo_voo))
        {
            cout << "Erro: O codigo do voo nao existe!" << endl;
            continue;
        }

        cout << "Digite o numero do assento: ";
        scanf("%d", &a.numero);

        if (verificarAssento(a.codigo_voo, a.numero))
        {
            cout << "Erro: O assento ja existe para este voo!" << endl;
            continue;
        }

        fstream arquivo;
        arquivo.open("assentos.dat", fstream::app | fstream::in | fstream::out);
        if (!arquivo)
        {
            cerr << "Erro ao abrir o arquivo!" << endl;
            return;
        }

        a.status = "Livre";

        arquivo << a.codigo_voo << ","
                << a.numero << ","
                << a.status << endl;

        arquivo.close();

        cout << "Deseja registrar outro assento? (s ou n): ";
        cin >> loop;

    } while (loop == 's');
}
