#include <iostream>
#include <string.h>
using namespace std;
struct people{
	//input -> onoma input -> epitheto input -> arithmos diavatiriou input -> ethnikotita input -> diefthinsi input -> thlefono
	
	string name,last,street;
	int flightcode,passport,number,wait;
	char origin[3];
	people *nextwait;
	};
class line{
	public:
	line();
	void add(string name,people *location);
	private:
	void add();
	people *start;
	};
line::line(){
	start=NULL;
	}
void line::add(){//first if noone exists ;p
	if (start==NULL){
		cout<<"FLIGHT CODE:";
		cin>>start->flightcode;//gotta check if exists !!!
		cout<<"FIRST NAME:";
		cin>>start->name;
		cout<<"LAST NAME:";
		cin>>start->last;
		cout<<"STREET ADRESS:";
		cin>>start->street;
		cout<<"PASSPORT ID:";
		cin>>start->passport;
		cout<<"TELEPHONE :";
		cin>>start->number;
		//DONT FORGET THE WAIT THING		
		cout<<"ORIGIN:";
		cin>>start->origin;
		start->nextwait=NULL;
		}
	else{
		string namee;
		cin>>namee;
		add(namee,start);
		}
	}
void line::add(string name, people *location){//if somebody exists
	//anadromiki kinisi opou tha kanoume sinexeia ston epomeno 
	}
