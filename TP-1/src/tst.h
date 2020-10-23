#ifndef TST_h
#define TST_h

#include <stdio.h>
#include <stdlib.h>
#define MAX 50

// Nó TST
typedef char data;
typedef struct TSTNode *TSTNodePointer;

typedef struct TSTNode
{
    data character;
    // Verdadeiro || 1 se este caractere for o último caractere de uma das palavras
    short isEndOfString : 1;
    TSTNodePointer left, eq, right;

} TSTNode;

void insert(TSTNodePointer *root, char *word);
void printTSTUtil(TSTNodePointer root, char *buffer, int depth);
void printTST(TSTNodePointer root);
int searchTST(TSTNodePointer root, char *word);
int counterWords(TSTNodePointer root,int *counter);
void counterWordsUtil(TSTNodePointer root, int *counter, int depth);
TSTNodePointer newNode(char data);
#endif
