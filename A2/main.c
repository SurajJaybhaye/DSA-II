#include "Tree.h"
#include <stdio.h>

int main(){

  aBST t ;
  init(&t) ;

  insert(&t, 10) ;
  insert(&t, 5) ;
  insert(&t, 20) ;
  insert(&t, 2) ;
  insert(&t, 8) ;
  insert(&t, 12) ;
  insert(&t, 50) ;

  preorder(t) ;  

  // 1. height of the tree 
  printf("\nHeight = %d \n", height(t)) ; 
  /* approach: 
  just check which level in array we are 
  relation => just check for which height s/2^(h+1) approches to zero 
  */

  // 2. Count of leaf nodes 
  printf("\nLeaf node = %d\n", leafCount(t)) ; 
  /* approach :
  node is leaf if 
  1. it's value is other than -1 and both left and right childs are -1 
  2. it value is other than -1 and left and right child does not exit 
  */

  // 3. Check whether complete or not 
  printf("\nisComplete = %d \n", isComplete(t)) ; 
  /* approach :
  for height < 2
  always complete otherwise 
  just check second last level is completely filled or not 
  second last level : start = 2^(h-2) end = 2^(h-1)
  */

  // 4. Level order traversal 
  printf("\nLevel order Traversal : \n") ; 
  levelOrder(t) ; 
  /* as this is array this already level order
  we just need to seperate it for different level 
  seperate it at every last node of level that (2^level -1)the node */

  return 0 ; 

}