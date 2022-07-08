/*
 * Algorithms & Data Structures
 *
 * Create a Binary Tree and traverse it in preorder, inorder and postorder
 * */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

struct node {
    int data;
    struct node *leftPtr;
    struct node *rightPtr;
};

typedef struct node arbol;
typedef arbol *treePtr;

void insnodo(treePtr *, int);

void inorder(treePtr nodePtr);

void preorder(treePtr nodoPtr);

void postOrder(treePtr nodePtr);

int main() {
    int i, elem;
    treePtr rootPtr = nullptr;

    srand(time(nullptr));

    printf("Original Elements\n\n");
    for (i = 1; i <= 7; i++) {
        elem = rand() % 15;
        printf("%3d", elem);
        insnodo(&rootPtr, elem);
    }

    printf("\n\nPreorder Traversal:\n");
    preorder(rootPtr);
    printf("\n\nInorder Traversal:\n");
    inorder(rootPtr);
    printf("\n\nPostorder Traversal:\n");
    postOrder(rootPtr);

    cout << "\n\n";
    system("pause");

    return 0;
}

void insnodo(treePtr *nodePtr, int value) {
    if (*nodePtr == nullptr) {
        *nodePtr = (arbol *) malloc(sizeof(arbol));

        if (*nodePtr != nullptr) {
            (*nodePtr)->data = value;
            (*nodePtr)->leftPtr = nullptr;
            (*nodePtr)->rightPtr = nullptr;
        } else
            printf("%d not inserted. No memory available\n", value);
    } else if (value < (*nodePtr)->data)
        insnodo(&((*nodePtr)->leftPtr), value);
    else if (value > (*nodePtr)->data)
        insnodo(&((*nodePtr)->rightPtr), value);
    else
        printf("duplicate");
}

void preorder(treePtr nodoPtr) {
    if (nodoPtr != nullptr) {
        printf("%3d", nodoPtr->data);
        preorder(nodoPtr->leftPtr);
        preorder(nodoPtr->rightPtr);
    }
}

void inorder(treePtr nodePtr) {
    if (nodePtr != nullptr) {
        inorder(nodePtr->leftPtr);
        printf("%3d", nodePtr->data);
        inorder(nodePtr->rightPtr);
    }
}

void postOrder(treePtr nodePtr) {
    if (nodePtr != nullptr) {
        postOrder(nodePtr->leftPtr);
        postOrder(nodePtr->rightPtr);
        printf("%3d", nodePtr->data);
    }
}
