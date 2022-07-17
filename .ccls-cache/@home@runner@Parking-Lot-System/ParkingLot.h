#include <bits/stdc++.h>
#include "Slot.h"
using namespace std;

class ParkingLot{
 public:
  ParkingLot() = delete;
  ParkingLot(int numSlots);
  ~ParkingLot();
   bool isFullParkingLot();
   bool isEmptyParkingLot();
   void park(string carRegNum, int driverAge);
   void leave(int numSlot);
   vector<int> getSlotsbyAge(int driverAge);
   vector<string> getCarRegNumbyAge(int driverAge);
   int getSlotbyCarRegNum(string carRegNum);

 private:
   void init_ParkingLot(int numSlots);
   static ParkingLot* parkingLotInstance;
   bool isEmpty;
   bool isFull;
   vector<Slot> slots;
};

