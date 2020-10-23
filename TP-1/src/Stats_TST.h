
// THIS FILE IS WILL USE TO QUANTIFY SOME MEASURES OF THE PATRICIA TREE
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h> 
#include <stdio.h>

typedef struct comparison_insert{ 
    long int Compare_insert_index ; 
    long int Compare_insert_char;  
    long int Compare_insert_internal_node ; 
    long int Compare_insert_external_node ; 
}comparison_insert; 

typedef struct Time{ 
    double time_insertion;  
    double time_search;
}Time; 

typedef struct{ 
    int measure_words;  
    long int measure_memory;  
    long int measure_comparisons_search ;  
    comparison_insert measure_comparisons_insert ;   
    Time measure_time;  
}TST_Stats;    
/** 
 * \brief Initialize and set to 0 the respective values 
 * \param S The data type that will be archieve all the metrics 
 */
void TST_Sats_Init(TST_Stats *T_S);  
/** 
 * \brief Show the metrics
 */
void TST_Stats_Print_Mount(TST_Stats T_S);  
void TST_Stats_Print_Memory_Consumption(TST_Stats T_S); 
void TST_Stats_Print_Comparisons_Search(TST_Stats T_S);
void TST_Stats_Print_Comparisons_Insert(TST_Stats T_S);