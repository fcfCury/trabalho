/********************************************************
 * FILENAME : main.cpp
 * DESCRIPTION : Implementação da função principal para gerenciar operações de passageiros,
 * tripulação, voos, assentos, reservas e pesquisas em um sistema de gerenciamento de voos.
 *
 * FUNCTION :
 * - int main() : Exibe um menu interativo que permite ao usuário realizar operações relacionadas
 * a passageiros, tripulação, voos, assentos, reservas e pesquisas. O menu continua sendo exibido
 * até que o usuário escolha finalizar.
 *
 * INCLUDED FILES :
 * - <iostream> : Para manipulação de entrada e saída padrão (cout, cin).
 * - <cstdio> : Para funções de entrada e saída como printf e scanf.
 * - <string> : Para usar a classe string do C++.
 * - <limits> : Para usar numeric_limits, utilizado para tratar entradas inválidas.
 * - "funcoes/fc.h" : Contém funções gerais para operações como obter o último código.
 * - "passageiros/passageiros.h" : Contém funções para registrar passageiros.
 * - "tripulacao/tripulacao.h" : Contém funções para registrar tripulação.
 * - "voo/voo.h" : Contém funções para registrar voos.
 * - "assento/assento.h" : Contém funções para registrar assentos.
 * - "pesquisa/pesquisa.h" : Contém funções para pesquisar passageiros e tripulantes.
 * - "reserva/reserva.h" : Contém funções para registrar e baixar reservas.
 *
 * NOTES :
 * Este programa é um sistema de gerenciamento de voos, permitindo o cadastro e a busca de informações de passageiros,
 * tripulação, voos, assentos e reservas. O usuário interage com um menu que oferece opções de registro, pesquisa e
 * gerenciamento de reservas.
 *
 * AUTHOR : Felipe Cury
 * START DATE : 23/11/2024
 ********************************************************/

#include <iostream> 
#include <cstdio>   
#include <string>   
#include <limits>   

#include "funcoes/fc.h"          
#include "passageiros/passageiros.h" 
#include "tripulacao/tripulacao.h"  
#include "voo/voo.h"         
#include "assento/assento.h"     
#include "pesquisa/pesquisa.h"    
#include "reserva/reserva.h"     

using namespace std;

// Variáveis globais para operações de pesquisa e reserva
int pesqui, res;

/**
 * FUNCTION: main
 * PURPOSE: Exibir um menu interativo para gerenciar operações de passageiros, tripulação, voos,
 *          assentos, reservas e pesquisas.
 *
 * DESCRIPTION:
 * A função principal do programa exibe um menu com opções para realizar operações específicas.
 * O loop continua até que o usuário escolha a opção para finalizar. As operações incluem
 * registrar passageiros, tripulação, voos, assentos, reservas, e realizar pesquisas de passageiros
 * ou tripulação. A função também trata entradas inválidas para garantir a execução adequada.
 *
 * RETURNS:
 * int : Retorna 0 indicando que o programa terminou com sucesso.
 */
int main()
{
    int menu; // Armazena a opção escolhida pelo usuário no menu principal

    do
    {
        // Exibe o menu principal com as opções disponíveis
        printf("\n-------------------------------------\n");
        printf(">> SELECIONE UMA OPCAO! <<"
               "\n[1] Registrar passageiro"
               "\n[2] Registrar tripulacao"
               "\n[3] Registrar voo"
               "\n[4] Registrar assentos"
               "\n[5] Reservar assento"
               "\n[6] Pesquisar"
               "\n[0] Finalizar cadastro\n");
        printf("|\nV\n");

        // Lê a opção digitada pelo usuário
        if (scanf("%d", &menu) != 1) {
            // Trata entradas inválidas que não são números
            cin.clear(); // Limpa o estado de erro do cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora caracteres restantes no buffer
            cout << "Entrada invalida! Por favor, insira um numero valido.\n";
            continue; // Reinicia o loop para exibir o menu novamente
        }

        printf("-------------------------------------\n");

        // Processa a opção selecionada pelo usuário
        switch (menu)
        {
        case 1:
            // Registra um novo passageiro no sistema
            registrarPassageiro();
            break;

        case 2:
            // Registra os dados da tripulação no sistema
            registraTripulacao();
            break;

        case 3:
            // Registra um novo voo no sistema
            registraVoo();
            break;

        case 4:
            // Registra a configuração dos assentos para um voo
            registrarAssento();
            break;

        case 5:
            // Permite ao usuário escolher entre reservar ou baixar uma reserva
            printf("reservar(1) ou baixar reserva(2)\n");
            scanf("%d", &res);
            if (res == 1) {
                // Registra uma nova reserva de assento
                registrarReserva();
            } else if (res == 2) {
                // Remove ou baixa uma reserva existente
                baixarReserva();
            } else {
                // Informa que a escolha foi inválida
                printf("Escolha invalida\n");
            }
            break;

        case 6:
            // Permite ao usuário pesquisar informações sobre passageiros ou tripulação
            printf("passageiro(1) ou tripulacao(2)\n");
            scanf("%d", &pesqui);
            if (pesqui == 1) {
                // Realiza a pesquisa de um passageiro
                pesquisarPassageiro();
            } else if (pesqui == 2) {
                // Realiza a pesquisa de um membro da tripulação
                pesquisarTripulacao();
            } else {
                // Informa que a escolha foi inválida
                printf("escolha invalida\n");
            }
            break;

        case 0:
            // Encerra a execução do programa
            break;

        default:
            // Informa ao usuário que a opção selecionada é inválida
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }

    } while (menu != 0); // O loop continua até que o usuário escolha a opção 0

    return 0; // Indica que o programa terminou com sucesso
}
