#include <iostream>
#include <string.h>
using namespace std;
struct people{
	//input -> onoma input -> epitheto input -> arithmos diavatiriou input -> ethnikotita input -> diefthinsi input -> thlefono
	
	string name,last,street,passport,number,origin;
	int flightcode,wait;//prepei na ftoia3w to w8 system , einai poli berdemeno lol evala to wait sto allo pragma
	
	people *nextwait;
	};
class line{
	public:
		line();
		int printcode(people *location);
		people *search(string name, string last);
		void add(string name,string last,int code);
	private:
		people *search(string name, string last,people *location);
		void add(string name,string last,int code, people *location);
		people *start;
	};
line::line(){
	start=NULL;
	}

void line::add(string name,string last,int code, people *location){//first if noone exists ;p
	if ((name!=location->name)&&(last!=location->last)){
		location->nextwait=new people;

		location->nextwait->flightcode=code;//gotta check if exists !!!
		cin.ignore();
		location->nextwait->name=name;
		location->nextwait->last=last;
		cout<<"STREET ADRESS:";
		cin>>location->nextwait->street;
		cin.ignore();
		cout<<"PASSPORT ID:";
		cin>>location->nextwait->passport;
		cin.ignore();
		cout<<"TELEPHONE :";
		cin>>location->nextwait->number;
		cin.ignore();
		//DONT FORGET THE WAIT THING		
		cout<<"ORIGIN:";
		cin>>location->nextwait->origin;
		}
	else{
		add(name,last,code,location->nextwait);
		}
	}
void line::add(string name,string last,int code){//if somebody exists

		if (start==NULL){//ean den uparxei kaneis stin oura
		start=new people;
		start->flightcode=code;//gotta check if exists !!!
		cin.ignore();
		start->name=name;
		start->last=last;
		cout<<"STREET ADRESS:";
		cin>>start->street;
		cin.ignore();
		cout<<"PASSPORT ID:";
		cin>>start->passport;
		cin.ignore();
		cout<<"TELEPHONE :";
		cin>>start->number;
		cin.ignore();
		cout<<"ORIGIN:";
		cin>>start->origin;

		}
	else{
		add(name,last,code,start);
		}
	}

people *line::search(string name, string last,people *location){
	if (location!=NULL){
		if ((name==location->name)&&(name==location->last)){
			
			return location;
			}
		else{
			search(name,last,location->nextwait);
		}
		}}

people *line::search(string name,string last){
	return search(name,last,start);//stelnei sto search
	}
int line::printcode(people *location){
	return location->flightcode;
	}
