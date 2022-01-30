//
// Created by jdwil on 27/01/2022.
//

#ifndef SYSTEMS_CRAFT_H
#define SYSTEMS_CRAFT_H

//#include "mk1_power_network/electrical_system.h"

#include <iostream>
#include <vector>
#include "primitives.h"
#include "Graph_Template.h"

using std::cout;
using std::endl;

class craft {
public:
    craft(int a);
    void tick();

private:

    void build_electrics();

};


#endif //SYSTEMS_CRAFT_H
