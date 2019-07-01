#include<iostream>
#include<math.h>
using namespace std;

class node
{
    int c,e;
    node *next;
    public:
        friend class polynomial;
};

class polynomial
{
    node *s,*l;
    public:
        polynomial()
        {
            s=NULL;
            l=NULL;
        }
    void create();
    void eval();
    void add(polynomial,polynomial);
    void display();
};

void polynomial::create()
{
    node *new1=NULL;
    new1=new node;
    cout<<"Enter coefficient and exponent\n";
    cin>>new1->c>>new1->e;
if(new1->c!=0)
{
    if(s==NULL&&l==NULL)
    {
        new1->next=new1;
        s=new1;
        l=new1;
    }
    else
    {
        l->next=new1;
        new1->next=s;
        l=new1;
    }
}
}

void polynomial::display()
{
    node *ch=NULL;
    ch=s;
    while(ch!=l)
    {
        cout<<ch->c<<"x^"<<ch->e<<" +";
        ch=ch->next;
    }
    cout<<ch->c<<"x^"<<ch->e;
    cout<<endl;
}

void polynomial::add(polynomial u,polynomial v)
{
    node *c1=NULL,*c2=NULL,*new1=NULL;
    c1=u.s; c2=v.s;
    do
    {
        new1=new node;
        if(s==NULL)
        {
            new1->next=new1;
            s=new1;
            l=new1;
        }
        else
        {
            l->next=new1;
            new1->next=s;
            l=new1;
        }
        if(c1->e==c2->e)
        {
            new1->c=c1->c+c2->c;
            new1->e=c1->e;
            c1=c1->next;
            c2=c2->next;
        }
        else if(c1->e>c2->e)
        {
            new1->c=c1->c;
            new1->e=c1->e;
            c1=c1->next;
        }
        else
        {
            new1->c=c2->c;
            new1->e=c2->e;
            c2=c2->next;
        }
       
    }while(c1!=u.l->next||c2!=v.l->next);
    node *ch=NULL;
    ch=s;
    while(ch!=l)
    {if(ch->c!=0)
{
        cout<<ch->c<<"x^"<<ch->e<<" +";}
        ch=ch->next;

    }
 if(ch->c!=0){   cout<<ch->c<<"x^"<<ch->e;}
    cout<<endl;   
}

void polynomial::eval()
{
    float x,V=0;
    cout<<"Enter value of x : ";
    cin>>x;
    node *ev=NULL;
    ev=s;
    while(ev!=l)
    {
        V=V + (ev->c * pow( x , ev->e ));
        ev=ev->next;       
    }
    V = V + (ev->c * pow( x , ev->e ));
    cout<<V<<"\n";
}

int main()
{
    polynomial p1,p2,p3;
    int count=0,choice,n1,n2;
   abc: cout<<"1. Enter number of terms for 1st polynomial\n";
cin>>n1;
if(n1<=0)
{cout<<"Number of terms should be positive!!\nTry Again\n";
goto abc;}
    do
    {
        p1.create();
        count++;
        n1--;
    }while(n1!=0);
   
        p1.display();
       
  abd:  cout<<"2. Enter Number of terms for 2nd polynomial\n";
        cin>>n2;
if(n2<=0)
{cout<<"Number of terms should be positive!!\nTry Again\n";
goto abd;}
    do
    {
        p2.create();
        n2--;
    }while(n2!=0);
   
        p2.display();
cont:cout<<"Enter : \n1] For Addition\n2] For Evaluation\n3] Exit ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Addition is :\n";
        p3.add(p1,p2);
    break;
case 2:
cout<<"For First Polynomial\n";
    p1.eval();
cout<<"For Second Polynomial\n";
p2.eval();
break;
case 3:
goto m;
break;
default:
cout<<"Error!!!\n";
break;
}
cout<<"continue(1 or 0)?";
int k;
cin>>k;
if(k==1)
{
goto cont;
}
    m:return 0;
}
