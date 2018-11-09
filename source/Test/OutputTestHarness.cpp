#include "HormoneDose.h"
#include "LaptopOutput.h"

int main(void)
{
	HormoneDose * h = new HormoneDose(GLUCAGON, 15.0);

	LaptopOutput * lo = new LaptopOutput("127.0.0.1", 3307);
	lo->sendInstruction(h);

	h->setHormoneType(BASAL_INSULIN);
	h->setHormoneAmount(12.0);

	lo->sendInstruction(h);
	
	delete(h);
	delete(lo);
}
