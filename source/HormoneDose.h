class HormoneDose
{
private:
	enum hormoneType { Basal_Insulin, Bolus_Insulin, Glucagon } type;
	double hormoneAmount;
	HormoneDose();
public:
	HormoneDose(hormoneType, double);
	~HormoneDose();
	const hormoneType getHormoneType() const;
	const double getHormoneAmount() const;
	void setHormoneType(const hormoneType);
	void setHormoneAmount(const double);
};
