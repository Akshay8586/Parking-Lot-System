#include <bits/stdc++.h>
using namespace std;

class Slot{
 bool isEmpty;
 string carRegNum;
 int driverAge;

 public:
   Slot();
   ~Slot();
   void fillSlot();
   void vacantSlot();
   bool isEmptySlot();
   void setCarRegNum(string carRegNum);
   string getCarRegNum();
   void setDriverAge(int driverAge);
   int getDriverAge();
};