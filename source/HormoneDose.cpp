#include "HormoneDose.h"

const hormoneType HormoneDose::getHormoneType() const
{
	return type;
}

const double HormoneDose::getHormoneAmount() const
{
	return hormoneAmount;
}

void HormoneDose::setHormoneType(const hormoneType hType)
{
	type = hType;
}

void HormoneDose::setHormoneAmount(const double hAmount)
{
	hormoneAmount = hAmount;
}