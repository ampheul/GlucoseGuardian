#include "main.h"

using namespace std;

int main(int argc, char **argv) 
{
	Account account;	
	Menu menu = new Menu(account);
	menu.getMenuItems();
	
	return 0;
}
