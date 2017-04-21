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
		//TREE
        node *search(int key);
        node *previous(int key);
        void addflight(int key);
        void loudsearch(int key);
        void deleteflight(int key);
        int  freeseats(int key);
        bool isleaf(int key);
        void reserved(int key , int a);//Το a μπορει να ειναι 1 η -1 αναλογα με το τι κανουμε

		//LINE
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
        int  freeseats(int key,node *leaf);
        void reserved(int key , int a,node *leaf);
        bool isleaf(int key,node *leaf);
        //tbc
		line *start;
};







btreeandline::btreeandline(){
	root=NULL;
	start=NULL;
}

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




node *btreeandline::search(int key){//PUBLIC
	if (root!=NULL){
		return search(key,root);
	}
	else{
		return NULL;
	}
}
node *btreeandline::search(int key, node *leaf){//PRIVATE
	if (leaf!=NULL){
		if (key==leaf->key){
			return leaf;
		}
		else if (key>leaf->key){
			search(key,leaf->right);
		}
		else if (key<leaf->key){
			search(key,leaf->left);
		}	
	}
	else{
	return NULL;
	}
}//Dont care about the error created here




void btreeandline::loudsearch(int key){//PUBLIC
	loudsearch(key,search(key));
	
}
void btreeandline::loudsearch(int key,node *leaf){//PRIVATE
	if (leaf!=NULL){
		cout<<"FLIGHT DETAILS"<<endl;
		cout<<"CODE :"<<leaf->key<<endl;
		cout<<"COST:"<<leaf->cost<<endl;
		cout<<"SEATS :"<<leaf->seats<<endl;
		cout<<"RESERVED SEATS :"<<leaf->rseats<<endl;
		cout<<"FLGHT TIME :"<<leaf->start.hours<<":"<<leaf->start.minutes<<endl;
		cout<<"LAND TIME :"<<leaf->reach.hours<<":"<<leaf->reach.minutes<<endl;
		cout<<"FROM :"<<leaf->from<<endl;
		cout<<"TO :"<<leaf->to<<endl;
	}

}



int btreeandline::freeseats(int key){//PUBLIC
	return freeseats(key,search(key));
}
int btreeandline::freeseats(int key,node *leaf){//PUBLIC
	return ((leaf->seats)-(leaf->rseats));	
}




bool btreeandline::isleaf(int key){//PUBLIC
	return isleaf(key,search(key));
}
bool btreeandline::isleaf(int key,node *leaf){//PRIVATE
	return ((leaf->left==NULL)&&(leaf->right==NULL));
}




void btreeandline::reserved(int key,int a){//PUBLIC
	reserved(key,a,search(key));
}
void btreeandline::reserved(int key,int a, node *leaf){//PRIVATE
	if (freeseats(key)>0){
		leaf->rseats+=a*1;
	}
}



int main(){
	btreeandline a;
	char S;
	int key;

	cout<<"SELECT :"<<endl;
	cout<<"A TO ADD FLIGHT"<<endl;
	cout<<"S TO SEARCH FLIGHT"<<endl;
	cout<<"X TO QUIT"<<endl;
	cin>>S;
	while(S!='X'){
		if (S=='A'){
			cout<<"GIVE FLIGHTCODE: ";
			cin>>key;
			a.addflight(key);
		}
		if (S=='S'){
			cout<<"GIVE FLIGHTCODE";
			cin>>key;
			a.loudsearch(key);
		}
		cout<<"SELECT :"<<endl;
		cin>>S;
	}
	return 0;
}
