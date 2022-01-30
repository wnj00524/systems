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
    if (node_exists(new_node.ID)) // Does the node exist?
    {
        //If it does update it!
        Node old_node = get_node(new_node.ID); //Gets the node via reference
        old_node = new_node; // Updates it.
    }

}

Node& Graph_Template::get_node(string ID) {
    for (auto item : table)
    {
        if (get<0>(item) == ID) // Does the ID match?
        {
            return *get<1>(item); //Return the reference via pointer.
        }

    }

}

bool Graph_Template::node_exists(string ID) {
    for (auto item: table)
    {
        if (get<0>(item) == ID)
        {
            return true;
        }
    }
    return false;

}