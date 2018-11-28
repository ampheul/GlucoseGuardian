#include "ArtificialPancreas.h"
#include <thread>

int main()
{
    ArtificialPancreas artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor glucoseMonitor = new GlucoseMonitor();

	glucosemonitor->listen(artificialPancreas);
}