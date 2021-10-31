#include "tree.h"

Node *initializeNode(int key) {

    Node *newNode = malloc(sizeof(Node));

    // check memory available
    if(newNode) {
        newNode->key = key;
        newNode->leftNode = NULL;
        newNode->rightNode = NULL;
    }

    return newNode;
}

extern void finalizeNode(Node *node) {
    free(node);
}

void addNode(Tree *tree, Node *newNode) {

    Node *childNode = *tree;

    // check if tree was initialized
    if(childNode == NULL) {
        *tree = newNode;
    } else {

        Node *parentNode = childNode;

        // find node position from root
        while (childNode) {
            parentNode = childNode;
            if(newNode->key < childNode->key) {
                childNode = childNode->leftNode;
            } else {
                childNode = childNode->rightNode;
            }
        }

        // place the subtree
        if(newNode->key < parentNode->key) {
            parentNode->leftNode = newNode;
        } else {
            parentNode->rightNode = newNode;
        }
            
    }

}

Node* removeNode(Tree *tree, int key) {

    Node *childNode = *tree;

    // check if tree was initialized
    if(childNode != NULL) {

        // keep track of the parente pointer to child
        Tree *ptrParentNode = tree;

        // find node from root
        while (childNode && childNode->key != key) {
            if(key < childNode->key) {
                ptrParentNode = &(childNode->leftNode);
                childNode = childNode->leftNode;
            } else {
                ptrParentNode = &(childNode->rightNode);
                childNode = childNode->rightNode;
            }
        }

        // check if node was found
        if(childNode) {
            #ifdef DEBUG
                printf("Node was found!");
            #endif
            if(childNode->leftNode == NULL) {
                *ptrParentNode = childNode->rightNode;
                childNode->rightNode = NULL;
            } else if(childNode->rightNode == NULL) {
                *ptrParentNode = childNode->leftNode;
                childNode->leftNode = NULL;
            } else{
                *ptrParentNode = childNode->leftNode;
                Node *tempNode = childNode->leftNode;
                while(tempNode->rightNode) {
                    tempNode = tempNode->rightNode;
                }
                addNode(ptrParentNode, childNode->rightNode);
                childNode->leftNode = NULL;
                childNode->rightNode = NULL;
            }

        } else{
            #ifdef DEBUG
                puts("Node was not found!");
            #endif
        }
    } else {
        #ifdef DEBUG
            puts("Tree was not initialized!");
        #endif
    }

    return childNode;
}

void printTreeAscending(Tree tree) {
    // check left tree
    if(tree) {
        printTreeAscending(tree->leftNode);
        printf("%d\t", tree->key);
        printTreeAscending(tree->rightNode);
    }
}

void printTreeDescending(Tree tree) {
    // check left tree
    if(tree) {
        printTreeDescending(tree->rightNode);
        printf("%d\t", tree->key);
        printTreeDescending(tree->leftNode);
    }
}