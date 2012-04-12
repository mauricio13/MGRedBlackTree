//
//  MGRedBlackTree.h
//  MGRedBlackTree
//
//  Created by Mauricio Galindo on 11/04/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef MGRedBlackTree_MGRedBlackTree_h
#define MGRedBlackTree_MGRedBlackTree_h



/* File: MGRedBlackTree.h
 * ------------------
 * Defines the interface for the RedBlackTree.
 */

/**
 * Type: MGRedBlackTreeRetainFunction
 * -------------------------
 */

typedef void (*MGRedBlackTreeRetainFunction)(const void *elemAddr);

/**
 * Type: MGRedBlackTreeReleaseFunction
 * ----------------------------
 */

typedef void (*MGRedBlackTreeReleaseFunction)(void *elemAddr);


/**
 * Type: MGRedBlackTreeCompareFunction
 * ------------------------
 */

typedef int (*MGRedBlackTreeCompareFunction)(const void *elemAddr1, const void *elemAddr);





typedef struct MGRedBlackTree {
    short color;
    void *data;
    struct MGRedBlackTree *parent;
    struct MGRedBlackTree *left_child;
    struct MGRedBlackTree *right_child;
    MGRedBlackTreeReleaseFunction releasefn;
    MGRedBlackTreeRetainFunction retainfn;
    MGRedBlackTreeCompareFunction comparefn;
} MGRedBlackTree;

/**
 * Type: MGRedBlackTreeCompareFunction
 * ------------------------
 * applies the function given as a parameter with data from the context parameter to de MGRedBlackTree
 */

//typedef void (*MGRedBlackTreeMapFunction)(MGRedBlackTree *node,void *context, void (*mapfn)(MGRedBlackTree *node, void *context));

enum MGRedBlackTreeColor
{
    
    MGRedBlackTreeColorBlack = 0,
    MGRedBlackTreeColorRed = 1
};

MGRedBlackTree *root;

/**
 * Function:  MGRedBlackTreeCreate
 * ---------------------
 * Initializes an empty Red-Black-Tree
 * Sets the compare fucntion of its elements to be comparefn
 * Sets its release function to be releasefn
 * Sets its retain function to be retain fn
 */

MGRedBlackTree * MGRedBlackTreeCreate(void *data, MGRedBlackTreeCompareFunction comparefn, MGRedBlackTreeReleaseFunction releasefn, MGRedBlackTreeRetainFunction retainfn);

/**
 * Function:MGRedBlackTreeRelease
 * ------------------------
 * Releases the rbt tree and al of its members
 */

void MGRedBlackTreeRelease(MGRedBlackTree *rbt);

/**
 * Function:
 * ------------------------
 */

void MGRedBlackTreeInsertElem(MGRedBlackTree *rbt, MGRedBlackTree *rbt_elem);

/**
 * Function:
 * ------------------------
 */

void MGRedBlackTreeRemoveElem(MGRedBlackTree *rbt, MGRedBlackTree *rbt_elem);

/**
 * Function:MGRedBlackTreeInorderTraversal
 * ------------------------
 */

void MGRedBlackTreeInorderTraversal(MGRedBlackTree *rbt,void *context,void (*mapfn)(MGRedBlackTree *node, void *context));

/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeParent(MGRedBlackTree *rbt);

/**
 * Function:MGRedBlackTreeSearch
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeSearch(MGRedBlackTree *rbt, const void *key);

/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeLeftChild(MGRedBlackTree *rbt);


/**
 * Function:
 * ------------------------
 */

MGRedBlackTree * MGRedBlackTreeRightChild(MGRedBlackTree *rbt);



#endif
