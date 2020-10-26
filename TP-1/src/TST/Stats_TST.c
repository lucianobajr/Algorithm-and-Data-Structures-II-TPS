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

#include "Stats_TST.h"   
/**********************************************************************************/
void TST_Sats_Init(TST_Stats *T_S){   
    T_S->measure_words = 0 ;    
    T_S->measure_memory = 0 ;  
    T_S->measure_comparisons_search = 0   ;  
    T_S->measure_comparisons_insert.Compare_insert_char = 0 ; 
    T_S->measure_time.time_search = 0.0 ; 
    T_S->measure_time.time_insertion = 0.0;  
    } 
/***************************************************************************************************************************************/
void TST_Stats_Print_Mount(TST_Stats T_S){ 
    printf("\nNúmero de palavras nesta árvore:  %d\n", T_S.measure_words);
} 
/****************************************************************************************************************************************/ 
void TST_Stats_Print_Memory_Consumption(TST_Stats T_S){ 
    printf("\nConsumo total de memória:  %ld  kilobytes\n", T_S.measure_memory);
}  
/****************************************************************************************************************************************/ 
void  TST_Stats_Print_Comparisons_Search(TST_Stats T_S){ 
    printf("\nTotal de comparações na pesquisa:  %ld  \n", T_S.measure_comparisons_search);   
}
/*****************************************************************************************************************************************/  
void  TST_Stats_Print_Comparisons_Insert(TST_Stats T_S){ 
    printf("\nTotal de comparações de caracteres na inserção: %ld  \n", T_S.measure_comparisons_insert.Compare_insert_char);    
    
}