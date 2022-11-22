#ifndef MAKEREGISTERS_H
#define MAKEREGISTERS_H
#include <iostream>
using namespace std;

class makeRegisters{
  public:
    makeRegisters();
		string* getRegions();
    int* getRegisters();
    void fillArray(int vector[], int length);
    void fillArrayString(string vector[], int length);
    void swapStr(string array[],int number1, int number2);
    void swapInt(int array[],int number1, int number2);
    void sort(string reference[], string regions[], int registers[], int length);
		void heapSort(string array[], int arrayInt[], int N);
		void makeHeap(string array[],int arrayInt[], int length, int nodeIndex);
		void heapify(string array[], int arrayInt[], int N, int i);
    void printFormat(string array[], int arrayInt[],int length);
    void readFile(string file);
    ~makeRegisters();
  private:
    string regions[16];
    int registers[16];            
};
#endif
