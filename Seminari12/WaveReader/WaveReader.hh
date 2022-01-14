#ifndef _WAVEREADER_HH_
#define _WAVEREADER_HH_

class WaveReader {
protected:
  void       Init();   //
  void       Clear(); //delete old data in case of new file open
  
  short      NumOfChannels;
  int        SampleRate;
  short      BitsPerSample;
  int        NumOfSamples;
  double     Peak2Peak;
  bool       DoNormalize;
  double**   Channel;
  double*    Time;

public:
  WaveReader(); //call init
  WaveReader(const char* file, int maxsmp=-1); //call init and open
  virtual ~WaveReader();
  
  int        Open(const char* file, int maxsmp=-1);   //read that much of data
  int        GetData(int ch, double* data) const;
  int        GetTimeAxis(double* time) const;
  short      GetNchannels() const { return NumOfChannels; }
  int        GetNsamples() const { return NumOfSamples; }
  int        GetNbits() const { return BitsPerSample; }
  int        GetSampleRate() const { return SampleRate; }
  int        GetMaxPositive();
  int        GetMaxRange();
  void       Print() const;
  void       SetVpp(double Vpp = 2.);  //
  void       Scale(double coe);  //increase or decrease signal
};

#endif
