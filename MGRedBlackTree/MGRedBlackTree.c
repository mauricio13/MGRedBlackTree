//
//  MGRedBlackTree.c
//  MGRedBlackTree
//
//  Created by Mauricio Galindo on 11/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "MGRedBlackTree.h"


/**
 * Function:  MGRedBlackTreeCreate
 * ---------------------
 * Initializes an empty Red-Black-Tree
 * Sets the compare fucntion of its elements to be comparefn
 * Sets its release function to be releasefn
 * Sets its retain function to be retain fn
 * Black = 1 and 
 */

MGRedBlackTree * MGRedBlackTreeCreate(void *data, MGRedBlackTreeCompareFunction comparefn, MGRedBlackTreeReleaseFunction releasefn, MGRedBlackTreeRetainFunction retainfn)
{
    MGRedBlackTree *rbt = malloc(sizeof(MGRedBlackTree));
    if (rbt->retainfn) rbt->retainfn(data);
    rbt->data = data;
    rbt->color = MGRedBlackTreeColorBlack;
    rbt->comparefn = comparefn;
    rbt->releasefn = releasefn;
    rbt->retainfn = retainfn;
    rbt->parent = NULL;
    rbt->left_child = NULL;
    rbt->right_child = NULL;
    return rbt;
}

/**
 * Function:MGRedBlackTreeRelease
 * ------------------------
 * Releases the rbt tree and al of its members
 */

void MGRedBlackTreeRelease(MGRedBlackTree *rbt)
{
    if (rbt->left_child)
        MGRedBlackTreeRelease(rbt->left_child);
    if (rbt->right_child)
        MGRedBlackTreeRelease(rbt->right_child);
    if (rbt->releasefn) rbt->releasefn(rbt->data);
    free(rbt);
}

/**
 * Function:
 * ------------------------
 */

void MGRedBlackTreeInsertElem(MGRedBlackTree *rbt, MGRedBlackTree *rbt_elem)
{
    
    MGRedBlackTree *current_node = rbt;
    while (current_node) {
        if (rbt->comparefn(current_node->data, rbt_elem->data) < 0) {
            if (!current_node->left_child) {
                //if (rbt->retainfn) rbt->retainfn(rbt_elem);
                rbt_elem->parent = current_node;
                current_node->left_child = rbt_elem;
                break;
            }
            else current_node = current_node->left_child;
        }
        else {
            if (!current_node->right_child) {
                //if (rbt->retainfn) rbt->retainfn(rbt_elem);
                rbt_elem->parent = current_node;
                current_node->right_child = rbt_elem;
                break;
            }
            else current_node = current_node->right_child;
        }
    }
    
}

/**
 * Function:
 * ------------------------
 */

void MGRedBlackTreeRemoveElem(MGRedBlackTree *rbt, MGRedBlackTree *rbt_elem)
{
    // Search for elem release it and set parent pointer to NIL
}

/**
 * Function:MGRedBlackTreeInorderTraversal
 * ------------------------
 * Walks the tree in sorted order and applies the mapfn of the tree to each node
 */

void MGRedBlackTreeInorderTraversal(MGRedBlackTree *rbt,void *context,void (*mapfn)(MGRedBlackTree *node, void *context))
{
    if (!rbt->left_child) 
        mapfn(rbt, context);
    else {
        MGRedBlackTreeInorderTraversal(rbt->left_child, context, mapfn);
        mapfn(rbt,context);
        if (rbt->right_child) MGRedBlackTreeInorderTraversal(rbt->right_child, context, mapfn);
    }
}

MGRedBlackTree * MGRedBlackTreeSearch(MGRedBlackTree *rbt, const void *key)
{
    MGRedBlackTree *current_node = rbt;
    while (current_node) {
        int cmp_res = rbt->comparefn(current_node->data, key);
        if (!cmp_res) return current_node;
        else {
            if (cmp_res < 0) 
                current_node = current_node->left_child;
            else current_node = current_node->right_child;
        }
        
    }
    return NULL;
}

/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeParent(MGRedBlackTree *rbt)
{
    return rbt->parent;
}

/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeLeftChild(MGRedBlackTree *rbt)
{
    return rbt->left_child;
}


/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeRightChild(MGRedBlackTree *rbt)
{
    return rbt->right_child;
}



