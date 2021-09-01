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

	SelectFunction(choice);
}

void SelectFunction(const int choice)
{
	switch (choice)
	{
	case 1:
		StringListInit(&list);
		break;
	case 2:
		AddStringToList();
		break;
	case 3:
		RemoveStringFromList();
		break;
	case 4:
		printf("Size of list: %d\n", StringListSize(list));
		break;
	case 5:
		PrintPositionOfStringInList();
		break;
	case 6:
		StringListRemoveDuplicates(list);
		break;
	case 7:
		ReplaceStringWithStringInList();
		break;
	case 8:
		StringListSort(list);
		break;
	case 9:
		StringListPrint(list);
		break;
	case 0:
		StringListDestroy(&list);
		end = true;
		break;
	default:
		puts("Wrong choice!");
	}
}

void InputStringSafe(const char* message, char buffer[][BUFFER_LENGTH])
{
	if (buffer == NULL)
	{
		puts("Buffer cannot be NULL");
		return;
	}

	printf(message);
	scanf_s(SCANF_BUFFER_SPECIFIER, *buffer, sizeof(*buffer));
	fseek(stdin, 0, SEEK_END);
}

void AddStringToList()
{
	char buffer[BUFFER_LENGTH];
	InputStringSafe("Enter string you want to add to the list: ", &buffer);

	StringListAdd(list, buffer);
}

void RemoveStringFromList()
{
	char buffer[BUFFER_LENGTH];
	InputStringSafe("Enter string you want to remove from the list: ", &buffer);

	StringListRemove(&list, buffer);
}

void PrintPositionOfStringInList()
{
	char buffer[BUFFER_LENGTH];
	InputStringSafe("Enter string you want to find in the list: ", &buffer);

	int index;
	if ((index = StringListIndexOf(list, buffer)) != -1)
		printf("Index of \"%s\": %d\n", buffer, index);
	else
		printf("\"%s\" not in the list\n", buffer);
}

void ReplaceStringWithStringInList()
{
	char before[BUFFER_LENGTH], after[BUFFER_LENGTH];
	InputStringSafe("Enter string you want to replace in the list: ", &before);
	InputStringSafe("Enter string you want to replace it with: ", &after);
	
	StringListReplaceInStrings(list, before, after);
}
