#define DEBUG
#include<stdio.h>
#include<assert.h>
#include"tree.h"

int main(){

    Tree tree = NULL;

    // test initializeNode()
    Node *newNode = initializeNode(10);
    assert(newNode->key == 10);
    assert(newNode->leftNode == NULL);
    assert(newNode->rightNode == NULL);

    // test addNode()
    puts("adding 10(initialize)");
    addNode(&tree, newNode);
    assert(tree != NULL);

    puts("adding 8");
    newNode = initializeNode(8);
    addNode(&tree, newNode);
    assert(tree->leftNode != NULL);
    assert(tree->rightNode == NULL);

    puts("adding 9");
    newNode = initializeNode(9);
    addNode(&tree, newNode);
    
    puts("adding 10");
    newNode = initializeNode(10);
    assert(tree->rightNode == NULL);
    addNode(&tree, newNode);
    assert(tree->rightNode != NULL);

    int keys[14] = {11, 2, 15, 1, 5, 12, 18, 4, 7, 19, 3, 6, 14, 13};
    for(int i=0; i<14; i++) {
        printf("adding %d\n", keys[i]);
        newNode = initializeNode(keys[i]);
        addNode(&tree, newNode);
    }

    // test printNodeAscending()
    printTreeAscending(tree);
    puts("");

    // test printNodeDescending()
    printTreeDescending(tree);
    puts("");

    // test removeNode()
    Node *rmNode = NULL;
    puts("removing node 17");
    rmNode = removeNode(&tree, 17);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 1");
    rmNode = removeNode(&tree, 1);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 19");
    rmNode = removeNode(&tree, 19);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 11");
    rmNode = removeNode(&tree, 11);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 8");
    rmNode = removeNode(&tree, 8);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 10(root)");
    rmNode = removeNode(&tree, 10);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    puts("removing node 9(root)");
    rmNode = removeNode(&tree, 9);
    finalizeNode(rmNode);
    printTreeAscending(tree);
    puts("");

    return 0;
}