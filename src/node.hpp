#include <iostream>
#include <vector>


class edge;


class node{

public: 
    std::string name;
    node* prev;
    std::vector<edge*> edges;
    int distanceToStart;

    node(std::string name, std::vector<edge*> edges, int distanceToStart, node* prev){
        this ->distanceToStart = distanceToStart;
        this ->edges = edges;
        this ->name = name;
        this ->prev = prev;
    }

    int getDistanceToStart(){
        return distanceToStart;
    }

    void setDistanceToStart(int d){
        distanceToStart = d;
    }

    

};