#include <stdio.h>
#include <stdlib.h>
#include "linklistmergesort.h"

void printList(NodeList *list)
{
  if (list->head != NULL) {
    Node *node = list->head;
    int i = 0;
    // printf("\nNode number start with %d and ends with %d\n\n", list->start, list->end);
    for(;;) {
      printf("[ %d ]", node->data);
      if (node->next ==NULL) {
        break;
      }
      printf(" -> ");
      node = node->next;
      i++;
    }
    printf("\n\n");
  } else {
    printf("\n List is empty \n");
  }
}

void checkForErrors(NodeList *list)
{
  Node *node = list->head;
  int tmpData;
  while(node->next != NULL){
    tmpData = node->data;
    if (tmpData > node->next->data) {
      printf("ERROR ---\n");
      break;
    }
    node = node->next;
  }
}

NodeList * initializeList()
{
  int readCount = 20000;
  NodeList *list = (NodeList *)malloc(sizeof(NodeList));
  list->head = NULL;
  list->tail = NULL;
  list->start = NULL;
  list->mid = NULL;
  list->end = NULL;

  // FILE *file = fopen("smallNumbers.txt", "r");
  FILE *file = fopen("IntegerArray.txt", "r");
  Node *node;
  for(int i = 0; i < readCount; i++) {
    node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    fscanf(file, "%d", &node->data);

    if (list->head == NULL) {
      list->head = node;
      list->tail = node;
      list->start = 0;
      list->end = 0;
    } else {
      list->tail->next = node;
      node->prev = list->tail;
      list->tail = list->tail->next;
      list->end++;
    }
    node = NULL;
  }

  free(node);
  return list;
}

void sort(NodeList *list, int start, int mid, int end)
{
  // printf("Sorting [%d : %d : %d] \n", start, mid, end);

  Node *startNode, *endNode, *midNode, *leftNodeIndex, *rightNodeIndex;

  if (list->head != NULL) {
    startNode = list->head;
    endNode = list->head;
    midNode = list->head;
  }

  for(int i = 0; i < start; i++) {
    if (startNode->next != NULL) {
      startNode = startNode->next;
      endNode = startNode;
      midNode = startNode;
    } else {
      printf("Error in the sort method for startNodem\n");
    }
  }

  for(int i = start; i < mid; i++) {
    if (midNode->next != NULL) {
      midNode = midNode->next;
      endNode = midNode;
    }
  }

  for(int i = mid; i < end; i++) {
    if(endNode->next != NULL) {
      endNode = endNode->next;
    }
    // else {
    //   printf("Error in the sort method in endNode\n");
    // }
  }


  leftNodeIndex = startNode;


  if (midNode->next != NULL) {
    rightNodeIndex = midNode->next;
  }
  else {
    rightNodeIndex = midNode;
  }


  int n1 = mid - start + 1;
  int n2 = end - mid;
  int i = 0;
  int j = 0;

  while(i < n1 && j < n2) {

    if (leftNodeIndex->data > rightNodeIndex->data) {

      Node *tmpNode = rightNodeIndex;

      if (rightNodeIndex->next == NULL) {
        rightNodeIndex = NULL;
        tmpNode->prev->next = NULL;

      } else {
        rightNodeIndex = rightNodeIndex->next;
        tmpNode->prev->next = rightNodeIndex;
        rightNodeIndex->prev = tmpNode->prev;
      }

      tmpNode->prev = NULL;
      tmpNode->next = NULL;


      if (leftNodeIndex->prev == NULL) {
        leftNodeIndex->prev = tmpNode;
        tmpNode->next = leftNodeIndex;
        list->head = tmpNode;
      } else {
        tmpNode->next = leftNodeIndex;
        tmpNode->prev = leftNodeIndex->prev;
        leftNodeIndex->prev->next = tmpNode;
        leftNodeIndex->prev = tmpNode;
      }

      tmpNode = NULL;
      // free(tmpNode);

      j++;
    } else {
      if (leftNodeIndex->next != NULL) {
        leftNodeIndex = leftNodeIndex->next;
      }
      i++;
    }


  }

  // printList(list);
  // printf("Nodes [%d %d %d]\n", startNode->data, midNode->data, endNode->data);
}


void divide(NodeList *list, int start, int end)
{
  int mid = start + (end - start)/2;
  if (start < end) {
    divide(list, start, mid);
    divide(list, mid + 1, end);
    sort(list, start, mid, end);
  }
}


int main()
{
  NodeList *nodelist = initializeList();
  // printList(nodelist);

  begin = clock();
/* here, do your time-consuming job */

  divide(nodelist, nodelist->start, nodelist->end);
  printList(nodelist);
  end = clock();
  time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

  checkForErrors(nodelist);

  printList(nodelist);
  printf("Time spend = %f\n", time_spent);

  return 0;
}
