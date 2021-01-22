//Author: Noble LeDuc
//Data  : 9/13/2020
//table.cpp implements some of the functions from table.h
#include "table.h"
//constructor for table
Table::Table(){
}
//constructor for table with parameters
Table::Table(const string& tName, int seats, const string& sName){
    this->tableID= new std::string(tName);
    numSeats=seats;
    this->serverName=new std::string(sName);

}
//destructor for table
Table::~Table(){
    delete tableID;
    delete serverName;
}
//function seat a part, parameter is a pointer to the party being seated
void Table:: seatParty(const Party* newParty){
    if(newParty!=nullptr){
        party=newParty;
    }
    else{
        party=nullptr;
    }

}
