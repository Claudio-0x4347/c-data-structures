#ifndef _STACK_H
#define _STACK_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *nxtNode;
} Node;

typedef Node *Stack;

/*  Input:
 *      key - node identifier.
 *
 *  Output:
 *      A pointer to the new node or NULL if memory was not
 *      allocated.
 * 
 *  Description:
 *      Allocate memory for the new node and initialize it.
 */
extern Node* initializeNode(const int key);

/*  Input:
 *      node - node to be free.
 *
 *  Output:
 * 
 *  Description:
 *      Deallocate node memory.
 */
extern void finalizeNode(Node *node);

/*  Input:
 *      stack - pointer to stack structure.
 *      newNode - pointer to node to be added.
 * 
 *  Output:
 * 
 *  Description:
 *      Add node in top of stack(definition).
 */
extern void push(Stack *stack, Node *newNode);

/*  Input:
 *      stack - pointer to stack structure.
 *
 *  Output:
 *      Pointer to the top element in stack.
 * 
 *  Description:
 *      Remove the top node and returns it.
 */
extern Node* pop(Stack *stack);

/*  Input:
 *      stack - stack structure.
 *
 *  Output:
 * 
 *  Description:
 *      Print elements from stack from top to bottom.
 */
extern void printStack(Stack stack);

#endif