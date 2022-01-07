#include "Graph.hh"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//Constructor
Graph::Graph(const char* name) : Drawable(name) {}

Graph::Graph(const char* name, int np) : Drawable(name){
    fXdata.resize(np, 0);
    fYdata.resize(np, 0);
    fEYdata.resize(np, 0);
}


//function - Setters
void Graph::SetPoint(int n, double x, double y, double ey){
    
    if(n + 1 > fXdata.size()){
        fXdata.resize(n, 0);
        fYdata.resize(n, 0);
        fEYdata.resize(n, 0);
        AddPoint(x, y, ey);
    }
    else{
        fXdata[n] = x;
        fYdata[n] = y;
        fEYdata[n] = ey;
    }
    
}

void Graph::AddPoint(double x, double y, double ey){
        fXdata.push_back(x);
        fYdata.push_back(y);
        fEYdata.push_back(ey);
}

void Graph::Draw(const char* option){
    const char* op = option;
    Drawable::Draw(op);
}
