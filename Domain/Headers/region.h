#ifndef REGION_H
#define REGION_H
#include <iostream>
using namespace std;

class Region{
  private:
    string code;
    int size;
  public:
    Region(); //Default constructor
    Region(string code); // constructor
    ~Region(); // Destructor
    void setCode(string code); //Set codigo
    string getCode(); // GET codigo
    int getSize(); //GET cantidad de registros
    void setSize(int size); //SET cantidad de registros
};
#endif
