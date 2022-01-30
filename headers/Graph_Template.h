//
// Created by jdwil on 29/01/2022.
//

#ifndef SYSTEMS_GRAPH_TEMPLATE_H
#define SYSTEMS_GRAPH_TEMPLATE_H

#include "primitives.h"

#include <tuple>


using std::tuple;

class Graph_Template {
public:

    void add_node(Node new_node);

private:
    //Data structure
    vector<Node> nodes; //Vector of all the nodes`
    vector<tuple<string, Node* >> table; // Table links node IDs to string descriptions
        // Functions


    //Helper functions
    void update_Node(Node);
    Node& get_node(string ID);
    bool node_exists(string ID);

};


#endif //SYSTEMS_GRAPH_TEMPLATE_H
