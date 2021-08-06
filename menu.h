#ifndef MENU_H_
#define MENU_H_

#include "string_list.h"

extern char** list;
extern bool end;

void ShowMenu();
void InputChoice();
void SelectFunction(const int choice);
void AddStringToList();
void RemoveStringFromList();
void PrintPositionOfStringInList();
void ReplaceStringWithStringInList();

#endif
