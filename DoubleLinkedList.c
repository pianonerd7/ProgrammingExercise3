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

add_to_front(int element, List *list) {
	Node *node = malloc(sizeof(Node));
	node->element = element;
	if (list->firstNode == null) {
		list->firstNode = node;
		list->lastNode = node;
	}
	else {
		node->next = list->firstNode;
		list->firstNode = node;
	}
	list -> firstNode;
}

add_to_back(int element, List *list) {
	Node *node = malloc(sizeof(Node));
	node->element = element;

	if (list->firstNode == null) {
		list->firstNode = node;
		list->lastNode = node;
	}
	else {
		list->lastNode->next = node;
		node.previous = list->lastNode;
		list->lastNode = node;
	}
}

remove_from_front
remove_from_back
transfer
