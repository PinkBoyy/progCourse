#ifndef _HISTO_HH_
#define _HISTO_HH_
#include "Drawable.hh"
#include <vector>
#include <string>

using namespace std;

class Histo : public Drawable
{
private:
    int fnbins;
    double fmin;
    double fmax;
    int fQuantity;
    double GetSquareMean();
    
public:
    //Constructor
    Histo(const char* name, int nbins, double min, double max);
    
    //Functions
    void Fill(double x);
    
    double GetMean();
    
    double GetRMS();
    
    int GetIntegral();
    
    void Draw(const char* option = "");
    
};



#endif
