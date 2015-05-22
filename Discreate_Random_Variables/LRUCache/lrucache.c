#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int pageNumber;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List{
    int count;
    int maxCount;
    struct Node *back;
    struct Node *front;
} List;


typedef struct Hash {
    int max;
    Node **nodeList;
} Hash;

/**
* Print the link list
**/
void printList(List *l) {
    if (l->back != NULL) {
        Node *node = l->back;
        while(node != NULL) {
            printf("[ %d ]", node->pageNumber);
            if (node->next != NULL){
                printf(" -> ");
                node = node->next;
            } else {
                node = NULL;
            }
        }
        printf("\n");
    }
}
/**
* Initialize the hash table with max value
**/
Hash *initializeHash(int max) {

    Hash *h = (Hash *)malloc(sizeof(Hash));
    h->max = max;

    //create array (memory locations) to hold pointers to Node
    h->nodeList = (Node **)malloc(sizeof(Node*) * max);
    for (int i = 0; i < max; i++) {
        h->nodeList[i] = NULL;
    }

    return h;
}


/**
* Initialize the link list
**/
List *initializeList(int max) {

    List *l = (List *)malloc(sizeof(List));
    l->count = 0;
    l->maxCount = max;
    l->back = NULL;
    l->front = NULL;

    return l;
}

/**
* Set the page to the cache
**/
void set(List *l, Hash *h, int pageNumber) {

    if (l->count == l->maxCount) { // link list of full need to remove the last node
        Node *delNode = l->back;
        h->nodeList[delNode->pageNumber] = NULL; // clear the hash table value
        l->back = delNode->next;
        printf("Node (%d) deleted \n", delNode->pageNumber);
        free(delNode);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->pageNumber = pageNumber;
    newNode->next = NULL;
    newNode->prev = NULL;
    // load the extra data to the node here ...
    h->nodeList[pageNumber] = newNode;

    if (l->back == NULL && l->front == NULL) { // list is empty
        l->back = l->front = newNode;
    } else { // set the new node to the front of the list
        l->front->next = newNode;
        newNode->prev = l->front;
        l->front = newNode;

    }
    l->count++;
    printf("Page (%d) loading \n", pageNumber);
}


/**
* Read the page, and when page is not found in the cache, it will load the page to the front of
* the list. If the page is already in the cache, move it to the front of the list.
**/

void get(List *l, Hash *h, int pageNumber) {

    if (pageNumber < h->max) {
        Node *readNode = h->nodeList[pageNumber];

        if (readNode == NULL) { // page not in the hash table. load the page
            set(l, h, pageNumber);
        } else { // need to move to the front of the list

            if (readNode->next != NULL && readNode->prev != NULL) { // this node not in the front nor back of the list
                readNode->prev->next = readNode->next;
                readNode->next->prev = readNode->prev;
                readNode->prev = readNode->next = NULL;
                // move the readNode to the front of the list
                l->front->next = readNode;
                l->front = readNode;
                printf("Moving the node (%d) to the front of the list  from the middle position\n", pageNumber);

            } else if (readNode->next != NULL && readNode->prev == NULL) { // last node of the list
                l->back = readNode->next;
                readNode->next = NULL;
                // move the readNode to the front of the list
                l->front->next = readNode;
                l->front = readNode;
                printf("Moving the node (%d) to the front of the list from back of the list\n", pageNumber);

            }


        }
    }
}

int main() {

    const int MAX_LIST = 3; // maximum number of nodes in the link list
    const int MAX_HASH = 5; // maxium capacity of the hash table

    List *l = initializeList(MAX_LIST);
    Hash *h = initializeHash(MAX_HASH);

    get(l, h, 0);
    printList(l);
    get(l, h, 1);
    printList(l);
    get(l, h, 2);
    printList(l);
    get(l, h, 0);
    printList(l);
    get(l, h, 0);
    printList(l);
    get(l, h, 2);
    printList(l);

}
