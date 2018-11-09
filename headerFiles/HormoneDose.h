
#ifndef HORMONEDOSE_H
#define HORMONEDOSE_H

enum hormoneType {BASAL_INSULIN, BOLUS_INSULIN, GLUCAGON};

class HormoneDose {
	
public:
    HormoneDose();
	HormoneDose(hormoneType, double);
	~HormoneDose();

	const enum hormoneType getHormoneType() const;
	const double getHormoneAmount() const;
	void setHormoneType(const hormoneType);
	void setHormoneAmount(const double);

private:
	double hormoneAmount;
	hormoneType type;

};

#endif
