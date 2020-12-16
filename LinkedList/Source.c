#include <stdio.h>


typedef struct Node {
	int data;
	struct Node* next;
}Node;


typedef struct {
	struct Node* head;
	struct Node* tail;
	int nodeCount;
}LinkedList;


void initList(LinkedList* pLinkedList) {
	pLinkedList->head = NULL;
	pLinkedList->tail = NULL;
	pLinkedList->nodeCount = 0;
}


void insertAtTail(LinkedList* pLinkedList, int data) {
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		fprintf(stderr, "Unable to allocate new node.\n");
		return;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;

	if (pLinkedList->nodeCount == 0) {
		pLinkedList->head = pNewNode;
		pLinkedList->tail = pNewNode;
	}
	else {
		pLinkedList->tail->next = pNewNode;
		pLinkedList->tail = pNewNode;
	}
	pLinkedList->nodeCount++;
}


void insertAtHead(LinkedList* pLinkedList, int data) {
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == NULL) {
		fprintf(stderr, "Unable to allocate new node.\n");
		return;
	}
	pNewNode->data = data;
	pNewNode->next = NULL;

	if (pLinkedList->nodeCount == 0) {
		pLinkedList->head = pNewNode;
		pLinkedList->tail = pNewNode;
	}
	else {
		pNewNode->next = pLinkedList->head;
		pLinkedList->head = pNewNode;
	}
	pLinkedList->nodeCount++;
}


int deleteFirst(LinkedList* pLinkedList) {
	if (pLinkedList->nodeCount == 0) {
		printf("Linked list is empty\n");
		return -9999;
	}

	Node* first = pLinkedList->head;
	int data = first->data;
	if (pLinkedList->nodeCount == 1) {
		pLinkedList->head = NULL;
		pLinkedList->tail = NULL;
	}
	else {
		pLinkedList->head = first->next;
	}
	free(first);
	pLinkedList->nodeCount--;
	return data;
}


int deleteLast(LinkedList* pLinkedList) {
	if (pLinkedList->nodeCount == 0) {
		printf("Linked list is empty\n");
		return -9999;
	}

	Node* current = pLinkedList->head;
	Node* last = pLinkedList->tail;
	int data = last->data;
	if (pLinkedList->nodeCount == 1) {
		pLinkedList->head = NULL;
		pLinkedList->tail = NULL;
	}
	else {
		while (current->next != pLinkedList->tail) {
			current = current->next;
		}
		pLinkedList->tail = current;
		pLinkedList->tail->next = NULL;
	}
	free(last);
	pLinkedList->nodeCount--;
	return data;
}


Node* find(LinkedList* pLinkedList, int target) {
	Node* current = pLinkedList->head;
	while (current != NULL) {
		if (current->data == target) {
			break;
		}
		current = current->next;
	}
	return current;
}


void printListDetail(LinkedList* pLinkedList) {
	if (pLinkedList->nodeCount == 0) {
		printf("Linked list is empty\n");
		return;
	}

	printf("HEAD: %p\n", pLinkedList->head);
	Node* current = pLinkedList->head;
	int i = 1;
	while (current != NULL) {
		printf("%d. (%p) [%d|%p]\n", i, current, current->data, current->next);
		current = current->next;
		i++;
	}
	printf("TAIL: %p\n", pLinkedList->tail);
}


void printList(LinkedList* pLinkedList) {
	if (pLinkedList->nodeCount == 0) {
		printf("Linked list is empty\n");
		return;
	}

	Node* current = pLinkedList->head;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

