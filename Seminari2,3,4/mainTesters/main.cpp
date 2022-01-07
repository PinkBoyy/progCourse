#include <iostream>
#include <math.h>
#include "RootFinder.hh"

using namespace std;

/* ----------------------------------------------
    Uncomment any option and test the Library As you want
--------------------------------------------------*/


double func (double x){ return sin(x) - 0.5*x; }

void Option_1();

void Option_2();

void Option_3();

int main(){
   
   Option_1();

   //Option_2();

   //Option_3();

}

void Option_1(){
    /* --------Option 1----------- */
    double a = 1; 
    double b = 3;
    RootFinder f1(func, a, b);

    f1.display();
}

void Option_2(){
    /*------------Option 2------------------*/
    double a = 1; 
    double b = 3;
    RootFinder f1(func, a, b);

    cout << "\nfindRootBinary: x =  " << f1.findRootBinary() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    cout << "\nfindRootline: x =  " << f1.findRootLine() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    cout << "\nfindRootNewton: x =  " << f1.findRootNewton() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n"; 
    
}

void Option_3(){
    
    /*-------------Option 3-------------------*/
    double a = 1; 
    double b = 3;
    RootFinder f1(func, a, b);
    
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary() << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    //overloaded:
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary(5, 7) << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n";
    f1.setPrecision(5);
    cout << "\nnormal findRootBinary: x =  " << f1.findRootBinary(5, 7) << endl;
    cout << "\nSteps: " << f1.howManySteps() << "\n\n"; 
}
