#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream F;
    // opening a file in input and output mode
    F.open("deepak_kumar_doc.dat",  ios::in | ios::out | ios::app);
    
   F.seekp(83,ios::beg);
   F.seekp(83,ios::beg);
   

   F<<"okay"<<endl;
    return 0;
}