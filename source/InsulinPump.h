#import "HormoneDose.h"

class InsulinPump
{
    protected:
        virtual void sendInstruction(const HormoneDose *) const = 0
};
