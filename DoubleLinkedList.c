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
  struct Node *node = malloc(sizeof(struct Node));
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
  struct Node *node = malloc(sizeof(struct Node));
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
  int value = oldFirst->element;
  list->firstNode = list->firstNode->next;
  
  //printf("in fxn %d \n", list->firstNode->element);
  
  free(oldFirst);
  
  return value;
}

int remove_from_back(List *list) {

  if (list->firstNode == NULL) {
    return -1;
  }
  
  Node *oldLast = list->lastNode;
  int value = oldLast->element;
  list->lastNode = list->lastNode->previous;
  
  free(oldLast);

  return value;
}

void transfer(int *arr1, int *arr2, int arrLength, void (*insertFunction)(int, List *), int (*removeFunction)(List *)) {
	List *newList = malloc(sizeof(List));
	
	int i, j;
	
	for (i = 0; i < arrLength; i++) {
		add_to_front(arr1[i], newList);
	}
	
	int index = 0;
	while (newList->firstNode != NULL) {
		arr2[index] = remove_from_front(newList);
		index++; 
	}
	
	for (j = 0; j < arrLength; j++) {
		printf("%d \n", arr2[j]);
	}
}

int main() {
	int A[] = {1, 2, 3, 4, 5};
	int B[5];
	
	transfer(A, B, 5, add_to_front, remove_from_front);
  /*
  List *list = malloc(sizeof(List));
  list->firstNode = NULL;
  list->lastNode = NULL;
  
  add_to_front(1, list);
  add_to_back(2, list); 
  
  printf("%d \n", list->firstNode->element);
  printf("%d \n", list->firstNode->next->element);
  
  printf("removing... \n");
  
  remove_from_front(list);
  
  printf("%d \n", list->firstNode->element);
  */
}
