#include <stdio.h>
#include <stdlib.h>

typedef struct treeN treeP;
struct treeN {
    int data;
    int height;
    int bfactor;
    treeP *left;
    treeP *right;
};
treeP *treeRootPtr = NULL;

#define FAILURE  -1
#define SUCCESS  0
#define NODE_NOT_FOUND  -2
#define MEMORY_NOT_FOUND  -3
#define ELEMEMTS 10

treeP search(treeP root, int nodeVal)
{
    if (!root)
        return NULL;

    if (root->data == nodeVal) {
        return root;
    }
    else if (root->data > nodeVal) {
        search(root->left, nodeVal);
    } else {
        search(root->right, nodeVal);
    }
}

int searchNode (treeP root, int nodeVal)
{
    treeP tmp;
    tmp = search(root, nodeVal);
    if (!tmp) {
        printf("NOT FOUND\n");
        return NODE_NOT_FOUND;
    }
    printf("Node FOUND\n");
    return SUCCESS;
}

int insert (treeP *root, int nodeVal)
{
    treeP searchedN = NULL, tmpN = NULL;
    if (!*root) {
        *root = (treeP ) calloc (1, sizeof(struct treeN));
        if (!*root) {
            return MEMORY_NOT_FOUND;
        }
        (*root)->left = (*root)->right = NULL;
        (*root)->data = nodeVal;
        return SUCCESS;
    }
    if (nodeVal < (*root)->data) {
        insert(&(*root)->left, nodeVal);
    } else {
        insert(&(*root)->right, nodeVal);
    }
    return SUCCESS;
}

void inorder (treeP root)
{
    if (root) {
        if (root->left)
            inorder(root->left);

        printf("%d ", root->data);

        if (root->right)
            inorder(root->right);
    }
}

void preorder (treeP root)
{
    if (root) {
        printf("%d ", root->data);

        if (root->left)
            preorder(root->left);

        if (root->right)
            preorder(root->right);
    }
}

void postorder (treeP root)
{
    if (root) {
        if (root->left)
            postorder(root->left);

        if (root->right)
            postorder(root->right);

        printf("%d ", root->data);
    }
}

void create (treeP *treeNodePtr)
{
    int i=0, nodeVal;
    for (i=0; i<ELEMEMTS; i++) {
        scanf("%d", &nodeVal);
        insert(treeNodePtr, nodeVal);
    }
}

treeP searchForDelete(treeP root, int nodeVal, treeP parentPtr)
{
    if (!root)
        return NULL;

    if (root->data == nodeVal) {
        return root;
    }
    else if (root->data > nodeVal) {
        search(root->left, nodeVal);
    } else {
        search(root->right, nodeVal);
    }
}

void deleteNode (int nodeVal, treeP ptr, treeP parent)
{
    treeP tmp = NULL;
    if (!ptr) {
        printf("Tree is NULL \n");
        return;
    }

    if (nodeVal < ptr->data) {
        if (!ptr->left) {
            printf("NOT FOUND\n");
            return;
        }
        deleteNode(nodeVal, ptr->left, ptr);
    } else if (nodeVal > ptr->data) {
        if (!ptr->right) {
            printf("NOT FOUND\n");
            return;
        }
        deleteNode(nodeVal, ptr->right, ptr);
    } else if (nodeVal == ptr->data) {
        printf("FOUND\n");
        if (!ptr->left && !ptr->right) {  //LEAF NODE
            if (parent->left == ptr) {
                parent->left = NULL;
            } else if (parent->right == ptr) {
                parent->right = NULL;
            }
            free(ptr);
            return;
        } else if (ptr->left && !ptr->right) {
            if (parent->left == ptr) {
                parent->left = ptr->left;
            } else if (parent->right == ptr) {
                parent->right = ptr->left;
            }
            free(ptr);
            return;
        } else if (!ptr->left && ptr->right) {
            if (parent->left == ptr) {
                parent->left = ptr->right;
            } else if (parent->right == ptr) {
                parent->right = ptr->right;
            }
            free(ptr);
            return;
        } else { //Both child case
            tmp = ptr->left;
            while(tmp->right) {
                tmp = tmp->right; //Finding the extreme right of left child
            }
            ptr->data = tmp->data;
            deleteNode(tmp->data, ptr->left, ptr);
            return;
        }
    }
}

int main(int argc, char *argv[])
{
    int inOper = -1, valueN = 0;

    printf("AVL operations\n");

    do {
        printf("Press 0 for create\n");
        printf("Press 1 for insert\n");
        printf("Press 2 for delete\n");
        printf("Press 3 for SEARCH\n");
        printf("Press 4 for INORDER traversal\n");
        printf("Press 5 for PRE-ORDER traversal\n");
        printf("Press 6 for POST-ORDER traversal\n");
        printf("Press 7 for EXIT\n");

        scanf("%d", &inOper);
        switch(inOper) {
            case 0:
                printf("Create the AVL\n");
                create(treeRootPtr);
                break;
            case 1:
                printf("Value to be added: ");
                scanf("%d", &valueN);
                insert(&treeRootPtr, valueN);
                break;
            case 2:
                printf("Value to be deleted: ");
                scanf("%d", &valueN);
                deleteNode(valueN, treeRootPtr, NULL);
                break;
            case 3:
                printf("Value to be searched: ");
                scanf("%d", &valueN);
                searchNode(treeRootPtr, valueN);
                break;
            case 4:
                printf("Inorder traversal: ");
                inorder(treeRootPtr);
                printf("\n");
                break;
            case 5:
                printf("preorder traversal: ");
                preorder(treeRootPtr);
                printf("\n");
                break;
            case 6:
                printf("postorder traversal: ");
                postorder(treeRootPtr);
                printf("\n");
                break;
            case 7:
            default:
                printf("GOOD BYE! :)\n");
                return SUCCESS;
        }
    } while (inOper != 7);
}
