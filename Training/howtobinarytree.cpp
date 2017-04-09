#include <iostream>
#include <fstream>
#include <string.h>
#include "people.h"
using namespace std;

struct node
{
	
	int key_value;
	node *left;
	node *right;
	//dedomena ptisis
	int fcode ,cost,seats,rseats;
	//  fcode = Flight code cost = ticket cost
	//  seats = all seats , rseats = reserved seats
	struct time{
		int hours;
		int minutes;
	}start,reach;
	char from[3],to[3];

};
struct oura{//edw telika tha benei i oura xD
	string waitingline[3];
	oura *next;
};
class btree
{
    public:
        btree();
        
        void insert(int key);
        node *search(int key);
        void destroy_tree(int key);
		int freeseats(node *location){
			return location->seats-location->rseats;//looking for free seats
			}
		void waitmore(int code,string name,string last){//stelnei ta pada sto struct oura
			
			};
    private:
        void destroy_tree(node *leaf);
        void insert(int key, node *leaf);
        node *search(int key, node *leaf);
        node *root;
};

btree::btree()
{
	root=NULL;
}
void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {//theoritika diagrafw olo to dendro apo tin thesi mnimis mexri to filo THEORITIKA
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}
int o=0;
void btree::insert(int key, node *leaf)
{
  if(key< leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left);
    else
    {
	  	  int cost,seats,rseats;
	  //  cost = ticket cost
	  //  seats = all seats , rseats = reserved seats
	  struct time{
		int hours;
		int minutes;
	  }start,reach;

	  std::cout<<"COST:";
	  std::cin>>cost;
	  std::cout<<"SEATS:";      
	  std::cin>>seats;
	  std::cout<<"RESERVED SEATS:";
	  std::cin>>rseats;
	  std::cout<<"START HOUR:";
	  std::cin>>start.hours>>start.minutes;
	  std::cout<<"REACH HOUR:";
	  std::cin>>reach.hours>>reach.minutes;
	  leaf->left=new node;
	  std::cout<<"FROM:";
	  for (int i=0;i!=3;i++)
	  {
	  std::cin>>leaf->left->from[i];
	  }
	  std::cout<<"TO:";
	  for (int i=0;i!=3;i++)
	  {
	  std::cin>>leaf->left->to[i];
	  }
      leaf->left->key_value=key;
      leaf->left->cost=cost;
      leaf->left->seats=seats;
      leaf->left->rseats=rseats;
      leaf->left->start.hours=start.hours;
      leaf->left->start.minutes=start.minutes;
      leaf->left->reach.hours=reach.hours;
      leaf->left->reach.minutes=reach.minutes;
      //end of import 
      leaf->left->key_value=key;

      leaf->left->left=NULL;    //Sets the left child of the child node to null
      leaf->left->right=NULL;   //Sets the right child of the child node to null
	  std::cout<<"New flightcode added left\n";
		o=0;
    }  
    
  }
  else if(key>=leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right);
    else
    {	
	  int cost,seats,rseats;
	  //  cost = ticket cost
	  //  seats = all seats , rseats = reserved seats
	  struct time{
		int hours;
		int minutes;
	  }start,reach;
	  std::cout<<"COST:";
	  std::cin>>cost;
	  std::cout<<"SEATS:";      
	  std::cin>>seats;
	  std::cout<<"RESERVED SEATS:";
	  std::cin>>rseats;
	  std::cout<<"START HOUR:";
	  std::cin>>start.hours>>start.minutes;
	  std::cout<<"REACH HOUR:";
	  std::cin>>reach.hours>>reach.minutes;
      leaf->right=new node;
	  std::cout<<"FROM:";
	  for (int i=0;i!=3;i++)//DUMB STUFF FOR DEBUGING
	  {
	  std::cin>>leaf->right->from[i];
	  }
	  
	  std::cout<<"TO:";
	  	  for (int i=0;i!=3;i++)
	  {
	  std::cin>>leaf->right->from[i];//SAME
	  }
      leaf->right->key_value=key;
      leaf->right->cost=cost;
      leaf->right->seats=seats;
      leaf->right->rseats=rseats;
      leaf->right->start.hours=start.hours;
      leaf->right->start.minutes=start.minutes;
      leaf->right->reach.hours=reach.hours;
      leaf->right->reach.minutes=reach.minutes;
      //end of import 
      leaf->right->left=NULL;  //Sets the left child of the child node to null
      leaf->right->right=NULL; //Sets the right child of the child node to null
	  std::cout<<"New flightcode added right\n";
		o=0;
    }
  }
  o=o+1;
  std::cout<<"Level "<<o<<endl;
}

node *btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key==leaf->key_value){
      cout<<"CODE "<<leaf->key_value<<"\nSEATS "<<leaf->seats<<"\nRESERVED SEATS "
	  <<leaf->rseats<<"\nDEPARTURE TIME "<<leaf->start.hours<<":"	 
	  <<leaf->start.minutes
		<<"\nARRIVAL TIME "<<leaf->reach.hours<<":"
	  <<leaf->reach.minutes<<"\nDEPARTURE AIRPORT ";
		for (int i=0;i!=3;i++){
		cout<<leaf->from[i];
		}
      cout<<"\nARRIVAL AIRPORT ";
		for (int i=0;i!=3;i++){
		cout<<leaf->to[i];
		}
	  cout<<endl;
      cout<<endl;
      return leaf;}
    if(key<leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return NULL;
}
void btree::insert(int key)
{
  if(root!=NULL)
    insert(key, root);
  else
  {
	
    root=new node;
    	  int cost,seats,rseats;
	  //  cost = ticket cost
	  //  seats = all seats , rseats = reserved seats
	  struct time{
		int hours;
		int minutes;
	  }start,reach;
	  std::cout<<"COST:";
	  std::cin>>cost;
	  std::cout<<"SEATS:";      
	  std::cin>>seats;
	  std::cout<<"RESERVED SEATS:";
	  std::cin>>rseats;
	  std::cout<<"START HOUR:";
	  std::cin>>start.hours>>start.minutes;
	  std::cout<<"REACH HOUR:";
	  std::cin>>reach.hours>>reach.minutes;
	  std::cout<<"FROM:";
	  for (int i=0;i!=3;i++)
	  {
	  std::cin>>root->from[i];
	  }
	  std::cout<<"TO:";
	  for (int i=0;i!=3;i++)
	  {
	  std::cin>>root->to[i];
	  }
      root->key_value=key;
      root->cost=cost;
      root->seats=seats;
      root->rseats=rseats;
      root->start.hours=start.hours;
      root->start.minutes=start.minutes;
      root->reach.hours=reach.hours;
      root->reach.minutes=reach.minutes;
      //end of import 
    root->key_value=key;
    root->left=NULL;//arxikopoihsh diefkrinisi kainou
    root->right=NULL;
          std::cout<<"ROOT added\n";
  }
}

node *btree::search(int key)
{
  return search(key, root);
}
void btree::destroy_tree(int key)
{
  destroy_tree(search(key));//theoritika vazw tin thesi mnimis pou thelw na diagrapsw
}










int main(){
	line t;
	btree e;
	char p;
cout<<"Do you want to add(A) remove(B) search(S) flights ,\n make (C) or cancel(D) a reservation?";
	//ADD WORKS , REMOVE HALF-WORkS SEARCH WORKS , MAKE WORKS , CANCEL TO DO , working on queue
	cin>>p;
	while (p!='N'){
	int a;
	if (p=='A'){
	std::cout<<"CODE:";
	cin>>a;
	e.insert(a);
	
	}
 	else if(p=='S'){
  	cin>>a;

 	e.search(a);
	}
	else if(p=='C'){
  	string b,g;
  	cout<<"Give NAME and SURNAME :";
  	cin>>b>>g;
 	t.add(b,g);
	//kai kala diadiasia twra 
	if(
	e.freeseats(e.search(t.printcode(t.search(b,g))))==0){
		//tha ekteli tin waitmore
		}//search dinei to location kai printcode kanei return ton kwdiko ptisis, to megalo e.search vriskei to location tis thesis mnimis gia to binary tree me ton idio kwdiko
	//freeseats vriskei tis eleftheres theseis (gia if )
	else{
		//prepei na kanoume diadikasia pou na svinei thesi (thelei ligo meleti gia to an prepei na swzei onoma)
		}
	}
	else if(p=='B'){
		cout<<"CODE:";
		cin>>a;
		e.destroy_tree(a);
	}
		cin>>p;
	}
	return 0;
}
