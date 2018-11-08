#include "HormoneDose.h"
#include "LaptopOutput.h"

int main(void)
{
	HormoneDose * h = new HormoneDose(hormoneType::Glucagon, 15.0);

	LaptopOutput * lo = new LaptopOutput("127.0.0.1", 3307);
	lo->sendInstruction(h);

	delete(h);
	delete(lo);
}