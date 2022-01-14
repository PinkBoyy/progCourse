#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//usual calculator
float calculator(char** argv);

//unsigned int Factorial Calculator
unsigned long lFactorialCalculator(int);

//Double Factorial Calculator
double dFactorialCalculator(int);

//deretmine float/double precisions
void check();

template <class T>
T factorialCalculator(int a){
  T answer = 1;
  while(a > 0){
    answer *= a;
    a--;
  }

  return answer;
}

//instructions if input is incorrect
void helper();




int main(int argc, char** argv) {
  
  //checking input validity
  if(argc == 4) cout << calculator(argv) << endl;
  
  //check which type we need { Unsigned Long or Double}
  else if(argc == 3 && atof(argv[1]) < 22 && *argv[2] == '!') cout << factorialCalculator<unsigned int>(atof(argv[1])) << endl;

  else if(argc == 3 && atof(argv[1]) >= 22 && *argv[2] == '!') cout << factorialCalculator<double>(atof(argv[1])) << endl;

  else helper();

}


float calculator(char** argv){
  
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
  cout << "To use just {x, /, +, -}, pattern is like that: { a + b }\n";
  cout << "To use factorial, pattern is: { a ! }\n";
  cout << "Where a and b are numbers..\n";
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