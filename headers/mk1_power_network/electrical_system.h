//
// Created by jdwil on 27/01/2022.
//

#ifndef SYSTEMS_ELECTRICAL_SYSTEM_H
#define SYSTEMS_ELECTRICAL_SYSTEM_H
#include "power_items.h"

class electrical_system {
public:
    vector<component> components;
    vector<connection> connections;

    vector<connection> get_connections(string ID);
    void add_component(component new_component);
    void add_connection(connection);
    component gen_component(int type, int start_charge, int state, string ID);
    component gen_component(int type, int start_charge, int power_generation, int state, string ID);
    connection gen_connection(string start, string end, bool status);

    component find_component(string ID);
    void update_component(component new_component);


    void tick();
    void showupdate();
};


#endif //SYSTEMS_ELECTRICAL_SYSTEM_H
