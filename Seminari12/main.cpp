#include <iostream>
#include "WaveReader.hh"
#include <unistd.h>
#include "Graph.hh"

using namespace std;


void Run(const char* fileName, WaveReader wav1, Graph &gr, double vpp=2){
    wav1.Open(fileName);
    wav1.SetVpp(vpp);

    double *Time = new double[wav1.GetNsamples()];
    double *Channel = new double[wav1.GetNsamples()];

    wav1.GetData(0, Channel);
    wav1.GetTimeAxis(Time);

    int size = wav1.GetNsamples();
    
    for(int i = 0; i < size; i++){
        gr.AddPoint(Time[i], Channel[i]);
    }

    gr.Draw();

    wav1.Print();   

    delete[] Time;
    delete[] Channel;
}


int main(){
    
    WaveReader wav1;
    // Graph gr1("gr1");
    Graph gr2("gr2");
    // Run("idle.wav", wav1, gr1, 5);
    Run("load.wav", wav1, gr2);

}