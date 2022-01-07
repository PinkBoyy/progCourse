#include <iostream>
#include <fstream>
#include <vector>
#include <Graph.hh>
#include <Histo.hh>
using namespace std;

struct obj
{
    double x;
    double y;
    double z;
} obj1;

vector<obj> data;


void Reader1(){
    ifstream binaryFile("channel1_old.bin3", ifstream::binary);
    double temp;

    //OFFSET
    binaryFile.read((char*)&obj1, 24);
    temp = obj1.x;
    obj1.x = 0;
    data.push_back(obj1);
    cout << data[0].x << " " << data[0].y << " " << data[0].z << endl;
    /*------------------------------------*/

    /*File size Determination */
    binaryFile.seekg(0, binaryFile.end);
    long size = binaryFile.tellg();
    binaryFile.seekg(24);
    size /= 24;
    /*-----------------------------------*/

    /*ReadFile*/
    for(int i = 0; i < size; i++){
         binaryFile.read((char*)&obj1, 24);
         obj1.x = obj1.x - temp;
         cout << obj1.x << " " << obj1.y << " " << obj1.z << endl;
         data.push_back(obj1);
    }
    /*------------------------------------------------*/

} 

void Reader2(){
    ifstream binaryFile("channel1_old.bin3", ifstream::binary);
    double val[3];
    
    //OFFSET
    binaryFile.read((char*)val, 24);
    double temp = val[0];
    obj1.x = 0;
    obj1.y = val[1];
    obj1.z = val[2];
    data.push_back(obj1);
    /*------------------------------------*/

    /*File size Determination */
    binaryFile.seekg(0, binaryFile.end);
    long size = binaryFile.tellg();
    binaryFile.seekg(24);
    size /= 24;

    for(int i = 0; i < size; i++){
         binaryFile.read((char*)val, 24); 
         obj1.x = val[0] - temp;
         obj1.y = val[1];
         obj1.z = val[2];
         data.push_back(obj1);
    }
}

void Reader3(){
    ifstream binaryFile("channel1_old.bin3", ifstream::binary);
    double* val;
    char buffer[24];
    
    //OFFSET
    binaryFile.read((char*)buffer, 24);
    val = (double*)buffer;
    double temp = *val;
    // cout << temp;
    obj1.x = 0;
    obj1.y = *(++val);
    obj1.z = *(++val);
    data.push_back(obj1);
    /*------------------------------------*/

    /*File size Determination */
    binaryFile.seekg(0, binaryFile.end);
    long size = binaryFile.tellg();
    binaryFile.seekg(0);
    size /= 24;

    for(int i = 0; i < size; i++){
        binaryFile.read((char*)buffer, 24);
        val = (double*)buffer;
        obj1.x = *val - temp;
        obj1.y = *(++val);
        obj1.z = *(++val);
        data.push_back(obj1);
    }

}

void Runner2(){
    Reader3();
    Histo h1("h1", 300, 30.005, 30.007);

    for(int i = 0; i < data.size(); i++){
        if(data[i].x > 12000 && data[i].x < 13000)
            h1.Fill(data[i].y);
    }

    h1.Draw();

    cout << "Mean = " << h1.GetMean() << "\nRMS = " << h1.GetRMS() << "\n";
}

void Runner(){
    Reader3();
    
    Graph gr1("gr1");
    for(int i = 0; i < data.size(); i++){
       gr1.AddPoint(data[i].x, data[i].y, data[i].z);
    }
    gr1.Draw();
}



int main(){
    
    Runner2();
    
}