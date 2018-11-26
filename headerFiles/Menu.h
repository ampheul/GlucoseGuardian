/*
	Group: 22
	Purpose: Header file for the Menu class
*/

#ifndef MENU_HEADER
#define MENU_HEADER

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "Menu.h"
#include "Account.h"

class Menu
{	
public:	
	Menu(Account account);
	~Menu();
	void PrintMenu();
	int GetMenuSelection();

private:
	std::string accountType;
	std::vector<std::string> _items;
	bool ValidateSelection();
};

#endif
