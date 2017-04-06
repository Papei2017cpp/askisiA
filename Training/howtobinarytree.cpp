#include <iostream>
#include <fstream>
#include <string>
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
	char from[2],to[2];
};
class btree
{
    public:
        btree();
        void insert(int key);
        node *search(int key);
        void destroy_tree(int key);

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
    leaf=NULL;
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
      leaf->left=new node;
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
	  char from[2],to[2];
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
	  std::cin>>from;
	  std::cout<<"TO:";
	  std::cin>>to;//telika kanoun kati alla den to kanoun kala lol >.<
      leaf->right=new node;
      leaf->right->key_value=key;
      leaf->right->cost=cost;
      leaf->right->seats=seats;
      leaf->right->rseats=rseats;
      leaf->right->start.hours=start.hours;
      leaf->right->start.minutes=start.minutes;
      leaf->right->reach.hours=reach.hours;
      leaf->right->reach.minutes=reach.minutes;
	  for (int i=0;i!=2;i++){//kapou malakizete edw nomizw
		leaf->right->from[i]=from[i];
		leaf->right->to[i]=to[i];
	  }
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
      cout<<"CODE "<<leaf->key_value<<"\nSEATS "<<leaf->seats<<"\nRESERVED SEATS "<<leaf->rseats<<"\nDEPARTURE TIME "<<leaf->start.hours<<":"<<leaf->start.minutes<<"\nDEPARTURE AIRPORT "<<leaf->from<<
      "\nARRIVAL AIRPORT "<<leaf->to<<endl;
      cout<<"kati egine ?";
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
    root->key_value=key;
    root->left=NULL;
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
	btree e;
	char p;
	cin>>p;
	while (p!='N'){
	int a;
	if (p=='a'){
	cin>>a;
	e.insert(a);
	
	}
	else if(p=='s'){
	cin>>a;
	e.search(a);
	}
	else if(p=='d'){
		cin>>a;
		e.destroy_tree(a);
	}
		cin>>p;
	}
	return 0;
}
