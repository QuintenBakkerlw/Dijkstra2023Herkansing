#include "graph.hpp"
#include "algorithm"

std::vector<std::string> graph::path(std::vector<node*> nodes, node* end){
    int distanceToEnd = end->distanceToStart;
    std::vector<std::string> list = {end->name};
    for(auto i : nodes){ // look through node and gets previous visited of node and adds it, then repeats it with previous visited node
        if (find(list.begin(), list.end(), end->prev->name) == list.end()) {
            list.push_back(end->prev->name);
        }
        end = end->prev;
    }
    return list;
}

int graph::distanceToPath(node* end){ // returns shortest distance
    return end->distanceToStart;
}


