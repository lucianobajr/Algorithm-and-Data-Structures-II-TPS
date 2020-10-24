#include "Stats_TST.h"   
/**********************************************************************************/
void TST_Sats_Init(TST_Stats *T_S){   
    T_S->measure_words = 0 ;    
    T_S->measure_memory = 0 ;  
    T_S->measure_comparisons_search = 0   ;  
    T_S->measure_comparisons_insert.Compare_insert_char = 0 ; 
    T_S->measure_time.time_insertion = 0.0 ; 
    T_S->measure_time.time_insertion = 0.0;  
    } 
/***************************************************************************************************************************************/
void TST_Stats_Print_Mount(TST_Stats T_S){ 
    printf("\nNumber of words in this tree:  %d\n", T_S.measure_words);
} 
/****************************************************************************************************************************************/ 
void TST_Stats_Print_Memory_Consumption(TST_Stats T_S){ 
    printf("\nTotal of memory consumption:  %ld  kilobytes\n", T_S.measure_memory);
}  
/****************************************************************************************************************************************/ 
void  TST_Stats_Print_Comparisons_Search(TST_Stats T_S){ 
    printf("\nTotal of comparison in the search:  %ld  \n", T_S.measure_comparisons_search);   
}
/*****************************************************************************************************************************************/  
void  TST_Stats_Print_Comparisons_Insert(TST_Stats T_S){ 
    printf("\nTotal of char comparison  in the insertion:  %ld  \n", T_S.measure_comparisons_insert.Compare_insert_char);    
    
}
void TST_Stats_Print_Time(TST_Stats T_S){ 
    printf("\nTotal of time spent in the insertion:  %f  \n", T_S.measure_time.time_insertion);  
    printf("\nTotal of time spent in the search:  %lf  \n", T_S.measure_time.time_search);  
    
}