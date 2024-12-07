/********************************************************
 * FILENAME : voo.cpp
 * DESCRIPTION : Implementação das funções para registro e gerenciamento de voos.
 *
 * FUNCTION :
 * - void registraVoo() : Coleta e valida informações de um voo, registrando-as em um arquivo de texto.
 * - bool checkarPiloto(int id) : Verifica se um tripulante com o código especificado é um piloto.
 *
 * INCLUDED FILES :
 * - <vector> : Para manipulação de vetores.
 * - <iostream> : Para manipulação de entrada e saída padrão.
 * - <fstream> : Para manipulação de arquivos.
 * - <string> : Para manipulação de strings.
 * - <climits> : Para limites de valores numéricos.
 * - <limits> : Para uso de INT_MAX e outros limites.
 * - <sstream> : Para manipulação de strings em streams.
 * - "voo.h" : Declaração da estrutura e funções relacionadas a voo.
 * - "../funcoes/fc.h" : Declaração das funções auxiliares de validação como `validaData`, `validaHorario` e `obterUltimoCodigo`.
 * - "../tripulacao/tripulacao.h" : Declaração da estrutura tripulacao e funções relacionadas à tripulação.
 *
 * NOTES :
 * A função `registraVoo` solicita ao usuário os detalhes do voo, realiza a validação das entradas e registra os dados em um arquivo chamado "voos.dat".
 * A função `checkarPiloto` verifica se um tripulante com um determinado código é um piloto, retornando `true` ou `false`.
 * O código do voo é gerado automaticamente com base no último código registrado, usando a função `obterUltimoCodigo`.
 *
 * AUTHOR : Agni Sofia Gomes Chaves
 * START DATE : 23/11/2024
 ********************************************************/
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <limits> // Para usar INT_MAX
#include <sstream>

#include "voo.h"
#include "../funcoes/fc.h"
#include "../tripulacao/tripulacao.h"

using namespace std;

// Variável global para armazenar os dados do voo
voo v;

/**
 * Função: checkarPiloto
 * Objetivo: Verificar se um tripulante com o código especificado é um piloto.
 *
 * Descrição:
 * Esta função abre o arquivo "tripulantes.dat" e percorre suas linhas para encontrar um tripulante com o código especificado.
 * Se o tripulante encontrado for um piloto, retorna true; caso contrário, retorna false.
 *
 * Entradas:
 * - id (int): Código do tripulante a ser verificado.
 *
 * Saídas:
 * - Retorna um valor booleano (true ou false).
 */
bool checkarPiloto(int id){
   

    ifstream arquivo("tripulantes.dat");
  
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

 bool encontrado = false;

        for (const tripulacao &t : tripulantes)
        {
            if (t.codigo == id)
            {
              if (t.cargo == "piloto")
              {
                return true;
              }
              else return false;
                
            }
            
        }
        return false;
}

/**
 * Função: registraVoo
 * Objetivo: Coletar e validar informações de um voo e registrá-las em um arquivo de texto.
 *
 * Descrição:
 * Esta função solicita ao usuário dados como data, horário, origem, destino, códigos dos tripulantes e tarifa,
 * realizando a devida validação e verificando a disponibilidade dos tripulantes. Em seguida, os detalhes do voo
 * são registrados no arquivo "voos.dat".
 *
 * Entradas:
 * - A função solicita e recebe entradas do usuário para preencher os campos do voo.
 *
 * Saídas:
 * - Registra as informações do voo em um arquivo chamado "voos.dat".
 * - Exibe mensagens de erro ou confirmação durante o processo de entrada de dados.
 */
void registraVoo()
{
    cin.ignore();

    do
    {
        cout << "Digite a data do voo (formato: DD/MM/AAAA): ";
        getline(cin, v.data);
        if (!validaData(v.data))
        {
            cout << "Data invalida. Tente novamente.\n";
        }
    } while (!validaData(v.data));

    do
    {
        cout << "Digite a hora do voo (formato: HH:MM): ";
        getline(cin, v.hora);
        if (!validaHorario(v.hora))
        {
            cout << "Horario invalido. Tente novamente.\n";
        }
    } while (!validaHorario(v.hora));

    cout << "Digite a origem do voo: ";
    getline(cin, v.origem);

    cout << "Digite o destino do voo: ";
    getline(cin, v.destino);

    cout << "Digite o codigo do aviao: ";
    cin >> v.codigo_aviao;

    // Verifica se o código do avião é numérico
    while (cin.fail() || v.codigo_aviao < 0)
    {
        cin.clear();                                         // Limpa o erro de falha de entrada
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora a linha de entrada inválida
        cout << "Erro: O codigo do avião deve conter apenas numeros. Tente novamente: ";
        cin >> v.codigo_aviao;
    }

    do
    {
        cout << "Digite o codigo do piloto: ";
        cin >> v.codigo_piloto;
        if (!checkarPiloto(v.codigo_piloto))
        {
            cout << "Piloto invalido. Verifique o codigo ou cargo e tente novamente.\n";
        }
    } while (!checkarPiloto(v.codigo_piloto));

    do
    {
        cout << "Digite o codigo do copiloto: ";
        cin >> v.codigo_copiloto;
        if (v.codigo_copiloto == v.codigo_piloto)
        {
            cout << "O copiloto nao pode ser o mesmo que o piloto.\n";
            continue;
        }
        if (!checkarPiloto(v.codigo_copiloto))
        {
            cout << "Copiloto invalido. Verifique o codigo ou cargo e tente novamente.\n";
        }
    } while (v.codigo_copiloto == v.codigo_piloto || !checkarPiloto(v.codigo_copiloto));

    do
    {
        cout << "Digite o codigo do comissario: ";
        cin >> v.codigo_comissario;
        if (v.codigo_comissario == v.codigo_piloto || v.codigo_comissario == v.codigo_copiloto)
        {
            cout << "O comissario nao pode ter o mesmo codigo que o piloto ou copiloto.\n";
            continue;
        }
    } while (v.codigo_comissario == v.codigo_piloto || v.codigo_comissario == v.codigo_copiloto);

    v.status = (v.codigo_piloto && v.codigo_copiloto) ? "Ativo" : "Inativo";

    cout << "Digite a tarifa do voo: ";
    cin >> v.tarifa;

      fstream arquivo;

   arquivo.open("voos.dat", fstream::app|fstream::in|fstream::out);
    if (!arquivo)  
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;  
    }

     v.codigo = obterUltimoCodigo("voos.dat") + 1;

    arquivo <<  v.tarifa << ","
        << v.data << ","
        << v.hora <<","
         << v.origem <<","
        << v.destino <<","
        << v.codigo_aviao <<","
         << v.codigo_piloto <<","
          << v.codigo_copiloto <<","
           << v.codigo_comissario <<","
            << v.status <<","
            <<  v.codigo  << endl;
          

    arquivo.close();  

    arquivo.close();
    cout << "[O codigo do voo eh: " << v.codigo << " Lembre-se dele!]\n";
}
