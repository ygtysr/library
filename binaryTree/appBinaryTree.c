/*
 * appBinaryTree.c
 *
 *  Created on: 8 A?u 2018
 *      Author: z003ybrv
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binaryTree.h"

binaryTree_t *pHandle;

void exitSys(const char *pMsg);

unsigned int randSeed;
treeNode_t *pNode;

int main(int argc, char **argv) {

	if ((pHandle = createBinaryTree()) == NULL)
		exitSys("create binary tree fault\n");

	printf("Tree has been created successfully \n");

	randSeed = time(NULL);
	randSeed = randSeed % 3510;
	printf("Rand seed is :%d \n", randSeed);

	srand(randSeed);

	for (int i = 0; i < 5000; ++i) {

		randSeed = rand() % 1000;
		if ((pNode = insertItem(pHandle, (TREE_DATATYPE)randSeed)) == NULL) {
			i--;
			continue;
		}
		printf("Item %d added successfully to %p \n", randSeed, pNode);
	}

	for (int j = 0; j < 5000; ++j) {

		randSeed = rand() % 1000;
		if ((pNode = findItem(pHandle, randSeed)) != NULL) {
			printf("Searching item %d was found at : %p \n", randSeed, pNode);
		}
		else {
			printf("Searching item %d was not found\n", randSeed);
		}
	}

	treeToGraphWrapper(pHandle->rootNode);

	printf("Everything is okay, good bye..\n");
	return 0;
}

void exitSys(const char *pMsg) {

	fprintf(stderr, pMsg);
	exit(EXIT_FAILURE);
}
