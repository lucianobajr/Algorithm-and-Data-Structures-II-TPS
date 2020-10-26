/*
   *    ==============GRUPO R2D2==============
   *    =                                    =    
   *    =       Cláudio Barbosa  - 3492      =
   *    =                                    =
   *    =       Guilherme Aguiar - 3496      =
   *    =                                    =
   *    =       Mateus Aparecido - 3858      =
   *    =                                    = 
   *    =       Luciano Belo     - 3897      =
   *    =                                    =  
   *    ======================================
*/

#include "tst.h"

// cria Nó da TST
TSTNodePointer newNode(char data, TST_Stats *T_S)
{   
    struct rusage resource_usage;
    TSTNode *temp = (struct TSTNode *)malloc(sizeof(TSTNode)); 
    int ret = getrusage(RUSAGE_SELF, &resource_usage);
    if (ret == 0) (*T_S).measure_memory += resource_usage.ru_maxrss;
  
    temp->character = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    temp->contador=0; 
    return temp;
}

// insere uma nova palavra na TST
void insert(TSTNodePointer *root, char *word, TST_Stats *T_S)
{
    // Caso Base: Árvore está vazia
    if (!(*root))
        *root = newNode(*word,T_S);

    // Se o caractere atual da palavra for menor que o caractere da raiz,
    // insira esta palavra na subárvore esquerda da raiz
    if ((*word) < (*root)->character){ 
        (*T_S).measure_comparisons_insert.Compare_insert_char+=1 ;
        insert(&((*root)->left), word,T_S);
        (*root)->contador=(*root)->contador+1;
    }
    // Se o caractere atual da palavra for maior do que o caractere da raiz, 
    // então insira esta palavra na subárvore direita da raiz
    else if ((*word) > (*root)->character){
        (*T_S).measure_comparisons_insert.Compare_insert_char+=1 ;
        insert(&((*root)->right), word,T_S);
        (*root)->contador=(*root)->contador+1;
        }
    // Se o caractere atual da palavra for igual ao caractere da raiz,
    else
    {   
        if (*(word + 1)){
            insert(&((*root)->eq), word + 1,T_S);
            (*root)->contador=(*root)->contador+1;
        }
        // último caractere da palavra
        else{
            (*root)->contador=(*root)->contador+1;
            (*root)->isEndOfString = 1;
            }
            
    }
}

// Percorre TST
void printTSTUtil(TSTNodePointer root, char *buffer, int depth)
{
    if (root)
    {
        // Primeira percorra a subárvore esquerda
        printTSTUtil(root->left, buffer, depth);

        // Armazene o caráter deste nó
        buffer[depth] = root->character;
        if (root->isEndOfString)
        {
            buffer[depth + 1] = '\0';
            printf("%s\n", buffer);
        }

        // Percorre subárvore do meio
        printTSTUtil(root->eq, buffer, depth + 1);

        // Finalmente, Percorre a subárvore direita
        printTSTUtil(root->right, buffer, depth);
    }
}

// Função principal pra percorrer TST
// Encapsula printTSTUtil()
void printTST(TSTNodePointer root)
{
    char buffer[MAX];
    printTSTUtil(root, buffer, 0);
}

// Função para pesquisar uma determinada palavra no TST
int searchTST(TSTNodePointer root, char *word, TST_Stats *T_S)
{
    if (!root)
        return 0;

    if (*word < (root)->character){  
        (*T_S).measure_comparisons_search +=1 ;
        return searchTST(root->left, word,T_S);

    }
        
    else if (*word > (root)->character){ 
        (*T_S).measure_comparisons_search+=1 ; 
        return searchTST(root->right, word, T_S);
    }

    else
    {   (*T_S).measure_comparisons_search+=1 ; 
        if (*(word + 1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word + 1, T_S);
    }
}

int counterWords(TSTNodePointer root, TST_Stats *T_S)
{
    int counter = 0;
    (*T_S).measure_words = counterWordsUtil(root, 0, &counter);
}

int counterWordsUtil(TSTNodePointer root,  int depth,int *counter)
{
    if (root)
    {
        // Primeira percorra a subárvore esquerda
        counterWordsUtil(root->left ,depth,counter);

        // Armazene o caráter deste nó
        if (root->isEndOfString)
        {
            (*counter)++;
        }

        // Percorre subárvore do meio
        counterWordsUtil(root->eq ,depth + 1,counter);

        // Finalmente, Percorre a subárvore direita
        counterWordsUtil(root->right ,depth,counter);
    }

    return *counter;
}