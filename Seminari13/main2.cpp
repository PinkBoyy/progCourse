#include <iostream>
#include <Graph.hh>
#include <RandomGenerator.hh>
#include <SignalGenerator.hh>
#include <fftw3.h>

void Runner(){

}




int main(){
    int N = 44100;
    double* in;
    fftw_complex *out;
    fftw_plan p;

    SignalGenerator s(1, N);
    s.AddHarmonic(1, 100, 0);

    N = N / 2 + 1;

    in = s.GetSignal();
    
    in = (double*) fftw_malloc(sizeof(double)*N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N);
    p = fftw_plan_dft_r2c_1d(N, in, out, FFTW_ESTIMATE);

    fftw_execute(p); // repeat as needed 
    fftw_destroy_plan(p);
    


    // fftw_free(in); fftw_free(out);

}