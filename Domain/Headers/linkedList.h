#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include "region.h"

class LinkedList{
  Node* first;
  public:
    Node* getFirst(); //Get del primer elemento de la lista
    LinkedList(); // COnstructor
    ~LinkedList(); //Destructor 
    int getSize();
    //Agrega un nodo como primero de la lista
    void add(Region* region);
    //Suma 1 a la region correspondiente
    void sum(Node* node);
    //Ordena la lista de menor a mayor
    void sort();
    //swap no implementado
    Node* swap(Node* ptr1, Node* ptr2);
    //Comprueba si existe un nodo
    Node* exists(std::string code);
};
#endif





