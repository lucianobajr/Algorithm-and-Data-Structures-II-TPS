#ifndef MENU_h
#define MENU_h


#include <string.h>
#include <time.h>
#include <ctype.h>
#include "PATRICIA/PATRICIA.h"
#include "TST/tst.h"

void print_menu1();
void print_menu2();
void print_menu3();
char *lower(char *word);
void menu(PATRICIA Patricia_Tree,TSTNode *root);

#endif