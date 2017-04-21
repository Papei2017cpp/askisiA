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
char from[3],to[3];
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
        ~btreeandline();
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
		cin>>root->cost;
		cin>>root->seats;
		cin>>root->rseats;
		root->left=NULL;
		root->right=NULL;
		cin>>root->start.hours;
		cin>>root->start.minutes;
		cin>>root->reach.hours;
		cin>>root->reach.minutes;
		cin>>root->from[3];
		cin>>root->to[3];
	}
	else{
	addflight(key,root);
	}
}

void btreeandline::addflight(int key,node *leaf){
	
}
