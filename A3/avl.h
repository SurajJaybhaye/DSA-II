typedef struct avl
{
    char *name;
    struct avl *left, *right, *parent;
    int bf;
} avl;

void init(avl **av);
int height(avl *av);
void updateBf(avl *av);
avl *LLRot(avl **av);
avl *RRRot(avl **av);
void insert(avl **av, char *name);
void printCurrentLevel(avl *root, int level);
void LevelOrder(avl *root);
void inorder(avl *av);
avl *rem(avl **root, char *name);
avl *destroyTree(avl **av);