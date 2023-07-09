#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

void init(avl **av)
{
    *av = NULL;
}

int height(avl *av)
{
    if (av == NULL)
        return 0;
    return height(av->left) > height(av->right) ? height(av->left) + 1 : height(av->right) + 1;
}

void updateBf(avl *av)
{
    if ((av) == NULL)
        return;
    (av)->bf = height((av)->left) - height((av)->right);
    updateBf((av)->left);
    updateBf((av)->right);
}

// ROTATIONS

// 1 . LL

avl *LLRot(avl **av)
{
    avl *head = (*av);
    avl *ret = NULL;
    avl *x = head, *y = head->left, *yR = head->left->right;

    // 1. Parent of x

    if (x->parent != NULL)
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    else
    {
        ret = y;
    }
    y->parent = x->parent;

    // 2. link of x  and  y

    y->right = x;
    x->parent = y;

    // 3. link of right of y
    x->left = yR;
    if (yR)
        yR->parent = x;

    return ret;
}

avl *RRRot(avl **av)
{

    avl *head = (*av);
    avl *ret = NULL;
    avl *x = head, *y = head->right, *yL = head->right->left;

    // 1. Parent of x

    if (x->parent != NULL)
    {
        if (x->parent->left == x)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    else
    {
        ret = y;
    }
    y->parent = x->parent;

    // 2. link of x  and  y

    y->left = x;
    x->parent = y;

    // 3. link of right of y
    x->right = yL;
    if (yL)
        yL->parent = x;

    // printf("%s", ret);
    return ret;
}

void insert(avl **av, char *name)
{
    avl *temp, *head = (*av);
    temp = (avl *)malloc(sizeof(avl));
    temp->name = malloc(20 * sizeof(char));
    strcpy(temp->name, name);
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    temp->bf = 0;
    if (head == NULL)
    {
        (*av) = temp;
        return;
    }
    avl *prev = NULL;

    while (head)
    {
        prev = head;
        if (strcmp(head->name, name) == 0)
            return;
        else if (strcmp(head->name, name) < 0)
            head = head->right;
        else
            head = head->left;
    }

    if (strcmp(prev->name, name) < 0)
        prev->right = temp;
    else
        prev->left = temp;

    temp->parent = prev;

    updateBf(*av);

    avl *unbalancedNode = temp->parent;
    avl *new_head = NULL;

    while (unbalancedNode)
    {
        if (unbalancedNode->bf == 0)
            return;
        // no adjustment needed

        // case 1 : left unbalanced
        if (unbalancedNode->bf == 2)
        {
            // LL or LR inbalance
            if (strcmp(unbalancedNode->left->name, temp->name) > 0)
            {
                new_head = LLRot(&unbalancedNode);
                if (new_head)
                    unbalancedNode = new_head;
                // printf("%d", (*av)->data);
            }
            else
            {
                RRRot(&unbalancedNode->left);
                new_head = LLRot(&unbalancedNode);
                if (new_head)
                    unbalancedNode = new_head;
            }
            break;
        }

        // case 2 : right imbalanced
        if (unbalancedNode->bf == -2)
        {
            // RR or RL inbalance
            if (strcmp(unbalancedNode->right->name, temp->name) < 0)
            {
                new_head = RRRot(&unbalancedNode);
                if (new_head)
                    unbalancedNode = new_head;
            }
            else
            {
                LLRot(&unbalancedNode->right);
                new_head = RRRot(&unbalancedNode);
                if (new_head)
                    unbalancedNode = new_head;
            }
            break;
            ;
        }

        unbalancedNode = unbalancedNode->parent;
    }

    if (new_head)
    {
        (*av) = new_head;
    }

    updateBf(*av);

    return;
}
/* Print nodes at a current level */
void printCurrentLevel(avl *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%s\t %d\n", root->name, root->bf);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void LevelOrder(avl *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

void inorder(avl *av)
{
    if (av == NULL)
        return;
    inorder(av->left);
    printf("%s %d \n", av->name, av->bf);
    inorder(av->right);
}

avl *rem(avl **root, char *name)
{

    avl *temp = (*root);

    if (!temp)
        return (*root);

    avl *prev = NULL;

    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            break;
        }
        prev = temp;
        if (strcmp(temp->name, name) < 0)
            temp = temp->right;
        else
            temp = temp->left;
    }

    // cases
    if (!temp)
        return (*root);

    if (temp->left == NULL && temp->right == NULL)
    {
        if (prev == NULL)
        {
            // printf("hii1");
            avl *temp1 = (*root);
            (*root) = NULL;
            free(temp1);
            return (*root);
        }
        if (prev->left == temp)
        {
            prev->left = NULL;
        }
        else
            prev->right = NULL;
    }

    else if (temp->left == NULL)
    {
        if (prev == NULL)
        {
            (*root) = (*root)->right;
            return (*root);
        }
        if (prev->left == temp)
        {
            prev->left = temp->right;
        }
        else
            prev->right = temp->right;
    }

    else if (temp->right == NULL)
    {
        if (prev == NULL)
        {
            (*root) = (*root)->left;
            return (*root);
        }
        if (prev->left == temp)
        {
            prev->left = temp->left;
        }
        else
            prev->right = temp->left;
    }

    else
    {
        avl *suc = temp->right, *jupr = temp;
        while (suc && suc->left)
        {
            jupr = suc;
            suc = suc->left;
        }
        strcpy(temp->name, suc->name);
        // temp = suc;
        // if (jupr == temp)
        // {
        //     jupr->right = NULL;
        // }
        // else
        //     jupr->left = NULL;
        // if (jupr == temp)
        // {
        //     printf("hello world%s %s %s ", temp, suc, temp->name);
        //     temp->right = suc->right;
        // }
        // else
        //     jupr->left = suc->right;

        if (jupr != temp)
            jupr->left = suc->right;
        else
            jupr->right = suc->right;
        temp = suc;

        // // Copy Successor Data to root
        // root->key = succ->key;
    }

    updateBf(*root);

    free(temp);
    temp = prev;

    while (temp)
    {
        int t = temp->bf;
        if (t == 0)
            break;
        if (t == 2)
        {
            if (strcmp(temp->right->name, name) < 0)
            {
                // printf("here");
                avl *set = LLRot(&temp);
                if (set)
                    temp = set;
            }
            else
            {
                // printf("here2");
                RRRot(&temp->left);
                avl *set = LLRot(&temp);
                if (set)
                    temp = set;
            }
        }
        else if (t == -2)
        {
            printf("here3");

            if (strcmp(temp->right->name, name) > 0)
            {
                // printf("here4");

                avl *set = RRRot(&temp);
                printf("%s", set);
                if (set)
                    temp = set;
            }
            else
            {
                LLRot(&temp->right);
                avl *set = RRRot(&temp);
                if (set)
                    temp = set;
            }
        }
        temp = temp->parent;
    }

    updateBf(*root);
    return (*root);
}

avl *destroyTree(avl **av)
{
    if ((*av) == NULL)
        return NULL;
    destroyTree(&(*av)->left);
    destroyTree(&(*av)->right);
    avl *temp = (*av);
    free(temp);
    (*av) = NULL;

    return NULL;
}