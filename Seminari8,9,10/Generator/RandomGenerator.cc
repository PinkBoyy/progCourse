#include "RandomGenerator.hh"
#include <climits>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

/*--------------Constructors-------------- */

RandomGenerator::RandomGenerator(){
    srand(time(NULL));
    fGaus2Count = 0;
    fn = 20;
}

RandomGenerator::RandomGenerator(unsigned int seed){
    srand(seed);
    fGaus2Count = 0;
    fn = 20;
}

RandomGenerator::RandomGenerator(unsigned int seed, int n){
    srand(seed);
    fGaus2Count = 0;
    fn = n;
}

RandomGenerator::~RandomGenerator(){
    /* Nothing YET     */
}
/*-------------------------------------------------------*/


/*---------------------FUNCTIONS-------------------------*/
   
double RandomGenerator::GetRndm(double min, double max){
    double x = (double)rand();
    x /= INT_MAX;
    x *= (max-min);
    x += min;

    return x;
     
}

double RandomGenerator::GetGaus(double mean, double sigma){
    double x = 0;
    
    for(int i = 0; i < fn; i++){
        x += GetRndm(0, 1);
    }

    //making standart gaus
    x -= double(fn) / 2;
    x /= sqrt(double(fn) / 12);

    //making edited gaus
    x *= sigma;
    x += mean;
    
    return x;
}

double RandomGenerator::GetGaus2(double mean, double sigma){
    if(fGaus2Count % 2 == 0){
        fGaus2Count++;

        double x1 = 0, x2 = 0;
        while(x1 == 0 || x2 == 0){
            x1 = GetRndm(0, 1);
            x2 = GetRndm(0, 1);
        }

        double Z0 = sqrt(-2 * log(x1)) * cos(2 * M_PI * x2);
        double Z1 = sqrt(-2 * log(x1)) * sin(2 * M_PI * x2);

        fTempRndm = Z1 * sigma + mean;
        return Z0 * sigma + mean;
    }
    else{
        fGaus2Count++;
        return fTempRndm;
    }
}