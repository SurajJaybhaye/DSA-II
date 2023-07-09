#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

typedef struct node{
    int s ;
    int *A ; 
}aBST ; 

void init(aBST *t) ;
void insert(aBST *t, int k) ;
int height(aBST t) ;
int leafCount(aBST t) ;
bool isComplete(aBST t) ;
void levelOrder(aBST t) ;
void preorder2(aBST t, int i) ;
void preorder(aBST t) ; 

