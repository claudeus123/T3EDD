#ifndef NODE_H
#define NODE_H
#include "region.h"

class Node{
  private:
    Node* next;
    Region* region;
  public:
    Node(); //Default constructor
    Node(Region* region); // COnstructor
    ~Node(); // Destructor
    Region* getRegion(); //GET de la region del nodo
    Node* getNext(); //GET del link
    void setNext(Node* next); //SET del link
};
#endif

