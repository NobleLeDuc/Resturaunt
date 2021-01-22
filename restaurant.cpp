//Author: Noble LeDuc
//Data  : 9/13/2020
//runs a resturaunt simulation using doublylinked lists
#include <iostream>
#include "restaurant.h"
using namespace std;

//Funtion to read in input
void Restaurant:: getInput(){
    //Declare variable for input
    bool input=true;
    string type;
    string tableID;
    int numSeats=0;
    string reservationName;
    int numDiners=0;
    int timeRequired=0;
    string serverName;
    //read in input
    while(input){
        cin>>type;
        if(type=="table"){
            cin>>tableID>>numSeats>>serverName;
            Table *ptr = new Table(tableID,numSeats,serverName);
            available.append(ptr);
        }
        else if(type=="party"){
            cin>>numDiners>>reservationName>>timeRequired;
            Party *ptr= new Party(reservationName,numDiners,timeRequired);
            waiting.append(ptr);
        }
        else if(type=="end"){
            input=false;
            return;
        }
        else{
            cout<<type<< "error\n";
            input=false;
            return;
        }
    }
}
//runs the simulation from the given input
void Restaurant:: serveParties(){
    Table *myTable;
    Table *occTable;
    bool open=true;
    bool serverFound=false;
    while(open){
        if(!occupied.empty()){
            occTable=occupied.first();
            while(occTable!=nullptr){
                occTable->decrementTimer();
                if(occTable->getTimer()==0){
                    cout<<*occTable->getParty()->getReservationName()
		        <<" finished at "<<*occTable->getTableID()<<endl;
		    occTable->clearTable();
		    available.append(occTable);
		    occTable=occupied.remove();

                }
                else{
                    occTable=occupied.next();
                }
            }
        }
        Party *myParty;
        if((!waiting.empty())||(!available.empty())){
            myParty=waiting.first();
            myTable=available.first();
            while(myParty!=nullptr){
                //iterate through available tables
                while((myTable!=nullptr)&&(myParty!=nullptr)){
                //if table with enough seats is found (take the first table),
                    if(myParty->getNumDiners()<=myTable->getNumSeats()){
		         occupied.append(myTable);
		        //partySeated=true;
                        cout<<*myParty->getReservationName()<<" seated at "
                            <<*myTable->getTableID()<<endl;
                        //set table->party
                        myTable->seatParty(myParty);
                        //set table->timer
                        myTable->setTimer(myParty->getTimeRequired());
                        //add # of diners to server total
                        if(servers.size()>0){
			    serverFound=false;
                            for(auto it = servers.cbegin();
				it != servers.cend(); ++it){
                                if(it->first==*myTable->getServerName()){
                                    servers.at(*myTable->getServerName())
				    +=myParty->getNumDiners();
				    serverFound=true;
                                }
			    }
                            if(serverFound==false){
                                    servers.insert({*myTable->getServerName(),
				    myParty->getNumDiners()});
                            }
                        }
                        else{
                            servers.insert({*myTable->getServerName(),
			    myParty->getNumDiners()});
                        }
                        //move table to occupied list
		        myParty=waiting.remove();
		        myTable=available.remove();
                        myTable=available.first();
                    }
		    else{
		        myTable=available.next();
		    }
                    //move to the next available table and check num seats
                }
	        myParty=waiting.next();
	        myTable=available.first();
            }
        }
        if((waiting.empty()) && (occupied.empty())){
        //print # of diners served by each server
        //close restaurant (end of while loop and program)
            for(auto it = servers.cbegin(); it != servers.cend(); ++it){
                 cout<< it->first << " served " << it->second<<endl;
            }
            open=false;
        }
    }
}




int main()
{
    Restaurant myRest;
    myRest.getInput();
    myRest.serveParties();

    return 0;
}
