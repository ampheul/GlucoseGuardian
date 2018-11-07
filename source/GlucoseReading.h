#ifndef GLUCOSEREADING_H
#define GLUCOSEREADING_H

class GlucoseReading
{
    public:
        GlucoseReading(const double glucoseAmount);
        const double getAmount() const;
    private:
        const double amount;
};

#endif
