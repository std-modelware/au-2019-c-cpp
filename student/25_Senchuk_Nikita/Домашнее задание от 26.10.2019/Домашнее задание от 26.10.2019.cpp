#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//
//struct Node {
//	int value;
//	int key;
//	Node* left;
//	Node* right;
//};
//
//Node* create_root(int key, int value) {
//	Node node;
//	node.value = value;
//	node.key = key;
//	node.left = NULL;
//	node.right = NULL;
//	return &node;
//}
//
//int tryFind(int key, Node node) {
//	if (node.left == NULL && node.right == NULL && node.key != key) { return 0; }
//	else {
//		int res = 0;
//		if (node.left != NULL) { res = res + tryFind(key, *node.left);};
//		if (node.right != NULL) { res = res + tryFind(key, *node.right); };
//		return res;
//	}
//}
//
//int find(int key, Node node) {
//	if (node.key == key) { return node.value; }
//	if (node.left != NULL && node.left != NULL) {return find(key, *node.left) + find(key, *node.right); }
//	if (node.left != NULL && node.left == NULL) { return find(key, *node.left); }
//	if (node.left == NULL && node.left != NULL) { return find(key, *node.right); }
//	return 0;
//}
//
//void add(int key, int value, Node node) {
//	if (node.left != NULL && node.right != NULL) {
//		if (node.key > key) { add(key, value, *node.left); }
//		if (node.key < key) { add(key, value, *node.right); }
//	}
//	if (node.left == NULL && node.right == NULL) {
//		Node* path = create_root(key, value);
//		if (node.key > key) { node.left = path; }
//		if (node.key < key) { node.right = path; }
//	}
//	if (node.left != NULL && node.right == NULL) {
//		if (node.key > key) { add(key, value, *node.left); }
//		if (node.key < key) {
//			Node* path = create_root(key, value);
//			node.right = path;
//		}
//	}
//	if (node.left == NULL && node.right != NULL) {
//		if (node.key > key) {
//			Node* path = create_root(key, value);
//			node.right = path;
//		}
//		if (node.key < key) { add(key, value, *node.left); }
//	}
//}
//
//Node* findbykey(Node node, int key) {
//	if (node.key == key) { return &node; }
//	if (node.key > key) { return findbykey(*node.left, key); }
//	if (node.key < key) { return findbykey(*node.left, key); }
//}
//
//Node remove(Node node, int key) {
//	if (node.left == NULL && node.right == NULL) { return node; }
//	if (node.key > key) {
//		*node.left = remove(*node.left, key);
//	}
//	else {
//		if (key > node.key) {
//			*node.right = remove(*node.right, key);
//		}
//		else {
//			if (node.left != NULL && node.right != NULL) {
//				node.key = (*node.right).key;
//				node.value = (*node.right).value;
//				*node.right = remove(*node.right, node.key);
//			}
//			else {
//				if (node.left != NULL) {
//					node = *node.left;
//				}
//				else {
//					node = *node.right;
//				}
//			}
//		}
//	}
//}
//
//void printTree(Node node) {
//	cout << "key:" << node.key << "| value:" << node.value << endl;
//	cout << "	";
//	if (node.left != NULL) { printTree(*node.left); }
//	else { cout << "-----"; }
//	cout << "	";
//	if (node.right != NULL) { printTree(*node.right); }
//	else { cout << "-----"; }
//}

void main() {
	int y = 0;
	cout << "Hello" << endl;
/*	Node* node = create_root(5,6);
	add(3, 8, *node);
	add(2, 1, *node);
	add(4, 0,  *node);
	add(1, 0, *node);
	add(7, 2, *node);
	add(6, 0, *node);
	add(9, 3, *node);
	add(8, 1, *node);
	printTree(*node);*/
}