#include<iostream>
using namespace std;

class node
{
	friend class binary;
	node *next;
	node *prev;
	int b;
	public:
		node()
		{                 
			next=NULL;
			prev=NULL;
			b=0;
		}
};

class binary
{
	node *head;
	node *last;
	int count;
	public:
	binary()
	{
		head=NULL;
		last=NULL;
		count=0;
	}
	void convert(int );
	void insert(int );
	void display();
	void compliment(binary &);
	void add(binary &,binary &);
};


void binary::display()
{
	node *t;
	t=last;
	while(t!=NULL)
	{
		cout<<t->b<<" ";
		t=t->prev;
	}
	cout<<endl;
}
void binary::insert(int x)
{
	node *t=new node;
	t->b=x;
	if(head==NULL)
	{
		head=t;
		last=t;
		count+=1;
	}
	else
	{ 
		last->next=t;
		t->prev=last;
		last=t;
		count+=1;
	}
}


void binary::convert(int x)
{
	int r;
	while(x!=1)
	{
		r=x%2;
		insert(r);
		x=(int)x/2;
	}
	insert(1);
}


void binary::compliment(binary &x)
{
	node *t;
	t=x.head;
	while(t!=NULL)
	{
		if(t->b==1)
		{
			insert(0);
		}
		else
		{
			insert(1);
		}
		t=t->next;
	}
}


void binary::add(binary &x,binary &y)
{
	node *t,*t1;
	t=x.head;
	t1=y.head;
	int c=0,s=0;
	while(t!=NULL&&t1!=NULL)
	{
		s=t->b+t1->b+c;
		if(s==0)
		{
			insert(0);
			c=0;
		}
		else if(s==1)
		{
			insert(1);
			c=0;
		}
		else if(s==2)
		{
			insert(0);
			c=1;
		}
		else
		{
			insert(1);
			c=1;
		}
		t=t->next;
		t1=t1->next;
	}

	while(t!=NULL)
	{
		s=t->b+c;
		if(s==0)
		{
			insert(0);
			c=0;
		}
		else if(s==1)
		{
			insert(1);
			c=0;
		}
		else if(s==2)
		{
			insert(0);
			c=1;
		}
		else
		{
			insert(1);
			c=1;
		}
		t=t->next;
	}
	while(t1!=NULL)
	{
		s=t1->b+c;
		if(s==0)
		{
			insert(0);
			c=0;
		}
		else if(s==1)
		{
			insert(1);
			c=0;
		}
		else if(s==2)
		{
			insert(0);
			c=1;
		}
		else
		{
			insert(1);
			c=1;
		}
		t1=t1->next;
	}
	if(t==NULL&&t1==NULL&&c==1)
	{
		insert(c);
	}
}


int main()
{
	binary x,y,z,w,v,u,p,q;
	int n,c,k=1;
	int ch;
	char cho;
cout<<"----------------------------------------"<<endl;
      m:cout<<"\nEnter the First Decimal Number"<<endl;
	cin>>n;
	x.convert(n);
	
	cout<<"\nEnter the Second Decimal Number"<<endl;
	cin>>n;
	z.convert(n);
	cout<<"\nFirst Number in Binary form is    : ";
	x.display();
	
	u.convert(k);
	
	
	cout<<"\nSecond Number in Binary form is   : ";
	z.display();
	
vcx:cout<<"Enter :\n1. Complements of First Number\n2. Complements of Second Number\n3. Addition\n4. Exit\n";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\n1`s compliment of First Number is : ";
y.compliment(x);
	y.display();
q.add(y,u);
cout<<"\n2`s compliment of First Number is: ";
	q.display();
break;
case 2:
cout<<"\n1`s compliment of Second Number is: ";
	v.compliment(z);
v.display();
p.add(v,u);
cout<<"\n2`s compliment of Second Number is: ";
	p.display();
break;
case 3:
w.add(x,z);
	cout<<"\nAddition of two Binary Numbers is :";
	w.display();
break;
default:
cout<<"Invalid, Try again";
goto vcx;
break;
case 4:
goto html;
break;
}
cout<<"\nContinue(1 or 0)?";
int cal;
cin>>cal;
if(cal==1)
{
goto vcx;
}
html:cout<<"----------------------------------------"<<endl;
}
