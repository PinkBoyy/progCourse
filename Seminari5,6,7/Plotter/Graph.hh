#ifndef _GRAPH_HH_
#define _GRAPH_HH_
#include "Drawable.hh"


class Graph : public Drawable
{
private:
    
    
public:
    //Constructor;
    Graph(const char* name);
    Graph(const char* name, int np);   //np - number of points to create empty vectors
    
    //function  -   Setters;
    void SetPoint(int n, double x, double y, double ey=0); //n - index 
    void AddPoint(double x, double y, double ey=0);

    //Draw function
    void Draw(const char* option = " -l ");
    
    
    
};





#endif
