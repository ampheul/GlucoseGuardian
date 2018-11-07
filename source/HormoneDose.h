#ifndef HORMONETYPE_H
#define HORMONETYPE_H

#include "HormoneType.h"

class HormoneDose
{
	private:
		double hormoneAmount;
		HormoneType hormoneType;
	public:
		HormoneDose(HormoneType hormoneType, double amount);
		const HormoneType getHormoneType() const;
		const double getHormoneAmount() const;
};

#endif
