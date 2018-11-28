#include "ArtificialPancreas.h"
#include "GlucoseMonitor.h"
#include <thread>

int main()
{
    ArtificialPancreas *artificialPancreas = new ArtificialPancreas();
	GlucoseMonitor *glucoseMonitor = new GlucoseMonitor();

	glucoseMonitor->listen(artificialPancreas);
}