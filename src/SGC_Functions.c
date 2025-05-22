#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char nome[50] ;
    char telefone[20] ;
    char email[50] ;
    char id[10] ;
} Contato ;


// Método para apresentar o menu de opções
void menuOpcoes() {
    printf("\n\033[1mMenu de opcoes\033[0m\n\n\
\033[0;33m1 - Adicionar Contatos\033[0m\n\
\033[0;33m2 - Buscar Contatos\033[0m\n\
\033[0;33m3 - Listar Contatos\033[0m\n\
\033[0;33m0 - Sair\033[0m\n\n") ;
}

//  Função que adiciona dinamicamente espaço a lista de conatos a medida que mais contatos são adicionados
void addNumContatos(Contato** ptrListaContatos, int* ptrTamListContatos) {
    //  Realocando um espaço de memória. Adicionando 1 ao tamanho.
    Contato *temp = realloc(*ptrListaContatos, ((*ptrTamListContatos) + 1) * sizeof(Contato)) ;
    if (temp == NULL) {
        printf("\n\033[1;31mErro na realocacao!\033[0m") ;
        free(*ptrListaContatos) ;
        exit(1) ;
    }
    *ptrListaContatos = temp ;
    (*ptrTamListContatos)++ ;
}

void add(Contato* listaContatoIndice) {
    //  Aficionar no array, expandindo a memória dinamicamente
    //  Definindo variaveis de escopo de função para alimentar os campos do struct Contato
    char inputNome[50], inputTelefone[20], inputEmail[50], inputId[10] ;
    //  Alimentando o campo nome
    printf("\n\033[1mNome: \033[0m") ;
    fgets(inputNome, sizeof(inputNome), stdin) ;
    // Removendo o caractere '\n' da string
    inputNome[strcspn(inputNome, "\n")] = '\0' ;
    strcpy(listaContatoIndice->nome, inputNome) ; 
    //  Alimentando o campo telefone
    printf("\033[1mTelefone: \033[0m") ;
    fgets(inputTelefone, sizeof(inputTelefone), stdin) ;
    // Removendo o caractere '\n' da string
    inputTelefone[strcspn(inputTelefone, "\n")] = '\0' ;
    strcpy(listaContatoIndice->telefone, inputTelefone) ;
    //  Alimentando o capo email
    printf("\033[1mE-mail: \033[0m") ;
    fgets(inputEmail, sizeof(inputEmail), stdin) ;
    // Removendo o caractere '\n' da string
    inputEmail[strcspn(inputEmail, "\n")] = '\0' ;
    strcpy(listaContatoIndice->email, inputEmail) ; 
    //  Alimentando o campo ID
    printf("\033[1mID: \033[0m") ;
    fgets(inputId, sizeof(inputId), stdin) ;
    // Removendo o caractere '\n' da string
    inputId[strcspn(inputId, "\n")] = '\0' ;
    strcpy(listaContatoIndice->id, inputId) ;
    printf("\n\033[1;32mContato adicionado com sucesso\033[0m") ;
    puts("");   //  Formatação: pular uma linha
}

//  Função de busca: recebe um ponteiro identificando onde será feita a busca e um buscador, valor o qual representará o parâmetro de busca;
void search(int opcaoBusca, Contato* ptrListaContatos, int numContatosAdd) {   //  Verificar se precisa ser o ponteiro presisa ser um ponteiro de um ponteiro e não somente um ponteiro
    //  Definindo variáveis com escopo de bloco para a busca de contatos
    int flagBusca = 0, comp = 1 ;
    char buscador[50] ;
    //  Busca por nome
    if (opcaoBusca == 1) {
        printf("\033[1m\nNome de busca: \033[0m") ;
        fgets(buscador, sizeof(buscador), stdin) ;
        // Removendo o caractere '\n' da string
        buscador[strcspn(buscador, "\n")] = '\0' ;
        //  Looping de busca
        for (int i=0; i<numContatosAdd; i++) {
            //  Comparando o nome buscado com os nomes na lista de contatos
            comp = strcmp(ptrListaContatos[i].nome, buscador) ;
            if (comp == 0) {
                //  Indica que o nome foi encontrado
                flagBusca = 1 ;
                printf("\033[1;32m") ;
                printf("\nNome: %s\n", ptrListaContatos[i].nome) ;
                printf("Telefone: %s\n", ptrListaContatos[i].telefone) ;
                printf("Email: %s\n", ptrListaContatos[i].email) ;
                printf("ID: %s\n", ptrListaContatos[i].id) ;
            }
            //  Formatação de linha
            puts("\033[0m") ;
        }
    }
    //  Busca por telefone
    else if (opcaoBusca == 2) {
        printf("\033[1m\nTelefone de busca: \033[0m") ;
        fgets(buscador, sizeof(buscador), stdin) ;
        // Removendo o caractere '\n' da string
        buscador[strcspn(buscador, "\n")] = '\0' ;
        //  Looping de busca
        for (int i=0; i<numContatosAdd; i++) {
            //  Comparando o telefone buscado com os telefones na lista de contatos
            comp = strcmp(ptrListaContatos[i].telefone, buscador) ;
            if (comp == 0) {
                //  Indica que o telefone foi encontrado
                flagBusca = 1 ;
                printf("\033[1;32m") ;
                printf("\nNome: %s\n", ptrListaContatos[i].nome) ;
                printf("Telefone: %s\n", ptrListaContatos[i].telefone) ;
                printf("Email: %s\n", ptrListaContatos[i].email) ;
                printf("ID: %s\n", ptrListaContatos[i].id) ;
            }
            //  Formatação de linha
            puts("\033[0m") ;
        }
    }
    else if (opcaoBusca == 3) {
        printf("\033[1m\nEmail de busca: \033[0m") ;
        fgets(buscador, sizeof(buscador), stdin) ;
        // Removendo o caractere '\n' da string
        buscador[strcspn(buscador, "\n")] = '\0' ;
        //  Looping de busca
        for (int i=0; i<numContatosAdd; i++) {
            //  Comparando o email buscado com os emails na lista de contatos
            comp = strcmp(ptrListaContatos[i].email, buscador) ;
            if (comp == 0) {
                //  Indica que o email foi encontrado
                flagBusca = 1 ;
                printf("\033[1;32m") ;
                printf("\nNome: %s\n", ptrListaContatos[i].nome) ;
                printf("Telefone: %s\n", ptrListaContatos[i].telefone) ;
                printf("Email: %s\n", ptrListaContatos[i].email) ;
                printf("ID: %s\n", ptrListaContatos[i].id) ;
            }
            //  Formatação de linha
            puts("\033[0m") ;
        }

    }
    else if (opcaoBusca == 4) {
        printf("\033[1m\nID de busca: \033[0m") ;
        fgets(buscador, sizeof(buscador), stdin) ;
        // Removendo o caractere '\n' da string
        buscador[strcspn(buscador, "\n")] = '\0' ;
        //  Looping de busca
        for (int i=0; i<numContatosAdd; i++) {
            //  Comparando o ID buscado com os IDs na lista de contatos
            comp = strcmp(ptrListaContatos[i].id, buscador) ;
            if (comp == 0) {
                //  Indica que o ID foi encontrado
                flagBusca = 1 ;
                printf("\033[1;32m") ;
                printf("\nNome: %s\n", ptrListaContatos[i].nome) ;
                printf("Telefone: %s\n", ptrListaContatos[i].telefone) ;
                printf("Email: %s\n", ptrListaContatos[i].email) ;
                printf("ID: %s\n", ptrListaContatos[i].id) ;
            }
            //  Formatação de linha
            puts("\033[0m") ;
        }
    }
    if (!flagBusca) printf("\033[1;31m\nContato nao encontrado\033[0m\n") ;
}

//  Função para a listaem dos contatos
void list (Contato* ptrListaContatos, int numContatosAdd) {
    if (numContatosAdd == 0) printf("\n\033[1;31mNenhum contato adicionado\033[0m\n") ;
    //  Exibir todos os contatos com  detahes completos
    for (int i=0; i<numContatosAdd; i++) {
        printf("\033[1;32m") ;
        printf("\nNome: %s\n", ptrListaContatos[i].nome) ;
        printf("Telefone: %s\n", (ptrListaContatos + i)->telefone) ; //   Usando a aritmética com ponteiros
        printf("Email: %s\n", ptrListaContatos[i].email) ;
        printf("ID: %s\n", ptrListaContatos[i].id) ;
    }
    //  Formatação de linha
    puts("\033[0m") ;
}
