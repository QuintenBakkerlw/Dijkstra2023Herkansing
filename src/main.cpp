#include <iostream>
#include "graph.hpp"
#include <algorithm>
using namespace std;

int main(){

    node a = node("a",{}, 0, &a); node b = node("b",{}, INT_MAX, &a); node c = node("c",{}, INT_MAX, &a); node d = node("d", {}, INT_MAX, &a); node e = node("e", {}, INT_MAX, &a);
    
    edge a1 = edge(&a, &b,10); edge a2 = edge(&a, &c, 1); edge a3 = edge(&a, &d, 4);
    edge b1 = edge(&b, &d, 3); edge b2 = edge(&b, &e, 3);
    edge c1 = edge(&c, &d, 2);
    edge d1 = edge(&d, &e, 10); edge d2 = edge(&d, &b, 3);

    a.edges.push_back(&a1); a.edges.push_back(&a2); a.edges.push_back(&a3);
    b.edges.push_back(&b1); b.edges.push_back(&b2);
    c.edges.push_back(&c1);
    d.edges.push_back(&d1); d.edges.push_back(&d2);

    graph g = graph(
        {&a, &b, &c, &d, &e},
        {&a1,&a2,&a3,&b1,&b2,&c1,&d1,&d2}
    );

    node* start = &a;
    node* end = &e;


    vector<node*> eval = {start};
    vector<node*> test = {&a, &b, &c, &d};
    node* shortestNode;
    // int shortestPath = INT_MAX;
    
    // for (int i = 0; i< 50; i++){
    //     int u = 0;
    //     int j;
    //         for(auto i : test){  
    //         if (i->distanceToStart < shortestPath){
    //             shortestPath = i->distanceToStart;
    //             j = u;
    //             test.erase(test.begin() + j);
    //             test.push_back(i);
    //         }
    //             u += 1;
    //             shortestPath = i->distanceToStart;
    //         }
            

    // }
    

    while (!eval.empty() == true)
    {   

        int var = INT_MAX;
        int x = 0;
        int y;
        for(auto i : eval){
                if(i->distanceToStart < var){
                    y = x;
                    shortestNode = i;
                    var = i->distanceToStart;
                }

                if(i->distanceToStart == eval.back()->distanceToStart){
                    eval.erase(eval.begin() + y);
                }
            x += 1;
            };
    
        for(auto i : shortestNode->edges){
            if (shortestNode->distanceToStart + i->weight < i->to->distanceToStart){
                // cout << shortest->distanceToStart + i->weight << ":" << i->to->distanceToStart << "\n";
                i->to->setDistanceToStart(shortestNode->distanceToStart + i->weight);
                i->to->prev = i->from;
                // cout << i->from->name << ":  " << i->to->name << "\n";
                if (find(eval.begin(), eval.end(), i->to) == eval.end()) {
                    eval.push_back(i->to);
                }
            }
        };
    }


    
    // int distanceToEnd = end->distanceToStart;
    // vector<string> list = {end->name};
    // for(auto i : g.nodes){
    //     if (find(list.begin(), list.end(), end->prev->name) == list.end()) {
    //         list.push_back(end->prev->name);
    //     }
    //     end = end->prev;
    // }

    // cout << "\n" << distanceToEnd;

    for(auto i :  g.path(g.nodes, end)){
        cout << i;
    }
    cout << g.distanceToPath(end);
  
} 