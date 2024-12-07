/********************************************************
 * FILENAME : passageiros.cpp
 * DESCRIPTION : Módulo para gerenciamento e registro de passageiros.
 *
 * PUBLIC FUNCTIONS :
 * - void registrarPassageiro()
 *
 * INCLUDED FILES :
 * - <iostream> : Para entrada e saída de dados.
 * - <cstdio> : Para funções de entrada e saída com C.
 * - <string> : Para manipulação de strings no estilo C++.
 * - <cctype> : Para funções de verificação de caracteres.
 * - <cstring> : Para manipulação de strings C-style.
 * - <fstream> : Para operações de leitura e escrita em arquivos.
 * - "../funcoes/fc.h" : Cabeçalho com funções auxiliares de validação.
 * - "passageiros.h" : Cabeçalho contendo a estrutura de dados de passageiro.
 *
 * NOTES :
 * Este módulo implementa a funcionalidade para coletar e registrar
 * os dados de um novo passageiro em um arquivo de texto "passageiros.dat".
 * Ele inclui validação de entrada para o telefone e o status de fidelidade.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 22/11/2024
 ********************************************************/

#include <iostream>   
#include <cstdio>      
#include <string>     
#include <cctype>     
#include <cstring>    
#include <fstream>    


#include "../funcoes/fc.h"
#include "passageiros.h"

using namespace std;


passageiro p; 

/*
 * Função: registrarPassageiro
 * Objetivo: Coletar e registrar os dados de um novo passageiro e salvar no arquivo "passageiros.dat".
 *
 * Entradas: Nenhuma (os dados são coletados a partir da entrada do usuário).
 * Saídas: Nenhuma (os dados são salvos diretamente no arquivo).
 *
 * Descrição:
 * A função coleta os seguintes dados de um passageiro:
 * - Nome (string)
 * - Endereço (string)
 * - Telefone (validação feita por meio de uma função auxiliar `validaTelefone`)
 * - Fidelidade (caractere 's' ou 'n' para sim ou não, respectivamente)
 * 
 * A função atribui um código único ao passageiro, com base no último código registrado no arquivo "passageiros.dat".
 * Os dados são então gravados no arquivo no formato CSV.
 * A função exibe o código gerado para o passageiro.
 */
void registrarPassageiro()
{
    cin.ignore(); 
    
    
    cout << "Digite o seu nome: ";
    getline(cin, p.nome);

    
    cout << "Digite o seu endereco: ";
    getline(cin, p.endereco);

    
    while (validaTelefone(p.telefone) != 0); 

    
    do
    {
        cout << "Fidelidade(s/n): ";
        cin >> p.fidelidade;

        
        if (p.fidelidade != 's' && p.fidelidade != 'n' && p.fidelidade != 'S' && p.fidelidade != 'N')
        {
            cout << "Formato invalido, escreva [S] para sim e [N] para nao.\n";
        }
    } while (p.fidelidade != 's' && p.fidelidade != 'n' && p.fidelidade != 'S' && p.fidelidade != 'N');
 
    fstream arquivo;

    arquivo.open("passageiros.dat", fstream::app|fstream::in|fstream::out);
    if (!arquivo)  
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;  
    }
 p.pontos_fidelidade = 0;

    
    p.codigo = obterUltimoCodigo("passageiros.dat") + 1; 
    
    arquivo <<  p.nome << ","
        << p.endereco << ","
        << p.telefone <<","
        << (p.fidelidade == 's' || p.fidelidade == 'S' ? "Sim" : "Não") <<","
        << p.pontos_fidelidade << ","
        << p.codigo << endl;
          

    arquivo.close();  

    
    cout << "[Seu codigo eh: " << p.codigo << " Lembre-se dele!]\n";
}