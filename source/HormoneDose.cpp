#include "HormoneDose.h"
#include "HormoneType.h"

HormoneDose::HormoneDose(HormoneType hormone, double amount)
	:	hormoneType(hormone), hormoneAmount(amount)
{}

const HormoneType HormoneDose::getHormoneType() const
{
	return this->hormoneType;
}

const double HormoneDose::getHormoneAmount() const
{
	return this->hormoneAmount;
}
