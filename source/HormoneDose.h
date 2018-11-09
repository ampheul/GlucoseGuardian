
#ifndef HORMONEDOSE_H
#define HORMONEDOSE_H

class HormoneDose {
	
public:
	enum hormoneType {Basal_Insulin, Bolus_Insulin, Glucagon};

    HormoneDose();
	HormoneDose(hormoneType, double);
	~HormoneDose();

	const hormoneType getHormoneType() const;
	const double getHormoneAmount() const;
	void setHormoneType(const hormoneType);
	void setHormoneAmount(const double);

private:
	double hormoneAmount;
	hormoneType type;

};

#endif
