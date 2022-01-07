#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//usual calculator
float calculator(int argc, char** argv);

//unsigned int Factorial Calculator
unsigned long lFactorialCalculator(int);

//Double Factorial Calculator
double dFactorialCalculator(int);

//deretmine float/double precisions
void check();

//instructions if input is incorrect
void helper();


int main(int argc, char** argv) {
  
  //checking input validity
  if(argc == 4) cout << calculator(argc, argv);
  
  else if(argc == 3 && atof(argv[1]) < 22) cout << lFactorialCalculator(atof(argv[1]));

  else if(argc == 3 && atof(argv[1]) >= 22) cout << dFactorialCalculator(atof(argv[1]));

  else helper();

}


float calculator(int argc, char** argv){
  
  float a = atof(argv[1]);
  float b = atof(argv[3]);
  
  if(*argv[2] == '+') return a + b;
  if(*argv[2] == '-') return a - b;
  if(*argv[2] == 'x') return a * b;
  if(*argv[2] == '/') return a / b;
  if(*argv[2] == '^') return pow(a, b);

  return 0;

}

unsigned long lFactorialCalculator(int a){
  unsigned long answer = 1;
  
  while(a > 0){
    answer *= a;
    a--;
  }

  return answer;

}

double dFactorialCalculator(int a){
  double answer = 1;
  
  while(a > 0){
    answer *= a;
    a--;
  }

  return answer;

}

void helper(){
  cout << "Some instructions for user..\n";
}

void check(){
  
  float a = 1, temp = 1;
  int k = 1;

  while(a != a + temp){
      temp /= 10;
      cout << "k " << k << endl;
      k++;
  }
  
  cout << "float precision = " << k << endl;

  double b = 1;
  k = 1, temp = 1;
  while(b != b + temp){
      temp /= 10;
      cout << "k " << k << endl;
      k++;
  }

  cout << "double precision = " << k << endl;

}