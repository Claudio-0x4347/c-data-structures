#include "stack.h"

Node* initializeNode(const int key) {

    Node *newNode = malloc(sizeof(Node));

    // check memory available
    if(newNode == NULL) {
        return NULL;
    }

    newNode->key = key;
    newNode->nxtNode = NULL;

    return newNode;

}

extern void finalizeNode(Node *node) {
    free(node);
}

void push(Stack *stack, Node *newNode) {

    // check if node was initialized
    if(newNode != NULL) {

        newNode->nxtNode = *stack;
        *stack = newNode;

    }

}

Node* pop(Stack *stack) {
    
    Node *rmNode = *stack;

    if(*stack != NULL){
        *stack = rmNode->nxtNode;
        rmNode->nxtNode = NULL;
    }

    return rmNode;
}

void printStack(Stack stack) {
    
    while (stack) {
        printf("%d > ", stack->key);
        stack = stack->nxtNode;
    }
    puts("END");

}