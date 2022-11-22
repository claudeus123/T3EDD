#include "Headers/system.h"
#include "Headers/node.h"
#include "Headers/linkedList.h"
#include "Headers/region.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

System::System(LinkedList list){
        this->list = list;
}
System::~System(){}
void System::readFile(std::string fileName){
        std::ifstream myFileStream(fileName);
        std::string code;
        std::string line;
        
        getline(myFileStream,line);
        while(getline(myFileStream,line)){
                std::stringstream ss(line);
                getline(ss,code,';');

                Node* node = list.exists(code);
                //std::cout << node << std::endl;
                if (node != nullptr){
                        list.sum(node);
                } else {
                        Region* region = new Region(code);
                        list.add(region);
						list.sum(list.getFirst());
                
                }
                //std::cout << line << std::endl;
        }       
        myFileStream.close();
}

void System::print(){
    list.sort();        
    Node* current = list.getFirst();
    while (current != nullptr){
        std::cout << current->getRegion()->getCode() << ": " << current->getRegion()->getSize() << " registros" << std::endl;
        current = current->getNext();
    }
}

void System::deleteList(){
	Node* current = list.getFirst();
	Node* aux;
	while (current != nullptr){
		aux = current;
		current = current->getNext();
		delete aux->getRegion();
		delete aux;
	}
}

void System::printHeapSort(){
	//crear heap (array)
	int size  = list.getSize();
	int registers[size];
	std::string regions[size];
	int counter = 0;
	
	Node* current = list.getFirst();
	while (current!=nullptr){
		registers[counter] = current->getRegion()->getSize();
		regions[counter] = current->getRegion()->getCode();
		counter++;
		current = current->getNext();
	}
	
	heapSort(regions,registers,size);

	for (int i = 0; i < size; i ++){
		std::cout << regions[i] << ": " << registers[i] << std::endl;
	}
}


void System::heapify(std::string array[],int arrayInt[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && stoi(array[l]) > stoi(array[largest]))
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && stoi(array[r]) > stoi(array[largest]))
        largest = r;
 
    // If largest is not root
    if (largest != i) {
		std::string temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		
 		int temp2 = arrayInt[i];
		arrayInt[i] = arrayInt[largest];
		arrayInt[largest] = temp2;
        // Recursively heapify the affected
        // sub-tree
        heapify(array,arrayInt, N, largest);
    }
}


void System::heapSort(std::string array[],int arrayInt[],int N){
	// Codigo basado en : https://www.geeksforgeeks.org/heap-sort/
	//hacer heapSort
	// comprobar heap
	//rintFormat(regions, registers, 16);
	for (int i = N / 2 - 1; i >= 0; i--)
        heapify(array,arrayInt, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N-1; i > 0; i--) {
 
        // Move current root to end
        //swapStr(array, 0,i);
		//swapInt(arrayInt,0,i);
 		std::string temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		int temp2 = arrayInt[0];
		arrayInt[0] = arrayInt[i];
		arrayInt[i] = temp2;
        // call max heapify on the reduced heap
        //heapify(arr, i, 0);
		heapify(array,arrayInt,i,0);
    }
	
}