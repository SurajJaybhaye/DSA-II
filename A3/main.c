#include <stdio.h>
#include "avl.h"

int main()
{
    avl *av;
    init(&av);
    printf("\n");
    insert(&av, "Anil");
    insert(&av, "Tushar");
    insert(&av, "Amit");
    insert(&av, "Danish");
    insert(&av, "Vineet");
    insert(&av, "Kamal");
    insert(&av, "Chandrakant");
    insert(&av, "Vijay");
    insert(&av, "Zinia");
    // printf("here  %d\n", (av)->data);
    // LevelOrder(av);
    // preorder(av);
    // rem(&av, "Zinia");
    // rem(&av, 70);
    // rem(&av, 70);
    // rem(&av, 20);
    // rem(&av, 30);
    // rem(&av, 40);

    // printf("\n");

    // LevelOrder(av);

    // insert(&av, "3");
    // insert(&av, "2");
    // insert(&av, "250");
    // insert(&av, "600");
    // insert(&av, "7");
    // insert(&av, "8");
    // insert(&av, "754");

    // printf("seperate\n");
    // preorder(av);

    // rem(&av, "3");
    // rem(&av, "2");
    // rem(&av, "250");
    // rem(&av, "600");
    // rem(&av, "7");
    // rem(&av, "8");
    // rem(&av, "754");

    // preorder(av);

    while (1)
    {
        printf("Enter \n1. Insert Student node \n2. Remove Student Node \n3 Inorder Traverse \n4 Destroy Tree \n-1 FOR EXIT\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter name of student to insert \n");
            char name[20];
            scanf("%s", name);
            insert(&av, name);
        }
        else if (choice == 2)
        {
            printf("Enter the name of student to be deleted \n");
            char name[20];
            scanf("%s", name);
            av = rem(&av, name);
        }
        else if (choice == 3)
        {
            inorder(av);
        }
        else if (choice == 4)
        {
            av = destroyTree(&av);
            printf( av);
        }
        else if (choice == -1)
        {
            break;
        }
        else
        {
            printf("Enter valid choice \n");
        }
    }

    return 0;
}
