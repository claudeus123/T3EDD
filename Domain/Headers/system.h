#ifndef SYSTEM_H
#define SYSTEM_H
#include "linkedList.h"
#include <iostream>
using namespace std;

class System {
  private:
    LinkedList list;
  public:
    System(LinkedList list); //CONSTRUCTOR
    ~System(); //DESTRUCTOR
    void readFile(string fileName); //Dado el path al dataset, lo procesa e ingresa los resultados a la lista
    void print();//Imprime la lista, antes ordenandola por los códigos de regiones de menor a mayor
    void deleteList();//Elimina todos los nodos, regiones de la lista, a fin de evitar leaks de memoria
    void printHeapSort();
		void heapify(string array[],int arrayInt[], int N, int i);
		void heapSort(string array[],int arrayInt[],int N);
};
#endif

