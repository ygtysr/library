/**
 * @file 	binaryTree.c
 * @date 	20 Tem 2018
 * @brief 	
 * @author	Yigit YASAR
 */



/*******************************************************************************
 * Includes																	   *
*******************************************************************************/
#include <stdlib.h>
#include "binaryTree.h"

/*******************************************************************************
* Defines
*******************************************************************************/


/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
static treeNode_t* createTreeNode(void);

/*******************************************************************************
* Functions
*******************************************************************************/
binaryTree_t* createBinaryTree(void) {

	binaryTree_t *pTree;

	if ((pTree = (binaryTree_t*)malloc(BINARY_TREE_SIZE)))
		return NULL;

	pTree->rootNode = createTreeNode();
	pTree->size = 0;

	return pTree;
}

static treeNode_t* createTreeNode(void) {

	treeNode_t *pNode;

	if (pNode = (treeNode_t *)malloc(BINARY_TREE_NODE_SIZE)) {
		return NULL;
	}

	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->data = 0;

	return pNode;
}

/*******************************************************************************
* End Of File
*******************************************************************************/

