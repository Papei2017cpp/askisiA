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
char from[3],to[3];
};//Για τις πτησεις

struct line{
		string first,last;
		int key,diavatirio,tilefono;
        string address,country;
		line *next;
};//Για την ουρα (Τα υπολοιπα τα βαζουμε μετα)

class btreeandline{
    public:
        btreeandline();
		//TREE
        node *search(int key);//Διαδικασια αναζητησης πτησης
        node *previous(int key);//Διαδικασια ευρεσης της προηγουμενης πτησης (στο δενδρο , για να κανουμε διαγραφη)
        void addflight(int key);//Διαδικασια προσθεσης νεας πτησης
        void loudsearch(int key);//Εμφανηση αποτελεσματος αναζητησης
        void deleteflight(int key);//Διαγραφη πτησης και ανασυναρμολογηση δενδρου TO BE FINISHED
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
        void swapnode(node *leaf,node *sec);
        int  freeseats(node *leaf);
        void reserved(int key , int a,node *leaf);
        bool isleaf(node *leaf);
        void addqueue(int key,string first,string last,string country,string address,int tilefono,int diavatirio,line *leaf);
		line *searchqueue(int key,string first,string last,line *leaf);
		line *lastonline(line *leaf);
        void gotoline(int a,int key);
        node *onlyWay(int a,node *leaf);
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
	return isleaf(search(key));
}
bool btreeandline::isleaf(node *leaf){//PRIVATE
    cout<<"ERROR" <<"  261"<<endl;
	return ((leaf->left==NULL)&&(leaf->right==NULL));
}




void btreeandline::reserved(int key,int a){//PUBLIC
	if (search(key)!=NULL){
        reserved(key,a,search(key));
    }
    else if (a==-1){
        cout<<"THIS CODE IS NOT AVALIABLE PLEASE SELECT ALL THE OTHER FLIGHTS TO YOUR DESTINATION '0' TO CANCEL"<<endl;
        int key,a,nkey;
        cout<<"GIVE FLIGHTCODE :"<<endl;
        cin>>key;
        if (key!=0) {
            cout<<"GIVE FLIGHTCODE :"<<endl;
            cin>>nkey;
            while ((key!=0)&&(search(key)->to==search(nkey)->from)){
                if (((search(nkey)->start.hours==search(key)->reach.hours)&&(search(nkey)->start.minutes>search(key)->reach.minutes))||
                search(nkey)->start.hours>search(key)->reach.hours){
                    reserved(key, a, search(key));
                    nkey=key;
                    cout<<"GIVE FLIGHTCODE OR PRESS '0' TO STOP :"<<endl;
                    cin>>key;
                }

            }
        }
    }
}
void btreeandline::reserved(int key,int a, node *leaf){//PRIVATE (Βλ. τελος διαδικασιας για περιγραφη)
	cout<<freeseats(key)<<" 274 ";//DEBUGGING
	if (freeseats(key)>0){
		leaf->rseats+=a;//Δεσμευση η αφαιρεση θεσης

	}
	else{
		if ((start==NULL)&&(a==1)){
			start=new line;
			cout<<"You are about to be added in queue "<<endl;
			cout<<"GIVE FIRST NAME"<<endl;
			cin>>start->first;
			cout<<"GIVE LAST NAME"<<endl;
			cin>>start->last;
            cout<<"GIVE PASSPORT ID"<<endl;
            cin>>start->diavatirio;
            cout<<"GIVE PHONE NUMBER"<<endl;
            cin>>start->tilefono;
            cout<<"GIVE COUNTRY"<<endl;
            cin>>start->country;
            cout<<"GIVE ADDRESS"<<endl;
            cin>>start->address;
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
            leaf->rseats-=1;
            gotoline(a,key);
            cout<<"Removing a reservation if any"<<endl;
		}//θελει ενα if αν θες να βσησεις ατομα απο rseats
		else if ((start!=NULL)&&(a==-1)){
			string first,last;
			cout<<"GIVE FIRST NAME";
			cin>>first;
			cout<<"GIVE LAST NAME";
			cin>>last;
			removequeue(key,first,last);
		}
        if (freeseats(key)<0){
            leaf->rseats=leaf->seats;
        }
	}
}//αν θελεις να σβησεις καποιον εκτως ουρασ δεν μπορεις (αν γεμησει τα rseats)



void btreeandline::gotoline(int a,int key) {
    if ((a==-1)&&(freeseats(key)>0)&&(searchkey(key)!=NULL)){
        line *leaf=searchkey(key);
        if (leaf==start){
            delete start;
            start=NULL;
        }else{
            if (previousqueue(key,leaf->first,leaf->last,start)!=NULL){
                line *tobedeleted=previousqueue(key,leaf->first,leaf->last,start);
                tobedeleted->next=leaf->next;//an ola afta uparxoun
            }
        }
    }
}


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
        string country;string address;int tilefono;int diavatirio;
        cout<<"START :"<<start<<endl;
        cout<<"GIVE PASSPORT ID"<<endl;
        cin>>diavatirio;
        cout<<"GIVE PHONE NUMBER"<<endl;
        cin>>tilefono;
        cout<<"GIVE COUNTRY"<<endl;
        cin>>country;
        cout<<"GIVE ADDRESS"<<endl;
        cin>>address;
		addqueue(key,first,last,country,address,tilefono,diavatirio,lastonline(start));
	}
}
void btreeandline::addqueue(int key,string first,string last,string country,string address,int tilefono,int diavatirio,line *leaf){
	leaf->next = new line;
	leaf->next->key=key;
	leaf->next->first=first;
	leaf->next->last=last;
    leaf->next->diavatirio=diavatirio;
    leaf->next->country=country;
    leaf->next->tilefono=tilefono;
    leaf->next->address=address;
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
    cout<<"SO A RESERVED SEAT WILL BE REMOVED"<<endl;
    gotoline(-1,key);
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
        cout<<"ERROR" <<"  474"<<endl;

        removeall(key);
        cout<<"ERROR" <<"  477"<<endl;

        node *leaf = search(key);
        cout<<search(key) <<"  480"<<endl;

        if (isleaf(leaf)) {
            cout<<"ERROR" <<"  483"<<endl;
            if (previous(leaf->key)->key>leaf->key){
                previous(leaf->key)->left=NULL;
            }else{
                previous(leaf->key)->right=NULL;
            }
            delete leaf;
		}
        else{
            cout<<"ERROR" <<"  494"<<endl;
            //Αν ενα απο τα υποδενδρα εχει μονο 1 υποδενδρο απο την ιδια κατεφθυνση
            if (leaf->left!=NULL){
                if (isleaf(leaf->left)){
                    cout<<"ERROR"<<" 491"<<endl;
                    leaf->left->right=leaf->right;
                    swapnode(leaf,leaf->left);
                }
                else if ((leaf->left->left!=NULL)&&(leaf->left->right==NULL)){
                    cout<<"ERROR" <<"  495"<<endl;
                    leaf=leaf->left;

                }
                else if (isleaf(onlyWay(0,leaf))){//ελεγχος αν το κλειδι που θελουμε να διαγραψουμε εχει υποδενδρα
                    previous(onlyWay(0,leaf)->key)->right=NULL;
                    if (onlyWay(0,leaf)!=leaf->right){
                        onlyWay(0,leaf)->right=leaf->right;
                    }
                    else{
                        onlyWay(0,leaf)->right=NULL;
                    }
                    cout<<"ERROR 510 "<<endl;
                    onlyWay(0,leaf)->left=leaf->left;
                    swapnode(leaf,onlyWay(0,leaf));

                }
                else{//αν δεν ειναι φυλλο τοτε θα εχει αριστερα πραγματα
                    cout<<"ERROR" <<"  522"<<endl;
                    previous(onlyWay(0,leaf)->key)->right=onlyWay(0,leaf)->left;
                    cout<<"ERROR 510 "<<endl;
                    if (onlyWay(0,leaf)!=leaf->right){
                        onlyWay(0,leaf)->right=leaf->right;
                    }
                    else{
                        onlyWay(0,leaf)->right=NULL;
                    }
                    cout<<"ERROR 525 "<<endl;
                    onlyWay(0,leaf)->left=leaf->left;
                    cout<<"ERROR 527 "<<endl;
                    swapnode(leaf,onlyWay(0,leaf));
                    cout<<"ERROR 529 "<<endl;
                }
            }
            else if(leaf->right!=NULL){
                if (isleaf(leaf->right)){
                    cout<<"ERROR"<<" 494"<<endl;
                    leaf->right->left=leaf->left;
                    swapnode(leaf,leaf->right);
                }
                else if (((leaf->right->left==NULL)&&(leaf->right->right!=NULL))){
                    cout<<"ERROR" <<"  500"<<endl;
                    leaf->right->left=leaf->left;
                    swapnode(leaf,leaf->right);

                }
                else if (isleaf(onlyWay(1, leaf))) {//ελεγχος αν το κλειδι που θελουμε να διαγραψουμε εχει υποδενδρα
                    cout<<"ERROR" <<"  529"<<endl;
                    previous(onlyWay(1,leaf)->key)->left=NULL;
                    if (onlyWay(1,leaf)!=leaf->left){
                        onlyWay(1,leaf)->left=leaf->left;
                    }
                    else{
                        onlyWay(1,leaf)->left=NULL;
                    }
                    onlyWay(1,leaf)->right=leaf->right;
                    swapnode(leaf,onlyWay(1,leaf));
                }
                else {//αν δεν ειναι φυλλο τοτε θα εχει δεξια πραγματα
                    cout<<"ERROR" <<"  535"<<endl;
                    previous(onlyWay(1,leaf)->key)->left=onlyWay(1,leaf)->right;
                    if (onlyWay(1,leaf)!=leaf->left){
                        onlyWay(1,leaf)->left=leaf->left;
                    }
                    else{
                        onlyWay(1,leaf)->left=NULL;
                    }
                    onlyWay(1,leaf)->right=leaf->right;
                    swapnode(leaf,onlyWay(1,leaf));
                }
                }
            }
        }
		cout<<"THE FLIGHT HAS BEEN DELETED"<<endl;
	}




node *btreeandline::onlyWay(int a,node *leaf) {
    if (a==0){
        int max;
        max = leaf->left->key;
        node *that=leaf->left;
        leaf = leaf->left;
        while (leaf->right!=NULL){
            if (leaf->right->key>max){
                that=leaf->right;
                max=leaf->right->key;
            }
            leaf=leaf->right;
        }
        return that;
    }
    else{
        int min;
        min = leaf->right->key;
        node *that=leaf->right;
        leaf = leaf->right;
        while (leaf->left!=NULL){
            if (leaf->left->key<min){
                that=leaf->left;
                min=leaf->left->key;
            }
            leaf=leaf->right;
        }
        return that;
    }

}


void btreeandline::swapnode(node *leaf,node *sec){

    leaf->right=sec->right;
    leaf->left=sec->left;
    leaf->key=sec->key;
    leaf->seats=sec->seats;
    leaf->rseats=sec->rseats;
    leaf->cost=sec->cost;
    leaf->from[0]=sec->from[0];
    leaf->from[1]=sec->from[1];
    leaf->from[2]=sec->from[2];
    leaf->from[3]=sec->from[3];
    leaf->to[0]=sec->to[0];
    leaf->to[1]=sec->to[1];
    leaf->to[2]=sec->to[2];
    leaf->to[3]=sec->to[3];
    leaf->start.hours=sec->start.hours;
    leaf->start.minutes=sec->start.minutes;
    leaf->reach.hours=sec->reach.hours;
    leaf->reach.minutes=sec->reach.minutes;
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
