#include "HormoneDose.h"

HormoneDose::HormoneDose(hormoneType hormone, double amount)
{
	type = hormone;
	hormoneAmount = amount;
}

HormoneDose::~HormoneDose()
{
}

const HormoneDose::hormoneType HormoneDose::getHormoneType() const
{
	return type;
}

const double HormoneDose::getHormoneAmount() const
{
	return hormoneAmount;
}

void HormoneDose::setHormoneType(const HormoneDose::hormoneType hormone)
{
	type = hormone;
}

void HormoneDose::setHormoneAmount(const double amount)
{
	hormoneAmount = amount;
}
