//
// Created by jdwil on 29/01/2022.
//

#ifndef SYSTEMS_PRIMITIVES_H
#define SYSTEMS_PRIMITIVES_H
#include <vector>
#include <string>

using std::vector;
using std::string;




class Node {
public:
    string ID;

private:
    vector<int> links_to;

};




#endif //SYSTEMS_PRIMITIVES_H
