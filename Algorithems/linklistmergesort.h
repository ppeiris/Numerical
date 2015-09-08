/*
Defile all the global vaiables for the merge sort using link list
*/
#include <time.h>
typedef struct _node{
    int data;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct _linklistnodes {
    Node *head;
    Node *tail;
    int start;
    int mid;
    int end;
} NodeList;

clock_t begin, end;
double time_spent;

