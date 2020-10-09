
// falta comentar brief
#include<stdlib.h>  
#include <stdio.h> 
#include <string.h>
#include <sys/time.h>
#define D 10    
#define Size 50 
typedef char Key_Word[Size];
typedef unsigned short IndexType;
typedef unsigned char TipoDib;
typedef enum { 

  Internal, External
} TypeNode;
typedef struct Node *Pointer; 
typedef struct Node_Type {
  TypeNode Type;
  union {

    struct {
      IndexType Index;
      Pointer Left, Right;
    }Internal_node; 
    
    Key_Word Generic_Word;
  
  }Node;
}Node_Type; 
typedef Pointer PATRICIA  
/** 
 *  
 **/ 
short PATRICIA_External_Node_Verify(PatNode Node); 
/** 
 *  
 **/
Pointer PATRICIA_Create_Internal_Node(Pointer *Left, Pointer *Right, int index, char compare);    
/** 
 *  
 **/
Pointer PATRICIA_Create_External_Node(Key_Word new_word, PATRICIA *P); 
/** 
 *  
 **/ 
void PATRICIA_Node_Search(Key_Word Searched_Word, PATRICIA *P); 
/** 
 *  
 **/ 
Pointer PATRICIA_Internal_Insert(Key_Word word, PATRICIA *P, short Index, char Distinct_char); 
/** 
 *  
 **/   
Pointer PATRICIA_Insert(Key_Word word, PATRICIA *tree);



