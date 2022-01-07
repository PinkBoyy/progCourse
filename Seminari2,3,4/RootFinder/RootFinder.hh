#ifndef _RootFinder_HH_
#define _RootFinder_HH_

class RootFinder
{
private:
    double (*f)(double);
    double a;
    double b;
    int precision;
    int steps;
    double middleXCalculator(double lEdge, double rEdge);
    double derivativeCalculator(double p);
    
public:
    //Constructor;
    RootFinder(double (*fp)(double), double, double);
    
    //getters
    double get_a();
    double get_b();
    double get_f(double x);
    
    //setters()
    void set_a(double ap);
    void set_b(double bp);
    void set_f(double (*fp)(double));
    void setPrecision(int p);
    
    double findRootBinary();
    double findRootBinary(double lEdge, double rEdge);
    
    double findRootLine();
    double findRootLine(double lEdge, double rEdge);
    
    double findRootNewton();
    double findRootNewton(double lEdge, double rEdge);
    
    int howManySteps();
    
    void display();
    
};


#endif
