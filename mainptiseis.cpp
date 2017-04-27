#include <iostream>
#include <string>
using namespace std;
struct node{
int key,cost,seats,rseats;//rseats = reserved seats
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
        node *search(int key);//Διαδικασια αναζητησης πτησης
        node *previous(int key);//Διαδικασια ευρεσης της προηγουμενης πτησης (στο δενδρο , για να κανουμε διαγραφη) TO BE COMPLETED
        void addflight(int key);//Διαδικασια προσθεσης νεας πτησης
        void loudsearch(int key);//Εμφανηση αποτελεσματος αναζητησης
        void deleteflight(int key);//Διαγραφη πτησης και ανασυναρμολογηση δενδρου TO BE CREATED
        int  freeseats(int key);//Ελεγχος για ελευθερες θεσεις
        bool isleaf(int key);//Ελεγχος δενδρου αν υπαρχουν παιδια του κομβου 
        void reserved(int key , int a);//Το a μπορει να ειναι 1 η -1 αναλογα με το τι κανουμε
		
		//LINE
        void addqueue(int key,string first,string last);//Προσθηκη νεου ατομου στην λιστα
        void removequeue(int key,string first, string last);//Διαγραφη ατομου απο λιστα
        void removeall(int key);//Διαγραφη ολων απο την λιστα
		line *searchqueue(int key,string first,string last);//Βρεισκει την θεση ενος συγκεκριμενου ατομου στην λιστα
		line *searchkey(int key);//Βρεισκει τον προτο στην ουρα της πτησης



    private://Οι παρακατω διαδικασιες ειναι ΒΟΗΘΗΤΙΚΕΣ για την υλοποιηση των απο επανω
        node *root;//ορισμος τις ριζας
        node *search(int key,node *leaf);
        node *previous(int key,node *leaf);
        void transportnext(line *leaf, line *tobedel);
        void addflight(int key, node *leaf);
        void loudsearch(int key,node *leaf);
		void forceadd(int key,node *leaf);
        int  freeseats(node *leaf);
        void reserved(int key , int a,node *leaf);
        bool isleaf(int key,node *leaf);
        void addqueue(int key,string first,string last,line *leaf);
		line *searchqueue(int key,string first,string last,line *leaf);
		line *lastonline(line *leaf);

		line *previousqueue(int key,string first,string last,line *leaf);
		line *searchkey(int key,line *leaf);
        //tbc
		line *start;//ορισμος τις ριζας
};







btreeandline::btreeandline(){
	root=NULL;
	start=NULL;
}//Constructor για αρχικοποιηση


void btreeandline::addflight(int key){
	if (root!=NULL){
		addflight(key,root);
	}
	else{
		root=new node;//Προσθεση της πρωτης πτησης στην ριζα
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
}
void btreeandline::addflight(int key,node *leaf){//PRIVATE
	if (key>leaf->key){
		if ((leaf->right!=NULL)&&(leaf->left->key!=key)){
            cout<<"RIGHT"<<endl;
			addflight(key,leaf->right);
			//debuging

		}
		else{
            leaf->right=new node;
			forceadd(key,leaf->right);
            cout<<"NEW FLIGHTCODE ADDED"<<endl;
        }

	}
	else if (key<leaf->key){
		if ((leaf->left!=NULL)&&(leaf->left->key!=key)){
            cout<<"LEFT"<<endl;
			addflight(key,leaf->left);
			//debuging

		}
		else{
            leaf->left=new node;//Δεσμευση μνημης για την διαδικασια απο κατω
			forceadd(key,leaf->left);//Καταχωριση
            cout<<"NEW FLIGHTCODE ADDED"<<endl;
        }
	}
	else{
		cout<<"THIS FLIGHTCODE ALREADY EXISTS"<<endl;
	}

}



void btreeandline::forceadd(int key, node *leaf){//PRIVATE
	leaf->key=key;
	cout<<"GIVE COST: ";
	cin>>leaf->cost;
	cout<<"GIVE SEATS: ";
	cin>>leaf->seats;
	cout<<"GIVE RESERVED SEATS: ";
	cin>>leaf->rseats;
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




node *btreeandline::search(int key){//PUBLIC
	if (root!=NULL){

		return search(key,root);
	}
	else{
		return NULL;
	}
}
node *btreeandline::search(int key, node *leaf){//PRIVATE
    if(leaf!=NULL)
    {
    if(key==leaf->key){
		return leaf;
    }
    if(key<leaf->key){
		return search(key, leaf->left);
    }
    else{

		return search(key, leaf->right);
	}
	}
	else return NULL;

}




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
			return search(key,leaf->right);
		}
		else if (key<leaf->key){
			return search(key,leaf->left);
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
	}

}



int btreeandline::freeseats(int key){//PUBLIC
	return freeseats(search(key));
}
int btreeandline::freeseats(node *leaf){//PUBLIC
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
void btreeandline::reserved(int key,int a, node *leaf){//PRIVATE (Βλ. τελος διαδικασιας για περιγραφη)
	cout<<freeseats(key)<<" 274 ";//DEBUGGING
	if (freeseats(key)>0){
		leaf->rseats+=a*1;//Δεσμευση η αφαιρεση θεσης
		if ((a==-1)&&(freeseats(key)>0)&&(searchkey(key)!=NULL)){
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
	}
	else{
		if ((start==NULL)&&(a==1)){
			start=new line;
			cout<<"You are about to be added in queue "<<endl;
			cout<<"GIVE FIRST NAME"<<endl;
			cin>>start->first;
			cout<<"GIVE LAST NAME"<<endl;
			cin>>start->last;
			start->key=key;
			start->next=NULL;
		}
		else if ((start!=NULL)&&(a==1)){
			cout<<"You are about to be added in queue"<<endl;
			string lastname,firstname;
			cout<<"GIVE FIRST NAME :"<<endl;
			cin>>firstname;
			cout<<"GIVE LAST NAME :"<<endl;
			cin>>lastname;
			addqueue(key,firstname,lastname);
		}
		else if ((start==NULL)&&(a==-1)){
			cout<<"There are no reservations in queue"<<endl;
		}//θελει ενα if αν θες να βσησεις ατομα απο rseats
		else if ((start!=NULL)&&(a==-1)){
			string first,last;
			cout<<"GIVE FIRST NAME";
			cin>>first;
			cout<<"GIVE LAST NAME";
			cin>>last;
			removequeue(key,first,last);
		}
	}
}//αν θελεις να σβησεις καποιον εκτως ουρασ δεν μπορεις (αν γεμησει τα rseats)




line *btreeandline::searchqueue(int key,string first,string last){
	if (start!=NULL){
		return searchqueue(key,first,last,start);
	}else{
        cout<<"NO QUEUE"<<endl;
		return NULL;
	}
}
line *btreeandline::searchqueue(int key,string first,string last,line *leaf){
	if (leaf!=NULL){
		if ((key==leaf->key)&&(first==leaf->first)&&(last==leaf->last)){
            cout<<leaf<<" 336 "<<endl;//debuging
            return leaf;
		}
		else {
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
	cout<<leaf<<" 358 "<<endl;
	return leaf;
	}
}





void btreeandline::addqueue(int key,string first,string last){
	if (searchqueue(key,first,last)!=NULL){
		cout<<"YOU ARE ALREADY ON QUEUE"<<endl;
	}
	else{
        cout<<"START :"<<start<<endl;
		addqueue(key,first,last,lastonline(start));
	}
}
void btreeandline::addqueue(int key,string first,string last,line *leaf){
	leaf->next = new line;
	leaf->next->key=key;
	leaf->next->first=first;
	leaf->next->last=last;
	leaf->next->next=NULL;
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
    cout<<"PREVIOUS "<<previousqueue(key,first,last,start)<<" 417 "<<endl;
    cout<<"THIS "<<searchqueue(key,first,last)<<" 418 "<<endl;
	transportnext(previousqueue(key,first,last,start),searchqueue(key,first,last));//to search queue xalaei ta pada
	
}



void btreeandline::transportnext(line *leaf,line *tobedel){
	if (tobedel!=NULL){
		cout<<leaf<<endl;//debuging
		cout<<tobedel<<endl;//debuging
		if (leaf!=NULL){
			leaf->next=tobedel->next;
		}
		delete tobedel;
		cout<<"YOU HAVE BEEN REMOVED FROM THE QUEUE"<<endl;
	}else{
		cout<<"YOU ARE NOT IN THIS QUEUE"<<endl;
	}
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
		node *leaf = search(key);
		if (leaf==root) {
			delete leaf;
			leaf = NULL;
		}
		//δεν ειναι ετσι απλο πρεπει να εννωσουμε τα παρακατω
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
			cout<<"GIVE FLIGHTCODE : ";
			cin>>key;
			a.addflight(key);
		}
		else if (S=='R'){
			cout<<"GIVE FLIGHTCODE : ";
			cin>>key;
			a.reserved(key,1);
		}
		else if (S=='S'){
			cout<<"GIVE FLIGHTCODE :";
			cin>>key;
			a.loudsearch(key);
		}
		else if (S=='C'){
			cout<<"GIVE FLIGHTCODE :";
			cin>>key;
			a.reserved(key,-1);
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
