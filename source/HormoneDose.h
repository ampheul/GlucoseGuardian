enum class HormoneType { 
	BASAL_INSULIN, 
	BOLUS_INSULIN, 
	GLUCAGON 
};

class HormoneDose
{
private:
	double hormoneAmount;
	HormoneType hormoneType;
	HormoneDose();
public:
	HormoneDose(HormoneType hormoneType, double amount);
	~HormoneDose();
	const hormoneType getHormoneType() const;
	const double getHormoneAmount() const;
	void setHormoneType(const hormoneType);
	void setHormoneAmount(const double);
};
