#ifndef _RandomGenerator_HH_
#define _RandomGenerator_HH_


class RandomGenerator
{
private:
    int fn; //in Gaus, how many times sum up
    double fTempRndm; //for Gaus2 second randNumber
    int fGaus2Count; //to get which gaus number we want

public:
    //Constructors
    RandomGenerator();  //srand(time(NULL))
    RandomGenerator(unsigned int seed); //srand(seed)
    RandomGenerator(unsigned int seed, int n); //not needed, I made it up
    virtual ~RandomGenerator();
    
    //Functions
    double GetRndm(double min, double max);

    double GetGaus(double mean, double sigma);

    double GetGaus2(double mean, double sigma);
   
};









#endif