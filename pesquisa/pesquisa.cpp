/********************************************************
 * Arquivo: pesquisa.cpp
 * Objetivo: Implementação das funções de pesquisa de passageiros e tripulantes.
 *
 * Descrição:
 * Este arquivo contém as implementações das funções `pesquisarPassageiro()` e
 * `pesquisarTripulacao()`. Ambas as funções realizam buscas em arquivos de texto
 * ("passageiros.dat" e "tripulantes.dat", respectivamente) para encontrar passageiros
 * e tripulantes com base em código ou nome. As funções exibem as informações encontradas
 * ou uma mensagem de "não encontrado" se a pesquisa falhar.
 *
 * Estruturas e Funções:
 * - void pesquisarPassageiro()
 *   Pesquisa e imprime as informações de um passageiro por código ou nome.
 * - void pesquisarTripulacao()
 *   Pesquisa e imprime as informações de um tripulante por código ou nome.
 *
 * Dependências:
 * - <iostream> : Para entrada e saída de dados.
 * - <cstdio> : Para funções de manipulação de entrada/saída em C.
 * - <string> : Para manipulação de strings.
 * - <cctype> : Para funções de verificação de caracteres.
 * - <cstring> : Para manipulação de strings em estilo C.
 * - <fstream> : Para manipulação de arquivos de entrada/saída.
 * - <sstream> : Para manipulação de strings de fluxo.
 * - <queue> : Para uso de filas (não utilizado diretamente neste código, mas incluído por compatibilidade).
 * - "../tripulacao/tripulacao.h" : Para manipulação de dados de tripulantes.
 * - "../passageiros/passageiros.h" : Para manipulação de dados de passageiros.
 * - "../funcoes/fc.h" : Para uso de funções auxiliares, como `isNumero`.
 *
 * AUTHOR : Felipe Cury
 * START DATE : 28/11/2024
 ********************************************************/
#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <cstring>
#include <fstream>
#include <sstream>
#include <queue> // Para usar std::queue

#include "pesquisa.h"
#include "../tripulacao/tripulacao.h"
#include "../passageiros/passageiros.h"
#include "../funcoes/fc.h"
string termoPesquisa;
using namespace std;

/*
 * Função: pesquisarPassageiro
 * Objetivo: Realizar a pesquisa de um passageiro por código ou nome em um arquivo de texto.
 *
 * Descrição:
 * A função solicita ao usuário o código ou nome do passageiro. Se for um código numérico, busca pelo código no arquivo
 * "passageiros.dat" e imprime as últimas 5 linhas anteriores à linha encontrada, além das informações do passageiro. Se
 * for um nome, busca todas as linhas que contêm o nome e imprime os dados até encontrar um separador de seção.
 *
 * Entradas:
 * - Nenhuma entrada direta, recebe input do usuário pelo console.
 *
 * Saídas:
 * - Imprime as informações do passageiro encontrado ou uma mensagem de "não encontrado" caso não haja correspondência.
 */
void pesquisarPassageiro()
{
    cin.ignore();
    printf("Escreva o nome ou o codigo do passageiro:\n");
    getline(cin, termoPesquisa);

    ifstream arquivo("passageiros.dat");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    vector<passageiro> passageiros;
    string linha;
    while (getline(arquivo, linha))
    {
        passageiro p;
        stringstream ss(linha);
        string fidelidade, pontos_fidelidade, codigo;

        getline(ss, p.nome, ',');
        getline(ss, p.endereco, ',');
        getline(ss, p.telefone, ',');
        getline(ss, fidelidade, ',');
        getline(ss, pontos_fidelidade, ',');
        getline(ss, codigo, ',');

        if (fidelidade == "Sim")
        {
            p.fidelidade = 'S';
        }
        else
        {
            p.fidelidade = 'N';
        }
        p.pontos_fidelidade = stoi(pontos_fidelidade);
        p.codigo = stoi(codigo);

        passageiros.push_back(p);
    }
    arquivo.close();

    if (isNumero(termoPesquisa))
    {
        int codigo = stoi(termoPesquisa);
        bool encontrado = false;

        for (const passageiro &p : passageiros)
        {
            if (p.codigo == codigo)
            {
                encontrado = true;
                cout << "Codigo: " << p.codigo << endl;
                cout << "Nome: " << p.nome << endl;
                cout << "Endereco: " << p.endereco << endl;
                cout << "Telefone: " << p.telefone << endl;
                cout << "Fidelidade: " << p.fidelidade << endl;
                cout << "Pontos de fidelidade: " << p.pontos_fidelidade << endl;
                break;
            }
        }
        if (!encontrado)
        {
            cout << "Passageiro com o codigo " << codigo << " nao encontrado." << endl;
        }
    }
    else
    {

        bool encontrado = false;
        for (const passageiro &p : passageiros)
        {
            if (p.nome.find(termoPesquisa) != string::npos)
            {
                encontrado = true;
                cout << "Codigo: " << p.codigo << endl;
                cout << "Nome: " << p.nome << endl;
                cout << "Endereco:" << p.endereco << endl;
                cout << "Telefone: " << p.telefone << endl;
                cout << "Fidelidade: " << p.fidelidade << endl;
                cout << "Pontos de fidelidade: " << p.pontos_fidelidade << endl;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Passageiro com o nome " << termoPesquisa << " nao encontrado." << endl;
        }

        arquivo.close();
    }
}

/*
 * Função: pesquisarTripulacao
 * Objetivo: Realizar a pesquisa de um tripulante por código ou nome em um arquivo de texto.
 *
 * Descrição:
 * A função solicita ao usuário o código ou nome do tripulante. Se for um código numérico, busca pelo código no arquivo
 * "tripulantes.dat" e imprime as últimas 3 linhas anteriores à linha encontrada, além das informações do tripulante. Se
 * for um nome, busca todas as linhas que contêm o nome e imprime os dados até encontrar um separador de seção.
 *
 * Entradas:
 * - Nenhuma entrada direta, recebe input do usuário pelo console.
 *
 * Saídas:
 * - Imprime as informações do tripulante encontrado ou uma mensagem de "não encontrado" caso não haja correspondência.
 */
void pesquisarTripulacao()
{
    cin.ignore();
    printf("Escreva o nome ou o codigo do tripulante:\n");
    getline(cin, termoPesquisa);

   ifstream arquivo("tripulantes.dat");
   if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }
    string linha;
    vector<tripulacao> tripulantes;
while (getline(arquivo,linha))
{
    string codigo;
    tripulacao t;
    stringstream ss(linha);

    getline(ss, t.nome, ',');
    getline(ss, t.cargo, ',');
    getline(ss, t.telefone, ',');
    getline(ss, codigo, ',');

    t.codigo = stoi(codigo);

    tripulantes.push_back(t);
}
arquivo.close();

    if (isNumero(termoPesquisa))
    {
       int codigo = stoi(termoPesquisa);
        bool encontrado = false;

        for (const tripulacao &t : tripulantes)
        {
            if (t.codigo == codigo)
            {
                encontrado = true;
                cout << "Codigo: " << t.codigo << endl;
                cout << "Nome: " << t.nome << endl;
                cout << "Telefone: " << t.telefone << endl;
                cout << "Cargo: " << t.cargo << endl;
                break;
            }
        }

        if (!encontrado)
        {
            cout << "Tripulante com o codigo " << codigo << " nao encontrado." << endl;
        }

        
    }
    else
    {
       
        bool encontrado = false;
        for (const tripulacao &t : tripulantes)
        {
            if (t.nome.find(termoPesquisa) != string::npos)
            {
                encontrado = true;
                cout << "Codigo: " << t.codigo << endl;
                cout << "Nome: " << t.nome << endl;
                cout << "Telefone: " << t.telefone << endl;
                cout << "Cargo: " << t.cargo << endl;
                break;
            }
        }
         

        if (!encontrado)
        {
            cout << "Tripulante com o nome " << termoPesquisa << " nao encontrado." << endl;
        }

        arquivo.close();
    }
}
