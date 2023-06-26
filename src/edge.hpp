#include "node.hpp"

class edge{
    public:
        node* from;
        node* to;
        int weight;

    edge(node* from, node* to, int weight){
        this ->from = from;
        this ->to = to;
        this ->weight = weight;
    };

};