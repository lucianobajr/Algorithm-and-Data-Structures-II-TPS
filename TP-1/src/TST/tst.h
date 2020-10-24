#ifndef TST_h
#define TST_h

#include <stdio.h>
#include <stdlib.h> 
#include "Stats_TST.h"
#define MAX 50

// Nó TST
typedef char data;
typedef struct TSTNode *TSTNodePointer;

typedef struct TSTNode
{
    data character;
    // Verdadeiro || 1 se este caractere for o último caractere de uma das palavras
    short isEndOfString : 1;
    int contador;
    TSTNodePointer left, eq, right;

} TSTNode;

void insert(TSTNodePointer *root, char *word,TST_Stats *T_S);
void printTSTUtil(TSTNodePointer root, char *buffer, int depth);
void printTST(TSTNodePointer root);
int searchTST(TSTNodePointer root, char *word,TST_Stats *T_S);
int counterWords(TSTNodePointer root,  TST_Stats *T_S);
void counterWordsUtil(TSTNodePointer root, int depth,  TST_Stats *T_S);
TSTNodePointer newNode(char data,TST_Stats *T_S);
#endif
