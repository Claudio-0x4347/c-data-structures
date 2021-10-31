#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"list.h"

int main(){

    List list = NULL;
    
    // test initializeNode()
    Node *newNode = initializeNode(1);
    assert(newNode->key == 1);
    assert(newNode->nxtNode == NULL);
    
    // test addNode()
    assert(list == NULL);
    int success = addNode(&list, newNode);
    assert(list == newNode);

    if(success){
        puts("Node added!");
    } else {
        puts("Duplicated key, element was not added!");
        finalizeNode(newNode);
    }
    // test printList()
    printList(list);

    newNode = initializeNode(0);
    addNode(&list, newNode);
    printList(list);

    for(int i = 0; i<10 ; i++) {
        newNode = initializeNode(i);
        success = addNode(&list, newNode);
        if(success){
            puts("Node added!");
        } else {
            puts("Duplicated key, element was not added!");
            finalizeNode(newNode);
        }
    }
    printList(list);
    
    // test getNode()
    puts("Trying to get element 5");
    Node *tempNode = getNode(list, 5);
    assert(tempNode->key == 5);
    printf("returned element: %d %p\n", tempNode->key, tempNode->nxtNode);

    // test removeNode()
    int keys[6] = {1, 4, 3, 9, 0, 10};
    for(int i=0; i<6; i++) {
        printf("Removed element: %d\n", keys[i]);
        removeNode(&list, keys[i]);
        printList(list);
    }

    return 0;
}