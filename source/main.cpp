#include "main.h"

using namespace std;

int main(int argc, char **argv) 
{
	ArtificialPancreas artificialPancreas = new ArtificialPancreas();
	Account account = new Account();
	Menu menu = new Menu(account);
	UserInputExecutor executor = new UserInputExecutor(artificialPancreas);
	bool running = true;
	
	while(running)
	{
		menu.PrintMenu();		
		int optionToRetrieve = menu.getMenuSelection();
		executor.MenuSwitch(optionToRetrieve);
	}
	
	return 0;
}
