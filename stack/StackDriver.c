#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {

    Stack stack = NULL;

    // test initializeNode()
    Node *newNode = initializeNode(1);
    assert(newNode->key == 1);
    assert(newNode->nxtNode == NULL);

    // test push()
    assert(stack == NULL);
    push(&stack, newNode);
    assert(stack == newNode);

    newNode = initializeNode(2);
    push(&stack, newNode);

    newNode = initializeNode(3);
    push(&stack, newNode);

    // test printStack()
    printStack(stack);

    // test pop() and finalizeNode()
    for(int i=0; i<4; i++){
        Node *rmNode = pop(&stack);
        if (rmNode) {
            printf("Removed Node: %d\n", rmNode->key);
            finalizeNode(rmNode);
            printStack(stack);
        } else {
            puts("STACK EMPTY");
        }
    }

    return 0;
}