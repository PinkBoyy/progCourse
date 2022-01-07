#include "SignalGenerator.hh"
#include <math.h>

/*-----------Constructors/Destructors---------------------------*/
SignalGenerator::SignalGenerator(double t, unsigned long np)
{
    ft = t;
    fnp = np;
    NoiseAdded = false;
    fSignals = NULL;
    CalcTime();

}

SignalGenerator::~SignalGenerator()
{
    delete fTimes;
    if(fSignals != NULL) delete fSignals;
    for(auto obj : Harmonics) delete[] obj;

}

/*-------------------------------------------------------------*/

/*---------------------Methods---------------------------------*/

void SignalGenerator::AddHarmonic(double ampl, double freq, double phase){
    double* Harmonic = new double [3];

    if(freq > (fnp-1)/2*ft){}
    else{
        Harmonic[0] = ampl;
        Harmonic[1] = freq;
        Harmonic[2] = phase;
        Harmonics.push_back(Harmonic);
    }
 
   
}

void SignalGenerator::AddDC(double dc){
    fDC = dc;
}

void SignalGenerator::AddNoise(double noise){
    fNoise = noise;
    NoiseAdded = true;
}

double* SignalGenerator::GetSignal(){

    if(fSignals == NULL){
        double* signals = new double [fnp];
        for(int i = 0; i < fnp; i++){
            double signal = 0;
            for(int j = 0; j < Harmonics.size(); j++){
                double ampl = Harmonics[j][0];
                double freq = Harmonics[j][1];
                double phase = Harmonics[j][2];
                signal += ampl * sin(2 * M_PI * freq * fTimes[i] + phase);
            }
            signal += fDC;
            if(NoiseAdded) signal += GetGaus2(0, fNoise);
            
            signals[i] = signal;
        }
        fSignals = signals;
        return fSignals;
    }

    else return fSignals;
    
}

double* SignalGenerator::GetTime(){    
    return fTimes;
}

double* SignalGenerator::CalcTime(){
    double dt = ft / (fnp - 1), currentTime = 0;
    double* time = new double [fnp];
    for(int i = 0; i < fnp; i++){
        time[i] = currentTime;
        currentTime += dt;
    }

    fTimes = time;
    return fTimes;
}

/*-----------------------------------------------------------*/