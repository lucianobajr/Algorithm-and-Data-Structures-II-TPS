#include "Stats.h"   

/*******************************************************************/
void Sats_Init(PATRICIA_Stats *S){   
    S->measure_words = 0 ;  
    printf("%d\n",S->measure_words); 
} 
/*******************************************************************/
void Stats_Print_Mount(PATRICIA_Stats S){ 
    printf("Number of words in this tree:  %d\n", S.measure_words);
} 

/*******************************************************************/