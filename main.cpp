#include "Domain/Headers/makeRegisters.h"
#include "Domain/Headers/system.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main() {
        int regionsSize = 16;
		string pathToFile = "el.csv";
        makeRegisters system = makeRegisters();
        system.readFile(pathToFile);
		string reference[] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16"}; 
		system.sort(reference, system.getRegions(), system.getRegisters(), 16);
        system.printFormat(system.getRegions(),system.getRegisters(),regionsSize);

	
		system.heapSort(system.getRegions(),system.getRegisters(),16);
		system.printFormat(system.getRegions(), system.getRegisters(),16);

		LinkedList ll;
		System system2 = System(ll);
		system2.readFile(pathToFile);
		system2.print();

		system2.printHeapSort();
		system2.deleteList();
}
