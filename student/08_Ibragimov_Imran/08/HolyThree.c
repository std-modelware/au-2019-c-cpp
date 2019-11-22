#include <assert.h>
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

void TwoPassesWay(struct SinglyLinkedList* list, int k) {
	struct OneWaySegment *p;
	assert(list != NULL);
	p = list->first;
	int count = 0;
	while (p->next != NULL) {
		count++;
		p = p->next;
	}

	p = list->first;
	for(int i = 0; i < count - k; i++) p = p->next;
	printf("%dth-element from the end is: %d  (two passes way) \n", k, p->number);
	//return p->next;
}

void TwoPointerWay(struct SinglyLinkedList* list, int k) {
	struct OneWaySegment *firstP = list->first;
	struct OneWaySegment *secondP = list->first;
	assert(list != NULL);

	for (int i = 0; i < k; i++) {
		assert(secondP->next != NULL);
		secondP = secondP->next;
	}
	while (secondP->next != NULL) {
		secondP = secondP->next;
		firstP = firstP->next;
	}
	printf("%dth-element from the end is: %d  (two pointer way) \n", k, firstP->number);

}

struct OneWaySegment* SubR(struct OneWaySegment* head, int k, int* count,
	struct OneWaySegment** nth_last)
{
	// if list is empty 
	if (!head)
		return;

	SubR(head->next, k, count, nth_last);

	// increment count 
	*count = *count + 1;

	// if true, then head is the nth node from the last 
	if (*count == k+1)
		*nth_last = head;
}

void RecursiveWay(struct SinglyLinkedList* list, int k)
{
	// Initialize 
	struct OneWaySegment* nth_last = NULL;
	int count = 0;

	// find nth node from the last 
	SubR(list->first, k, &count, &nth_last);
	printf("%dth-element from the end is: %d  (recursive way) \n", k, nth_last->number);
}




void main() {
	OneWayListToString(CreateOneWayChain(8));
	TwoPassesWay(CreateOneWayChain(8), 3);
	TwoPointerWay(CreateOneWayChain(8), 3);
	RecursiveWay(CreateOneWayChain(8), 3);

}