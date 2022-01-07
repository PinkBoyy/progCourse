#ifndef _DRAWABLE_HH_
#define _DRAWABLE_HH_
#include <vector>
#include <string>


using namespace std;

class Drawable
{
protected:
    vector <double> fXdata;
    vector <double> fYdata;
    vector <double> fEYdata;
    string fCommand;
    bool fDisplayError;     //display error or not
    string fName;
    
    
public:
    static int fDrCount;        //count how many objects we have
    //Constructor
    Drawable(const char* name);
    //Destructor
    ~Drawable();
    
    //function;
    virtual void Draw(const char* option = "");
    
    //setErrorShowing
    void ShowError(bool a);     //set True or False 
    
    
};


#endif
