#ifndef SPAGHETTI_H
#define SPAGHETTI_H

#include "PatientFactory.h"
#include <iostream>

class Spaghetti : public PatientFactory
{
    public:
        PatientInfo* makePatient();
};

#endif
