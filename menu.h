#ifndef MENU_H_
#define MENU_H_

#include "string_list.h"

#define BUFFER_LENGTH 50
#define SCANF_BUFFER_SPECIFIER "%49s"

extern char** list;
extern bool end;

void ShowMenu();
void InputChoice();
void SelectFunction(const int choice);
void InputStringSafe(const char* message, char buffer[][BUFFER_LENGTH]);
void AddStringToList();
void RemoveStringFromList();
void PrintPositionOfStringInList();
void ReplaceStringWithStringInList();

#endif
