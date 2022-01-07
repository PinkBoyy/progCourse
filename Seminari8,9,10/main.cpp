#include <iostream>
#include <climits>
#include <math.h>
#include <vector>
#include "RandomGenerator.hh"
#include "Histo.hh"
#include "SignalGenerator.hh"
#include "Graph.hh"

using namespace std;

//PI calculator Function
double calculatePI(int n);
//Heper for PI Calculator
bool isInCircle(pair<double, double> a);


//Gaus2 Checker
void Runner();
//PI calculator
void Runner2();
//Signals
void Runner3();
//Draw a circle with Graph
void Runner4();


int main(){
    
/* -------Uncomment any to test-----------*/

    // Runner();
    // Runner2();
    // Runner3();
    // Runner4();


/*----------------------------------------*/

}

//PI calculator Function
double calculatePI(int n){
    double PI;
    int circleCount = 0;

    pair<double, double> a;
    RandomGenerator rndm;

    for(int i = 0; i < n; i++){
        a.first = rndm.GetRndm(-1, 1);
        a.second = rndm.GetRndm(-1, 1);

        if(isInCircle(a)){
            circleCount++;
        }
    } 
    
    PI = double(n) / circleCount;
    PI = 4 / PI;

    return PI;

}

//Helper for PI Calculator
bool isInCircle(pair<double, double> a){
    double d = sqrt(abs(a.first * a.first) + abs(a.second * a.second));
    if(d <= 1) return true;
    else return false;
}

//Gaus2 Checker
void Runner(){
    double mean = 5, sigma = 1, size;
    cout << "\nEnter the number of Points:\n";
    cin >> size;
    Histo h1("h1", 100, -4 * sigma + mean, 4 * sigma + mean);
    
    RandomGenerator r1(time(NULL), 20);
    for(int i = 0; i < size; i++)
        h1.Fill(r1.GetGaus2(mean, sigma));

    h1.Draw();
}

//PI calculator
void Runner2(){
    int n;
    cout << "\nEnter the Number of Points:\n";
    cin >> n;

    cout << calculatePI(n);
}

//Signals
void Runner3(){
    double t, np;
    cout << "\nEnter the time and the number of Points:\n";
    cin >> t >> np;

    SignalGenerator s(t, np);
    s.AddHarmonic(1, 100, 0);
    s.AddHarmonic(0.5, 200, 0);
    
    Graph gr("gr");

    for(int i = 0; i < np; i++)
        gr.AddPoint(s.GetTime()[i], s.GetSignal()[i]);

    gr.Draw();

}

//Draw a circle with Graph
void Runner4(){
    int n;
    cout << "\nEnter the number of Points:\n";
    cin >> n;
    pair<double, double> a;
    RandomGenerator rndm;
    Graph circle("circle");
    for(int i = 0; i < n; i++){
        a.first = rndm.GetRndm(-1, 1);
        a.second = rndm.GetRndm(-1, 1);

        if(isInCircle(a))
            circle.AddPoint(a.first, a.second);
    }

    circle.Draw(" -d ");
}

