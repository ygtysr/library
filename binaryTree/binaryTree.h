/**
 * @file 	binaryTree.h
 * @date 	20 Tem 2018
 * @brief 	
 * @author	Yigit YASAR
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_



typedef int TREE_SIZETYPE;
typedef int TREE_DATATYPE;


typedef struct _tagNode {

	 struct _tagNode *pLeft;
	 struct _tagNode *pRight;
	 TREE_DATATYPE   data;
}treeNode_t;

typedef struct _binaryTree {

	treeNode_t 		*rootNode;
	TREE_SIZETYPE	size;
}binaryTree_t;

#define BINARY_TREE_SIZE 			(sizeof(binaryTree_t))
#define BINARY_TREE_NODE_SIZE		(sizeof(treeNode_t))


binaryTree_t* createBinaryTree(void);
treeNode_t* insertItem(binaryTree_t *pHandle, TREE_DATATYPE val);
treeNode_t* findItem(binaryTree_t *pHandle, TREE_DATATYPE val);
void treeToGraphWrapper(treeNode_t *root);

#endif /* BINARYTREE_H_ */
