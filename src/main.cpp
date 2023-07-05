#include <iostream>
#include "graph.hpp"
#include <algorithm>
#include <queue>


struct SortingNode{
    bool operator()(const node* lhs, const node* rhs) const{
        return lhs->distanceToStart > rhs->distanceToStart;
    }
};

int main(){

    // nodes
    node a = node("A",{}, 0, &a); node b = node("B",{}, INT_MAX, &a); node c = node("C",{}, INT_MAX, &a); node d = node("D", {}, INT_MAX, &a); node e = node("E", {}, INT_MAX, &a);
    
    // edges
    edge a1 = edge(&a, &b,10); edge a2 = edge(&a, &c, 1); edge a3 = edge(&a, &d, 4);
    edge b1 = edge(&b, &d, 3); edge b2 = edge(&b, &e, 3);
    edge c1 = edge(&c, &d, 2);
    edge d1 = edge(&d, &e, 10); edge d2 = edge(&d, &b, 3);


    // add edges to nodes
    a.edges.push_back(&a1); a.edges.push_back(&a2); a.edges.push_back(&a3);
    b.edges.push_back(&b1); b.edges.push_back(&b2);
    c.edges.push_back(&c1);
    d.edges.push_back(&d1); d.edges.push_back(&d2);

    // graph
    graph g = graph( 
        {&a, &b, &c, &d, &e}, 
        {&a1,&a2,&a3,&b1,&b2,&c1,&d1,&d2}
    );

    // choose your starting node and ending node
    node* start = &a;
    node* end = &e;


    std::vector<node*> eval = {start}; // eval has al the avaliable node to use
    node* shortestNode;

    while (!eval.empty() == true)
    {       
        std::priority_queue<node*, std::vector<node*>, SortingNode> prioQueue;
        // int var = INT_MAX;
        // int x = 0;
        // int y;
        // for(auto i : eval){
        //         if(i->distanceToStart < var){
        //             y = x;
        //             var = i->distanceToStart;
        //         }

        //         if(i->distanceToStart == eval.back()->distanceToStart){
        //             eval.erase(eval.begin() + y);
        //         }
        //     x += 1;
        // };

        for(auto i : eval){ // puts nodes of eval into the priority queue
            prioQueue.push(i);
        }
        eval.clear();

        while(!prioQueue.empty()){ //using priority qeueu sorting from shortest to fartest
            node* node = prioQueue.top();
            prioQueue.pop();
            eval.push_back(node);
        }

        shortestNode = eval[0]; // Is the shortest path then erase it from eval
        eval.erase(eval.begin());

        // looks through avaliable edges of shortest node
        for(auto i : shortestNode->edges){ 
            if (shortestNode->distanceToStart + i->weight < i->to->distanceToStart){ // if it is shorter then origanol path, change it to shortest distance 
                i->to->setDistanceToStart(shortestNode->distanceToStart + i->weight); // add previous node to using node
                i->to->prev = i->from;
                if (find(eval.begin(), eval.end(), i->to) == eval.end()) { // add visited node to eval
                    eval.push_back(i->to);
                }
            }
        };
    }



    
    // prints the shortest path and the cost of the shortest path //
    std::cout << "shortest path to " << end->name << " from " << start->name << " is: \n\n";
    
    for(auto i :  g.path(g.nodes, end)){
        std::transform(i.begin(), i.end(), i.begin(), ::toupper); // converts lowercase to uppercase, is not needed if using uppercase in node
        std::cout << i << "\n";
    }
    
    std::cout << "\nPath cost : " << g.distanceToPath(end);
  
} 