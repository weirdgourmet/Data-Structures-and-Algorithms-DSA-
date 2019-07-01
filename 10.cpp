Name: weirdgourmet

#include<iostream>
using namespace std;
class deque
{
	int front,rear,max;
	int *data;
public:
	deque()
	{
		front=-1;
		rear=-1;
		data[0]='\0';
	}

	deque(int m)
	{
		max=m;
		front=-1;
		rear=-1;
		data=new int[max];
	}

	void adddqr(int e)
	{
		if(rear==-1)
		{
			rear=0;
			front=0;
			data[0]=e;
		}
		else
		{
			rear=(rear+1)%max;
			data[rear]=e;
		}
	}

	void adddqf(int e)
	{
		int j;
		if(isfullq())
			cout<<"Queue is full";
		else if(rear!=max and front==0)
		{
			for(j=rear;j>front;j--)
			{
				data[j+1]=data[j ];
			}
			data[1]=e;
			rear=j;
		}
		else
			data[front--]=e;
	}

	void deletedqf()
	{
		if(front==rear)
		{
			rear=-1;
			front=-1;
		}
		else
			front=(front+1)%max;
	}

	void deletedqr()
	{
		if(isemptyq())
			cout<<"Queue is empty";
		else
			rear--;
		if(front==rear)
		{
			front=0;
			rear=0;
		}
	}

	int isemptyq()
	{
		if(rear==-1)
			return 1;
		else
			return 0;
	}

	int isfullq()
	{
		if(front==(rear+1)%max)
			return 1;
		else
			return 0;
	}


	void displayq()
	{
		int i;
		for(i=front;i<=rear;i++)
		{
			cout<<data[i]<<"\t";
		}
	}
};

int main()
{
	int x,y,m,dat;

	cout<<"Enter the no. of data to be stored";
	cin>>m;
	deque d(m);
	do
	{
		cout<<"Press 1 to add element at front.\nPress 2 to add element at rear.\nPress 3 to delete element from front.\nPress 4 to delete element from rear.\nPress 5 to display.\n ";
		cin>>x;
		switch(x)
		{
		case 1:
			cout<<"Enter data: ";
			cin>>dat;
			d.adddqf(dat);
			break;
			case 2:
				cout<<"Enter data: ";
				cin>>dat;
				d.adddqr(dat);
				break;
			case 3:
				d.deletedqf();
				break;
			case 4:
				d.deletedqr();
				break;
			case 5:
				d.displayq();
				break;
			default:
				cout<<"Enter appropriate value";
				break;
		}
		cout<<"\nPress 1 to continue.\tPress 2 to exit";
		cin>>y;
	}
	while(y==1);
	return 0;
}
