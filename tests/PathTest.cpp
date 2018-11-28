#include "ArtificialPancreas.h"
#include "GlucoseMonitor.h"
#include <thread>

int main()
{
    ArtificialPancreas *artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor *glucoseMonitor = new GlucoseMonitor();

	std::thread t1(glucoseMonitor->listen, artificialPancreas);
	t1.join();
}