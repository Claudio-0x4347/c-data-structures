#include<stdio.h>
#include<stdlib.h>

#ifndef _TREE_H
#define _TREE_H

typedef struct node {
    int key;
    struct node *leftNode;
    struct node *rightNode;
} Node;

typedef Node* Tree;

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
 *      tree - pointer to binary tree structure.
 *      newNode - pointer to node to be added.
 * 
 *  Output:
 * 
 *  Description:
 *      Find the node position and place it.
 */
extern void addNode(Tree *tree, Node *newNode);

/*  Input:
 *      tree - pointer to binary tree structure.
 *      key - key from node to be removed.
 * 
 *  Output:
 *      Pointer to node removed.
 * 
 *  Description:
 *      Find the node in the tree, remove and return it.
 */
extern Node* removeNode(Tree *tree, int key);

/*  Input:
 *      tree - binary tree structure.
 *
 *  Output:
 * 
 *  Description:
 *      Print tree in ascending order.
 */
extern void printTreeAscending(Tree tree);

/*  Input:
 *      tree - binary tree structure.
 *
 *  Output:
 * 
 *  Description:
 *      Print tree in descending order.
 */
extern void printTreeDescending(Tree tree);

#endif