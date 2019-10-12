#include <stdlib.h>
#pragma once	

typedef struct single_list* node;
typedef struct double_list* node_2;

struct single_list {
	int num;
	node next;
};
struct double_list {
	int num;
	node next;
	node prev;

};

void new_node_1(node* head) {
	node new_node;
	new_node = (node)malloc(sizeof(struct single_list));
	new_node->next = NULL;
	if (*head == NULL) {
		*head = new_node;
		new_node->num = 1;
	}
	else {
		node temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->num = temp->num+1;
	}
}
void new_node_2(node_2* head) {
	node_2 new_node;
	new_node = (node_2)malloc(sizeof(struct double_list));
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*head == NULL) {
		*head = new_node;
		new_node->num = 1;
	}
	else {
		node_2 temp = *head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		new_node->prev = temp;
		temp->next = new_node;
		new_node->num = temp->num + 1;
	}
}
void create_list_1(node* head, int len) {
	for (size_t i = 0; i < len; i++) {
		new_node_1(head);
	}
}
void create_list_2(node_2* head, int len) {
	for (size_t i = 0; i < len; i++) {
		new_node_2(head);
	}
}