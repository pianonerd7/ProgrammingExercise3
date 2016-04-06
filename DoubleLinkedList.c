#include<stdio.h>
#include<stdlib.h>

struct list;
struct node;

typedef struct node {
	int element;
	struct node *next;
	struct node *previous;

} node;

typedef struct list {
	struct node *firstNode;
	struct node *lastNode;
} list;



