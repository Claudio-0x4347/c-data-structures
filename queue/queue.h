#ifndef _QUEUE_H
#define _QUEUE_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *nxtNode;
} Node;

typedef Node *Queue;

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
 *      queue - pointer to queue structure.
 *      newNode - pointer to node to be added.
 * 
 *  Output:
 *      
 *  Description:
 *      Add node in tail of queue(definition).
 */
extern void enQueue(Queue *queue, Node *newNode);

/*  Input:
 *      queue - pointer to queue structure.
 *      key - chave de exclusão.
 *
 *  Output:
 *      Pointer to the head element in queue.
 *  
 *  Description:
 *      Remove the head node of queue and returns it.
 */
extern Node* deQueue(Queue *queue);

/*  Input:
 *    queue - queue structure.
 *
 *  Output:
 *
 *  Description:
 *      Print nodes from head to tail.
 */
extern void printQueue(Queue queue);

#endif