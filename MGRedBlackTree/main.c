//
//  main.c
//  MGRedBlackTree
//
//  Created by Mauricio Galindo on 11/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include "MGRedBlackTree.h"
#include <assert.h>

int comp(const void * elem1, const void * elem2)
{
    printf("Comparing tree_elem: %d with insert_elem: %d \n", *(int*)elem1, *(int*)elem2);
    if (*(int*)elem2 < *(int*)elem1) return -1;
    if (*(int*)elem2 == *(int*)elem1) return 0;
    return 1;
    
}

void map(MGRedBlackTree *node, void *context)
{
    printf("%d\n", *(int*)node->data);
}

int main(int argc, const char * argv[])
{

    // insert code here...
    //CFShow(CFSTR("Hello, World!\n"));
    MGRedBlackTree *tree = NULL;
    MGRedBlackTree *node_2 = NULL;
    MGRedBlackTree *node_3 = NULL;
    MGRedBlackTree *node_4 = NULL;
    MGRedBlackTree *node_5 = NULL;
    MGRedBlackTree *node_6 = NULL;
    MGRedBlackTree *node_7 = NULL;
    int data = 10;
    int data_2 = 5;
    int data_3 = 16;
    int data_4 = 3;
    int data_5 = 6;
    int data_6 = 14;
    int data_7 = 17;
    
    int (*intcmp)(const void *a, const void *b) = &comp;
    tree = MGRedBlackTreeCreate(&data, intcmp, NULL, NULL);
    node_2 = MGRedBlackTreeCreate(&data_2, intcmp, NULL, NULL);
    node_3 = MGRedBlackTreeCreate(&data_3, intcmp, NULL, NULL);
    node_4 = MGRedBlackTreeCreate(&data_4, intcmp, NULL, NULL);
    node_5 = MGRedBlackTreeCreate(&data_5, intcmp, NULL, NULL);
    node_6 = MGRedBlackTreeCreate(&data_6, intcmp, NULL, NULL);
    node_7 =MGRedBlackTreeCreate(&data_7, intcmp, NULL, NULL);
    
    MGRedBlackTreeInsertElem(tree, node_2);
    MGRedBlackTreeInsertElem(tree, node_3);
    MGRedBlackTreeInsertElem(tree, node_4);
    MGRedBlackTreeInsertElem(tree, node_5);
    MGRedBlackTreeInsertElem(tree, node_6);
    MGRedBlackTreeInsertElem(tree, node_7);
    
   
    
    MGRedBlackTreeInorderTraversal(tree, NULL, map);
    MGRedBlackTree *red_6 =  MGRedBlackTreeSearch(tree, &data_7);
    printf("red_6: %d \n", *(int*)red_6->data);
    MGRedBlackTreeRelease(tree);
    printf("Passed with merit\n");
    
    return 0;
}

