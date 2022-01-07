#include "Histo.hh"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//Constructor
Histo::Histo(const char* name, int nbins, double min, double max) : Drawable(name) {
    //assigning 
    fnbins = nbins;
    fmin = min;
    fmax = max;

    double interval = (max - min) / nbins;
    fXdata.resize(fnbins, 0);
    for(int i = 0; i < fXdata.size(); i++){
        fXdata[i] = min + interval / 2;
        min += interval;
    }
    
    fYdata.resize(nbins, 0);
    fEYdata.resize(nbins);
    

    fQuantity = 0;
    
}

//Filler
void Histo::Fill(double x){
    if(x < fmin || x >= fmax) cout << x << " is Out of intervals\n";
    else{
        double interval = (fmax - fmin) / fnbins;
        x -= fXdata[0] - interval / 2;
        fYdata[int(x/interval)] += 1;
        fQuantity++;  
    }
   
    
}

//Get Quantity
int Histo::GetIntegral(){
    return fQuantity;
}

//Get Mean
double Histo::GetMean(){
    double sum = 0;
    double interval = (fmax - fmin) / fnbins;
    
    for(int i = 0; i < fXdata.size(); i++){
        double center = fXdata[i];
        sum += center * fYdata[i];
    }
    
    return sum / GetIntegral();
}

//Helper Function for GetRMS
double Histo::GetSquareMean(){
    double sum = 0;
    double interval = (fmax - fmin) / fnbins;
    
    for(int i = 0; i < fXdata.size(); i++){
        double center = fXdata[i];
        sum += center * center * fYdata[i];
    }
    
    return sum / GetIntegral();
}

//GetRMS
double Histo::GetRMS(){
    return sqrt(GetSquareMean() - GetMean() * GetMean());
}

void Histo::Draw(const char* option){
    //calculating EY
    for(int i = 0; i < fYdata.size(); i++){
        fEYdata[i] = sqrt(fYdata[i]);
    }
    
    const char* op = " -b ";
    Drawable::Draw(op);
}
















