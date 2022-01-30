//
// Created by jdwil on 27/01/2022.
//

#ifndef SYSTEMS_POWER_ITEMS_H
#define SYSTEMS_POWER_ITEMS_H

#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::string;

struct component;

struct connection
{
    ~connection();
    int ID;
    string from;
    string to;
    int charge;
    int max_charge = 20;
    bool state;
};

struct component
{


    component();
    ~component();
    string ID;
    int charge;
    int power_in;
    int power_out;
    int power_use;
    int max_charge;
    int charge_per_connection;
    int power_generation;
    int type; // 1 = battery, 2 = light, 3 = generator
    int state; //0 = off, 1 = on, 2 = standby

};




#endif //SYSTEMS_POWER_ITEMS_H
