class node
{
	friend class poly;
	node *next;
	int expo,coeff;
	public:
		node()
		{                 
			next=NULL;
			expo=0;
			coeff=0;	
		}
};

class poly
{
	node *head,*last;
	int count;
	public:
	binary()
	{
		head=NULL;
last=NULL;
		count=0;
	}
void insert(int x,int y)
{
node *t=new node;
t->expo=y;
t->coeff=x;
if(head==NULL)
	{
		head=t;
last=t;
		t->next=*head;
		count+=1;
	}
	else
	{ 
		last->next=t;
		t->next=*head;
		last=t;
		count+=1;
	}
}
void display()
{
node *t;
t=head;
while(t!=last)
{
cout<<t->coeff<<"x^"<<t->expo<<"+";
t=t->next;
}
}
void main()
{
int m,i,a,b;
poly s;
cout<<"Enter the highest degree in polynomial Expression";
cin>>m;
cout<<"\nCoeffiecient and exponents from highest to lowest degree term\n";
for(i=1;i<=m;i++)
{
cin>>a>> b;
