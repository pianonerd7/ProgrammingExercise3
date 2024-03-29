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
  	node->next = NULL;
  	node->previous = NULL;
    list->firstNode = node;
    list->lastNode = node;
  }
  else {
  	node->previous = NULL;
  	list->firstNode->previous = node;
    node->next = list->firstNode;
    list->firstNode = node;
  }
}

void add_to_back(int element, List *list) {
  struct Node *node = malloc(sizeof(struct Node));
  node->element = element;

  if (list->firstNode == NULL) {
  	node->next = NULL;
  	node->previous = NULL;
    list->firstNode = node;
    list->lastNode = node;
  }
  else {
  	node->next = NULL;
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
  
  if (list->firstNode == list->lastNode) {
  	list->lastNode = NULL;
  	list->firstNode = NULL;
  	free(oldFirst);
  	return value;
  }
  
  list->firstNode = list->firstNode->next;
  list->firstNode->previous = NULL;
  
  free(oldFirst);
  return value;
}

int remove_from_back(List *list) {

  if (list->firstNode == NULL) {
    return -1;
  }

  Node *oldLast = list->lastNode;
  int value = oldLast->element;
  
  if (list->lastNode->previous == NULL) {
  	list->lastNode = NULL;
  	list->firstNode = NULL;
  	return value;
  }
  
  list->lastNode = list->lastNode->previous;
  list->lastNode->next = NULL;
  
  free(oldLast);
  return value;
}

void transfer(int *arr1, int *arr2, int arrLength, void (*insertFunction)(int, List *), int (*removeFunction)(List *)) {

	List *newList = malloc(sizeof(List));
	newList->firstNode = NULL;
	newList->lastNode = NULL;
	
	int i;
	for (i = 0; i < arrLength; i++) {
		insertFunction(arr1[i], newList);
	}
	
	int index = 0;
	while (newList->firstNode != NULL) {
		arr2[index] = removeFunction(newList);
		index++;
	}	
	free(newList);
}

int main() {
	int i;
	int arrLength = 5;
	
	printf("[add_to_front, remove_from_front] \n");
	printf("[Input array {1, 2, 3, 4, 5}] \n");
	printf("[Expected output {5, 4, 3, 2, 1}] \n");
	int A1[] = {1, 2, 3, 4, 5};
	int B1[5];
	transfer(A1, B1, arrLength, add_to_front, remove_from_front);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B1[i]);
	}
	printf("\n\n");
	
	printf("[add_to_back, remove_from_back] \n");
	printf("[Input array {2, 3, 4, 5, 6}] \n");
	printf("[Expected output {6, 5, 4, 3, 2}] \n");
	int A2[] = {2, 3, 4, 5, 6};
	int B2[5];
	transfer(A2, B2, arrLength, add_to_back, remove_from_back);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B2[i]);
	}
	printf("\n\n");
	
	printf("[add_to_front, remove_from_back] \n");
	printf("[Input array {3, 4, 5, 6, 7}] \n");
	printf("[Expected output {3, 4, 5, 6, 7}] \n");
	int A3[] = {3, 4, 5, 6, 7};
	int B3[5];
	transfer(A3, B3, arrLength, add_to_front, remove_from_back);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B3[i]);
	}
	printf("\n\n");
	
	printf("[add_to_back, remove_from_front] \n");
	printf("[Input array {4, 5, 6, 7, 8}] \n");
	printf("[Expected output {4, 5, 6, 7, 8}] \n");
	int A4[] = {4, 5, 6, 7, 8};
	int B4[5];
	transfer(A4, B4, arrLength, add_to_back, remove_from_front);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B4[i]);
	} 
	printf("\n\n");
}
