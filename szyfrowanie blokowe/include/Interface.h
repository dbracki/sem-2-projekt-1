#ifndef INTERFACE_H
#define INTERFACE_H

#include "Cmachine.h"
#include <iostream>
#include <vector>

using namespace std;

class Interface
{
    public:
        Cmachine cm;

        Interface();

        bool run();

    private:

};

#endif // INTERFACE_H
