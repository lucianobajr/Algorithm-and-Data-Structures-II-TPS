
// Developed By Guilherme Aguiar  ... the other names 
/// !!!!!!!!! Attention bitches !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Put your names here guys, don't forget it  ˆˆˆ 
//
#include<stdlib.h>  
#include <stdio.h> 
#include <string.h>
#include <sys/time.h>
#include "Stats.c"
#define D 10    
#define Size 50 
typedef char Key_Word[Size];
typedef unsigned int IndexType;
typedef unsigned char TipoDib;
typedef enum { 
  Internal, External
} TypeNode; 
typedef struct Stats{ 
    int Height;  
    int Comparisons; 
}Stats;
typedef struct Node_Type *Pointer; 
typedef struct Node_Type {
  TypeNode Type;
  union {
    struct {
      IndexType Index;
      Pointer Left, Right;  
      /* This char "Char_to_compare" that will be used to compare the key in the insertion moment.  
      if this char is bigger than the char in the tree, will be allocated to right.  
      Otherwise, it will be allocated to the left side */
      char Char_to_Compare; 
    }Internal_Node; 

    Key_Word Generic_Word;
  
  }Node;  
}Node_Type; 
 
typedef Pointer PATRICIA  ; 
/** 
 *  \brief Verify if the node is an internal node
 *  \brief Verify if the node is an  external node
 *  \param Node The node that will be verified.   
 * 
 **/  
short PATRICIA_Internal_Node_Verify(Pointer Node);
short PATRICIA_External_Node_Verify(Pointer Node); 
/** 
 *  \brief Creates an internal node, this node contains index like the main information and is used to compare with other nodes
 *  \param  Left  
 *  \param Right 
 **/
Pointer PATRICIA_Create_Internal_Node(Pointer *Left, Pointer *Right, int index, char compare, PATRICIA_Stats *S);    
/** 
 *  \brief Create an external
 **/
Pointer PATRICIA_Create_External_Node(Key_Word new_word, PATRICIA *P, PATRICIA_Stats *S); 
/** 
 *  \brief This function is used to find a wished node 
 **/ 
void PATRICIA_Node_Search(Key_Word Searched_Word, PATRICIA P, PATRICIA_Stats *S); 
/** 
 *  \brief This function is an encapsulation of the PATRICIA Insert function, it is in this function that the entire decision, in relation to the type of node, that will be taken
 **/ 
Pointer PATRICIA_Internal_Insert(Key_Word word, PATRICIA *P, short Index, char Distinct_char, PATRICIA_Stats *S); 
/** 
 *  \brief The function of insertion, specifically the prime function, in this occurs the encapsulation of the internal function 
 **/   
Pointer PATRICIA_Insert(Key_Word word, PATRICIA *tree, PATRICIA_Stats *S);
/** 
 *  
 **/  
void PATRICIA_Print_Alphabetical_Order(PATRICIA P);


