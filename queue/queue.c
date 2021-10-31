#include "queue.h"

Node* initializeNode(const int key) {
    
    Node *newNode = malloc(sizeof(Node));

    // check memory available
    if(newNode == NULL){
        return NULL;
    }

    newNode->key = key;
    newNode->nxtNode = NULL;

    return newNode;
}

extern void finalizeNode(Node *node) {
    free(node);
}

void enQueue(Queue *queue, Node *newNode) {

    // check if queue was initialized
    if(*queue != NULL) {
        
        Node *tempNode = *queue;

        while (tempNode->nxtNode != NULL) {
            tempNode = tempNode->nxtNode;
        }
        
        tempNode->nxtNode = newNode;

    } else{
        // initialize queue
        *queue = newNode;
    }

}

Node* deQueue(Queue *queue) {

    Node *firstNode = *queue;

    // check if queue is empty
    if(*queue != NULL) {
        *queue = firstNode->nxtNode;
        firstNode->nxtNode = NULL;
    }

    return firstNode;
}

void printQueue(Queue queue) {

    while (queue != NULL)
    {
        printf("%d > ", queue->key);
        queue = queue->nxtNode;
    }
    puts("END");

}