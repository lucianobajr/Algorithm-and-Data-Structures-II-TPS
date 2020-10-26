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

#include "Stats.h"   
/**********************************************************************************/
void Sats_Init(PATRICIA_Stats *S){   
    S->measure_words = 0 ;    
    S->measure_memory = 0 ;  
    S->measure_comparisons_search = 0   ;  
    S->measure_comparisons_insert.Compare_insert_char = 0 ;   
    S->measure_comparisons_insert.Compare_insert_index = 0;  
    S->measure_comparisons_insert.Compare_insert_internal_node = 0  ; 
    S->measure_comparisons_insert.Compare_insert_external_node = 0  ; 
    S->measure_time.time_search = 0.0 ; 
    S->measure_time.time_insertion = 0.0;  
    } 
/***************************************************************************************************************************************/
void Stats_Print_Mount(PATRICIA_Stats S){ 
    printf("\nNúmero de palavras nesta árvore:  %d\n", S.measure_words);
} 
/****************************************************************************************************************************************/ 
void Stats_Print_Memory_Consumption(PATRICIA_Stats S){ 
    printf("\nConsumo total de memória:  %ld  kilobytes\n", S.measure_memory);
}  
/****************************************************************************************************************************************/ 
void  Stats_Print_Comparisons_Search(PATRICIA_Stats S){ 
    printf("\nTotal de comparações na pesquisa:  %ld  \n", S.measure_comparisons_search);   
}
/*****************************************************************************************************************************************/  
void  Stats_Print_Comparisons_Insert(PATRICIA_Stats S){ 
    printf("\nTotal de comparações de caracteres na inserção:  %ld  \n", S.measure_comparisons_insert.Compare_insert_char);    
    printf("\nTotal de comparações de índices na inserção:  %ld  \n", S.measure_comparisons_insert.Compare_insert_index);  
    printf("\nTotal de comparações de nó interno na inserção:  %ld  \n", S.measure_comparisons_insert.Compare_insert_internal_node);  
    printf("\nTotal de comparações de nó externo na inserção:  %ld  \n", S.measure_comparisons_insert.Compare_insert_external_node);  
}