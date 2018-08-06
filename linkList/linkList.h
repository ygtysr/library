#ifndef LINKLIST_H_
#define LINKLIST_H_

#include <stddef.h>

typedef int 	DATATYPE_t;
typedef size_t  LLCOUNT_t;

typedef struct _node{

	DATATYPE_t	 	data;
	struct _node 	*next;
	struct _node	*prev;

}node_t;

typedef struct _handleOfList {

	node_t		*head;
	node_t		*tail;
	LLCOUNT_t	size;

}handleOfList_t;

#define SIZE_OF_HANDLE		(sizeof(handleOfList_t))
#define SIZE_OF_NODE		(sizeof(node_t))
#define GET_NODE_COUNT(handle) 	(handle->size)

node_t* addNodeToHead (handleOfList_t *handleLL, DATATYPE_t val);
node_t* addNodeToTail(handleOfList_t *handleLL, DATATYPE_t val);
handleOfList_t* createList(void);
void deleteNode(handleOfList_t *handleLL, node_t *node);
void deleteNodeByIndex (handleOfList_t *handle, LLCOUNT_t indx);
node_t* addNodetoIndex (handleOfList_t *handleLL, LLCOUNT_t indx, DATATYPE_t val);
void deleteNode(handleOfList_t *handle, node_t *pNode);
void clearList (handleOfList_t *handle);
DATATYPE_t getDataByIndex(handleOfList_t *handle, LLCOUNT_t indx);
node_t* findItem(handleOfList_t *handle, LLCOUNT_t *pIndex,DATATYPE_t item);
#endif /* LINKLIST_H_ */
