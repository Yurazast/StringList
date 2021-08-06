#include "menu.h"

bool end = false;

void ShowMenu()
{
	puts("-------------------------------------------------------------");
	puts("1 - Initialize string list");
	puts("2 - Insert value at the end of the list");
	puts("3 - Remove all occurrences of str in the list");
	puts("4 - Return the number of items in the list");
	puts("5 - Return the index position of str in the list");
	puts("6 - Remove duplicate entries from the list");
	puts("7 - Replace every occurrence of before in the list with after");
	puts("8 - Sort the list of strings in ascending order");
	puts("9 - Print the list of strings to the console");
	puts("0 - Clear list and exit the program");
	puts("-------------------------------------------------------------");
}

void InputChoice()
{
	int choice;
	printf("Enter your choice: ");
	scanf_s("%d", &choice);
	while (choice < 0 || choice > 9)
	{
		printf("Wrong choice! Enter again: ");
		scanf_s("%d", &choice);
	}

	SelectFunction(choice);
}

void SelectFunction(const int choice)
{
	if (choice == 1)
		StringListInit(&list);
	else if (choice == 2)
		AddStringToList();
	else if (choice == 3)
		RemoveStringFromList();
	else if (choice == 4)
		printf("Size of list: %d\n", StringListSize(list));
	else if (choice == 5)
		PrintPositionOfStringInList();
	else if (choice == 6)
		StringListRemoveDuplicates(list);
	else if (choice == 7)
		ReplaceStringWithStringInList();
	else if (choice == 8)
		StringListSort(list);
	else if (choice == 9)
		StringListPrint(list);
	else
	{
		StringListDestroy(&list);
		end = true;
	}
}

void AddStringToList()
{
	char buffer[50];
	printf("Enter string you want to add to the list: ");
	scanf_s("%49s", buffer, sizeof(buffer));
	fseek(stdin, 0, SEEK_END);

	StringListAdd(list, buffer);
}

void RemoveStringFromList()
{
	char buffer[50];
	printf("Enter string you want to remove from the list: ");
	scanf_s("%49s", buffer, sizeof(buffer));
	fseek(stdin, 0, SEEK_END);

	StringListRemove(&list, buffer);
}

void PrintPositionOfStringInList()
{
	char buffer[50];
	printf("Enter string you want to find in the list: ");
	scanf_s("%49s", buffer, sizeof(buffer));
	fseek(stdin, 0, SEEK_END);

	int index;
	if ((index = StringListIndexOf(list, buffer)) != -1)
		printf("Index of \"%s\": %d\n", buffer, index);
	else
		printf("\"%s\" not in the list\n", buffer);
}

void ReplaceStringWithStringInList()
{
	char before[50], after[50];
	printf("Enter string you want to replace in the list: ");
	scanf_s("%49s", before, sizeof(before));
	fseek(stdin, 0, SEEK_END);

	printf("Enter string you want to replace it with: ");
	scanf_s("%49s", after, sizeof(after));
	fseek(stdin, 0, SEEK_END);
	
	StringListReplaceInStrings(list, before, after);
}
