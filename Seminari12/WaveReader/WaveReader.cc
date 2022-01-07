#include "WaveReader.hh"
#include <iostream>
#include <math.h>
#include <fstream>
#include <string.h>


using namespace std;

/*---------------Constructor/Destructor---------------------*/
WaveReader::WaveReader(){
    Init();
}

WaveReader::WaveReader(const char* file, int maxsmp){
    Init();
    Open(file, maxsmp);
}

WaveReader::~WaveReader(){
    Clear();
}
/*-------------------------------------------------------------*/

/*---------------------Protected-Methods-------------------*/

void WaveReader::Init(){
    NumOfChannels = 0;
    SampleRate = 0;
    BitsPerSample = 0;
    Peak2Peak = 0;
    DoNormalize = false;
    NumOfSamples = 0;
    Channel = 0;
    Time = 0;
}

void WaveReader::Clear(){
    for(int i = 0; i < NumOfChannels; i++){
            delete[] Channel[i];
    }
    delete[] Channel; 
    
    delete Time;
    //Gotta make correct;
}   
/*-----------------------------------------------------------------*/

/*------------------------Public-Methods--------------------------*/
int WaveReader::Open(const char* file, int maxsmp){

    ifstream inFile(file, ios::binary);
    
    char name[4];
    inFile.read(name, 4);
    if(!strstr(name, "RIFF")) 
        return -1;
    
    int ChunkSize;
    inFile.read((char*)&ChunkSize, 4);

    char Format[4];
    inFile.read(Format, 4);
    if(!strstr(Format, "WAVE"))
        return -2;
    
    char SubchunkID[4];
    inFile.read((char*)&SubchunkID, 4);
    if(!strstr(SubchunkID, "fmt"))
        return -3;
    
    int SubChunkSize;
    inFile.read((char*)&SubChunkSize, 4);
    
    short AudioFormat;
    inFile.read((char*)&AudioFormat, 2);

    inFile.read((char*)&NumOfChannels, 2);

    inFile.read((char*)&SampleRate, 4);

    int ByteRate;
    inFile.read((char*)&ByteRate, 4);

    short BlockAlign;
    inFile.read((char*)&BlockAlign, 2);

    inFile.read((char*)&BitsPerSample, 2);

    char Subchunk2ID[4];
    inFile.read(Subchunk2ID, 4);
    if(!strstr(Subchunk2ID, "data")) return -4;

    int Subchunk2Size;
    inFile.read((char*)&Subchunk2Size, 4);
    NumOfSamples = Subchunk2Size * 8 / BitsPerSample / NumOfChannels;

    if(maxsmp > 0 && maxsmp < NumOfSamples)
        NumOfSamples = maxsmp; 
    
    bool TooBig = true;

    while(TooBig)
    try{
        Time = new double [NumOfSamples];
        Channel = new double* [NumOfChannels];
        for(int i = 0; i < NumOfChannels; i++)
            Channel[i] = new double[NumOfSamples];

        TooBig = false;
    }
    catch(bad_alloc&){
        cout << "Error allocating memory: Not enough free memory!\n";
        NumOfSamples /= 2;
    }

    int data;
    int MaxRange = GetMaxRange();
    int MaxPositive = GetMaxRange()/2 - 1;
    int SSize = BitsPerSample / 8;
    bool Is2sComplement = BitsPerSample >= 16;

    inFile.seekg(44, ios::beg);
    for(int i = 0; i < NumOfSamples; i++){
        for(int j = 0; j < NumOfChannels; j++){
            data = 0;
            inFile.read((char*)&data, SSize);
            if(Is2sComplement){
                if(data > MaxPositive)
                    Channel[j][i] = data - MaxRange;
                else Channel[j][i] = data;
            }
            else Channel[j][i] = data - MaxPositive;
        }

        Time[i] = 1./SampleRate * i;
    }

    if(DoNormalize)
        SetVpp(Peak2Peak);
    
    return 0;
} 

int WaveReader::GetData(int ch, double* data) const{
    if(ch < NumOfChannels && ch >= 0){
        for(int i = 0; i < NumOfSamples; i++){
            data[i] = Channel[ch][i];
        }
    }
    else{
        cout <<"No such Channel!\n";
        return -1;
    }
    
    return 0;
}

int WaveReader::GetTimeAxis(double* time) const{
    for(int i = 0; i < NumOfSamples; i++){
        time[i] = Time[i];
    }
    return 0;
}

int WaveReader::GetMaxPositive(){
    return GetMaxRange()/2 - 1;
}

int WaveReader::GetMaxRange(){
    return pow(2, BitsPerSample);
}

void WaveReader::Print() const{

    cout << "Number of Channels: " << NumOfChannels << endl;
    cout << "Sample Rate: " << SampleRate << " Hz" << endl;
    cout << "Bits Per Sample: " << BitsPerSample << endl;
    cout << "Number of Samples: " << NumOfSamples << endl;

    // NumOfSamples = 5;
}

void WaveReader::SetVpp(double Vpp){
    double coef;
    if(DoNormalize){
        coef = Vpp / Peak2Peak;
        Peak2Peak = Vpp;
    }           // IDK IF THIS WORKS <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    else{
        DoNormalize = true;
        Peak2Peak = Vpp;
        coef = Peak2Peak / GetMaxRange();
    }

    Scale(coef);
}

void WaveReader::Scale(double coe){
   
    for(int i = 0; i < NumOfChannels; i++){
        for(int j = 0; j < NumOfSamples; j++){
            Channel[i][j] *= coe;
        }
    }

}

/*-------------------------------------------------------------*/






