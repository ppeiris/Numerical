#include <stdio.h>
#include <stdlib.h>


typedef struct _node{
    int data;
    struct _node *right;
    struct _node *left;
} Node;


Node *initialize()
{
    Node *root = NULL;
    return root;
}

void Inorder(Node *root)
{
    if (root == NULL) {
        return;
    }
    // print the left sub tree - this also print the root node
    Inorder(root->left);

    // if (root->right != NULL && root->left != NULL) {
        printf("data = %d \n", root->data);
    // }
    //print the right sub tree
    Inorder(root->right);

}

void Postorder(Node *root)
{
    if (root == NULL) {
        return;
    }
    // print the left sub tree - this also print the root node
    Inorder(root->left);
    //print the right sub tree
    Inorder(root->right);
    printf("data = %d\n", root->data);
}

Node *Insert(Node *head, int data)
{
    if (head == NULL) {
        head = (Node *)malloc(sizeof(Node));
        head->data = data;
        head->right = head->left = NULL;
    } else {

        if (data < head->data) {
            head->left = Insert(head->left, data);
        } else {
            head->right = Insert(head->right, data);
        }
    }
    return head;
}

void search(Node *root, int data)
{
    if (root == NULL) {
        printf("Sorry data (%d) not found \n", data);
    } else if (root->data == data) {
        printf("hoooray .... value (%d) found in the tree \n", data);
        return;
    } else if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }
}


Node *minValueNode(Node *root)
{
    Node *current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else { // Found the Node to be deleted
        if (root->right != NULL && root->left != NULL) {

            /***************************************************
                Delete a node that has left and right children
            ****************************************************/
            printf("this nee to be deleted %d\n", root->data);
            Node *tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        } else if (root->right == NULL && root->left == NULL) {
            /**************************************************
                Delete a node that does not have cchildren
            ***************************************************/
            free(root);
            return NULL;
        } else if (root->left == NULL && root->right != NULL) {
            /**************************************************
                Delete a node who only has right child
            **************************************************/
            Node *tmp = root->right;
            free(root);
            return tmp;
        } else if (root->left != NULL && root->right == NULL) {
            /**************************************************
                Delete a node who only has left child
            ***************************************************/
            Node *tmp = root->left;
            free(root);
            return tmp;
        }
    }

    return root;
}



int main()
{

    Node* root = NULL;
    root = Insert(root, 8);
    Insert(root, 14);
    Insert(root, 3);
    Insert(root, 6);
    Insert(root, 4);
    Insert(root, 5);
    Insert(root, 7);
    Insert(root, 9);
    Insert(root, 1);
    Insert(root, 10);
    Insert(root, 2);
    Inorder(root);
    printf("=======================\n");
    // search(root, 13);


    printf("Deleting Node (2) (right NULL, left NULL) \n");
    deleteNode(root, 2); // both right and left NULL
    Inorder(root);



    printf("Deleting Node (14) (right NULL, left NOT NULL)\n");
    deleteNode(root, 14); // right = NULL left NOT NULL
    Inorder(root);


    printf("Deleting Node (1) (right Not NULL, left NULL) \n");
    deleteNode(root, 1); // right NOT NULL left NULL
    Inorder(root);


    printf("Deleting Node (3) (right Not NULL, left Not NULL)\n");
    deleteNode(root, 3); // right NOT NULL left NOT NULL
    Inorder(root);


    // Inorder(root);
    return 0;
}
