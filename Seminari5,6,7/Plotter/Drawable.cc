#include "Drawable.hh"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <unistd.h>

using namespace std;

int Drawable::fDrCount = 0;         //Starting number is 0

//Constructor
Drawable::Drawable(const char* name){ fName = name; fDrCount++; fDisplayError = false;}

//Destructor
Drawable::~Drawable(){

    string command = "find ";
    command += fName;
    command += " > /dev/null 2>&1";


    // if(!system(command.c_str())){
    //     command = "rm -f ";
    //     command += fName;
    //     system(command.c_str());
    // }

    if(fCommand.length()){
        command = "pkill -f ";
        command += fName;
        // system(command.c_str());
    }


}

//SetError
void Drawable::ShowError(bool a){
    fDisplayError = a;
}

//Draw function
void Drawable::Draw(const char* option){
    
    fDrCount--;   //decreasing the number of objects since they are already drawn

/*--------------------------------------------------------------------*/    
    //insert data into file.txt
    ofstream mydata;
    mydata.open(fName);
    for(int i = 0; i < fXdata.size(); i++){
        mydata << setprecision(10) << fXdata[i] << "\t" << fYdata[i] << "\t" << fEYdata[i] << "\n";
    }
    
    mydata.close();
/*--------------------------------------------------------------------*/    
    

/*--------------------------------------------------------------------*/    
    //call kst program and display as ordered
   string command = "kst2 ";
   command += fName;
   fCommand = command;
   command += option;
   if(fDisplayError) command += " -x 1 -e 3 -y 2&"; 
    else command += " -x 1 -y 2&"; 
    
    system(command.c_str());
/*--------------------------------------------------------------------*/  

/*--------------------------------------------------------------------*/  
    //sleep if it is the last Draw!!
    if(fDrCount == 0){
        getline(cin, command);
    }



}

