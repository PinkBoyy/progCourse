#include <iostream>
#include <math.h>
#include "Drawable.hh"
#include "Graph.hh"
#include "Histo.hh"
#include <fstream>

using namespace std;

/*  ---------------

    TESTING main.cpp For PLOTTER LIBRARY - Uses "load_10mA" for DATA

---------------------------*/

//Read Data
void ReadFile(string fileName, Graph* gr1, Histo* h1){
    double input[3];            //to store X, Y and EY
    char d[40], e[40];          //just to read but not store additional data (not needed)
    ifstream database(fileName);
    double offset;              //since there are high numbers, i make first one zero
    database >> input[0] >> input[1] >> input[2] >> d >> e;
    gr1->AddPoint(0, input[1], input[2]);
    h1->Fill(input[2]);
    offset = input[0];

    if(database.is_open()){
        while (database >> input[0] >> input[1] >> input[2] >> d >> e) //Reading while valid
        { 
          gr1->AddPoint(input[0] - offset, input[1], input[2]);     //Adding to Gr1 Object
          h1->Fill(input[2]);   //Adding to h1 Object
        }
        database.close();
    }
    
}


int main(){
    
    Graph gr1("gr1_data");
    
    Histo h1("h1_data", 100, 0, 0.1);

    ReadFile("load_10mA", &gr1, &h1);
    
    gr1.Draw();

    h1.Draw();
    
}
