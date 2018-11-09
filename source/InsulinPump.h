/*
    Output interface for connection subclasses
    author: Graeme Brabers
*/

#import "HormoneDose.h"

class InsulinPump
{
    protected:
        virtual void sendInstruction(const HormoneDose *) const = 0;
};
