#include <stdio.h>
#include <stdlib.h>

#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

typedef struct Node {
    int key;
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

Node *root;

Node* create_node(int key, int value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->key = key;
    tmp->value = value;
    tmp->parent = parent;
    return tmp;
}

void add(int key, int value) {
    Node *tmp = root;

    while (tmp) {
        if (CMP_GT(value, tmp->value)) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = create_node(key, value, tmp);
                return;
            }
        } else if (CMP_LT(value, tmp->value)) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = create_node(key, value, tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}

void create_root(int key, int value) {
    root = create_node(key, value, NULL);
}

Node* find_node(Node* head, int key) {
    if (head == NULL) {
        return 0;
    }

    if (head->key == key) {
        return head;
    }

    Node* left = find_node(head->left, key);
    Node* right = find_node(head->right, key);

    if (left == NULL) return right;
    else return left;
}

int try_find(int key) {
    if (find_node(root, key) == NULL) return 0;
    else return 1;
}

int find(int key) {
    return find_node(root, key)->value;
}

void removeNodeByPtr(Node *target) {
    if (target->left && target->right) {
        Node *localMax = target->left;
        while (localMax->right) {
            localMax = localMax->right;
        }
        target->value = localMax->value;
        target->key = localMax->key;
        removeNodeByPtr(localMax);
        return;
    } else if (target->left) {
        if (target == target->parent->left) {
            target->parent->left = target->left;
        } else {
            target->parent->right = target->left;
        }
    } else if (target->right) {
        if (target == target->parent->right) {
            target->parent->right = target->right;
        } else {
            target->parent->left = target->right;
        }
    } else {
        if (target == target->parent->left) {
            target->parent->left = NULL;
        } else {
            target->parent->right = NULL;
        }
    }
    free(target);
}

void delete(int key) {
    Node *target = find_node(root, key);
    removeNodeByPtr(target);
}

void printTree(Node *head, const char *dir, int level) {
    if (head) {
        printf("lvl %d %s = %d,%d\n", level, dir, head->key, head->value);
        printTree(head->left, "left", level+1);
        printTree(head->right, "right", level+1);
    }
}

int main() {
    create_root(10, 10);
    add(8, 8);
    add(12, 12);
    add(7, 7);
    add(9, 9);
    add(11, 11);
    add(29, 29);
    add(4, 4);
    printf("------------------\n");
    printTree(root, "root", 0);
    delete(10);
    printf("%d\n", try_find(12));
    printf("%d\n", find(9));
    printf("------------------\n");
    printTree(root, "root", 0);

    return 0;
}