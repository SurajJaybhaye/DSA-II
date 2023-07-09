#include<stdio.h>
#include<stdlib.h>
#include"func.h"

int main(){
    BT t1 = NULL; //BST
    BT t2 = NULL; //BT

    FILE *fptr1;
    fptr1 = fopen("data-1k.txt", "r");
    
    int ans1=0;
    int ans2=0;

    initBT(&t1);
    initBT(&t2);
    int num1;
    for(int i=0;i<1000000;i++){
        fscanf(fptr1, "%d", &num1);
        insertBST(&t1, num1);
        insertBT(&t2, num1);
    }
    
    fclose(fptr1);

    // printf("\n-----------------\n");

    int count1=0;
    int count2=0;
    FILE *fptr3;
    fptr3 = fopen("data-compare.txt", "r");
    int num3;
    int flag=0;
    for(int i=0;i<100;i++){
        fscanf(fptr3, "%d", &num3);

        count1=0;
        count1=searchBST(t1, num3, count1);
        ans1+=count1;
        // printf("\nComparison for %d in Binary Search Tree=%d",num3,count1);

        count2=0;
        flag=0;
        searchBT(t2, num3,&flag, &count2);
        // count2=searchBT(t2, num3,&flag);
        ans2+=count2;
        // printf("\nComparison for %d in Binary Tree=%d\n",num3,count2);
    }
    // printf("\n-----------------\n");
    fclose(fptr3);

    printf("\nTotal Count in BST %d",ans1);
    printf("\nTotal Count in BT %d",ans2);

}