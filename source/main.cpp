/*!
	@author Group 22
	Description: runs the artificial pancreas program
*/

#include "main.h"

using namespace std;

int main(int argc, char **argv) 
{
	ArtificialPancreas* artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor* glucoseMonitor = new GlucoseMonitor();

	Thread t1 = new Thread(&GlucoseMonitor::listen, glucoseMonitor, artificialPancreas);

	Account* account = new Account();
	Menu* menu = new Menu(account);
	UserInputExecutor executor = new UserInputExecutor(artificialPancreas);
	bool running = true;
	
	while(running)
	{
		menu.printMenu();		
		int optionToRetrieve = menu.getMenuSelection();
		executor.menuSwitch(optionToRetrieve);
	}
	
	return 0;
}
