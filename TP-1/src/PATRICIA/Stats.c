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
    S->measure_time.time_insertion = 0.0 ; 
    S->measure_time.time_insertion = 0.0;  
    } 
/***************************************************************************************************************************************/
void Stats_Print_Mount(PATRICIA_Stats S){ 
    printf("\nNumber of words in this tree:  %d\n", S.measure_words);
} 
/****************************************************************************************************************************************/ 
void Stats_Print_Memory_Consumption(PATRICIA_Stats S){ 
    printf("\nTotal of memory consumption:  %ld  kilobytes\n", S.measure_memory);
}  
/****************************************************************************************************************************************/ 
void  Stats_Print_Comparisons_Search(PATRICIA_Stats S){ 
    printf("\nTotal of comparison in the search:  %ld  \n", S.measure_comparisons_search);   
}
/*****************************************************************************************************************************************/  
void  Stats_Print_Comparisons_Insert(PATRICIA_Stats S){ 
    printf("\nTotal of char comparison  in the insertion:  %ld  \n", S.measure_comparisons_insert.Compare_insert_char);    
    printf("\nTotal of index's comparison  in the insertion:  %ld  \n", S.measure_comparisons_insert.Compare_insert_index);  
    printf("\nTotal of internal's node comparison  in the insertion:  %ld  \n", S.measure_comparisons_insert.Compare_insert_internal_node);  
    printf("\nTotal of external's node comparison  in the insertion:  %ld  \n", S.measure_comparisons_insert.Compare_insert_external_node);  
    
}
void Stats_Print_Time(PATRICIA_Stats S){ 
    printf("\nTotal of time spent in the insertion:  %f  \n", S.measure_time.time_insertion);  
    printf("\nTotal of time spent in the search:  %lf  \n", S.measure_time.time_search);  
    
}