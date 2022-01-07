#include "RootFinder.h"
#include <iostream>
#include <cmath>
using namespace std;

/*---------------------------------
        Mokled
iteraciis shecdoma martivi iyo: k = 0; gaklda.. da k-s mnishvnelobas kompiuteri anichebda 
tviton ragac uazro ricxvs.. eg chavaswroe.. 

UFRO MNISHVNELOVANI SHECDOMA:

funqcias shen tviton unda adzlevde RootFinder-s da ara shignit iyos chashenebuli
rame konkretuli.. amitom, shen tviton funqciis ganmarteba, romelzec ginda amushavo 
sheni klasi unda gqondes main-shi da ara ushualod klasis heder-cpp-shi rogorc shen gqonda..

tan anu ashkarad gamocxadebuli gaqvs funqciis cvladi ( c ) rom qvia eg.. da ar iyenebdi saertod..
albat ar icodi ristvis iyo.. nu itokshi chavaswore da ase unda.. erti gadaxedvit sxva 
shecdomas ver vnaxulob axla.. 

do{
    ...
} while( ... )     <--- amis gamoyeneba ar ginda dzmura magari cudi gasashifria ucxo 
tvalistvis kodi mere.. 

kido ravi, dalshe gadaxede kido rame homarali iseti.. 

------------------------------------*/

double func(double x){
	return sin(x)-0.5*x;
}

int main(){

    RootFinder obj1(func,1,3);
    cout<<obj1.newton(0.001)<<endl;
    cout<<obj1.middlepoint(0.001)<<endl;
    cout<<obj1.qorda(0.001)<<endl;

}
