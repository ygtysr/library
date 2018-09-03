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
#include <stdio.h>
#include "binaryTree.h"

/*******************************************************************************
* Defines
*******************************************************************************/
#define COUNT 1																						/*NOTE: For graph*/

/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/
static treeNode_t* createTreeNode(void);
static void treeToGraph(treeNode_t *root, int space);
/*******************************************************************************
* Functions
*******************************************************************************/
binaryTree_t* createBinaryTree(void) {

	binaryTree_t *pTree;

	if ((pTree = (binaryTree_t*)malloc(BINARY_TREE_SIZE)) == NULL)
		return NULL;

	pTree->rootNode = NULL;
	pTree->size = 0;

	return pTree;
}

static treeNode_t* createTreeNode(void) {

	treeNode_t *pNode;

	if ((pNode = (treeNode_t *)malloc(BINARY_TREE_NODE_SIZE)) == NULL) {
		return NULL;
	}

	pNode->pLeft = NULL;
	pNode->pRight = NULL;
	pNode->data = 0;

	return pNode;
}

treeNode_t* insertItem(binaryTree_t *pHandle, TREE_DATATYPE val) {

	treeNode_t *pNewNode;
	treeNode_t *pTempNode;
	treeNode_t *pOldTemp;

	if ((pNewNode = createTreeNode()) == NULL)
		return NULL;

	pNewNode->data = val;

	if (pHandle->rootNode == NULL) {

		pHandle->rootNode = pNewNode;
		pHandle->size++;

		return pNewNode;
	}

	pTempNode = pHandle->rootNode;

	while (pTempNode != NULL) {

		pOldTemp = pTempNode;

		if (pTempNode->data > pNewNode->data) {
			pTempNode = pTempNode->pRight;
		}
		else if (pTempNode->data < pNewNode->data){
			pTempNode = pTempNode->pLeft;
		}
		else
			return NULL;
	}

	pHandle->size++;

	if (pOldTemp->data > pNewNode->data) {
		pOldTemp->pRight = pNewNode;
	}
	else if (pOldTemp->data < pNewNode->data){
		pOldTemp->pLeft = pNewNode;
	}

	return pNewNode;
}

treeNode_t* findItem(binaryTree_t *pHandle, TREE_DATATYPE val) {

	treeNode_t *pNode = pHandle->rootNode;

	while (pNode != NULL) {

		if (pNode->data > val) {

			pNode = pNode->pRight;
		}
		else if (pNode->data < val ) {

			pNode = pNode->pLeft;
		}
		else {
			return pNode;
		}
	}

	return NULL;
}

static void treeToGraph(treeNode_t *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    treeToGraph(root->pRight, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    treeToGraph(root->pLeft, space);
}

void treeToGraphWrapper(treeNode_t *root)
{
	treeToGraph(root, 0);
}

/*******************************************************************************
* End Of File
*******************************************************************************/

