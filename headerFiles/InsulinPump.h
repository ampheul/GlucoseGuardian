/*
    Output interface for connection subclasses
    author: Graeme Brabers
*/
#ifndef INSULINPUMP_H
#define INSULINPUMP_H

#include "HormoneDose.h"

class InsulinPump
{
    public:
        virtual void sendInstruction(const HormoneDose *) const = 0;
};

#endif