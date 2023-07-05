#include <iostream>
#include "node.hpp"
#include "edge.hpp"
#include <queue>
#include <string>


class graph{
    private:
    std::vector<edge*> edges;

    public:
    std::vector<node*> nodes;

    graph(std::vector<node*> nodes, std::vector<edge*> edges){
        this->nodes = nodes;
        this->edges = edges;
    }

    std::vector<std::string> path(std::vector<node*> nodes, node* end);
    int distanceToPath(node* end);    
};