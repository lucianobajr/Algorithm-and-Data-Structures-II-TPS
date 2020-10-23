#include "menu.h"
<<<<<<< Updated upstream
#include "tst.h"
#include "patricia.h"
#include "TSTinfo.h"
=======

void menu(PATRICIA Patricia_Tree, TSTNode *root)
{
    int resp[3];
    char word[MAX];
    char search[MAX];
    char aux[MAX];

    double tempo;
    clock_t fim, inicio;
    PATRICIA_Stats S; 
    TST_Stats T_S ; 

    print_menu1();
    scanf("%d", &resp[0]);
    if (resp[0] == 1)
    {   
        do
        {

            print_menu2();
            scanf("%d", &resp[1]);

            //opções para TST
            if (resp[0] == 1 && resp[1] == 1)
            {
                printf("Digite a palavra que será inserida = ");
                scanf("%s", word);
                inicio = clock();
                insert(&root, word,&T_S);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("O TEMPO  GASTO PARA INSERIR A PALAVRA FOI DE %f segundos\n", tempo); 
                T_S.measure_time.time_insertion += tempo;
            }
            if (resp[0] == 1 && resp[1] == 2)
            {
                print_menu3();
                scanf("%d", &resp[2]);
                FILE *teste;

                char *name;
                char aux[50];

                if (resp[2] == 1)
                {
                    name = "./data/baby_shark.txt";
                }
                else if (resp[2] == 2)
                {
                    name = "./data/the_scientist.txt";
                }
                else if (resp[2] == 3)
                {
                    name = "./data/orpheus.txt";
                }
                else if (resp[2] == 4)
                {
                    name = "./data/dic_1.txt";
                }
                else if (resp[2] == 5)
                {
                    name = "./data/dic_2.txt";
                }
                else if (resp[2] == 6)
                {
                    name = "./data/tianastacia.txt";
                }

                teste = fopen(name, "r");
                if (teste == NULL)
                {
                    printf("dando erro");
                }
                else
                {
                    while (!feof(teste))
                    {
                        if (resp[2] == 4 || resp[2] == 5)
                        {
                            fscanf(teste, "%s", aux);
                        }
                        else
                        {
                            fscanf(teste, "%s ", aux);
                        }
                        insert(&root, aux,&T_S);
                    }
                    fclose(teste);
                }
            }

            if (resp[0] == 1 && resp[1] == 3)
            {
                printf("Digite a palavra que será pesquisada = ");
                scanf("%s", search);
                inicio = clock();
                searchTST(root, search,&T_S) ? printf("Encontrado\n") : printf("Não Encontrado\n");
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("O TEMPO  GASTO PARA PESQUISAR A PALAVRA FOI DE %f segundos\n", tempo);
                T_S.measure_time.time_search+= tempo; 
            }
            if (resp[0] == 1 && resp[1] == 4)
            {
                printTST(root);
            }
            if (resp[0] == 1 && resp[1] == 5)
            {
                int counter = 0;
                counterWords(root, &counter);
                counter == 1 ? printf("%d PALAVRA INSERIDA\n", counter) : printf("%d PALAVRAS INSERIDAS\n", counter);
            }
        } while (resp[1] == 1 || resp[1] == 2 || resp[1] == 3 || resp[1] == 4 || resp[1] == 5);
    }
    else
    {   
        Sats_Init(&S);
        do
        {
            print_menu2();
            scanf("%d", &resp[1]);
            //opções para PATRICIA
           
            if (resp[0] == 2 && resp[1] == 1)
            {
                printf("Digite a palavra que será inserida = ");
                scanf("%s", word);
                inicio = clock();
                Patricia_Tree = PATRICIA_Insert(word, &Patricia_Tree, &S);
                fim = clock();
                tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                printf("O TEMPO  GASTO PARA INSERIR A PALAVRA FOI DE %f segundos\n", tempo);

            }
            if (resp[0] == 2 && resp[1] == 2)
            {
                print_menu3();
                scanf("%d", &resp[2]);
                FILE *teste;

                char *name;
                char aux[50];

                if (resp[2] == 1)
                {
                    name = "./data/baby_shark.txt";
                }
                else if (resp[2] == 2)
                {
                    name = "./data/the_scientist.txt";
                }
                else if (resp[2] == 3)
                {
                    name = "./data/orpheus.txt";
                }
                else if (resp[2] == 4)
                {
                    name = "./data/dic_1.txt";
                }
                else if (resp[2] == 5)
                {
                    name = "./data/dic_2.txt";
                }

                teste = fopen(name, "r");
                if (teste == NULL)
                {
                    printf("dando erro");
                }
                else
                {
                    while (!feof(teste))
                    {
                        if (resp[2] == 4 || resp[2] == 5)
                        {
                            fscanf(teste, "%s", aux);
                        }
                        else
                        {
                            fscanf(teste, "%s ", aux);
                        }
                        Patricia_Tree = PATRICIA_Insert(aux, &Patricia_Tree, &S);
                    }
                    fclose(teste);
                }
            }
            if (resp[0] == 2 && resp[1] == 3)
            {
                
                    printf("Digite a palavra que será pesquisada = ");
                    scanf("%s", search);
                    inicio = clock();
                    S.measure_words == 0 ? printf("Nenhuma Palavra Inserida\n") : PATRICIA_Node_Search(search, Patricia_Tree, &S);
                    fim = clock();
                    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
                    printf("O TEMPO  GASTO PARA PESQUISAR A PALAVRA FOI DE %f segundos\n", tempo); 
                    
            }
            if (resp[0] == 2 && resp[1] == 4)
            {
                PATRICIA_Print_Alphabetical_Order(Patricia_Tree);
            }
            if (resp[0] == 2 && resp[1] == 5)
            {
               Stats_Print_Mount(S);
               Stats_Print_Memory_Consumption(S);
               Stats_Print_Comparisons_Insert(S);
            }
            
        } while (resp[1] == 1 || resp[1] == 2 || resp[1] == 3 || resp[1] == 4 || resp[1] == 5);
    }
}
>>>>>>> Stashed changes

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
    printf("Digite (1) Para Inserir word, (2) Para Pesquisar Palavra");
    for (i = 0; i < 45; i++)
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
    fflush(stdin);
}

void menu(TipoApontador p, TSTNode *root)
{
    int resp[2];
    char word[MAX];
    char search[MAX];
    TipoRegistro aux;

    print_menu1();
    scanf("%d", &resp[0]);
    if (resp[0] == 1)
        ;
    else
        inicializa(&p);
    do
    {

        print_menu2();
        scanf("%d", &resp[1]);

        //opções para TST
        if (resp[0] == 1 && resp[1] == 1)
        {
            printf("Digite a palavra que será inserida = ");
            scanf("%s", word);
            insert(&root, word);
        }
        if (resp[0] == 1 && resp[1] == 2)
        {
            printf("Digite a palavra que será pesquisada = ");
            scanf("%s", search);
            searchTST(root, search) ? printf("Encontrado\n") : printf("Não Encontrado\n");
        }
        if (resp[0] == 1 && resp[1] == 3)
        {
            printTST(root);
        }
        if (resp[0] == 1 && resp[1] == 4)
    
        {   
            printf("Quantidade de palavras na arvore: %d \n",root->contador);
            //CountWordsTST(root);  //funcao para contar as palavras                    XXXXXXXXXXXXXXXXXXX
        }

        //opções para PATRICIA
        if (resp[0] == 2 && resp[1] == 1)
        {
            printf("Digite a palavra que será inserida = ");
            scanf("%s", word);
            aux.word = (*word);
            insere(aux, &p);
        }
        if (resp[0] == 2 && resp[1] == 2)
        {
            printf("Digite a palavra que será pesquisada = ");
            scanf("%s", search);
            aux.word = (*search);
            pesquisa(&aux, &p);
        }
        if (resp[0] == 2 && resp[1] == 3)
        {
        }
        if (resp[0] == 2 && resp[1] == 4)
        {
        }
    } while (resp[1] == 1 || resp[1] == 2 || resp[1] == 3 || resp[1] == 4);
}