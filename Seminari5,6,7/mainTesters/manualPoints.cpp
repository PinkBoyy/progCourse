#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "Drawable.hh"
#include "Graph.hh"
#include "Histo.hh"
using namespace std;


void testGraph(){
    Graph g1("g1", 20);
    int b = 1;
    for(int i = 0; i < 20; i++){
        double a = rand() % 20;
        g1.SetPoint(i, a + b, a);
        
        b *= -1;
    }
    
    g1.Draw();
   
}

void testHisto(){
    Histo h1("h1", 4, 1, 9);
    
    h1.Fill(4);
    h1.Fill(3);
    h1.Fill(4);
    h1.Fill(2);
    h1.Fill(8);
    h1.Fill(6);
    h1.Fill(8);
    h1.Fill(6);
    h1.Fill(4);
    h1.Fill(4);
    h1.Fill(3);
    h1.Fill(4);
    h1.Fill(2);
    h1.Fill(8);
    h1.Fill(6);
    h1.Fill(8);
    h1.Fill(6);
    h1.Fill(4);
    
    cout << "\nGetIntegral = " << h1.GetIntegral() << "\n";
    cout << "\nMean = " << h1.GetMean() << "\n"; 
    cout << "\nRMS = " << h1.GetRMS() << "\n"; 
    
    h1.ShowError(true);
    h1.Draw();
}

int main(){
    srand(time(0));
    
    testGraph();
    
    testHisto();
    
    
}
