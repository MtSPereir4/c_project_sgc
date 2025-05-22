# Documentação Sistema de Gerenciamento de Contatos (SGC)

## Descrição Geral

O **SGC** (Sistema de Gerenciamento de Contatos) é um programa desenvolvido em linguagem **C** que visa auxiliar na organização de informações relacionadas a uma lista de contatos, bem como exercitar os conceitos aprendidos na disciplina de estrutura de dados. Esse programa aborda, principalmente, conceitos de alocação dinâmica de memória e modularização de funções. O sistema foi estruturado em três arquivos principais:

-   `SGC.c` — Arquivo principal do programa, responsável pela inicialização e controle do fluxo.
    
-   `SGC_Functions.c` — Contém a implementação das funções utilizadas no sistema.
    
-   `SGC_Functions.h` — Arquivo de cabeçalho com as declarações das e definições de tipos.

O sistema adota uma abordagem modular, visando maior organização, facilidade de manutenção e escalabilidade futura.

----------

## Descrição das Funções do Sistema

O sistema conta com diversas funções que implementam as principais operações do programa:

-   **`void menuOpcoes () ;`**  
    Exibe o menu principal do sistema, apresentando as opções disponíveis para interação com usuário, como: adicionar contatos, buscar contatos e listar contatos.
    
-   **`void  addNumContatos (Contato**  ptrListaContatos, int* ptrTamListContatos)`**  
    Amplia a capacidade da lista de contatos.
    
-   **`void  add(Contato*  listaContatoIndice)`**  
    Adiciona um contato a lista de contatos.
    
-   **`void  search(int  opcaoBusca, Contato*  ptrListaContatos, int  numContatosAdd)`**  
    Realiza a busca de um contato informado pelo  usuário. A busca pode ser feita por nome, e-mail, telefone ou id.
    
-   **`void  list (Contato*  ptrListaContatos, int  numContatosAdd) ;`**
Lista todos os contatos adicionados.
 
## Estrutura dos Arquivos

`/c_project_sgc
├── src/
│	├── SGC.c
│	├── SGC_Functions.c
│	├── SGC_Functions.h` 

----------

## Requisitos para Compilação

-   **Compilador C** instalado, como:
    
    -   **GCC** (Linux ou Windows via MinGW)
        
    -   **Clang** (alternativo para Linux/macOS)
        
-   **Terminal** ou **Prompt de Comando** configurado para usar o compilador.
    
-   **Sistema operacional**:
    
    -   Windows 10 ou superior
        
    -   Distribuições Linux
        
    -   macOS (com adaptações se necessário)
        

----------

##  Instruções de Compilação

### 1. Acesse o diretório do projeto:

No terminal ou prompt de comando:

`cd caminho/para/Projeto_SGC` 

### 2. Compile o programa:

#### Usando GCC (Linux ou MinGW no Windows):

`gcc SGC.c SGC_Functions.c -o SGC` 

Explicação:

-   `SGC.c` e `SGC_Functions.c` são os arquivos fonte.
    
-   `-o SGC` define que o executável gerado será chamado `SGC`.
    

----------

##  Instruções de Execução

Após a compilação bem-sucedida:

### Linux/macOS:

`./SGC` 

### Windows:

`SGC.exe` 

> **Nota:** certifique-se de estar no mesmo diretório onde o executável foi gerado.
----------
