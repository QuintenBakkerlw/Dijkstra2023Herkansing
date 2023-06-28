#include <iostream>
#include "node.hpp"
#include "edge.hpp"
using namespace std;

class graph{
    private:
    vector<edge*> edges;

    public:
    vector<node*> nodes;

    graph(vector<node*> nodes, vector<edge*> edges){
        this->nodes = nodes;
        this->edges = edges;
    }
};