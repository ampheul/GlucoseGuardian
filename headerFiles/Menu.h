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
	MenuItem* getMenuItems();

private:
	std::vector<*MenuItem> _items;
};

#endif
