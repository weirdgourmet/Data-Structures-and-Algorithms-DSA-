#include<iostream>
using namespace std;

class node{
	string name;
	int pnumber;
	node *next;
	public:
	friend class queue;
};

class queue{
	node *start;
	node *last;
	public:
	queue(){
		start = NULL;
		last = NULL;
	}
	void addnode(){
		node *new1 = new node;
		cout<<"\nEnter your name: ";
		cin>>new1->name;
		cout<<"\nEnter the priority: ";
		cin>>new1->pnumber;
		if(start == NULL){
			start = new1;
			last = new1;
			new1->next = NULL;
		}
		else{
			last->next = new1;
			new1->next = NULL;
			last = new1;
		}
	}
	void popnode(){
		if(start == NULL){
			cout<<"\nThe queue is empty";
		}
		else if(start == last && last != NULL){
			cout<<"\nThe following name has got the job: "<<start->name<<"  "<<start->pnumber;
			node *current;
			current = start;
			delete current;
			current = NULL;
			start = NULL;
			last = NULL;
		}
		else{
			cout<<"\nThe following name has got the job: "<<start->name<<"  "<<start->pnumber;
			node *current;
			current = start;
			start = current->next;
			delete current;
			current = NULL;
		}
	}
	void display(){
		if(start == NULL && last == NULL){
			cout<<"\nThe queue is empty! ";
		}
		else{
			cout<<"\nThe queue is: \n";
			node *c;
			c = start;
			while(c != NULL){
				cout<<c->name<<"  "<<c->pnumber<<"\n";
				c = c->next;
			}
		}

	}
	void sort(){
		if(start != last){
		node *c, *p;
		p = start;
		while(p != last){
			c = p->next;
			if(c != NULL){
				while(c != NULL){
					if(c->pnumber > p->pnumber){
						int temp = p->pnumber;
						p->pnumber = c->pnumber;
						c->pnumber = temp;
						string temp1 = p->name;
						p->name = c->name;
						c->name = temp1;
					}
					c = c->next;
				}
			}
			p = p->next;
		}
	}
	}

};

int main(){
	queue job;
	char ch;
	while(ch != 'n'){
		cout << "\nEnter 1 to add job,\n2 to assign a job,\n 3 to display: \n";
		int c;
		cin >> c;
		switch(c){
			case 1:
				job.addnode();
				job.sort();
				break;
			case 2:
				job.popnode();
				break;
			case 3:
				//job.sort();
				job.display();
				break;
			default:
				cout << "\n" ;
		}
		cout << "\nWant to repeat(y or n): ";
		cin >> ch;
	}

	return 0;
}
