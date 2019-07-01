/*
 * queue.cpp
 *
 *      Name: weirdgourmet

 */
#include<iostream>
using namespace std;

class queue
{
	int *job;
	int front,rear,max;
public:

	queue()
	{
		job=new int[100];
		front=0;
		rear=0;
	}

	queue(int m)
	{
		max=m;
		if(max<1)
		{
			cout<<"Capacity must be greater than 0";
		}
		else
			front=0;
	    	rear=0;
	    	job=new int[max];
	}

	void insert(int e);
	int del();
	void displayq();
	int frontq();
	int rearq();
	bool isempty();
	bool isfull();
};

int queue::del()
{
	if(isempty())
	{
		cout<<"Queue is empty";
	}
	else if(front==rear)
	{
		front=0;
		rear=0;
		front++;
	}
	else
		front++;
}

int queue:: frontq()
{
	if(isempty())
	{
		cout<<"Queue is empty";
	}
	else
		return job[front++];
}

bool queue:: isempty()
{
	if(front==rear)
		return true;
	else
		return false;
}

bool queue:: isfull()
{
	if(rear==max)
		return true;
	else
		return false;
}

void queue:: insert(int m)
{
	int i,j;
	if(isfull())
		cout<<"Queue is full";
	else
	{
    	job[rear]=m;
	    rear++;
	}
	if(rear==max && front!=0)
	{
		for(j=0,i=front;i<=rear;i++,j++)
		{
			job[j]=job[i];
		}
		front=0;
		rear=j;
	}
}

void queue:: displayq()
{
	int i;
	for(i=front;i<rear;i++)
	{
		cout<<job[i];
		cout<<"\t";
	}
}

int main()
{
	int i,m,j,z;
	cout<<"Enter the no. of jobs: ";
	cin>>m;
	queue q(m);
	do
		{
			cout<<"Press 1 to add job.\nPress 2 to delete job.\nPress 3 to display.";
			cin>>i;
			switch(i)
			{
				case 1:
					cout<<"Enter job: ";
					cin>>j;
					q.insert(j);
					break;
				case 2:
					q.del();
					break;
				case 3:
					q.displayq();
					break;
				default:
					cout<<"Enter appropriate choice.";
					break;
			}
			cout<<"Press 1 to CONTINUE.\t Press 0 to EXIT. \t";
			cin>>z;
     }while(z==1);
	 return 0;
}
