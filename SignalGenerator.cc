#include "SignalGenerator.hh"
#include <math.h>

/*-----------Constructors---------------------------*/
SignalGenerator::SignalGenerator(double t, unsigned long np)
{
    ft = t;
    fnp = np;
    fSignalCalculated = false;
    fTimeCalculated = false;
    NoiseAdded = false;

}

SignalGenerator::~SignalGenerator()
{

}

/*-------------------------------------------------------------*/

/*---------------------Methods---------------------------------*/

void SignalGenerator::AddHarmonic(double ampl, double freq, double phase){
    double* Harmonic = new double [3];
    Harmonic[0] = ampl;
    Harmonic[1] = freq;
    Harmonic[2] = phase;

    Harmonics.push_back(Harmonic);
}

void SignalGenerator::AddDC(double dc){
    fDC = dc;
}

void SignalGenerator::AddNoise(double noise){
    fNoise = noise;
    NoiseAdded = true;
}

double* SignalGenerator::GetSignal(){
    if(!fTimeCalculated){
        GetTime();
    }

    if(!fSignalCalculated){
        double* signals = new double [fnp];
        for(int i = 0; i < fnp; i++){
            double signal = 0;
            for(int j = 0; j < Harmonics.size(); j++){
                double ampl = Harmonics[j][0];
                double freq = Harmonics[j][1];
                double phase = Harmonics[j][2];
                signal += ampl * sin(2 * M_PI * freq * fTimes[i] + phase);
               //std::cout << ampl << " " << freq << " " << phase << std::endl;
            }
            signal += fDC;
            if(NoiseAdded) signal += GetGaus2(0, fNoise);
            
            signals[i] = signal;
            //std::cout << signal << std::endl;
        }
        fSignals = signals;
        fSignalCalculated = true;
        return fSignals;
    }
    else return fSignals;
    
}

double* SignalGenerator::GetTime(){
    if(!fTimeCalculated){
        double dt = ft / (fnp - 1), currentTime = 0;
        double* time = new double [fnp];
        for(int i = 0; i < fnp; i++){
            time[i] = currentTime;
            currentTime += dt;
        }

        fTimes = time;
        fTimeCalculated = true;
        return fTimes;
    }

    else return fTimes;
    
}