//
// Created by jdwil on 29/01/2022.
//

#include "../headers/Graph_Template.h"

using std::get;

void Graph_Template::add_node(Node new_node) {
    nodes.push_back(new_node); //Add the new node to the network
    if (!nodes.empty()) {
        auto newentry = std::make_tuple(new_node.ID, &nodes.back()); //Update the index table.

    }
}

void Graph_Template::update_Node(Node new_node) {

}

Node& Graph_Template::findNode(string ID) {
    for (auto item : table)
    {
        if (get<0>(item) == ID)
        {
            return *get<1>(item);
        }

    }

}