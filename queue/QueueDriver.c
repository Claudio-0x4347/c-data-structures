#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"queue.h"

int main(){

    Queue queue = NULL;

    // test initializeNode()
    Node *newNode = initializeNode(1);
    assert(newNode->key == 1);
    assert(newNode->nxtNode == NULL);

    // test enQueue()
    assert(queue == NULL);
    enQueue(&queue, newNode);
    assert(queue == newNode);
    newNode = initializeNode(3);
    enQueue(&queue, newNode);
    assert(queue != newNode);

    newNode = initializeNode(2);
    enQueue(&queue, newNode);

    // test printQueue()
    printQueue(queue);

    // test deQueue()
    Node *rmNode = deQueue(&queue);
    printf("Node Removed: %d\n", rmNode->key);
    assert(rmNode->key == 1);
    assert(rmNode->nxtNode == NULL);
    finalizeNode(rmNode);
    printQueue(queue);

    rmNode = deQueue(&queue);
    printf("Node Removed: %d\n", rmNode->key);
    finalizeNode(rmNode);
    printQueue(queue);

    rmNode = deQueue(&queue);
    printf("Node Removed: %d\n", rmNode->key);
    finalizeNode(rmNode);
    printQueue(queue);

    return 0;
}