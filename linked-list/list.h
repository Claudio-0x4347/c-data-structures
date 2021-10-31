#ifndef _LIST_H
#define _LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *nxtNode;
} Node;

typedef Node *List;

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
extern Node *initializeNode(const int key);

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
 *      list - pointer to list structure.
 *      newNode - pointer to node to be added.
 * 
 *  Output:
 *      1- successfully added.
 *      0- if try to add duplicated key.
 * 
 *  Description:
 *      Add node in ascending order.
 */
extern int addNode(List *list, Node *newNode);

/*  Input:
 *      list - pointer to list structure.
 *      key - node identifier.
 * 
 *  Output:
 * 
 *  Description:
 *      Remove and deallocate the identified node.
 */
extern void removeNode(List *list, const int key);

/*  Input:
 *      list - pointer to list structure.
 *      key - node identifier.
 * 
 *  Output:
 *      A reference to the node element.
 * 
 *  Description:
 *      Find the node identified and returns it.
 */
extern Node* getNode(List list, const int key);

/*  Input:
 *      list - list structure.
 *
 *  Output:
 * 
 *  Description:
 *      Print list in ascending order.
 */
extern void printList(List list);

#endif