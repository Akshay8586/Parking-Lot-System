#include "ParkingLot.h"

ParkingLot* ParkingLot::parkingLotInstance;
ParkingLot::ParkingLot(int numSlots){
  if(parkingLotInstance == NULL){
    parkingLotInstance = this;
  }
  else{
    return;
  }
  init_ParkingLot(numSlots);
}

void ParkingLot::init_ParkingLot(int numSlots){
  isEmpty = true;
  isFull = false;
  slots = vector<Slot>(numSlots,Slot());
}

void ParkingLot::park(string carRegNum, int driverAge){
  for(int i=0;i<slots.size();i++){
    if(slots[i].isEmptySlot()){
      slots[i].fillSlot();
      slots[i].setCarRegNum(carRegNum);
      slots[i].setDriverAge(driverAge);
    }
  }
}

void ParkingLot::leave(int numSlot){
  if(!slots[numSlot].isEmptySlot()){
    slots[numSlot].vacantSlot(numSlot);
  }
}

vector<int> ParkingLot::getSlotsbyAge(int driverAge){
  vector<int> slotNums;
  for(int i=0;i<slots.size();i++){
    if(slots[i].getDriverAge() == driverAge){
      slotNums.push_back(i+1);
    }
  }
  return slotNums;
}

vector<string> ParkingLot::getCarRegNumbyAge(int driverAge){
  vector<string> carRegNums;
  for(int i=0;i<slots.size();i++){
    if(slots[i].getDriverAge() == driverAge){
      carRegNums.push_back(slots[i].getCarRegNum());
    }
  }
  return carRegNums;
}

int ParkingLot::getSlotbyCarRegNum(string carRegNum){
  int slotNum=-1;
  for(int i=0;i<slots.size();i++){
    if(slots[i].getCarRegNum() == carRegNum){
      slotNum = i+1;
      break;
    }
  }
  return slotNum;
}