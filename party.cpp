//Author: Noble LeDuc
//Data  : 9/13/2020
//implements the functions from party.cpp
#include "party.h"
#include <iostream>
#include <string>
using namespace std;
//constructor for party
Party::Party(){
}
//constructer for party containing parameter
Party::Party(const string& rName, int nDiners, int tRequired){
    this->reservationName = new std::string(rName);
    numDiners=nDiners;
    timeRequired=tRequired;

}
//destructor for party
Party::~Party(){
    delete reservationName;
}
