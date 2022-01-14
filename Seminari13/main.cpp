#include <iostream>
#include <string>
#include <math.h>
#include <fftw3.h>
#include <Graph.hh>
#include <RandomGenerator.hh>
#include <SignalGenerator.hh>
#include <WaveReader.hh>


/*
    In Terminal, to run this file, i needed to write the following commandLine:
        myg++ main.cpp -lPlotter -lGenerator -lWaveReader -lfftw3 && ./a.out
*/


int main(){

    //Reading data from load.wav file
    WaveReader wav1("load.wav");
    int N = wav1.GetNsamples();
    int cN= N / 2 + 1; //complex N
    wav1.Print();
    
    /*------------getting TimeAxis, and data from both channels-----*/
    double* timeAxis = new double[N];
    double* current = new double[N];
    double* voltage = new double[N];
    wav1.GetTimeAxis(timeAxis);
    wav1.GetData(0, current);
    wav1.GetData(1, voltage);
    /*-------------------------end_of_Getting_Data-------------------------*/ 


    /*----------Preparing X-Axis for Complex things-----------*/
    double maxFreq = double(N) / timeAxis[N - 1] / 2;
    double offSet = maxFreq / cN;
    double* xComplex = new double[cN]; 
    for(int i = 0; i < cN; i++) 
        xComplex[i] = offSet * i;
    /*-------------------------end_of_Making_X_AXIS--------  --------------------*/ 



    /*-----unccomment whichever you'd like to check------*/
    double* in = voltage;
    // double* in = current; 


    /*----------------------Making conversion-----------------------------------*/
    fftw_complex *out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * cN);
    fftw_plan p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);
    fftw_execute(p);
    /*-------------------------end_of_Conversion-------------------------------------*/ 



    /*------------------------Displaying info---------------------------*/
    //unccoment this in case of detailed info of x and y axis    
    // for(int i = 0; i < cN; i++){
    //     string op = " + ";
    //     if(out[i][1] < 0) op = " - ";
    //     cout << "x: "  << in[i] << "    y: " << out[i][0] << op << abs(out[i][1]) << "i"<< endl;
    // }

    Graph gr("gr2", cN);
    for(int i = 0; i < cN; i++){
        double a = sqrt(out[i][0] * out[i][0] + out[i][1] * out[i][1]) / cN;
        gr.AddPoint(xComplex[i], a);
    }

    gr.Draw();
    /*-------------------------end_of_Display_Info----------------------------------*/ 


    //Clearing
    fftw_destroy_plan(p);
    fftw_free(out);

}