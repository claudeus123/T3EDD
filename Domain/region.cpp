#include "Headers/region.h"
#include <iostream>
using namespace std;

Region::Region(){
  code = "defecto";
  size = 0;
}
Region::Region(string code) {
  this->code = code;
  size = 0;
}
string Region::getCode(){ 
	return code; 
}
int Region::getSize(){ 
	return size; 
}
void Region::setSize(int size){ 
	this->size = size; 
}
void Region::setCode(string code){ 
	this->code = code; 
}
Region::~Region(){}
