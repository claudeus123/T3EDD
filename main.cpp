#include "Domain/Headers/makeRegisters.h"
#include "Domain/Headers/system.h"
#include "Domain/Headers/linkedList.h"
#include "Domain/Headers/region.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main() {
	int rf;
	cout << "1) ArrayList + BubbleSort " << endl;
	cout << "2) ArrayList + HeapSort " << endl;
	cout << "3) LinkedList + BubbleSort " << endl;
	cout << "4) LinkedList + HeapSort " << endl;
	cout << "Ingrese un numero: " <<endl;
	cin >> rf;
        int regionsSize = 16;
	string pathToFile = "/home/data/Microdato_Censo2017-Personas.csv";
        
	if (rf == 1){
		makeRegisters rf1 = makeRegisters();
        	rf1.readFile(pathToFile);
		string reference[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"}; 
		rf1.sort(reference, rf1.getRegions(), rf1.getRegisters(), 16);
	        rf1.printFormat(rf1.getRegions(),rf1.getRegisters(),regionsSize);	
	} else if (rf == 2){
		makeRegisters rf2 = makeRegisters();
		rf2.readFile(pathToFile);
		rf2.heapSort(rf2.getRegions(),rf2.getRegisters(),16);
		rf2.printFormat(rf2.getRegions(), rf2.getRegisters(),16);
	} else if (rf == 3){
		LinkedList ll;
		System rf3 = System(ll);
		rf3.readFile(pathToFile);
		rf3.print();
		rf3.deleteList();
	} else if (rf == 4){
		LinkedList ll;
		System rf4 = System(ll);
		rf4.readFile(pathToFile);
		rf4.printHeapSort();
		rf4.deleteList();
	} else {
		cout << "Codigo no valido" << endl;
	}
	
}
