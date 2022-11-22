#include "Headers/makeRegisters.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

makeRegisters::makeRegisters(){
  fillArray(registers, 16);
	fillArrayString(regions, 16);
}
void makeRegisters::fillArray(int vector[], int length){
	for (int i = 0; i < length; i ++){
    vector[i] = 0;
  }
}
void makeRegisters::fillArrayString(string vector[], int length){
  for(int i = 0; i < length; i ++ ){
    vector[i] = to_string(i+1);            
  }
}
void makeRegisters::swapStr(string array[],int number1, int number2){
  string aux = array[number1];
  array[number1] = array[number2];
	array[number2] = aux;   
}
void makeRegisters::swapInt(int array[],int number1, int number2){
	int aux = array[number1];
	array[number1] = array[number2];
	array[number2] = aux;   
}
void makeRegisters::sort(string reference[], string regions[], int registers[], int length){
  for(int i =0 ; i < length - 1; i ++){
    for (int j = i; j < length; j++){
      if (reference[i] == regions[j]){
				swapStr(regions,i,j);
        swapInt(registers,i,j);
        break;
      }
    }
  }
}
void makeRegisters::printFormat(string array[], int arrayInt[],int length){
  cout << "Codigo Region; registros" << endl;
  for (int i = 0; i < length; i++){
		cout << array[i] << "; " << arrayInt[i] << endl;
  }
}
void makeRegisters::readFile(string file){
  ifstream myFileStream(file);
  string code;
  string line;
  int number;      
  getline(myFileStream,line);
  while(getline(myFileStream,line)){
		stringstream ss(line);
		getline(ss,code,';');
		number = stoi(code);
		registers[number-1] += 1;
  }       
	myFileStream.close();
}
makeRegisters::~makeRegisters(){}
string * makeRegisters::getRegions(){
	return this->regions;
}
int * makeRegisters::getRegisters(){
  return this->registers;
}
void makeRegisters::makeHeap(string array[],int arrayInt[], int length, int nodeIndex){
	// En vez de utilizar hijos como 2i y 2i+1, se puede utilizar 2i+1 y 2i+2 (empezando con el arreglo en 0)
	int minor = nodeIndex;
	cout << stoi (array[2*nodeIndex+1]) << "  " << stoi (array[2* nodeIndex+2]) << endl;
	if (2* nodeIndex+ 1 < length && stoi(array[2* nodeIndex+1]) > 
		stoi(array[minor])) minor = 2*nodeIndex + 1; 
	if (2* nodeIndex+ 2 < length && stoi(array[2* nodeIndex+2]) > 
		stoi(array[minor])) minor = 2*nodeIndex + 2;
	while (nodeIndex!= minor){
		swapStr(regions,nodeIndex,minor);
		swapInt(registers,nodeIndex,minor);
		makeHeap(regions, registers, length, minor);
	}
}

void makeRegisters::heapify(string array[],int arrayInt[], int N, int i)
{
  // Iniciar con el dato mayor como raiz
  int largest = i;
  
	// hijo izquierdo = 2*i + 1
  int l = 2 * i + 1;
	
  // hijo derecho = 2*i + 2
  int r = 2 * i + 2;
 
  // Si el hijo izquierdo es mayor que la raiz
  if (l < N && stoi(array[l]) > stoi(array[largest]))
    largest = l;
 
  // Si el hijo derecho es mayor que la raiz
  if (r < N && stoi(array[r]) > stoi(array[largest]))
    largest = r;
	
  // Si el mayor no es la raiz
  if (largest != i) {
		string temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
 		int temp2 = arrayInt[i];
		arrayInt[i] = arrayInt[largest];
		arrayInt[largest] = temp2;
  	// Hacer heap del sub-árbol 
  	heapify(array,arrayInt, N, largest);
  }
}


void makeRegisters::heapSort(string array[],int arrayInt[],int N){
	// Codigo basado en : https://www.geeksforgeeks.org/heap-sort/
	// Hacer heapSort
	// Comprobar heap
	// PrintFormat(regions, registers, 16);
	for (int i = N / 2 - 1; i >= 0; i--)
    heapify(array,arrayInt, N, i);
    // Extraer uno por uno los valores del heap
    for (int i = N-1; i > 0; i--) {
    	// Mover la raiz actual al final
      //swapStr(array, 0,i);
			//swapInt(arrayInt,0,i);
 			string temp = array[0];
			array[0] = array[i];
			array[i] = temp;
			int temp2 = arrayInt[0];
			arrayInt[0] = arrayInt[i];
			arrayInt[i] = temp2;
      // LLamar a max heapify en el heap reducido
      //heapify(arr, i, 0);
			heapify(array,arrayInt,i,0);
    }
}