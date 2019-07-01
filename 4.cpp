/*
 * pinnacle.cpp
 
 *  Name: weordgourmet

 *  Assignment 4 : Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of Second, third and final
year of department can be granted membership on request.Similarly one may cancel the membership of club. First node
is reserved for president of club and last node is reserved for secretary of club. Write C++ program to maintain club
member‘s information using singly linked list. Store student PRN and Name. Write functions to
 a) Add and delete the members as well as president or even secretary.
 b) Compute total number of members of club
 c) Display members
 d) Display list in reverse order using recursion
 e) Two linked lists exists for two divisions. Concatenate two lists
 f) Sort the singly linked list.
 */

#include<iostream>
#include<string.h>
using namespace std;

class Node
{
	public:
		char name[30];
		int prn;
		Node* next;
		Node()
		{
			prn=0;
			next=NULL;
			name[0]='\0';
		}
		Node(int x,char A[])
		{
			int i;
			prn=x;
			for(i=0;A[i]!='\0';i++)
			{
				name[i]=A[i];
			}
			name[i]='\0';
			next=NULL;
		}
		friend class Pinnacle_club;

};

Node* head;
class Pinnacle_club
{
	public:
	Node* head;
	Pinnacle_club()
	{
		head=NULL;
	}
    void create();
    void insertpres();
    void insertmem();
    void insertsec();
    void display();
    void deletel();
    void sort();
    void compute();
    void concatenate(Pinnacle_club p);
    void reverseprint(Node *q);
    void reverse();
};

void Pinnacle_club::concatenate(Pinnacle_club p)
{
	Node *x,*y;
	x=head;
	y=p.head;
	while(x->next!=NULL)
	{
		x=x->next;
	}
	x->next=y;

}

void Pinnacle_club::compute()
{
	int t=0;
	Node *temp;
	temp=head;
	while(temp!=NULL)
	{
		t++;
		temp=temp->next;
	}
	cout<<"The total members in the club are: "<<t<<endl;
}

void Pinnacle_club::sort()
{
	int val;
	Node *ptr,*s;
	s=head;
	if(head==NULL)
	{
		cout<<"The list is empty";
	}
	else
	{
		ptr=head;
		while(ptr!=NULL)
		{
			for(s=ptr->next;s!=NULL;s=s->next)
			{
				if(ptr->prn > s->prn)
				{
					val=ptr->prn;
					ptr->prn=s->prn;
					s->prn=val;
				}
			}
			ptr=ptr->next;
		}
	}
}

void Pinnacle_club::deletel()
{
	int posn,i;
	Node *ptr,*s;
	s=head;
	if(head==NULL)
	{
		cout<<"The list is empty";
	}
	else
	{
		cout<<"Enter the position: ";
		cin>>posn;
		if(posn==1)
		{
			head=head->next;
			delete(s);
		}
		else
		{
			s=head;
			for(i=1;i<posn;i++)
			{
				ptr=s;
				s=s->next;
			}
			ptr->next=s->next;
		}
	}
}

void Pinnacle_club::insertpres()
{
	char pre[20];
	int s;
	cout<<"Enter President name: "<<endl;
	cin>>pre;
	cout<<"Enter PRN no."<<endl;
	cin>>s;
	Node* p=new Node(s,pre);
	if(head==NULL)
    {
		head=p;
    }
	else
	{
		Node* temp;
		temp=head;
		p->next=temp;
		head=p;
	}
}

void Pinnacle_club::insertmem()
{
	char mem[20];
	int s,total1;


	cout<<"Enter member name: ";
	cin>>mem;
	cout<<"Enter PRN no.";
	cin>>s;
	Node* q=new Node(s,mem);
	if(head==NULL)
	{
		head=q;
	}
	else
	{
		Node* temp;
		temp=head;
		q->next=temp->next;
		temp->next=q;
	}
}

void Pinnacle_club::insertsec()
{
	char sec[20];
	int s,total1;


	cout<<"Enter secretary name: ";
	cin>>sec;
	cout<<"Enter PRN no.";
	cin>>s;
	Node* r= new Node(s,sec);
	if(head==NULL)
	{
		head=r;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=r;
		r->next=NULL;
	}


}

void Pinnacle_club::display()
{
	Node* temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<"Name is: "<<temp->name<<endl;
		cout<<"PRN is: "<<temp->prn<<endl;
		temp=temp->next;
	}
}

void Pinnacle_club::create()
{
	char a[20];
	int j;
	cout<<"Enter name";
	cin>>a;
	cout<<"Enter PRN no.";
	cin>>j;
	if(head!=NULL)
	cout<<"The list is already full"<<endl;
	else
	{
		Node *temp= new Node(j,a);
		head=temp;
	}
}

void Pinnacle_club::reverseprint(Node *q)
{
	if(q==NULL)
	{
		return;
	}
	reverseprint(q->next);
	cout<<"PRN is: "<<q->prn<<endl;
	cout<<"Name is: "<<q->name<<endl;
}

void Pinnacle_club::reverse()
{
	Node *q;
	q=head;
	reverseprint(q);
}

int main()
{
	Pinnacle_club p,p1,p2;
	char pre[20];
	int menu,i,s,total;
	do{
	cout<<"1.Display the list.\n2.Insert the President.\n3.Insert the secretary.\n4.Insert the member.\n5.Delete the element.\n6.Reverse and display the list.\n7.Concatenate the two lists.\n8.Sort the list.\n9.To compute the total members of the list.";
        cin>>menu;
        switch(menu)
        {
        case 1:
            p.display();
            break;
        case 2:
        	p.insertpres();
        	p.display();
        	break;
        case 3:
        	p.insertsec();
        	p.display();
        	break;
        case 4:
        	p.insertmem();
        	p.display();
        	break;
        case 5:
        	p.deletel();
        	p.display();
        	break;
        case 6:
          	p.reverse();
           	break;

        case 7:
        		cout<<"Enter the total no. of members in second list: ";
        				cin>>total;
        				p1.insertpres();
        				for(i=0;i<total-2;i++)
        				{
        				p1.insertmem();
        				}

        					p1.insertsec();

        				p.concatenate(p1);
        		p.display();
        		break;
        case 8:
        	p.sort();
        	p.display();
        	break;

        case 9:
            p.compute();
            break;
        default:
        	cout<<"Enter correct choice";
        	break;
        }
        cout<<"Press 1 to continue \t Press 0 to exit \t ";
        		cin>>s;
        	}
        	while(s==1);
        return 0;
        }


/* OUTPUT :


1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.2
Enter President name
asdfg
Enter PRN no.
1212
Name is: asdfg
PRN is: 1212
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.3
Enter secretary name: qwert
Enter PRN no.2323
Name is: asdfg
PRN is: 1212
Name is: qwert
PRN is: 2323
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.4
Enter member name: zxcvb
Enter PRN no.2525
Name is: asdfg
PRN is: 1212
Name is: zxcvb
PRN is: 2525
Name is: qwert
PRN is: 2323
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.4
Enter member name: fghjk
Enter PRN no.4545
Name is: asdfg
PRN is: 1212
Name is: fghjk
PRN is: 4545
Name is: zxcvb
PRN is: 2525
Name is: qwert
PRN is: 2323
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.1
Name is: asdfg
PRN is: 1212
Name is: fghjk
PRN is: 4545
Name is: zxcvb
PRN is: 2525
Name is: qwert
PRN is: 2323
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.8
Name is: asdfg
PRN is: 1212
Name is: fghjk
PRN is: 2323
Name is: zxcvb
PRN is: 2525
Name is: qwert
PRN is: 4545
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.6
PRN is: 4545
Name is: qwert
PRN is: 2525
Name is: zxcvb
PRN is: 2323
Name is: fghjk
PRN is: 1212
Name is: asdfg
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.9
The total members in the club are: 4
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.7
Enter the total no. of members in second list: 4
Enter President name
tyuio
Enter PRN no.
2121
Enter member name: bnmzx
Enter PRN no.5858
Enter member name: fgtry
Enter PRN no.6969
Enter secretary namepoiuy
Enter PRN no.2468
Name is: asdfg
PRN is: 1212
Name is: fghjk
PRN is: 2323
Name is: zxcvb
PRN is: 2525
Name is: qwert
PRN is: 4545
Name is: tyuio
PRN is: 2121
Name is: fgtry
PRN is: 6969
Name is: bnmzx
PRN is: 5858
Name is: poiuy
PRN is: 2468
Press 1 to continue 	 Press 0 to exit 	 1
1.Display the list.
2.Insert the President.
3.Insert the secretary.
4.Insert the member.
5.Delete the element.
6.Reverse and display the list.
7.Concatenate the two lists.
8.Sort the list.
9.To compute the total members of the list.5
Enter the position: 3
Name is: asdfg
PRN is: 1212
Name is: fghjk
PRN is: 2323
Name is: qwert
PRN is: 4545
Name is: tyuio
PRN is: 2121
Name is: fgtry
PRN is: 6969
Name is: bnmzx
PRN is: 5858
Name is: poiuy
PRN is: 2468
Press 1 to continue 	 Press 0 to exit 	 0

*/










