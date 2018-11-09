#include "HormoneDose.h"
#include "LaptopOutput.h"

int main(void)
{
	HormoneDose * h = new HormoneDose(GLUCAGON, 15.0);

	LaptopOutput * lo = new LaptopOutput("127.0.0.1", 3307);
	lo->sendInstruction(h);

	h = new HormoneDose(BASAL_INSULIN, 12.0);

	lo->sendInstruction(h);
	
	delete(h);
	delete(lo);
}
