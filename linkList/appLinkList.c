/**
 * @file 	linkList.c
 * @date 	02.07.2018
 * @brief 	This source file just a example for link list usage.
 * @author	Yigit YASAR
 */
/*its just test*/
#include <stdio.h>
#include <stdlib.h>
#include "linkList.h"

void exitSys(const char *sError);

int main (int argc, char *argv []) {

	handleOfList_t *pList;
	LLCOUNT_t itemIndex;

	printf("Here we go..");

	if ((pList = createList()) == NULL) {

		exitSys("Create List \n");
	}

	for (LLCOUNT_t i = 0; i < 50000; ++i) {
		addNodeToTail(pList, i*2);
	}


	for (LLCOUNT_t i = 0; i < pList->size ; ++i)
		printf("%d \n", getDataByIndex (pList, i));

	if (findItem(pList, &itemIndex, 99998) != NULL) {

		printf("item find at %d.node \n", (int)itemIndex);

		printf("%d.node value is %d \n", (int)itemIndex, getDataByIndex(pList, itemIndex));
	}
	else {

		printf("Item could not found on list..\n");
	}

	printf("Success..\n");

	clearList(pList);
	printf("clear list Success.. \n");
}


void exitSys(const char *sError) {

	fprintf(stderr, sError);
	exit(EXIT_FAILURE);
}
