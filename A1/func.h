typedef struct node {
    int data;
    struct node *left,*right;
} node;

typedef node *BT;

void initBT(BT *t);

void insertBST(BT *t, int key);
int searchBST(BT t, int key, int count);

int count(BT t);

void insertBT(BT *t, int key);
// int searchBT(BT t, int key,int *flag);
void searchBT(BT t, int key, int *flag, int *count);

void inorder(BT t);
