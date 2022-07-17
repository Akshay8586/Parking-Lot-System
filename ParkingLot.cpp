#include "ParkingLot.h"

ParkingLot* ParkingLot::parkingLotInstance;

//Create new parking lot -- only one parking lot should be craeted.
ParkingLot::ParkingLot(int numSlots){
  if(parkingLotInstance == NULL){
    parkingLotInstance = this;
  }
  else{
    cout<<"Parking lot has been already created!"<<endl;
    return;
  }
  init_ParkingLot(numSlots);
  cout<<"Created parking of "<<numSlots<<" slots"<<endl;
}

//Initialize parking lot to default values
void ParkingLot::init_ParkingLot(int numSlots){
  slots = vector<Slot>(numSlots,Slot());
}

//Park vehicle in nearest empty slot
void ParkingLot::park(string carRegNum, int driverAge){
  int i; //i+1 represent slot number
  for(i=0;i<slots.size();i++){
    if(slots[i].isEmptySlot()){
      slots[i].fillSlot();
      slots[i].setCarRegNum(carRegNum);
      slots[i].setDriverAge(driverAge);
      break;
    }
  }
  if(i==slots.size()){ //parking lot is already full
    cout<<"No parking slot is empty !"<<endl;
  }
  cout<<"Car with vehicle registration number "<<carRegNum<<" has been parked at slot number "<<i+1<<endl;
}

//Vacate the given parking slot
void ParkingLot::leave(int numSlot){
  if(!slots[numSlot-1].isEmptySlot()){
    cout<<"Slot number "<<numSlot<<" vacated, the car with vehicle registration number "<<slots[numSlot-1].getCarRegNum()<<" left the space, the driver of the car was of age "<<slots[numSlot-1].getDriverAge()<<endl;
    slots[numSlot-1].vacantSlot();
  }
  else{
    cout<<"Slot number "<<numSlot<<" is already empty!"<<endl;
  }
}

//Get all slots acquired by drivers of given age
vector<int> ParkingLot::getSlotsbyAge(int driverAge){
  vector<int> slotNums;
  for(int i=0;i<slots.size();i++){
    if(slots[i].getDriverAge() == driverAge){
      slotNums.push_back(i+1);
    }
  }
  return slotNums;
}

//Get all car registration numbers whose drivers are of given age
vector<string> ParkingLot::getCarRegNumbyAge(int driverAge){
  vector<string> carRegNums;
  for(int i=0;i<slots.size();i++){
    if(slots[i].getDriverAge() == driverAge){
      carRegNums.push_back(slots[i].getCarRegNum());
    }
  }
  return carRegNums;
}

//Get the slot number of given car registration number
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