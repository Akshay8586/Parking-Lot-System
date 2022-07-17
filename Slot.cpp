#include "Slot.h"

//Initialize slot by default values
Slot::Slot(){
  isEmpty = true;
  carRegNum = "";
  driverAge = 0;
}

Slot::~Slot(){ }

//Park car in slot
void Slot::fillSlot(){
  if(isEmpty){
    isEmpty = false;
  }
}

//Leave car from slot
void Slot::vacantSlot(){
  if(!isEmpty){
    this->isEmpty = true;
    this->carRegNum = "";
    this->driverAge = 0;
  }
}

//Check if slot is empty
bool Slot::isEmptySlot(){
  return isEmpty;
}

//Set car registration number of car parked in given slot
void Slot::setCarRegNum(string carRegNum){
  this->carRegNum = carRegNum;
}

//Get car registration number of car parked in given slot
string Slot::getCarRegNum(){
  return carRegNum;
}

//Set driver age of car parked in given slot
void Slot::setDriverAge(int driverAge){
  this->driverAge = driverAge;
}

//Get driver age of car parked in given slot
int Slot::getDriverAge(){
  return driverAge;
}