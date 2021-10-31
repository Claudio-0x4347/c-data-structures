#include "list.h"

Node *initializeNode(const int key) {

    Node *newNode = malloc(sizeof(Node));

    // check memory available
    if(newNode==NULL){
        return NULL;
    }

    newNode->key = key;
    newNode->nxtNode = NULL;

    return newNode;

}

void finalizeNode(Node *node) {
    free(node);
}

int addNode(List *list, Node *newNode) {

    if(*list == NULL) {
        // initialize list
        *list = newNode;
    } else {

        Node *tempNode = *list;
        Node *prevNode = tempNode;

        while ( tempNode->key < newNode->key && tempNode->nxtNode != NULL ) {
            prevNode = tempNode;
            tempNode = tempNode->nxtNode;
        }
        
        if(tempNode->key == newNode->key){
            // check duplicated key
            return 0;
        } else if(prevNode == tempNode){
            // add in the first node
            *list = newNode;
            newNode->nxtNode = tempNode;
        } else if(tempNode->nxtNode == NULL){
            // add in the last node
            tempNode->nxtNode = newNode;
        } else {
            // add in the middle of list
            prevNode->nxtNode = newNode;
            newNode->nxtNode = tempNode;
        }

    }

    return 1;
}

void removeNode(List *list, const int key) {

    if(*list != NULL){

        Node *tempNode = *list;
        Node *prevNode = tempNode;

        while (tempNode->key != key && tempNode->nxtNode != NULL) {
            prevNode = tempNode;
            tempNode = tempNode->nxtNode;
        }
        
        if(tempNode == prevNode){
            // is first node
            *list = tempNode->nxtNode;
            free(tempNode);
        } else if(tempNode->key == key) {
            // is in the middle or end of list
            prevNode->nxtNode = tempNode->nxtNode;
            free(tempNode);
        }
    }

}

Node* getNode(List list, const int key) {

    Node *tempNode = list;

    if(list != NULL){

        Node *prevNode = tempNode;

        // find the node
        while (tempNode->key != key && tempNode->nxtNode != NULL) {
            prevNode = tempNode;
            tempNode = tempNode->nxtNode;
        }
        
    }

    return tempNode;
}

void printList(List list) {
    while (list) {
        printf("%d > ", list->key);
        list = list->nxtNode;
    }
    puts("END");   
}