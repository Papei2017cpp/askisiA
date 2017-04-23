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
		string first,last;
		int key;
		line *next;
};//Για την ουρα (Τα υπολοιπα τα βαζουμε μετα)

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
		line *searchqueue(int key,string first,string last);//vriskei thesi enos sigekrimenou
		line *searchkey(int key);//vriskei to prwto prwto me ton arithmo afto



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
        void addqueue(int key,string first,string last,line *leaf);
		line *searchqueue(int key,string first,string last,line *leaf);
		line *lastonline(line *leaf);
		line *previousqueue(int key,string first,string last,line *leaf);
		line *searchkey(int key,line *leaf);
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




node *btreeandline::previous(int key){//PUBLIC
	if (root!=NULL){
		return search(key,root);
	}
	else{
		return NULL;
	}
}
node *btreeandline::previous(int key, node *leaf){//PRIVATE
	if (leaf!=NULL){
		if ((key==leaf->left->key)||(key==leaf->right->key)){
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
}//same error as above :)




void btreeandline::loudsearch(int key){//PUBLIC
	loudsearch(key,search(key));
	
}
void btreeandline::loudsearch(int key,node *leaf){//PRIVATE
	if (leaf!=NULL){
		if (key==leaf->key){
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
		else if (key>leaf->key){
			loudsearch(key,leaf->right);
		}
		else if (key<leaf->key){
			loudsearch(key,leaf->left);
		}
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
	cout<<freeseats(key);//DEBUGGING
	if (freeseats(key)>0){
		leaf->rseats+=a*1;
		if ((a==-1)&&(freeseats(key)>0)&&(searchkey(key)!=NULL)){//den uparxei akoma tpt sto firstonline
			line *leaf=searchkey(key);
			if (leaf==start){
			delete start;	
			}else{
			if (previousqueue(key,leaf->first,leaf->last,start)!=NULL){
				line *tobedeleted=previousqueue(key,leaf->first,leaf->last,start);
				tobedeleted->next=leaf->next;//an ola afta uparxoun
			}
		}
	}
	else{
		if ((start==NULL)&&(a==1)){
			start=new line;
			cout<<"You are about to add to queue "<<endl;
			cout<<"GIVE FIRST NAME"<<endl;
			cin>>start->first;
			cout<<"GIVE LAST NAME"<<endl;
			cin>>start->last;
			start->key=key;
			start->next=NULL;
		}
		else if ((start!=NULL)&&(a==1)){
			cout<<"You are about to add to queue "<<endl;
			string lastname,firstname;
			cout<<"GIVE FIRST NAME"<<endl;
			cin>>firstname;
			cout<<"GIVE LAST NAME"<<endl;
			cin>>lastname;
			addqueue(key,firstname,lastname);
		}
		else if ((start==NULL)&&(a==-1)){
			cout<<"There are no reservations in queue"<<endl;//gia kapoio legit periergo logo emfanizei afto lol
		}
		else if ((start!=NULL)&&(a==-1)){
			string first,last;
			cout<<"GIVE FLIGHTCODE";
			cin>>key;
			cout<<"GIVE FIRST NAME";
			cin>>first;
			cout<<"GIVE LAST NAME";
			cin>>last;
			removequeue(key,first,last);
		}
	}
}


}
line *btreeandline::searchqueue(int key,string first,string last){
	if (start!=NULL){
		return searchqueue(key,first,last,start);
	}else{
		return NULL;
	}
}
line *btreeandline::searchqueue(int key,string first,string last,line *leaf){
	if (leaf!=NULL){
		if ((key==leaf->key)&&(first==leaf->first)&&(last==leaf->last)){
			return leaf;
		}
		else{
			return searchqueue(key,first,last,leaf->next);
		}
	}
	else{
		return NULL;
	}
}




line *btreeandline::lastonline(line *leaf){
	if (leaf->next!=NULL){
	return lastonline(leaf->next);
	}
	else{
	return leaf->next;	
	}
}





void btreeandline::addqueue(int key,string first,string last){
	if (searchqueue(key,first,last)!=NULL){
		addqueue(key,first,last,lastonline(start));
	}
	else{
		cout<<"YOU ARE ALREADY ON QUEUE"<<endl;
	}
}
void btreeandline::addqueue(int key,string first,string last,line *leaf){
	leaf= new line;
	leaf->key=key;
	leaf->first=first;
	leaf->last=last;
	leaf->next=NULL;
}





line *btreeandline::searchkey(int key){
	if (start!=NULL){
		searchkey(key,start);
	}
	else{
	return NULL;
	}	
}
line*btreeandline::searchkey(int key,line *leaf){
	if (leaf!=NULL){
		if (key==leaf->key){
			return leaf;
		}
		else{
			return searchkey(key,leaf->next);
		}
	}
	else{
		return NULL;
	}		
	
}






void btreeandline::removequeue(int key,string first,string last){
	line *leaf=previousqueue(key,first,last,start);
	line *tobedeleted=searchqueue(key,first,last);
	leaf->next=tobedeleted->next;
}





line *btreeandline::previousqueue(int key,string first,string last,line *leaf){
	if (leaf->next!=NULL){
		if ((key==leaf->next->key)&&(first==leaf->next->first)&&(last==leaf->next->last)){
			return leaf;
		}
		else{
			return previousqueue(key,first,last,leaf->next);
		}
	}
	else{
		return NULL;
	}	
}



void btreeandline::removeall(int key){
	if (searchkey(key)!=NULL){
		if (previousqueue(key,searchkey(key)->first,searchkey(key)->last,start)!=NULL){
			line *leaf=searchkey(key);
			line *previousleaf=previousqueue(key,searchkey(key)->first,searchkey(key)->last,start);
			previousleaf->next=leaf->next;
			removeall(key);
		}
		else{
			delete searchkey(key);
		}
	}
}




void btreeandline::deleteflight(int key){
	if (search(key)!=NULL){
		removeall(key);
		delete search(key);
		cout<<"THE FLIGHT HAS BEEN DELETED"<<endl;
	}
}




int main(){
	btreeandline a;
	char S;
	int key;
	string first;
	string last;
	cout<<"SELECT :"<<endl;
	cout<<"A TO ADD FLIGHT"<<endl;
	cout<<"S TO SEARCH FLIGHT"<<endl;
	cout<<"R TO RESERVE A SEAT OR ADD TO QUEUE"<<endl;
	cout<<"C TO CANCEL A RESERVATION OR QUIT QUEUE"<<endl;
	cout<<"D TO DELETE A FLIGHT"<<endl;
	cout<<"X TO QUIT"<<endl;
	cin>>S;
	while(S!='X'){
		if (S=='A'){
			cout<<"GIVE FLIGHTCODE: ";
			cin>>key;
			a.addflight(key);
		}
		else if (S=='R'){
			cout<<"GIVE FLIGHTCODE: ";
			cin>>key;
			a.reserved(key,1);
		}
		else if (S=='S'){
			cout<<"GIVE FLIGHTCODE";
			cin>>key;
			a.loudsearch(key);
		}
		else if (S=='C'){
			cout<<"GIVE FLIGHTCODE";
			cin>>key;
			a.reserved(key,-1);//do this twice if freeseats are empty and delete the first on line
		}
		else if (S=='D'){
			cout<<"GIVE FLIGHTCODE";
			cin>>key;
			a.deleteflight(key);
		}
		cout<<"SELECT :"<<endl;
		cin>>S;
	}
	return 0;
}
