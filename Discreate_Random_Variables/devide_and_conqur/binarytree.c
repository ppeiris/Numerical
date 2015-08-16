#include <stdio.h>
#include <stdlib.h>





typedef struct node {
    int data;
    struct node *parent;
    struct node *left;
    struct node *right;
} Node;


// void insert(node ** tree, int val)
// {
//     node *temp = NULL;
//     if(!(*tree))
//     {
//         temp = (node *)malloc(sizeof(node));
//         temp->left = temp->right = NULL;
//         temp->data = val;
//         *tree = temp;
//         return;
//     }

//     if(val < (*tree)->data)
//     {
//         insert(&(*tree)->left, val);
//     }
//     else if(val > (*tree)->data)
//     {
//         insert(&(*tree)->right, val);
//     }

// }


/**
    Add a node in to the tree
**/
void addNode(Node *root, int data) {



    Node *newNode =(Node *)malloc(sizeof(Node));
    newNode->data = data;


    if (root->data == -1) {
        // Add the first node to the tree

        newNode->parent = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        root->data = data;



        printf("%d\n", root->data);
        // printf("%d\n", newNode->data);

    }



}


Node *initialize() {
    Node *n = (Node *)malloc(sizeof(Node));
    n->parent = NULL;
    n->left = NULL;
    n->right = NULL;
    n->data = -1;

    return n;
}

int main()
{


    Node *root = initialize();

    addNode(root, 10);

    printf("%d\n", root->data);


    return 0;
}
