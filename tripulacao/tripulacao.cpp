/********************************************************
 * FILENAME : tripulacao.cpp
 * DESCRIPTION : Implementação da função para registro de tripulantes.
 *
 * FUNCTION :
 * - void registraTripulacao() : Coleta e registra os dados de um tripulante em um arquivo de texto.
 *
 * INCLUDED FILES :
 * - <iostream> : Para manipulação de entrada e saída padrão.
 * - <fstream> : Para manipulação de arquivos.
 * - <cstring> : Para manipulação de strings C-style.
 * - "tripulacao.h" : Declaração da estrutura tripulacao.
 * - "../funcoes/fc.h" : Declaração das funções auxiliares `validaTelefone` e `obterUltimoCodigo`.
 *
 * NOTES :
 * Esta função coleta os dados de um tripulante (nome, cargo, telefone e código) e os armazena em um arquivo chamado "tripulantes.dat".
 * O código do tripulante é gerado automaticamente com base no último código registrado no arquivo, usando a função `obterUltimoCodigo`.
 * A função inclui validação de entrada para o telefone, utilizando a função `validaTelefone`.
 * 
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 22/11/2024
 ********************************************************/
#include <iostream>
#include <fstream>
#include <cstring>

#include "tripulacao.h"
#include "../funcoes/fc.h"

/*
 * Função: registraTripulacao
 * Objetivo: Registrar os dados de um tripulante em um arquivo de texto.
 * 
 * Entradas: Nenhuma diretamente da função (dados são coletados através do usuário).
 * 
 * Saídas: 
 * - Nenhuma, mas os dados do tripulante são gravados em um arquivo chamado "tripulantes.dat".
 * 
 * Descrição:
 * Esta função coleta e registra as informações de um tripulante, como:
 * 1. Nome
 * 2. Cargo
 * 3. Telefone (validado utilizando a função `validaTelefone` para garantir que o telefone esteja no formato correto).
 * 4. Código (gerado automaticamente com base no último código registrado no arquivo "tripulacao.dat", obtido através da função `obterUltimoCodigo`).
 * 
 * O código do tripulante é então exibido ao usuário para que ele o memorize. Após isso, os dados são salvos em um arquivo de texto, "tripulantes.dat", em formato de texto simples.
 * A função garante que o arquivo seja aberto corretamente para a escrita e que os dados sejam salvos no final do arquivo.
 * 
 * Fluxo da função:
 * 1. O nome e cargo são coletados do usuário.
 * 2. O telefone é validado até que um formato correto seja inserido.
 * 3. O código do tripulante é gerado com base no último código registrado no arquivo "tripulacao.dat".
 * 4. As informações do tripulante são registradas no arquivo "tripulantes.dat".
 * 5. O código do tripulante é exibido para o usuário.
 */

using namespace std;

tripulacao t; 

void registraTripulacao() {
    cin.ignore();         
    cout << "Digite o seu nome: ";
    getline(cin, t.nome); 

    cout << "Digite o seu cargo: ";
    getline(cin, t.cargo); 

    
    do {
        
    } while (validaTelefone(t.telefone) != 0);

    fstream arquivo;

    arquivo.open("tripulantes.dat", fstream::app|fstream::in|fstream::out);
    if (!arquivo)  
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;  
    }

    t.codigo = obterUltimoCodigo("tripulantes.dat") + 1; 

  
   arquivo <<  t.nome << ","
        << t.cargo << ","
        << t.telefone <<","
        << t.codigo << endl;

    
   

    
    arquivo.close();

    cout << "[ Seu codigo eh: " << t.codigo << " Lembre-se dele! ]" << endl;
}