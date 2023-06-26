#include <iostream>
#include <vector>
using namespace std;

class edge;

class node{

public: 
    string name, prev;
    vector<edge*> edges;
    int distanceToStart;

    node(string name, vector<edge*> edges, int distanceToStart, string prev){
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