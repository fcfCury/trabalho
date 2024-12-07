/********************************************************
* FILENAME : reserva.cpp
* DESCRIPTION : Implementação das funções para reservar 
acentos nos voos, registras as reservas e os pontos de 
fidelidade e tambem poder remover as reservas.
*
* PUBLIC FUNCTIONS :
* - void registrarReserva()
* - void baixarReserva()
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
* verificar voos, verificar assentos, verificar passageiros 
e registrar novas reservas em arquivos.
*
* AUTHOR : Felipe Cury
* START DATE : 23/11/2024
********************************************************
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>

#include "../assento/assento.h"
#include "reserva.h"
#include "../passageiros/passageiros.h"
#include "../funcoes/fc.h"

using namespace std;

reserva r;

/*
 * Função: registrarReserva
 * Objetivo: Coletar e registrar os dados de uma nova reserva de voo e atualizar o status de ocupação de assentos.
 *
 * Entradas: Nenhuma
 * Saídas: Nenhuma (os dados são salvos nos arquivos "assentos.dat" e "passageiros.dat")
 *
 * Descrição:
 * Esta função realiza as seguintes etapas:
 * 1. Solicita ao usuário o código do voo e o número do assento desejado.
 * 2. Verifica a tarifa do voo consultando o arquivo `voos.dat`.
 * 3. Atualiza o status do assento no arquivo `assentos.dat`, marcando-o como "Ocupado" se estiver disponível.
 * 4. Solicita o código de passageiro e atualiza o arquivo `passageiros.dat` com o voo associado e pontuações de fidelidade, se aplicável.
 * 5. Registra a reserva no sistema ou exibe mensagens de erro se houver problemas como assento já ocupado ou voo não encontrado.

 * Caso uma reserva falhe, a função reverte a alteração do status do assento no arquivo `assentos.dat`.

 * Possíveis mensagens de erro:
 * - "Erro ao abrir o arquivo voos.dat."
 * - "Erro ao abrir o arquivo assentos.dat."
 * - "Erro ao abrir o arquivo passageiros.dat."
 * - "Voo não encontrado no arquivo voos.dat."
 * - "Assento não encontrado no voo especificado."
 * - "Assento já está ocupado. Escolha outro."
 * - "Passageiro não encontrado."
 */


void registrarReserva()
{
    cin.ignore(); // Limpa o buffer de entrada

    std::cout << "Digite o codigo do seu voo: ";
    cin >> r.codigo_voo;
    

    std::cout << "Digite o numero do seu assento: ";
    cin >> r.numero_assento;
    

    std::cout << "Digite o seu codigo de passageiro: ";
    cin >> r.codigo_passageiro;


    ifstream arquipass("passageiros.dat");
    if (!arquipass.is_open())
    {
        std::cout << "Erro ao abrir o arquivo passageiros.dat." << endl;
        return;
    }
    vector<passageiro> passageiros;
    string linha;
    while (getline(arquipass, linha))
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
    arquipass.close();

    bool encontrado = false;

    for (passageiro &p : passageiros)
    {
        if (p.codigo == r.codigo_passageiro)
        {
            encontrado = true;

            if (p.fidelidade == 'S')
            {
                p.pontos_fidelidade += 10;
            }
        }
    }

    if (!encontrado)
    {
        cout << "Passageiro não encontrado" << endl;
        return;
    }

    // Procurar a tarifa do voo no arquivo `voos.dat`

    ifstream arquivo("voos.dat");

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

        if (r.codigo_voo == v.codigo)
        {
            std::cout << "O valor da tarifa para este voo eh: R$ " << v.tarifa << endl;
        }
    }
    arquivo.close();

    // Abrir o arquivo `assentos.dat` para atualizar o status do assento
    ifstream assentos("assentos.dat");
    if (!assentos.is_open())
    {
        std::cout << "Erro ao abrir o arquivo assentos.dat." << endl;
        return;
    }

    fstream arquivos;

    arquivos.open("assentos_temp.dat", fstream::app | fstream::in | fstream::out);
    if (!arquivos)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    vector<assento> assentar;
    while (getline(assentos, linha))
    {
        string numero, codigo_voo;
        stringstream ss(linha);
        assento a;
        getline(ss, codigo_voo, ',');
        getline(ss, numero, ',');
        getline(ss, a.status, ',');

        a.codigo_voo = stoi(codigo_voo);
        a.numero = stoi(numero);

        assentar.push_back(a);
    }
    assentos.close();

    int ex = 0;

    for (assento &a : assentar)
    {
        if (r.codigo_voo == a.codigo_voo && r.numero_assento == a.numero && a.status == "Livre")
        {
            a.status = "Ocupado";
            ex++;
        }

        arquivos << a.codigo_voo << ","
                 << a.numero << ","
                 << a.status << endl;
    }
    if (ex == 0)
    {
        cout << "O assento não existe ou já está ocupado!" << endl;
    }
arquivos.close();
    remove("assentos.dat");
    rename("assentos_temp.dat", "assentos.dat");

    // Atualizar o arquivo `passageiros.dat`

    fstream pas_temp;

    pas_temp.open("passageiros_temp.dat", fstream::app | fstream::in | fstream::out);
    if (!pas_temp)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    for (passageiro &p : passageiros)
    {
        pas_temp << p.nome << ","
                << p.endereco << ","
                << p.telefone << ","
                << (p.fidelidade == 'S' || p.fidelidade == 'N' ? "Sim" : "Não") << ","
                << p.pontos_fidelidade << ","
                << p.codigo << endl;
    }
pas_temp.close();
arquipass.close();

    remove("passageiros.dat");
    rename("passageiros_temp.dat", "passageiros.dat");

    std::cout << "Reserva registrada com sucesso!" << endl;

    fstream arquivoReserva;

    arquivoReserva.open("reserva.dat", fstream::app | fstream::in | fstream::out);
if (!arquivoReserva)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    arquivoReserva <<r.codigo_voo<<","
    <<r.numero_assento<<","
    <<r.codigo_passageiro<<endl;

    arquivoReserva.close();


}

/*
 * Função: baixarReserva
 * Objetivo: Cancelar uma reserva de voo e atualizar o status de ocupação do assento.
 *
 * Entradas: Nenhuma
 * Saídas: Nenhuma (os dados são atualizados nos arquivos "assentos.dat" e "passageiros.dat")
 *
 * Descrição:
 * Esta função realiza as seguintes etapas:
 * 1. Solicita ao usuário o código do voo, número do assento e código do passageiro para a reserva que deve ser cancelada.
 * 2. Atualiza o arquivo `assentos.dat`, marcando o assento como "Livre" se estava "Ocupado".
 * 3. Atualiza o arquivo `passageiros.dat`, removendo a associação do passageiro ao voo especificado.
 * 4. Exibe a tarifa do voo que será devolvida ao passageiro, consultando o arquivo `voos.dat`.
 * 5. Confirma a exclusão da reserva ou exibe mensagens de erro se houver problemas como voo não encontrado ou assento não ocupado.

 * Possíveis mensagens de erro:
 * - "Erro ao abrir o arquivo assentos.dat."
 * - "Erro ao abrir o arquivo passageiros.dat."
 * - "Erro ao abrir o arquivo voos.dat."
 * - "Assento não estava ocupado ou não encontrado."
 * - "Passageiro ou voo não encontrado."
 * - "Voo não encontrado no arquivo voos.dat."
 */
void baixarReserva()
{
    cin.ignore(); // Limpa o buffer de entrada

    std::cout << "Digite o codigo do seu voo: ";
    cin >> r.codigo_voo;

    std::cout << "Digite o numero do seu assento: ";
    cin >> r.numero_assento;

    std::cout << "Digite o seu codigo de passageiro: ";
    cin >> r.codigo_passageiro;

    ifstream arquipass("passageiros.dat");
    if (!arquipass.is_open())
    {
        std::cout << "Erro ao abrir o arquivo passageiros.dat." << endl;
        return;
    }
    vector<passageiro> passageiros;
    string linha;
    while (getline(arquipass, linha))
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
    arquipass.close();

    bool encontrado = false;

    for (passageiro &p : passageiros)
    {
        if (p.codigo == r.codigo_passageiro)
        {
            encontrado = true;

            if (p.fidelidade == 'S')
            {
                p.pontos_fidelidade -= 10;
            }
        }
    }

    if (!encontrado)
    {
        cout << "Passageiro não encontrado" << endl;
        return;
    }

   // Abrir o arquivo `assentos.dat` para atualizar o status do assento
    ifstream assentos("assentos.dat");
    if (!assentos.is_open())
    {
        std::cout << "Erro ao abrir o arquivo assentos.dat." << endl;
        return;
    }

    fstream arquivos;

    arquivos.open("assentos_temp.dat", fstream::app | fstream::in | fstream::out);
    if (!arquivos)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    vector<assento> assentar;
    while (getline(assentos, linha))
    {
        string numero, codigo_voo;
        stringstream ss(linha);
        assento a;
        getline(ss, codigo_voo, ',');
        getline(ss, numero, ',');
        getline(ss, a.status, ',');

        a.codigo_voo = stoi(codigo_voo);
        a.numero = stoi(numero);

        assentar.push_back(a);
    }
    assentos.close();

    int ex = 0;

    for (assento &a : assentar)
    {
        if (r.codigo_voo == a.codigo_voo && r.numero_assento == a.numero && a.status == "Ocupado")
        {
            a.status = "Livre";
            ex++;
        }

        arquivos << a.codigo_voo << ","
                 << a.numero << ","
                 << a.status << endl;
    }
    if (ex == 0)
    {
        cout << "O assento não existe ou está livre!" << endl;
    }
arquivos.close();
    remove("assentos.dat");
    rename("assentos_temp.dat", "assentos.dat");

  // Atualizar o arquivo `passageiros.dat`

    fstream pas_temp;

    pas_temp.open("passageiros_temp.dat", fstream::app | fstream::in | fstream::out);
    if (!pas_temp)
    {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    for (passageiro &p : passageiros)
    {
        pas_temp << p.nome << ","
                << p.endereco << ","
                << p.telefone << ","
                << (p.fidelidade == 'S' || p.fidelidade == 'N' ? "Sim" : "Não") << ","
                << p.pontos_fidelidade << ","
                << p.codigo << endl;
    }
pas_temp.close();
arquipass.close();

    remove("passageiros.dat");
    rename("passageiros_temp.dat", "passageiros.dat");

   

    std::cout << "Reserva baixada com sucesso." << endl;
}