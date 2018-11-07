#include "HormoneDose.h"

HormoneDose::HormoneDose(HormoneType hormone, double amount)
{
	hormoneType = hormone;
	hormoneAmount = amount;
}

const HormoneDose::hormoneType HormoneDose::getHormoneType() const
{
	return type;
}

const double HormoneDose::getHormoneAmount() const
{
	return hormoneAmount;
}
