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
  fstream f("input.txt", std::ios::in); //read input file
  string line, cell;
  vector<string> row; //store each row of input file
  int i = 1; //to check first command
  ParkingLot* parkinglot; //declare instance of Parking Lot
  
  if(f){ //if input file opens successfully...
    while (getline(f, line)){
      row.clear();
      stringstream str(line);

      //read each command line by line
      while (getline(str, cell, ' '))
        row.push_back(cell);
      
      //if first command is not for creating parking lot
      if(i==1 && row[0]!=Create){
        cout<<"Not a valid Input!"<<" ";
        return 0;
      }
      i++; //increase command count

      //create new parking lot
      if(row[0] == Create){
        int sz = row.size();
        if(sz==2){
          try{
            parkinglot = new ParkingLot(stoi(row[1]));
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
      }

      //park new car
      else if(row[0] == Park){
        int sz = row.size();
        if(sz==4){
          try{
            parkinglot->park(row[1],stoi(row[3]));
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
      }

      //car leave slot
      else if(row[0] == Leave){
        int sz = row.size();
        if(sz==2){
          try{
            parkinglot->leave(stoi(row[1]));
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
      }

      //Get all slots acquired by drivers of given age
      else if(row[0] == SlotsByAge){
        vector<int> slotsByAge;
        int sz = row.size();
        if(sz==2){
          try{
            slotsByAge = parkinglot->getSlotsbyAge(stoi(row[1]));
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
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

      //Get the slot number of given car registration number
      else if(row[0] == SlotByRegNo){
        int slot;
        int sz = row.size();
        if(sz==2){
          try{
            slot = parkinglot->getSlotbyCarRegNum(row[1]);
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
        if(slot != -1){
          cout<<slot<<endl;
        }
        else{
          cout<<"No slot acquired by any car with registration number "<<row[1]<<endl;
        }
      }

      //Get all car registration numbers whose drivers are of given age
      else if(row[0] == RegNumsByAge){
        vector<string> RegNums;
        int sz = row.size();
        if(sz==2){
          try{
            RegNums = parkinglot->getCarRegNumbyAge(stoi(row[1]));
          }
          catch(exception &err){
            cout<<"Not a valid command!"<<endl;
          }
        }
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

      //Invalid command
      else{
        cout<<"Not a valid command!"<<endl;
      }
    }
 }
 else{//input file not able to open 
    cout<<"Not able to open input file!"<<endl;
  }
  f.close();
  return 0;
}