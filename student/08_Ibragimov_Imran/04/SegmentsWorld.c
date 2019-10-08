#include <math.h>
#include <stdio.h>
#include <stdlib.h> 

struct OneWaySegment {
	int number;
	struct OneWaySegment *next;
};

struct OneWaySegment * CreateOneWaySegment() {

	struct OneWaySegment* newSegment = (struct OneWaySegment *) malloc(sizeof(struct OneWaySegment));
	if (newSegment == NULL) exit(1);
	else return newSegment;
}

struct SinglyLinkedList {
	int segmentCount;
	struct OneWaySegment *first;
};

struct SinglyLinkedList* CreateOneWayChain(int num) {
	if (num == 0) return NULL;
	else {
		struct SinglyLinkedList* myList = (struct SinglyLinkedList *) malloc(sizeof(struct SinglyLinkedList));
		if (myList == NULL) exit(1);

		myList->segmentCount = num;
		struct OneWaySegment * seg = CreateOneWaySegment();
		seg->number = 0;
		myList->first = seg;
		for (int i = 1; i < num; i++) {
			struct OneWaySegment* newSeg = CreateOneWaySegment();
			newSeg->number = i;
			seg->next = newSeg;
			seg = newSeg;
		}
		seg->next = NULL;
		return myList;
	}
}

void OneWayListToString(struct SinglyLinkedList* list) {
	if (list == NULL) printf("NULL \n");
	else {
		struct OneWaySegment* currentSegment = list->first;
		printf("OneWayList: [%d", list->first->number);
		currentSegment = currentSegment->next;
		while (currentSegment != NULL) {
			printf(", %d", currentSegment->number);
			currentSegment = currentSegment->next;
		}
		printf("] \n");
	}
}

struct TwoWaySegment {
	int number;
	struct TwoWaySegment *next;
	struct TwoWaySegment *previous;
};

struct TwoWaySegment * CreateTwoWaySegment() {
	struct TwoWaySegment* newSegment = (struct TwoWaySegment *) malloc(sizeof(struct TwoWaySegment));
	if (newSegment == NULL) exit(1);
	else return newSegment;
}

struct DoubleLinkedList {
	int segmentCount;
	struct TwoWaySegment *first;
	struct TwoWaySegment *last;
};

struct DoubleLinkedList* CreateTwoWayChain(int num) {
	if (num == 0) return NULL;
	else {
		struct DoubleLinkedList* myList = (struct DoubleLinkedList *) malloc(sizeof(struct DoubleLinkedList));
		if (myList == NULL) exit(1);

		myList->segmentCount = num;
		struct TwoWaySegment * seg = CreateTwoWaySegment();
		seg->number = 0;
		myList->first = seg;
		seg->previous = NULL;

		for (int i = 1; i < num; i++) {
			struct TwoWaySegment* newSeg = CreateTwoWaySegment();
			newSeg->number = i;
			seg->next = newSeg;
			newSeg->previous = seg;
			seg = newSeg;
		}
		myList->last = seg;
		seg->next = NULL;
		return myList;
	}
}

enum Direction1D{LEFT, RIGHT};

struct TwoWaySegment* Step(struct TwoWaySegment* start, enum Direction1D dir) {
	if (dir == LEFT) return start->previous;
	else return start->next;
}

void LinkedListDirectionPrint(struct TwoWaySegment* start, enum Direction1D dir) {
	if (start == NULL) printf("NULL \n");
	else {
		struct TwoWaySegment* currentSegment = start;
		printf("Part of Linked List: [%d", start->number);
		currentSegment = Step(currentSegment, dir);
		while (currentSegment != NULL) {
			printf(", %d", currentSegment->number);
			currentSegment = Step(currentSegment, dir);
		}
		printf("]  \n");
	}
}

void main() {
	OneWayListToString(CreateOneWayChain(0));
	OneWayListToString(CreateOneWayChain(1));
	OneWayListToString(CreateOneWayChain(2));
	OneWayListToString(CreateOneWayChain(7));

	struct DoubleLinkedList* myList = CreateTwoWayChain(11);
	LinkedListDirectionPrint(myList->first, RIGHT);
	LinkedListDirectionPrint(myList->last, LEFT);
	LinkedListDirectionPrint(myList->last->previous->previous->previous, LEFT);
}