#include "menu.h"

void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 41; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (1) para Utilizar a TRIE TST e (2) Utilizar a PATRICIA");
    for (i = 0; i < 50; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n|           ");
    for (i = 0; i < 152; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");

    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    printf("\n");
    fflush(stdin);
}

void print_menu2()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 51; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (1) Para Inserir Palavra, (2) Para Pesquisar Palavra");
    for (i = 0; i < 42; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n|           ");

    for (i = 0; i < 38; i++)
    {
        fputs(" ", stdout);
    }
    printf(" ");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 45; i++)
    {
        fputs(" ", stdout);
    }
    printf(" (3) Para Exibir Todas as Palavras em Ordem Alfabética, (4) Para Contar as Palavras ou");
    for (i = 0; i < 32; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 38; i++)
    {
        fputs(" ", stdout);
    }
    printf(" ");
    for (i = 0; i < 124; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 60; i++)
    {
        fputs(" ", stdout);
    }
    printf("Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 39; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");

    for (i = 0; i < 163; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    printf("\n");
    fflush(stdin);
}

void menu()
{
    print_menu1();
   
    print_menu2();
}