#include <stdlib.h>
#include <stdio.h>

typedef struct node *Node;
struct node {
    int key;
    int value;
    Node left, right;
};

void TraversalPrint(Node root, char *leftright) {
    if (root != NULL) {
        printf("%d %d %s\n", root->key, root->value, leftright);
        TraversalPrint(root->left, "Left");
        TraversalPrint(root->right, "Right");
    }
}

Node NewNode(int key, int value) {
    Node temp = (Node) malloc(sizeof(struct node));
    temp->left = NULL;
    temp->right = NULL;
    temp->key = key;
    temp->value = value;
    return temp;
}

// A wrapper for better readability
Node CreateRoot(int key, int value) {
    return NewNode(key, value);
}

void Insert(Node *root, int key, int value) {
    if (*root == NULL) {
        *root = CreateRoot(key, value);
    } else if (key < (*root)->key) {
        Insert(&(*root)->left, key, value);
    } else if (key > (*root)->key) {
        Insert(&(*root)->right, key, value);
    }
}

int SuperFind(Node root, int key, int mode) {
    // mode == 0 - TryFind
    // mode == 1 - Find
    if (root == NULL) {
        return 0;
    }

    if (root->key == key) {
        return root->value;
    }

    int left_traversal = SuperFind(root->left, key, mode);
    int right_traversal = SuperFind(root->right, key, mode);

    switch (mode) {
        case 0:
            return (left_traversal || right_traversal);
        case 1:
            return (left_traversal == 0) ? right_traversal : left_traversal;
    }
}

Node MinValueNode(Node node) {
    Node current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

void Remove(Node *root, int key) {
    if (*root == NULL)
        return;

    if (key < (*root)->key)
        Remove(&(*root)->left, key);

    else if (key > (*root)->key)
        Remove(&(*root)->right, key);

    else {
        if ((*root)->left == NULL) {
            *root = (*root)->right;
            return;

        } else if ((*root)->right == NULL) {
            *root = (*root)->left;
            return;
        }

        Node temp = MinValueNode((*root)->right);

        (*root)->key = temp->key;
        (*root)->value = temp->value;

        Remove(&(*root)->right, temp->key);
    }
    return;
}

int main() {
    Node root = CreateRoot(3, 10);
    Insert(&root, 3, 10);
    Insert(&root, 1, 101);
    Insert(&root, 2, 102);
    Insert(&root, 8, 103);
    Insert(&root, 5, 1049);
    Insert(&root, 4, 12992);
//    Insert(&root, 4, 102);
    Insert(&root, 6, 1929);
    // Tests
    TraversalPrint(root, "Root");
    printf("Found: %d %d\n",
           SuperFind(root, 8, 0),
           SuperFind(root, 8, 1));
    printf("Not found: %d %d\n",
           SuperFind(root, 666, 0),
           SuperFind(root, 666, 1));

    Remove(&root, 3);
    TraversalPrint(root, "Root");

    return 0;
}
