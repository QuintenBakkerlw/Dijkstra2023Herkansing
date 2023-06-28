#include <iostream>
#include "edge.hpp"
#include <algorithm>
using namespace std;

int main(){

    node a = node("a",{}, 0, "a"); node b = node("b",{}, INT_MAX, ""); node c = node("c",{}, INT_MAX, ""); node d = node("d", {}, INT_MAX, ""); node e = node("e", {}, INT_MAX, "");
    
   
    edge a1 = edge(&a, &b,10); edge a2 = edge(&a, &c, 1); edge a3 = edge(&a, &d, 4);
    edge b1 = edge(&b, &d, 3); edge b2 = edge(&b, &e, 3);
    edge c1 = edge(&c, &d, 2);
    edge d1 = edge(&d, &e, 10); edge d2 = edge(&d, &b, 3);

    a.edges.push_back(&a1);
    a.edges.push_back(&a2);
    a.edges.push_back(&a3);
    b.edges.push_back(&b1);
    b.edges.push_back(&b2);
    c.edges.push_back(&c1);
    d.edges.push_back(&d1);
    d.edges.push_back(&d2);


    node start = a;
    node end = d;
    vector<node*> eval = {&a};
    vector<node*> graph = {&a, &b, &c, &d, &e};
    // vector<int> path = {1,0,1,0,1,1,1};
    

    node* shortest;
   
    // for(auto i: eval){
    //     cout << i->name;
    // }
    
    while (!eval.empty() == true)
    {   
        // path.erase(path.begin());

        // for(auto i: eval){
        //     cout << i->name;
        // }
        // cout << "\n";
        int var = INT_MAX;
        int x = -1;
        int y = -1;
        for(auto i : eval){
            x = x + 1;
        
                if(i->distanceToStart < var){
                    y = x;
                    shortest = i;
                    var = i->distanceToStart;
                }

                if(i->distanceToStart == eval.back()->distanceToStart){
                    eval.erase(eval.begin() + y);
                }

            };
       
        for(auto i : shortest->edges){
            // cout << ".";
            if (shortest->distanceToStart + i->weight < i->to->distanceToStart){
                // cout << shortest->distanceToStart + i->weight << ":" << i->to->distanceToStart << "\n";
                i->to->setDistanceToStart(shortest->distanceToStart + i->weight);
                i->to->prev = i->from->name;
                // cout << i->from->name << ":  " << i->to->name << "\n";
                if (find(eval.begin(), eval.end(), i->to) == eval.end()) {
                    eval.push_back(i->to);
                }

            }
        };
    }
    
    cout << a.prev << "\n";
    cout << b.prev << "\n";
    cout << c.prev << "\n";
    cout << d.prev << "\n";
    cout << e.prev << "\n";
   vector<string> list;
   for (auto i : graph){
    list.push_back(i->prev);

   }
} 