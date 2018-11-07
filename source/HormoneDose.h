#ifndef HORMONEDOSE_H
#define HORMONEDOSE_H

#include "HormoneType.h"

class HormoneDose
{
	private:
		const double hormoneAmount;
		const HormoneType hormoneType;
	public:
		HormoneDose(const HormoneType hormoneType, const double amount);
		const HormoneType getHormoneType() const;
		const double getHormoneAmount() const;
};

#endif
