#include<stdio.h>
#include<stdlib.h>

struct List;
struct Node;

typedef struct Node {
  int element;
  struct Node *next;
  struct Node *previous;
} Node;

typedef struct List {
  struct Node *firstNode;
  struct Node *lastNode;
} List;

void add_to_front(int element, List *list);
void add_to_back(int element, List *list);
int remove_from_front(List *list);
int remove_from_back(List *list);
void transfer();

void add_to_front(int element, List *list) {
  Node *node = malloc(sizeof(Node));
  node->element = element;
  if (list->firstNode == NULL) {
    list->firstNode = node;
    list->lastNode = node;
  }
  else {
    node->next = list->firstNode;
    list->firstNode = node;
  }
}

void add_to_back(int element, List *list) {
  Node *node = malloc(sizeof(Node));
  node->element = element;

  if (list->firstNode == NULL) {
    list->firstNode = node;
    list->lastNode = node;
  }
  else {
    list->lastNode->next = node;
    node->previous = list->lastNode;
    list->lastNode = node;
  }
}

int remove_from_front(List *list) {

  if (list->firstNode == NULL) {
    return -1;
  }

  Node *oldFirst = list->firstNode;
  int *value = oldFirst->element;
  list->firstNode = list->firstNode->next;
  free(oldFirst);
  return value;
}

int remove_from_back(List *list) {

  if (list->firstNode == NULL) {
    return NULL;
  }

  return 1;
}

void transfer() {

}

void main() {
  /*
  List list = {null, null};
  add_to_front(list, 1);
  add_to_back(list, 2);

  printf("first: " + list->element);
  printf("second: " + list->next->element);*/
}
