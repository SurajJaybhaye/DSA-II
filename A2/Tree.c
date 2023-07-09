#include "Tree.h"

void init(aBST *t){
	(t)->A = NULL;
	(t)->s = 0;
	return;
}

int power(int a, int b){
	
	if(b<=0)
		return 1 ;

	return a*power(a, b-1) ;
	
}

void insert(aBST *t, int k){

  if(t->s == 0){
    
    t->A = (int*)malloc(sizeof(int));
    if(!(t->A))
      return;
    t->A[0] = k;
    t->s++;
    return;
  }
  int p = 0;
  while(p < t->s && t->A[p] != -1){
    if(t->A[p] == k)
      return;
    if(t->A[p] > k)
      p = p * 2 + 1;
    else
      p = p * 2 + 2;
  }
  
  if(p < t->s && t->A[p] == -1){
    t->A[p] = k;
    return;
  }
  t->A = realloc(t->A, (p + 1) * sizeof(int));
  if(!(t->A))
    return;
  for(int i = t->s; i <= p; i++)
    t->A[i] = -1;
  t->s = p + 1;
  t->A[p] = k;
  return;
}

int height(aBST t){
  
  if(t.s == 0)
    return -1 ; 
  
  int height = 0 ; 
  int length = t.s-1 ;

  while(length>0){
    length -= 2*(height+1) ; 
    height ++ ;
  }

  return height;

}

int leafCount(aBST t){

    int count = 0 ; 

    for(int i=0; i<t.s; i++){
      if(t.A[i]!=-1 && 2*i+2<t.s && t.A[2*i+1]==-1 && t.A[2*i+2]==-1)
        count ++ ;
      else if(t.A[i]!=-1 && 2*i+1>=t.s)
        count ++ ; 
    }

    return count ; 

}


bool isComplete(aBST t){

  if(t.s<=3)
    return 1 ; 

  int size = t.s ; 

  int ht = height(t) ;
  
  int start = power(2, ht-2) ; 

  for(int i=start; i<power(2,ht-1); i++){
    if(t.A[i]==-1)
      return false  ; 
  }

  return true ; 
  
}

void levelOrder(aBST t){

  int newLine = 1 ; 
  int back = 0 ;
  int count = 1 ; 

  for(int i=0; i<t.s; i++){

    if(back==newLine){
      printf("\n") ; 
      newLine = 2*newLine + 1 ; 
    }

    back ++ ;

    if(t.A[i]!=-1)
      printf("%d ", t.A[i]) ;

  }
  
  return;

}

void preorder2(aBST t, int i){
  if(i >= t.s || t.A[i] == -1)
    return;
  printf("%d\t", t.A[i]);
  preorder2(t, (2 * i) + 1);
  preorder2(t, (2 * i) + 2);
  return;
}

void preorder(aBST t){
  printf("\n") ; 
  preorder2(t , 0);
  printf(" \n") ; 
  return;
}


 
