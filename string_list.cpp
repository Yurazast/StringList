#include "string_list.h"

void SwapStrings(char** a, char** b);
void SelectionSort(char** list);

void StringListInit(char*** list)
{
	if (list == NULL) return;

	if (*list != NULL)
	{
		puts("String list is already initialized");
		return;
	}

	*list = (char**) malloc(sizeof(char*) * 2);
	if (*list == NULL)
		exit(1);
	(*list)[0] = NULL;
	(*list)[1] = NULL;
}

void StringListDestroy(char*** list)
{
	if (list == NULL || *list == NULL) return;

	char** next_ptr;
	do
	{
		next_ptr = (char**) (*list)[NEXT];
		free((*list)[VALUE]);
		free(*list);
		*list = next_ptr;
	} while (next_ptr != NULL);

	*list = NULL;
}

void StringListAdd(char** list, String str)
{
	if (list == NULL)
	{
		puts("String list is not initialized");
		return;
	}

	char* new_str = (char*) malloc(sizeof(char) * strlen(str) + 1);
	if (new_str == NULL)
		return;
	strcpy_s(new_str, sizeof(char) * (strlen(str) + 1), str);

	if (list[VALUE] == NULL)
	{
		list[VALUE] = new_str;
		return;
	}

	char** new_el = (char**) malloc(sizeof(char*) * 2);
	if (new_el == NULL)
	{
		free(new_str);
		return;
	}
	new_el[VALUE] = new_str;
	new_el[NEXT] = NULL;

	char** next_ptr = list;
	while (next_ptr[NEXT] != NULL)
		next_ptr = (char**) next_ptr[NEXT];
	next_ptr[NEXT] = (char*) new_el;
}

void StringListRemove(char*** list, String str)
{
	if (list == NULL || *list == NULL || (*list)[VALUE] == NULL)
	{
		puts("String list is not initialized or is empty");
		return;
	}

	char** save_ptr = *list;

	for (char** next_ptr = (char**) (*list)[NEXT], **prev_ptr = NULL; ; next_ptr = (char**) next_ptr[NEXT])
	{
		if (strcmp((*list)[VALUE], str) == 0)
		{
			free((*list)[VALUE]);

			if (prev_ptr != NULL)
				prev_ptr[NEXT] = (char*) next_ptr;
			else
				save_ptr = next_ptr;

			free(*list);
		}
		else
		{
			prev_ptr = *list;
		}

		if (next_ptr == NULL) break;
		*list = next_ptr;
	}

	*list = save_ptr;
}

int StringListSize(char** list)
{
	if (list == NULL || list[VALUE] == NULL) return 0;

	int n = 0;
	for ( ; list != NULL; list = (char**) list[NEXT])
		++n;

    return n;
}

int StringListIndexOf(char** list, String str)
{
	if (list == NULL || list[VALUE] == NULL) return -1;

	int i = 0;
	for ( ; list != NULL; list = (char**) list[NEXT])
	{
		if (strcmp(list[VALUE], str) == 0)
			return i;

		++i;
	}

    return -1;
}

void StringListRemoveDuplicates(char** list)
{
	if (StringListSize(list) < 2) return;

	for (char** el_to_cmp = list; el_to_cmp != NULL && el_to_cmp[NEXT] != NULL; el_to_cmp = (char**) el_to_cmp[NEXT])
	{
		list = (char**) el_to_cmp[NEXT];
		for (char** next_ptr = (char**) list[NEXT], **prev_ptr = el_to_cmp; ; next_ptr = (char**) next_ptr[NEXT])
		{
			if(strcmp(el_to_cmp[VALUE], list[VALUE]) == 0)
			{
				free(list[VALUE]);
				free(list);
				prev_ptr[NEXT] = (char*) next_ptr;
			}
			else
			{
				prev_ptr = list;
			}

			if (next_ptr == NULL) break;
			list = next_ptr;
		}
	}
}

void StringListReplaceInStrings(char** list, String before, String after)
{
	if (list == NULL || list[VALUE] == NULL)
	{
		puts("String list is not initialized or is empty");
		return;
	}

	const int len = strlen(after) + 1;
	while (list != NULL)
	{
		if (strcmp(list[VALUE], before) == 0)
		{
			list[VALUE] = (char*) realloc(list[VALUE], sizeof(char) * len);
			if (list[VALUE] == NULL)
				return;
			strcpy_s(list[VALUE], sizeof(char) * len, after);
		}

		list = (char**) list[NEXT];
	}
}

void StringListSort(char** list)
{
	if (StringListSize(list) < 2) return;
	SelectionSort(list);
}

void StringListPrint(char** list)
{
	if (list == NULL || list[VALUE] == NULL)
	{
		puts("String list is empty");
		return;
	}

	puts("String list:");
	while (list != NULL)
	{
		printf("> %s\n", list[VALUE]);
		list = (char**) list[NEXT];
	}
}

void SwapStrings(char** a, char** b)
{
	if (a == b) return;
	char* temp = a[VALUE];
	a[VALUE] = b[VALUE];
	b[VALUE] = temp;
}

void SelectionSort(char** list)
{
	for (char** el_to_cmp = list, **min_el; el_to_cmp[NEXT] != NULL; el_to_cmp = (char**) el_to_cmp[NEXT])
	{
		for (min_el = el_to_cmp, list = (char**) el_to_cmp[NEXT]; list != NULL; list = (char**) list[NEXT])
		{
			if (strcmp(list[VALUE], min_el[VALUE]) < 0)
				min_el = list;
		}
		SwapStrings(el_to_cmp, min_el);
	}
}

