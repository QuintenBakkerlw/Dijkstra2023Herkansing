#include <iostream>
#include "edge.hpp"
using namespace std;

int main(){

    node a = node("a",{}, 0, "a"); node b = node("b",{}, INT_MAX, ""); node c = node("c",{}, INT_MAX, ""); node d = node("d", {}, INT_MAX, "");
    
   
    edge a1 = edge(&a, &b, 2); edge a2 = edge(&a, &c, 5); edge a3 = edge(&a, &d, 4);
    edge b1 = edge(&b, &d, 1);
    edge c1 = edge(&c, &d, 3);

    a.edges.push_back(&a1);
    a.edges.push_back(&a2);
    a.edges.push_back(&a3);
    b.edges.push_back(&b1);
    c.edges.push_back(&c1);

    node start = a;
    node end = d;
    vector<node*> eval = {&a};
    int var = INT_MAX;

    node* shortest;

    
    // while (eval.empty() == false)
    // {
    //     /* code */
    // }
    
    for(auto i : eval){
       
        if(i->distanceToStart < var){
            shortest = i;
            var = i->distanceToStart;
            
            
        }
    }

    for(auto i : shortest->edges){
        if (a.getDistanceToStart() + i->weight < i->to->getDistanceToStart()){
            i->to->setDistanceToStart(a.getDistanceToStart() + i->weight);
            i->to->prev = i->from->name;
            eval.push_back(i->to);

        }
    };
    
    

    
    cout << shortest->name;
  
   
    
} 