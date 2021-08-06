#include "menu.h"

char** list = NULL;

int main (void)
{
	do
	{
		ShowMenu();
		InputChoice();
	} while (!end);

	return 0;
}
