#include <iostream>
#include <vector>
using namespace std;

class edge;


class node{

public: 
    string name;
    node* prev;
    vector<edge*> edges;
    int distanceToStart;

    node(string name, vector<edge*> edges, int distanceToStart, node* prev){
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