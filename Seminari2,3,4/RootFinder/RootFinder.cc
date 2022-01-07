#include "RootFinder.hh"
#include <math.h>
#include <iostream>

using namespace std;


//Constructor
RootFinder::RootFinder(double (*fp)(double), double ap, double bp){
    f = fp;
    a = ap;
    b = bp;
    precision = 3;
    steps = 0;
}

//getters
double RootFinder::get_a(){ return a; }
double RootFinder::get_b(){ return b; }
double RootFinder::get_f(double x) { return f(x); }

//setters()
void RootFinder::set_a(double ap) { a = ap; }
void RootFinder::set_b(double bp) { b = bp; }
void RootFinder::set_f(double (*fp)(double)) { f = fp; }
void RootFinder::setPrecision(int p){ precision = p; }

//Finding Methods

//BinaryMethod
double RootFinder::findRootBinary(){
    steps = 0;
    double lEdge = a, rEdge = b, left, middle, right, Pprecision = pow(10, -precision);
    
    while(true){
        steps++;
        left = f(lEdge);
        right = f(rEdge);
        middle = f((rEdge + lEdge) / 2);
        
        //precision determine
        if((rEdge - lEdge) / 2 < Pprecision){
            return (rEdge + lEdge) / 2;
        }
        
        //interval determine
        else if(left * middle < 0) rEdge = (rEdge + lEdge) / 2;
        else lEdge = (rEdge + lEdge) / 2;
        
    }
    
    return 0;
}

//BinaryMethodOverloaded
double RootFinder::findRootBinary(double lEdge, double rEdge){
    steps = 0;
    double left, middle, right, Pprecision = pow(10, -precision);
    
    while(true){
        steps++;
        left = f(lEdge);
        right = f(rEdge);
        middle = f((rEdge + lEdge) / 2);
        
        //precision determine
        if((rEdge - lEdge) / 2 < Pprecision){
            return (rEdge + lEdge) / 2;
        }
        
        //interval determine
        else if(left * middle < 0) rEdge = (rEdge + lEdge) / 2;
        else lEdge = (rEdge + lEdge) / 2;
        
    }
    
    return 0;
}

//LineMethod
double RootFinder::findRootLine(){
     steps = 0;
     double lEdge = a, rEdge = b, left, middle, right, Pprecision = pow(10, -precision);
     
     while(true){
        steps++;
        left = f(lEdge);
        right = f(rEdge);
        middle = f(middleXCalculator(lEdge, rEdge));
        
        //precision determine
        if(fabs(middleXCalculator(lEdge, rEdge) - lEdge) < Pprecision) return (middleXCalculator(lEdge, rEdge) + lEdge) / 2;
        else if(fabs(rEdge - middleXCalculator(lEdge, rEdge)) < Pprecision) return (middleXCalculator(lEdge, rEdge) + rEdge) / 2;
        
        //interval determine
        else if(left * middle < 0) rEdge = middleXCalculator(lEdge, rEdge);
        else lEdge = middleXCalculator(lEdge, rEdge);
    }
    
    return 0;
}

//LineMethodOverloaded
double RootFinder::findRootLine(double lEdge, double rEdge){
     steps = 0;
     double left, middle, right, Pprecision = pow(10, -precision);
     
     while(true){
        steps++;
        left = f(lEdge);
        right = f(rEdge);
        middle = f(middleXCalculator(lEdge, rEdge));
        
        //precision determine
        if(fabs(middleXCalculator(lEdge, rEdge) - lEdge) < Pprecision) return (middleXCalculator(lEdge, rEdge) + lEdge) / 2;
        else if(fabs(rEdge - middleXCalculator(lEdge, rEdge)) < Pprecision) return (middleXCalculator(lEdge, rEdge) + rEdge) / 2;
        
        //interval determine
        else if(left * middle < 0) rEdge = middleXCalculator(lEdge, rEdge);
        else lEdge = middleXCalculator(lEdge, rEdge);
    }
    
    return 0;
}

//NewtonMethod
double RootFinder::findRootNewton(){
    steps = 0;
    double lEdge = a, rEdge = b, l, m, x, tempX, Pprecision = pow(10, -precision);
    tempX = (lEdge + rEdge) / 2;
    
    m = derivativeCalculator(tempX);
    
    while(true){
        steps++;
        l = f(tempX) - m * tempX;
        x = (-l) / m;
        
        if(fabs(tempX - x) / 2 < Pprecision) return (tempX + x) / 2;
        
        else{
            tempX = x;
            m = derivativeCalculator(tempX);
        }
    }
    
}

//NewtonMethodOverloaded
double RootFinder::findRootNewton(double lEdge, double rEdge){
    steps = 0;
    double l, m, x, tempX, Pprecision = pow(10, -precision);
    tempX = (lEdge + rEdge) / 2;
    
    m = derivativeCalculator(tempX);
    
    while(true){
        steps++;
        l = f(tempX) - m * tempX;
        x = (-l) / m;
        
        if(fabs(tempX - x) / 2 < Pprecision) return (tempX + x) / 2;
        
        else{
            tempX = x;
            m = derivativeCalculator(tempX);
        }
    }

}


//private HELPER methods
double RootFinder::derivativeCalculator(double p){
    double delta = 0.001;
    
    return (f(p + delta) - f(p))/ delta;
}

double RootFinder::middleXCalculator(double lEdge, double rEdge){
    double left, right, middleX, l, k;
    left = f(lEdge);
    right = f(rEdge);
    
    k = (right - left) / (rEdge - lEdge);
    l = right - k * rEdge;
    
    middleX = (-l) / k;
    
    return middleX;
    
}

//steps
int RootFinder::howManySteps(){ return steps; }

//display
void RootFinder::display(){
    cout << "\n\nFinding root using Binary Method: x = " << findRootBinary() << endl <<
            "\nFinding root using Line Method: x = " << findRootLine() << endl <<
            "\nFinding root using Newton Method: x = " << findRootNewton() << endl << endl << endl;
}