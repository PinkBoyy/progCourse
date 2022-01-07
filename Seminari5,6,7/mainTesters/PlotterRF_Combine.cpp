#include <iostream>
#include <math.h>
#include "RootFinder.hh"
#include "Drawable.hh"
#include "Graph.hh"
#include "Histo.hh"

using namespace std;

double func (double x){ return sin(x) - 0.5*x; }
double func2 (double x){ return x * x; }
double func3 (double x) { return x * x * x; }
double func4 (double x) { return x * sin(1 / x);}

void useNewLibrary(){
    Graph gr1("gr1");
    Graph gr2("gr2");
    Graph gr3("gr3");
    Graph gr4("gr4");
    double x = -5;
    while(x < 5){
        gr1.AddPoint(x, func(x));
        gr2.AddPoint(x, func2(x));
       	gr3.AddPoint(x, func3(x));
        gr4.AddPoint(x, func4(x));
	x += 0.1;

    }
    
    gr1.Draw();
    gr2.Draw();
    gr3.Draw();
    gr4.Draw();
}


int main(){
    double a = 1; 
    double b = 3;
    RootFinder f1(func, a, b);
    
    //f1.display();
    
    
    cout << "\nfindRootBinary: x =  " << f1.findRootBinary() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    cout << "\nfindRootline: x =  " << f1.findRootLine() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    cout << "\nfindRootNewton: x =  " << f1.findRootNewton() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n"; 
    
    //normal:
    /*
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    //overloaded:
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary(5, 7) << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    f1.setPrecision(5);
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary(5, 7) << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n"; */
    
    
    cout << f1.get_f((a+b)/2) << endl;
    useNewLibrary();
}
