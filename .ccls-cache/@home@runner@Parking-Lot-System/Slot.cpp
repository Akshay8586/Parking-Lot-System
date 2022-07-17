#include "Slot.h"

Slot::Slot(){
  isEmpty = true;
  carRegNum = "";
  driverAge = 0;
}

void Slot::fillSlot(){
  if(isEmpty){
    isEmpty = false;
  }
}

void Slot::vacantSlot(int numSlot){
  if(!isEmpty){
    this->isEmpty = true;
    this->carRegNum = "";
    this->driverAge = 0;
  }
}

bool Slot::isEmptySlot(){
  return isEmpty;
}

void Slot::setCarRegNum(string carRegNum){
  this->carRegNum = carRegNum;
}

string Slot::getCarRegNum(){
  return carRegNum;
}

void Slot::setDriverAge(int driverAge){
  this->driverAge = driverAge;
}

int Slot::getDriverAge(){
  return driverAge;
}