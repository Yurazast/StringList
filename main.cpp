#include "string_list.h"

int main (void)
{
	char** list = NULL;
	printf("Size of list: %d\n", StringListSize(list));
	StringListInit(&list);
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something3");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something2thing");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something4");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	StringListAdd(list, "something3");
	printf("Size of list: %d\n", StringListSize(list));
	StringListPrint(list);
	int index;
	if ((index = StringListIndexOf(list, "something4")) != -1)
		printf("Index of something4: %d\n\n", index);
	else
		printf("something4 not in the list\n\n");
	StringListRemoveDuplicates(list);
	StringListPrint(list);
	StringListRemove(&list, "something");
	StringListPrint(list);
	if ((index = StringListIndexOf(list, "something")) != -1)
		printf("Index of something: %d\n\n", index);
	else
		printf("something not in the list\n\n");
	StringListReplaceInStrings(list, "thing", "one");
	StringListPrint(list);
	StringListSort(list);
	StringListPrint(list);
	StringListDestroy(&list);

	return 0;
}
