#include "PATRICIA.h"

/****************************************************************************************************/
short PATRICIA_External_Node_Verify(Pointer Node){ return (Node->Type == External); }  
short PATRICIA_Internal_Node_Verify(Pointer Node){ return (Node->Type == Internal); }
/****************************************************************************************************/
Pointer PATRICIA_Create_Internal_Node(Pointer *Left, Pointer *Right, int index, char compare, PATRICIA_Stats *S) 
{ 
  Pointer P;  
  struct rusage resource_usage; 
  P = (Pointer)malloc(sizeof(Node_Type)); 
  int ret = getrusage(RUSAGE_SELF,&resource_usage);
      if(ret == 0)
         printf("Memory usage to create an internal node: %ld kilobytes\n",resource_usage.ru_maxrss); 
         (*S).measure_memory += resource_usage.ru_maxrss;  
  P->Type = Internal; 
  P->Node.Internal_Node.Left = *Left;
  P->Node.Internal_Node.Right = *Right;   
  P->Node.Internal_Node.Index = index;   
  P->Node.Internal_Node.Char_to_Compare = compare ;   

  return P;
}   

/****************************************************************************************************/
// just create a new external node that contains, in this case, a word !  
Pointer PATRICIA_Create_External_Node(Key_Word new_word, PATRICIA *P, PATRICIA_Stats *S){
  struct rusage resource_usage;
  *P = (Pointer)malloc(sizeof(Node_Type));  
  int ret = getrusage(RUSAGE_SELF,&resource_usage);
      if(ret == 0)
         printf("Memory usage to create an external node: %ld kilobytes\n",resource_usage.ru_maxrss); 
         (*S).measure_memory += resource_usage.ru_maxrss;  
      
  (*P)->Type = External;  
  (*S).measure_words++;  
  printf(" NUM: %d\n",(*S).measure_words);
  strcpy((*P)->Node.Generic_Word,new_word);  
  return *P; 
}   

/****************************************************************************************************/

void PATRICIA_Node_Search(Key_Word Searched_Word, PATRICIA P, PATRICIA_Stats *S){ 
    // its possible implement the height and comparison calculus here
    int tam_word = strlen(Searched_Word); 
    int index_char = P->Node.Internal_Node.Index; 
    if(PATRICIA_External_Node_Verify(P)){ 
      if(strcmp(Searched_Word,P->Node.Generic_Word) == 0 ){ 
        printf("This word was been finded!\n"); 
        return ; 
      } 
    } 
    
    if(tam_word < P->Node.Internal_Node.Index){ 
      (*S).measure_comparisons_search +=1; 
      PATRICIA_Node_Search(Searched_Word, P->Node.Internal_Node.Left,S);   
      return ;  
    }   
    else if( Searched_Word[index_char] < P->Node.Internal_Node.Char_to_Compare){ 
      (*S).measure_comparisons_search +=1;  
      PATRICIA_Node_Search(Searched_Word, P->Node.Internal_Node.Left,S);    
      return ; 

    }
    else{ 
      (*S).measure_comparisons_search +=1; 
      PATRICIA_Node_Search(Searched_Word, P->Node.Internal_Node.Right,S); 
      return  ; 
       
    } 
    printf("The search was not succeeded... \n The word [%s] isn't in this tree",Searched_Word); 

  
} 

/****************************************************************************************************/
Pointer PATRICIA_Internal_Insert(Key_Word word, PATRICIA *P, short Index, char Distinct_char, PATRICIA_Stats *S){ 
   Pointer new_external_node = NULL;

    if (PATRICIA_External_Node_Verify(*P)) {  
        (*S).measure_comparisons_insert.Compare_insert_index += 1 ;
        PATRICIA_Create_External_Node(word, &new_external_node, S);  
        // this conditional will inform the word size, if the new word size is bigger than the word in the tree 
        // if the word in the tree is less than the new word.... new word go to right
        if (strcmp((*P)->Node.Generic_Word, word) < 0) { 
            (*S).measure_comparisons_insert.Compare_insert_external_node+=1;
            return (PATRICIA_Create_Internal_Node(P, &new_external_node, Index, Distinct_char,S));
        } 
        // if thw word in the tree is bigger than the new word ... new word go to the left 
        else if (strcmp((*P)->Node.Generic_Word, word) > 0) { 
            (*S).measure_comparisons_insert.Compare_insert_external_node+=1; 
            return (PATRICIA_Create_Internal_Node(&new_external_node, P, Index, Distinct_char,S));     
        } 
        return NULL;
    
    } 
    else if (Index < (*P)->Node.Internal_Node.Index) { 
        (*S).measure_comparisons_insert.Compare_insert_index+= 1 ;

        PATRICIA_Create_External_Node(word, &new_external_node,S);
        if (word[Index] < Distinct_char) return (PATRICIA_Create_Internal_Node(&new_external_node, P, Index, Distinct_char,S));
        else return (PATRICIA_Create_Internal_Node(P, &new_external_node, Index, Distinct_char,S));
        
    } 
    else { 
        (*S).measure_comparisons_insert.Compare_insert_index+= 1 ; 
        int Index_Changed = (*P)->Node.Internal_Node.Index;
        
        if (word[Index_Changed] < (*P)->Node.Internal_Node.Char_to_Compare) { 
          (*S).measure_comparisons_insert.Compare_insert_internal_node+=1; 
          (*P)->Node.Internal_Node.Left = PATRICIA_Internal_Insert(word, &(*P)->Node.Internal_Node.Left, Index, Distinct_char,S);
        }
        
        else{  
          (*S).measure_comparisons_insert.Compare_insert_internal_node+=1 ; 
          (*P)->Node.Internal_Node.Right = PATRICIA_Internal_Insert(word, &(*P)->Node.Internal_Node.Right, Index, Distinct_char,S);
        } 
        return (*P);
    }
}


/****************************************************************************************************/
Pointer PATRICIA_Insert(Key_Word word, PATRICIA *tree, PATRICIA_Stats *S){ 
  printf("Enter here !");
  if(*tree == NULL){ 
    printf("The First node that will be inserted, COOL !\n"); 
    return PATRICIA_Create_External_Node(word, tree,S); 
  }  
  // This tree already has some nodes 
  else { 
    PATRICIA P = *tree;  
    int Aux_Index ; 
    int Last_Index ; 
    char aux_char ;  
    // verify  all the internall nodes  
    // later this part  can be implemented using PATRICIA search
    while(!PATRICIA_External_Node_Verify(P)){ 
    
      Last_Index = P->Node.Internal_Node.Index;  
      aux_char = word[P->Node.Internal_Node.Index]; 

      if(aux_char < P->Node.Internal_Node.Char_to_Compare){ 
        (*S).measure_comparisons_insert.Compare_insert_char += 1 ;
        P = P->Node.Internal_Node.Left;     
        }  
      else if(aux_char >= P->Node.Internal_Node.Char_to_Compare){  
        (*S).measure_comparisons_insert.Compare_insert_char += 1 ;
        P = P->Node.Internal_Node.Right; 
        } 
      else{  
        (*S).measure_comparisons_insert.Compare_insert_char += 1 ;
        P = P->Node.Internal_Node.Left; 
        }
    
    } 
    if(strcmp(P->Node.Generic_Word,word) == 0){ 
      printf("The tree already contain this node\n"); 
      return (*tree);
    } 
    else { 
      // the node is really new 
      /**
             * Trecho da função baseado no trio - Vitor Luís, Lucas Duarte e Vinícius Gabriel
             * Copyright © 2018 UFV Florestal. All rights reserved.
             */
            char charDif;
            
            // verifica qual caracter é o diferente 
            // Verifica qual palavra é a menor
            int lowerSize = (strlen(word) < strlen(P->Node.Generic_Word)) ? strlen(word) : strlen(P->Node.Generic_Word);

            for (Aux_Index = 0; Aux_Index <= lowerSize; Aux_Index++) {
                if (word[Aux_Index] != P->Node.Generic_Word[Aux_Index]) {
                    if (word[Aux_Index] < P->Node.Generic_Word[Aux_Index]) {
                        charDif = P->Node.Generic_Word[Aux_Index];
                        break;
                    } else {
                        charDif = word[Aux_Index];
                        break;
                    }
                }
            }

            return PATRICIA_Internal_Insert(word, tree, Aux_Index, charDif,S);
    }
     
  }
}   

/****************************************************************************************************/ 
void PATRICIA_Print_Alphabetical_Order(PATRICIA P){ 
  if(P == NULL) return ;   
  
  if(PATRICIA_Internal_Node_Verify(P))PATRICIA_Print_Alphabetical_Order(P->Node.Internal_Node.Left);
  
  if(PATRICIA_External_Node_Verify(P)) printf("%s\n",P->Node.Generic_Word); 
  
  if(PATRICIA_Internal_Node_Verify(P))PATRICIA_Print_Alphabetical_Order(P->Node.Internal_Node.Right); 
}
/****************************************************************************************************/ 
