//
// Created by jdwil on 27/01/2022.
//

#include "../headers/craft.h"

craft::craft(int a)
{
    Node new_node;

}

void craft::tick(){


}

void craft::build_electrics() {
    /* Uses mk1 power network.
     *
     * component batt = electrics.gen_component(1,100,1,"battery");
    component batt2 = electrics.gen_component(2,0,1,"light");
    component batt3 = electrics.gen_component(2,0,1,"light2");
    component generator = electrics.gen_component(3,12,50,1,"generator");
    electrics.components.push_back(batt);
    electrics.components.push_back(batt2);
    electrics.components.push_back(batt3);
    electrics.components.push_back(generator);
    cout << "Charge per connection = " << electrics.find_component("battery").charge_per_connection << endl;
    electrics.add_connection(electrics.gen_connection("battery","light",1));
    cout << "Charge per connection = " << electrics.find_component("battery").charge_per_connection << endl;
    electrics.add_connection(electrics.gen_connection("battery","light2",1));
    electrics.add_connection(electrics.gen_connection("generator","battery",1));
    cout << "Charge per connection = " << electrics.find_component("battery").charge_per_connection << endl;*/
}