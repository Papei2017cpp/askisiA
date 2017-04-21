#include <iostream>
#include <string>
using namespace std;
struct node{
int key,cost,seats,rseats;
node *left;
node *right;
    struct time{
        int hours;
        int minutes;
    }start,reach;
char from[4],to[4];
};//Για τις πτησεις

struct line{
		string frist,last;
		int key;
		line *next;
};//Για την ουρα

class btreeandline{
    public:
        btreeandline();
        node *search(int key);
        node *previous(int key);
        void addflight(int key);
        void loudsearch(int key);
        void deleteflight(int key);
        int  freeseats(int key);
        bool isleaf(int key);
        void reserved(int key , int a);//Το a μπορει να ειναι 1 η -1 αναλογα με το τι κανουμε


        void addqueue(int key,string first,string last);
        void removequeue(int key,string first, string last);
        void removeall(int key);
    private:
        node *root;
        node *search(int key,node *leaf);
        node *previous(int key,node *leaf);
        void addflight(int key, node *leaf);
        void loudsearch(int key,node *leaf);
        void deleteflight(node *leaf);
        //tbc
		line *start;
};


btreeandline::btreeandline(){
	root=NULL;
	start=NULL;
}
//LINE
//NODE
void btreeandline::addflight(int key){//PUBLIC
	if (root==NULL){
		root=new node;
		root->key=key;
		cout<<"GIVE COST: ";
		cin>>root->cost;
		cout<<"GIVE SEATS: ";
		cin>>root->seats;
		cout<<"GIVE RESERVED SEATS: ";
		cin>>root->rseats;
		root->left=NULL;
		root->right=NULL;
		cout<<"GIVE FLIGHT TIME: ";
		cin>>root->start.hours;
		cin>>root->start.minutes;
		cout<<"GIVE LAND TIME: ";
		cin>>root->reach.hours;
		cin>>root->reach.minutes;
		cout<<"GIVE STARTING LOCATION: ";
		cin>>root->from;
		cout<<"GIVE ARRIVAL LOCATION: ";
		cin>>root->to;
	}
	else{
	addflight(key,root);
	}
}

void btreeandline::addflight(int key,node *leaf){//PRIVATE
	if (leaf!=NULL){
		if (key>leaf->key){
			addflight(key,leaf->right);
		}
		else if (key<leaf->key){
			addflight(key,leaf->left);
		}
		else{
			cout<<"THIS FLIGHTCODE ALREADY EXISTS"<<endl;
		}
	}
	else{
		leaf=new node;
		leaf->key=key;
		cout<<"GIVE COST: ";
		cin>>leaf->cost;
		cout<<"GIVE SEATS: ";
		cin>>leaf->seats;
		cout<<"GIVE RESERVED SEATS: ";
		cin>>root->rseats;
		leaf->left=NULL;
		leaf->right=NULL;
		cout<<"GIVE FLIGHT TIME: ";
		cin>>leaf->start.hours;
		cin>>leaf->start.minutes;
		cout<<"GIVE LAND TIME: ";
		cin>>leaf->reach.hours;
		cin>>leaf->reach.minutes;
		cout<<"GIVE STARTING LOCATION: ";
		cin>>leaf->from;
		cout<<"GIVE ARRIVAL LOCATION: ";		
		cin>>leaf->to;
	}
}




int main(){
	btreeandline a;
	char S;
	int key;

	cout<<"SELECT :"<<endl;
	cout<<"A FOR ADD FLIGHT"<<endl;
	cout<<"X TO QUIT"<<endl;
	cin>>S;
	while(S!='X'){
		if (S=='A'){
		cout<<"GIVE FLIGHTCODE: ";
		cin>>key;
		a.addflight(key);
		}

		cout<<"SELECT :"<<endl;
		cin>>S;
	}
	return 0;
}
