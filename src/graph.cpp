#include "graph.hpp"
#include "algorithm"

vector<string> graph::path(vector<node*> nodes, node* end){
    int distanceToEnd = end->distanceToStart;
    vector<string> list = {end->name};
    for(auto i : nodes){
        if (find(list.begin(), list.end(), end->prev->name) == list.end()) {
            list.push_back(end->prev->name);
        }
        end = end->prev;
    }

    // for(auto i : list){
    //     cout << i;
    // }
    // cout << "\n" << distanceToEnd;
    return list;
}

int graph::distanceToPath(node* end){
    return end->distanceToStart;
}

// node* graph::shortestEdge(vector<edge*> edges){

// }

