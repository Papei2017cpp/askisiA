#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class flight{
	
private://same as main
	
	int fcode ,cost,seats,rseats;
	//  fcode = Flight code cost = ticket cost
	//  seats = all seats , rseats = reserved seats
	struct time{
		int hours;
		int minutes;
	}start,reach;
	char from[2],to[2];
public:
	int add(){
		
		return 0;
		}//function to add new flights
		
		
	flight(int a, char b[],char c[],int d, int e,int dd,int ee, int f,int g, int h){
	//so many things up but dont mind it works lol
	fcode=a;
	for (int i=0;i<=2;i++){//repeat to load all word
		from[i]=b[i];
		to[i]=c[i];
	}
	start.hours=d;
	start.minutes=e;
	reach.hours=dd;
	reach.minutes=ee;
	cost=f;
	seats=g;
	rseats=h;
	fstream base;//seting a var in/output file basi.txt
		base.open("basi.txt",fstream::app);
		cout<<"Opening databese..."<<endl;
		//somewhere here should be a search for the FROM airport to sort the database
		base <<fcode<<"|";
		for (int i=0;i<2;i++){//to pase the full word
		base << from[i];
		}
		base <<"|";
		
		for (int i=0;i<2;i++){//to pase the full word
		base << to[i];
		}
		base << "|"<<start.hours<<":"<<start.minutes<<"|"<<reach.hours<<":"<<reach.minutes<<","<<endl;
		cout<<"New flight added";
	}//constractor for select=='A' (add flights)

};

int main(){

int fcode ,cost,seats,rseats;
//  fcode = Flight code cost = ticket cost
//  seats = all seats , rseats = reserved seats
struct time{
	int hours;
	int minutes;
}start,reach;
//for the time to separate minutes from hours and do math with them
char from[2],to[2];
char select;//selection manager
cout<<"Do you want to add(A) remove(B) flights, make (C) or cancel(D) a reservation?";
cin>>select;
if (select=='A'){
	//puting stuff in var
    cout<<"Give the following (required)"<<endl;
    cout<<"Flight Code : ";
    cin>>fcode;
    cout<<"From : ";
    cin>>from;	
    cout<<"To : ";
    cin>>to;
    cout<<"Start time (Hours minutes separated with space) : "; // with space , i cant figure out another method atm '-.-
    cin>>start.hours>>start.minutes;
    cout<<"Reach time (Hours minutes separated with space) : ";
    cin>>reach.hours>>reach.minutes;//need to put everywhere , check for values lengh ;p 
    //we have to put more variables and fill the 0 below 
    cout<<"Ticket Cost : ";
    cin>>cost;	
    cout<<"All seats  : ";
    cin>>seats;
    cout<<"Reserved seats : ";
    cin>>rseats;	
    flight(fcode,from,to,start.hours,start.minutes,reach.hours,reach.minutes,cost,seats,rseats);
}
return 0;
}
