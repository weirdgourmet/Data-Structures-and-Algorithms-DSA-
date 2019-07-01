/*
* Assignment 5 :  Write C++ program for storing binary number using doubly  linked lists. Write functions a) to compute 1‘s and 2‘s
complement b) add two binary numbers.
* Name : weirdgourmet
 */

#include <iostream>
using namespace std;
class node
{
int b;
node *prv;
node *nxt;
friend class link;
};

class link
{
	public:
node *start;
node *last;

link() //constructor
{
start=NULL;
last=NULL;
}
void insertlst(int);
void display();
void one();
void two();

};
void  link :: two()
{node *ptr;
int c;
ptr=start;
if(start->b==0)
start->b=1;
else{
while(ptr->b!=0 && ptr!=NULL){
	ptr->b=0;
	ptr=ptr->nxt;
}
if(ptr==NULL)
{
	node *new1;
	new1=new node;
	new1->prv=last;
	new1->b=1;
	new1->nxt=NULL;
	last=new1;
}
else
	ptr->b=1;
}
}
void  link :: one()
{node *ptr;
ptr=start;
while(ptr!=NULL){
if(ptr->b==1)
{ptr->b=0;
ptr=ptr->nxt;
}
else
{ptr->b=1;
ptr=ptr->nxt;
}
}
}
void  link :: insertlst(int n)
{
node *new1;
new1=new node;

new1->b=n;
if(start==NULL)
{
last=new1;
start=new1;
new1->nxt=NULL;
new1->prv=NULL;
}
else{
last->nxt=new1;
new1->nxt=NULL;
new1->prv=last;
last=new1;
}

}

void link::display()
{node *ptr;
ptr=last;
	while(ptr!=NULL)
	{
		cout<<ptr->b;
		ptr=ptr->prv;
	}
}
int main() {

int n1,n2,q,r,s,p,x;
link a,b,s1;
	do
	{
    cout << "Enter decimal number : ";
	cin>>n1;
	cout<<"Press 1 to find one's compliment.\nPress 2 to find two's compliment.\nPress 3 to find addition. ";
	cin>>p;
	switch(p)
	{
	case 1:
	for(q=n1;q!=0;)
	{
		r=q%2;
		q=q/2;
		a.insertlst(r);
	}


	a.one();
	cout<<endl<<"One's Complement : ";
	a.display();
	break;
	case 2:
	cout<<endl<<"Two's Complement : ";
	a.two();
	a.display();
	break;
	case 3:
	cout <<endl<< "Enter decimal number : ";
		cin>>n2;
		for(q=n2;q!=0;)
		{
			r=q%2;
			q=q/2;
			b.insertlst(r);
		}

		s=n1+n2;
		for(q=s;q!=0;)
			{
				r=q%2;
				q=q/2;
				s1.insertlst(r);
			}
		cout<<endl<<"Addition : ";
			s1.display();
	     break;
	default:
		cout<<"Enter appropriate choice";
	break;
	}
	cout<<endl<<"Press 1 to continue.\t   Press 0 to exit.\t";
	cin>>x;
	}while(x==1);
			return 0;
}
/*
  OUTPUT :

Enter decimal number : 14
Press 1 to find one's compliment.
Press 2 to find two's compliment.
Press 3 to find addition. 1

One's Complement : 0001
Press 1 to continue.	   Press 0 to exit.	1
Enter decimal number : 14
Press 1 to find one's compliment.
Press 2 to find two's compliment.
Press 3 to find addition. 2

Two's Complement : 0010
Press 1 to continue.	   Press 0 to exit.	1
Enter decimal number : 14
Press 1 to find one's compliment.
Press 2 to find two's compliment.
Press 3 to find addition. 3

Enter decimal number : 6

Addition : 10100
Press 1 to continue.	   Press 0 to exit.	0

*/

