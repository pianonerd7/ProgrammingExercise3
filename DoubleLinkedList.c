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
	printf("transfer enter...");
	List *newList = malloc(sizeof(List));
	printf("made new list...");
	
	int i;
	for (i = 0; i < arrLength; i++) {
		insertFunction(arr1[i], newList);
	}

	for (i = 0; i < arrLength; i++) {
		arr2[i] = removeFunction(newList);
		printf("%d \n", arr2[i]);
	} 
	
	free(newList);
}

int main() {
	int i;
	int arrLength = 5;
	
	int A1[] = {1, 2, 3, 4, 5};
	int B1[5];
	transfer(A1, B1, arrLength, add_to_front, remove_from_front);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B1[i]);
	}

	printf("safe \n\n");

	int A2[] = {2, 3, 4, 5, 6};
	int B2[5];
	transfer(A2, B2, arrLength, add_to_back, remove_from_back);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B2[i]);
	}
	/*
	printf("safe \n\n");

	int A3[] = {3, 4, 5, 6, 7};
	int B3[5];
	transfer(A3, B3, arrLength, add_to_front, remove_from_back);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B3[i]);
	}*/
	
	printf("safe \n\n");
	
	int A4[] = {4, 5, 6, 7, 8};
	int B4[5];
	transfer(A4, B4, arrLength, add_to_back, remove_from_front);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B4[i]);
	}
}
