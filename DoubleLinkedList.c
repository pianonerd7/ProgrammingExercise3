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
  
  int oneElement = 0;
  if (list->lastNode->previous == NULL) {
  	oneElement = 1;
  }

  Node *oldLast = list->lastNode;
  int value = oldLast->element;
  list->lastNode = list->lastNode->previous;
  
  free(oldLast);
  
  if (oneElement) {
  	free(list);
  	printf("SET TO NULL\n");
  }
  
  return value;
}

void transfer(int *arr1, int *arr2, int arrLength, void (*insertFunction)(int, List *), int (*removeFunction)(List *)) {
	
	List *newList = malloc(sizeof(List));
	
	int i;
	for (i = 0; i < arrLength; i++) {
		insertFunction(arr1[i], newList);
	}
	
	
	int index = 0;
	while (newList != NULL) {
	printf("safe1\n");
		//arr2[index] = removeFunction(newList);
		//printf("%d \n", arr2[index]);
		printf("%d \n", removeFunction(newList));
		index++;
		printf("safe2\n");
	}
	
	/*
	for (i = 0; i < arrLength; i++) {
		arr2[i] = removeFunction(newList);
	} */
	
	//free(newList);
}

int main() {
	int i;
	int arrLength = 5;
	
	//int A3[] = {3, 4, 5, 6, 7};
	//int A4[] = {4, 5, 6, 7, 8};
	//int B3[5];
	//int B4[5];
	
	/*
	int A1[] = {1, 2, 3, 4, 5};
	int B1[5];
	transfer(A1, B1, arrLength, add_to_front, remove_from_front);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B1[i]);
	}*/

	
	int A2[] = {2, 3, 4, 5, 6};
	int B2[5];
	transfer(A2, B2, arrLength, add_to_back, remove_from_back);
	for (i = 0; i < arrLength; i++) {
		printf("%d \n", B2[i]);
	}
}
