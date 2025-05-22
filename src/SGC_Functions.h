#ifndef SGC_FUNCTIONS_H
#define SGC_FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//  Definição da Strunct
typedef struct {
    char nome[50] ;
    char telefone[20] ;
    char email[50] ;
    char id[10] ;
} Contato ;


//  Declaração das Funções
// Método para apresentar o menu de opções
void menuOpcoes () ;
//  Método que adiciona dinamicamente espaço a lista de conatos a medida que mais contatos são adicionados
void addNumContatos (Contato** ptrListaContatos, int *ptrTamListContatos) ;
// Método que adiciona contatos a lista de contatos
void add(Contato* listaContatoIndice) ;
void search(int opcaoBusca, Contato* ptrListaContatos, int numContatosAdd) ;
void list (Contato* ptrListaContatos, int numContatosAdd) ;

#endif