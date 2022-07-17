#include <iostream>
#include <fstream>
#include <sstream>
#include "ParkingLot.h"
using namespace std;

#define Create "Create_parking_lot"
#define Park "Park"
#define SlotsByAge "Slot_numbers_for_driver_of_age"
#define SlotByRegNo "Slot_number_for_car_with_number"
#define Leave "Leave"
#define RegNumsByAge "Vehicle_registration_number_for_driver_of_age"

int main() {
  fstream f("input.txt", std::ios::in);
  string line, cell;
  vector<string> row;
  int i = 1;
  ParkingLot* parkinglot;
  if(f){
    while (getline(f, line)){
      row.clear();
      stringstream str(line);

      while (getline(str, cell, ' '))
          row.push_back(cell);
      if(i==1 && row[0]!=Create){
        cout<<"Not a valid Input!"<<" ";
        return 0;
      }
      i++;
      if(row[0] == Create){
        int sz = row.size();
        parkinglot = new ParkingLot(stoi(row[1]));
      }
  
      else if(row[0] == Park){
        parkinglot->park(row[1],stoi(row[3]));
      }
  
      else if(row[0] == Leave){
        parkinglot->leave(stoi(row[1]));
      }
  
      else if(row[0] == SlotsByAge){
        vector<int> slotsByAge;
        slotsByAge = parkinglot->getSlotsbyAge(stoi(row[1]));
        if(slotsByAge.size()>0){
          for(int i=0;i<slotsByAge.size();i++){
            cout<<slotsByAge[i];
            if(i < slotsByAge.size()-1){
              cout<<",";
            }
          }
          cout<<endl;
        }
        else{
          cout<<"No slot acquired by any driver of age "<<stoi(row[1])<<endl;
        }
      }
  
      else if(row[0] == SlotByRegNo){
        int slot;
        slot = parkinglot->getSlotbyCarRegNum(row[1]);
        if(slot != -1){
          cout<<slot<<endl;
        }
        else{
          cout<<"No slot acquired by any car with registration number "<<row[1]<<endl;
        }
      }
  
      else if(row[0] == RegNumsByAge){
        vector<string> RegNums;
        RegNums = parkinglot->getCarRegNumbyAge(stoi(row[1]));
        if(RegNums.size()>0){
           for(int i=0;i<RegNums.size();i++){
            cout<<RegNums[i];
            if(i < RegNums.size()-1){
              cout<<",";
            }
          }
          cout<<endl;
        }
        else{
          cout<<"No car parked by any driver of age "<<stoi(row[1])<<endl;
        }
      }
    }
 }
 else{
    cout<<"Not able to open input file!"<<endl;
  }
  f.close();
  return 0;
}