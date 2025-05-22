#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SGC_Functions.h"


int main() {
    //  Definindo variáveis inteiras
    int numContatosAdd = 0 ;
    int tamListContatos = 1 ;
    //  Criando o ponteiro, lista de contatos, para fazer alocação dinâmica
    Contato* listaContatos ;
    //  Alocando um espaço dinâmico na memória.
    listaContatos = malloc(tamListContatos * sizeof(Contato)) ;
    
    printf("\n\033[1;33mSistema de Gerenciamento de Contatos\033[0m\n") ;

    //  Looping geral de interação com o usuário
    while(1) {
        int opcao = 9 ;
        menuOpcoes() ;
        do {
            printf("Informe a opcao desejada: ") ;
            scanf("%d", &opcao) ;
            //  Tratamento do buffer
            while(getchar() != '\n') ;
            //  Tratamento para entrada inválida
            if (opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3) printf("\n\033[1;31mOpcao invalida. Tente novamente\033[0m\n\n") ;
        } while(opcao != 0 && opcao != 1 && opcao != 2 && opcao != 3) ;

        //  Encerrando o programa
        if (opcao == 0) {
            printf("\033[1;33mPrograma finalizado.\033[0m") ;
            break ;
        }

        //  Adicionando contatos
        else if (opcao == 1) {
            //  Condição para aumentar a capacidade da lista de contatos
            if (numContatosAdd == tamListContatos) {
                //  Chama a função para aumentar a capacidade da lista de contatos
                addNumContatos(&listaContatos, &tamListContatos) ;
            }
            //  Chamando a função add para adiciona contatos. Informando o parâmetro referente ao índice do contato que será adicionado
            add(&listaContatos[numContatosAdd]) ;
            numContatosAdd++ ;
        }

        // Buscando Contatos
        else if (opcao == 2) {
            //  Definindo variáveis com escopo de bloco para a busca de contatos
            int opcaoBusca = 9 ;
            char inputBusca[50] ;
            //  Tratando o caso para nenhnum contato adicionado
            if (numContatosAdd == 0) {
                printf("\n\033[1;31mNenhum contado adicionado\033[0m\n") ;
                continue ;
            }
            //  Opções de busca
            printf("\033[1;33m\nMenu de opcoes de busca\033[0m\n") ;
            printf("\033[1;33m1 - Nome\n2 - Telefone\n3 - Email\n4 - ID\033[0m\n\n") ;
            do {
                printf("Informe a opcao de busca: ") ;
                scanf("%d", &opcaoBusca) ;
                // Tratando o buffer
                while(getchar() != '\n') ;
                //  Tratamento para entrada inválida
                if (opcaoBusca != 1 && opcaoBusca != 2 && opcaoBusca != 3 && opcaoBusca != 4) printf("\n\033[1;31mOpcao invalida. Tente novamente\033[0m\n\n") ;
            } while (opcaoBusca != 1 && opcaoBusca != 2 && opcaoBusca != 3 && opcaoBusca != 4) ;
            //  Chama o método search passadno o valor a ser procurado, a opção que o valor será comparado a lista de contatos e o número de contatos adicionados
            search(opcaoBusca, listaContatos, numContatosAdd) ;
            //  Redefinição para as opcoes padrao
            opcaoBusca = 9;
        }

        //  Listando Contatos
        else if (opcao == 3) {
            if (numContatosAdd != 0) printf("\033[1;33m\nListagem de contatos\033[0m\n") ;
            list(listaContatos, numContatosAdd) ;
        }
    }
    //  Liberando a memória.
    free(listaContatos) ; 

    return 0 ;
}