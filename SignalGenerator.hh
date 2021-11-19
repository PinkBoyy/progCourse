#ifndef _SignalGenerator_HH_
#define _SignalGenerator_HH_

#include "RandomGenerator.hh"
#include <iostream>
#include <vector>

class SignalGenerator : public RandomGenerator
{
private:
    double ft; // Time
    unsigned long fnp; //Number of Points
    std::vector<double*> Harmonics;
    double fDC;
    double fNoise;
    double* fSignals;
    double* fTimes;
    bool fSignalCalculated;
    bool fTimeCalculated;
    bool NoiseAdded;


public:
    //Constructors
    SignalGenerator(double t, unsigned long np);
    ~SignalGenerator();
    
    //Functions
    void AddHarmonic(double ampl, double freq, double phase);
    void AddDC(double);
    void AddNoise(double);
    double* GetSignal();
    double* GetTime();

};






















#endif