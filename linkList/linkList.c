/**
 * @file 	linkList.c
 * @date 	02.07.2018
 * @brief 	This file show you basic link list implementation
 * @author	Yigit YASAR
 * @warning its not complete.
 */

/*******************************************************************************
 * Includes																	   *
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

/*******************************************************************************
* Defines
*******************************************************************************/

/*******************************************************************************
* Static Function Prototypes
*******************************************************************************/

static node_t* createNode(int initVal);
static node_t* addNodeAfterNode(handleOfList_t *handleLL, node_t *node, DATATYPE_t val);
static node_t* walkToIndex(handleOfList_t *handle, LLCOUNT_t indx);

/*******************************************************************************
* Functions
*******************************************************************************/

/**
 * @func	createList
 * @brief	Create new list
 * @param	void
 * @retval 	Reference of new born Handle (pHandle)
 */
handleOfList_t* createList(void) {

	handleOfList_t *pHandle;

	if ((pHandle = (handleOfList_t*)malloc(SIZE_OF_HANDLE)) == NULL) {

		goto failure;
	}

	pHandle->head = NULL;
	pHandle->tail = NULL;
	pHandle->size = 0;

	return pHandle;

	failure:																							/*NOTE: Do your failure implementation in here*/

	return NULL;
}

/**
 * @func	addNodeToHead
 * @brief	Add a new head node
 * @param 	handleOfList_t *handleLL
 * 			DATATYPE_t 		val
 * @retval	New head node reference
 */
node_t* addNodeToHead (handleOfList_t *handleLL, DATATYPE_t val) {

	node_t *pNode;

	if ((pNode = createNode(val)) == NULL) {

		goto failure;
	}

	if (handleLL->head == NULL) {
		handleLL->tail = pNode;
		/*WARNING: Is it neccessary to assgin NULL to pNode->prev?*/
		/*NOTE: pNode->prev and pNode->next is already NULL in createNode function*/
	}
	else {
		handleLL->head->prev = pNode;
	}

	pNode->next = handleLL->head;
	pNode->prev = NULL;

	handleLL->head = pNode;
	handleLL->size++;

	return pNode;

	failure:

	return NULL;
}

/**
 * @func	addNodeToTail
 * @brief	Add a new node to tail
 * @param 	handleOfList_t *handleLL
 * 			DATATYPE_t 		val
 * @retval	New tail node reference
 */
node_t* addNodeToTail(handleOfList_t *handleLL, DATATYPE_t val) {

	node_t *pNode;

	if ((pNode = createNode(val)) == NULL) {

		goto failure;
	}

	if (handleLL->tail == NULL) {
		handleLL->head = pNode;
	}
	else {
		handleLL->tail->next = pNode;
		pNode->prev = handleLL->tail;
	}

	pNode->next = NULL;

	handleLL->tail = pNode;
	handleLL->size++;

	return pNode;

	failure:

	return NULL;
}


/**
 * @func	addNodetoIndex
 * @brief	Create a new node desired index
 * @param 	handleOfList_t *handleLL
 * 			LLCOUNT_t indx
 * 			DATATYPE_t val
 * @retval	Newborn node reference
 */
node_t* addNodetoIndex (handleOfList_t *handleLL, LLCOUNT_t indx, DATATYPE_t val) {

	node_t *pNode;
	LLCOUNT_t i = 0;

	if (indx > GET_NODE_COUNT(handleLL))
		goto failure;

	if (indx == 0)
		return addNodeToHead(handleLL, val);

	pNode = handleLL->head;

	for (i = 0; i < indx - 1; ++i)
	        pNode = pNode->next;

	return addNodeAfterNode(handleLL, pNode, val);

	failure:
	return NULL;
}

/**
 * @func	deleteNode
 * @brief	Delete node by reference and handle next and prev nodes link
 * @param 	handleOfList_t  *handle
 * 			node_t 			*pNode
 * @retval	none
 * @todo 	currently we don not check the pNode but it must be cause,
 * 			any reference could delete on list and it brings only chaos !!
 */
void deleteNode (handleOfList_t *handle, node_t *pNode) {

	if (pNode == handle->head) {
		handle->head = handle->head->next;
	}
	else {
		pNode->prev->next = pNode->next;
	}

	if (pNode == handle->tail) {
		handle->tail = handle->tail->prev;
	}
	else {
		pNode->next->prev = pNode->prev;
	}

	free(pNode);
	handle->size--;
}

/**
 * @func	deleteNodeByIndex
 * @brief	Delete node by index and handle next and prev nodes link
 * @param 	handleOfList_t *handle
 * 			LLCOUNT_t 		indx
 * @retval	none
 */
void deleteNodeByIndex(handleOfList_t *handle, LLCOUNT_t indx) {

	node_t *pNode;

	if (indx > GET_NODE_COUNT(handle))
		return;

	pNode = walkToIndex (handle, indx);

	if (pNode == NULL)
		return;

	deleteNode(handle, pNode);
}

/**
 * @func	addNodeAfterNode
 * @brief	Add node after the stated node and handle next and prev nodes link
 * @param 	handleOfList_t *handleLL
 * 			node_t 		   *node
 * 			DATATYPE_t 		val
 * @retval	Newborn node reference
 */
static node_t* addNodeAfterNode(handleOfList_t *handleLL, node_t *node, DATATYPE_t val) {

	node_t *pNode;

	if ((pNode = createNode(val)) == NULL) {

		goto failure;
	}

	if (node->next == NULL) {
		handleLL->tail = pNode;
	}
	else {
		node->next->prev = pNode;
	}

	pNode->next = node->next;														/*WARNING: Do not change the sequence or it will be a big problem*/
	node->next = pNode;
	pNode->prev = node;

	handleLL->size++;

	return pNode;

	failure:
	return NULL;
}

/**
 * @func	findItem
 * @brief	Find stated value on list.
 * @param 	handleOfList_t 	*handle
 * 			LLCOUNT_t 		*pIndex
 * 			DATATYPE_t 		item
 * @retval	Item founded node reference.
 */
node_t* findItem(handleOfList_t *handle, LLCOUNT_t *pIndex,DATATYPE_t item) {

	node_t *pNode;
	LLCOUNT_t indx = 0;

	for (pNode = handle->head; pNode != NULL; pNode = pNode->next) {

		if (pNode->data == item) {

			*pIndex = indx;
			return pNode;
		}

		++indx;
	}

	return NULL;
}

/**
 * @func	createNode
 * @brief	Find stated value on list.
 * @param 	int initVal
 * @retval	Newborn node reference
 */
static node_t* createNode(int initVal) {

	node_t *pNode;

	if ((pNode = (node_t*)malloc(SIZE_OF_NODE)) == NULL) {

		goto failure;
	}

	pNode->data = initVal;
	pNode->next = NULL;
	pNode->prev = NULL;

	return pNode;

	failure:
	return NULL;
}

/**
 * @func	clearList
 * @brief	Find stated value on list.
 * @param 	handleOfList_t 	*handle
 * @retval	Newborn node reference
 * @warning	Handle could be any reference, it could be cause to run time error.
 * @todo 	Check the handle param
 */
void clearList(handleOfList_t *handle) {

	node_t *pNode, *ptmpNode;

	pNode = handle->head;

	while (pNode != NULL) {

		ptmpNode = pNode;
		pNode = pNode->next;
		free(ptmpNode);
	}
}

/**
 * @func	walkToIndex
 * @brief	Walk to stated index of list.
 * @param 	handleOfList_t 	*handle
 * @retval	Reference of stated index
 */
static node_t* walkToIndex(handleOfList_t *handle, LLCOUNT_t indx) {

	node_t *pNode;

	if (indx > GET_NODE_COUNT(handle))
		return NULL;

	pNode = handle->head;
	for(LLCOUNT_t i = 0; i < indx; ++i) {
		pNode = pNode->next;
	}

	return pNode;
}

/**
 * @func	getDataByIndex
 * @brief	Get node data of stated index.
 * @param 	handleOfList_t 	*handle
 * 			LLCOUNT_t 		indx
 * @retval	Value of stated node
 */
DATATYPE_t getDataByIndex(handleOfList_t *handle, LLCOUNT_t indx) {

	node_t *pNode;

	if (indx > GET_NODE_COUNT(handle))
		return 0;				/*WARNING: not enough !!*/

	pNode = walkToIndex(handle, indx);

	if (pNode == NULL)
		return 0;				/*WARNING: not enough !!*/

	return pNode->data;
}

