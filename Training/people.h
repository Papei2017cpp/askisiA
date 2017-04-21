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
		void remove(string name , string last , int code);//to be done
		int printcode(people *location);
		people *search(string name, string last,int key);
		void add(string name,string last,int code);
	private:
		people *search(string name, string last,int key,people *location);
		void add(string name,string last,int code, people *location);
		people *start;
		people *previous(string name,string last,int key,people *location);//tha dinei ton akrivos proigoumeno arithmo
		void remove(people *location);//tha allazei to nextwait me to epomeno apo to people p exoume 
	};
line::line(){
	start=NULL;
	}

void line::add(string name,string last,int code, people *location){//first if noone exists ;p
	if (location->nextwait==NULL){
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
		location->nextwait->nextwait=NULL;
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

people *line::search(string name, string last,int key,people *location){
	if (location!=NULL){
		if ((name==location->name)&&(last==location->last)&&(key==location->flightcode)){
			
			return location;
			}
		else{
			search(name,last,key,location->nextwait);
		}
	}else{
	return NULL;	
	}
}
people *line::previous(string name, string last,int key,people *location){
	if ((location!=0)&&(location->nextwait!=0)){
		if ((name==location->nextwait->name)&&(last==location->nextwait->last)){
			
			return location;
			}
		else{
			search(name,last,key,location->nextwait);
		}
	}else{
		return NULL;
		}
}
people *line::search(string name,string last,int key){
	return search(name,last,key,start);//stelnei sto search
	}
int line::printcode(people *location){
	return location->flightcode;
	}

