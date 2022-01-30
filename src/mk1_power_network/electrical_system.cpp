//
// Created by jdwil on 27/01/2022.
//

#include "../../headers/mk1_power_network/electrical_system.h"

void electrical_system::add_component(component new_component) {
    components.push_back(new_component);
}

component electrical_system::gen_component(int type, int start_charge, int power_generation, int state, string ID) {
    component new_C = gen_component(type, start_charge, state, ID);
    new_C.power_generation = power_generation;
    return new_C;
}

component electrical_system::gen_component(int type, int start_charge=0, int state=0, string ID="") {
//Types: 1 = battery. 2 = light, 3 = generator
    component new_component;
    new_component.type = type;
    new_component.charge = start_charge;
    new_component.state = state;
    new_component.ID = ID;
    new_component.charge_per_connection = start_charge;
    new_component.power_generation = 0;
    if (new_component.charge_per_connection > 20)
    {
        new_component.charge_per_connection = 20;
    }
    if (type == 1)
    {
        new_component.power_use = 0;
        new_component.max_charge = 100;
    }
    if (type == 2)
    {
        new_component.power_use = 1;
        new_component.max_charge = 2;
    }
    if (type == 3)
    {
        new_component.power_use = 0;
        new_component.max_charge = 200;
    }
    return new_component;

}

connection electrical_system::gen_connection(string start, string end, bool status) {
    connection new_connection;
    new_connection.from = start;
    new_connection.to = end;
    new_connection.state = status;
    return new_connection;
}

void electrical_system::add_connection(connection new_connection) {

    connections.push_back(new_connection);
    cout << "Added connection from " << new_connection.from << " to " << new_connection.to << endl;
    vector<connection> curCons = get_connections(new_connection.from);
    cout << "When adding connection I found " << curCons.size() << " connections" << endl;
    int C = curCons.size();
    component gotC = find_component(new_connection.from);
    if (C != 0)
    {
        gotC.charge_per_connection = gotC.charge / C;
        if (gotC.charge_per_connection > 20)
        {
            gotC.charge_per_connection = 20;
        }
    }
    update_component(gotC);
    cout << "In " << gotC.ID << " there is now a charge per connection of " << gotC.charge_per_connection << " from a total charge of " << gotC.charge << endl;
    cout << endl << endl;

}

component electrical_system::find_component(string ID)
{
    for (auto c : components)
    {
        if (c.ID == ID)
        {
            return c;
        }
    }
}

vector<connection> electrical_system::get_connections(string ID)
{
    vector<connection> conns;
    for (auto c : connections)
    {
        if (c.from == ID)
        {
            conns.push_back(c);
        }
    }
    return conns;
}


void electrical_system::tick()
{
    for (auto C : components)
    {
        if (C.type == 3)
        {
            if (C.state == 1)
            {
                cout << "I am adding " << C.power_generation << " to " << C.charge << endl;
                C.charge = C.charge + C.power_generation;

            }
        }

        // First off, lets make sure that previous updates haven't taken us over max charge.
        if (C.charge > C.max_charge)
        {
            C.charge = C.max_charge;
        }
        // Power goes out first. Lets find all the places we connect to.
        vector<connection> conns = get_connections(C.ID);
        //Let's update the charge per conneection.
        if (conns.size() > 0)
        {
            C.charge_per_connection = C.charge / conns.size();
            if (C.charge_per_connection > 20)
            {
                C.charge_per_connection = 20;
            }
        }

        // Ok, lets check to make sure we're not going to overload...
        int charge_spent = 0;
        cout << C.ID << " has a charge per connection of " << C.charge_per_connection << " over " << conns.size() << " connections. There is a total charge of " << C.charge << "." << endl;
        if (C.charge_per_connection * conns.size() < C.charge)
        {
            cout << "Not overloading " << C.ID << endl;
            //Update our held charge first.

            // Go through the connections and update their charge.
            for (auto outward_connection : conns)
            {
                component other_c = find_component(outward_connection.to);
                int new_charge = other_c.charge + C.charge_per_connection;
                if (new_charge > other_c.max_charge)
                {
                    new_charge = other_c.max_charge - other_c.charge;
                }
                //Keep track of how much we've sent out,
                charge_spent = charge_spent + new_charge;
                //Update the other component.
                update_component(other_c);
            }
        }
        //Lets update the compnent with charge spent...
        C.charge = C.charge - charge_spent;
        //Update for our own power use...
        C.charge = C.charge - C.power_use;
        if (C.charge < 0)
        {
            C.charge = 0;
        }

        update_component(C);


    }

}

void electrical_system::update_component(component new_component)
{
    for (int a = 0; a < components.size(); a++)
    {
        if (new_component.ID == components[a].ID)
        {
            components[a] = new_component;
        }
    }
}

void electrical_system::showupdate() {
    for (auto C: components)
    {
        cout << C.ID << " has " << C.charge << endl;
    }
}