Name: weirdgourmet

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class student
{
private:
	float *Percentage;
	int max;
public:
	student(int m)
	{
		max = m;
		Percentage = new float [m];
	}
	inline void Store (int pos, float r)
	{
		Percentage[pos] = r; 
	}
	void Display()
	{
		for (int j=0; j<max ; j++)
			cout<<Percentage[j]<<endl;
	}
	void SelectionSort()
	{
		int i,index,j;
		float large;
		for(i=max-1; i>0; i--)
		{ 
			large=Percentage[0];
			index=0;
			for (j=1;j<=i;j++)
				if(Percentage[j]>large)
				{
					large= Percentage[j];
					index=j;
				}
			Percentage[index]=Percentage[i];
			Percentage[i]=large;
		}
	}
	
	void BubbleSort()
	{
		int flag,i,j;
		float temp;
		for (i=0; i<max ;i++)
		{
			flag = 0;
			for (j=0; j<max-1; j++)
			{
				if (Percentage[j] > Percentage[j+1])
				{
					temp = Percentage[j];
					Percentage[j] = Percentage[j+1];
					Percentage[j+1] = temp;
					flag = 1;
				}
			}
			if (flag == 0)
				break;
		}
	}
	void Top5 ()
	{
		int i = max-1;
		int rank = 1;
		int count = 0;
		for (count=0; count < 5; count++)
		{
			cout<<rank<<setw(20)<<Percentage[i]<<endl;
			i--;
			rank++;
		}
	}

};

int main ()
{
	int num,menu,choice;
	float p;
	cout<<"Enter the total number of students : ";
	cin>>num;
	if(num<6)
	{
		cout<<"Error : Number of students should be greater than 5."<<endl;
		return 0;
	}
	student obj(num);
	cout<<"Enter the percentage of students : "<<endl;
	for(int i=0; i<num; i++)
	{
		cout<<"Student "<<i+1<<": ";
		cin>>p;
		obj.Store(i,p);
	}
	cout<<"The percentages of students : "<<endl;
	obj.Display();
	cout<<"Press 1 for Selection Sort.\t Press 2 for Bubble Sort. \t";
	cin>>menu;
		switch(menu)
		{
			case 1 :
			{
				obj.SelectionSort();
				cout<<"The students who topped are :"<<endl;
				cout<<"Rank"<<setw(20)<<"Percentage"<<endl;
				obj.Top5();
				break;
			}
			case 2 :
			{
				obj.BubbleSort();
				cout<<"The students who topped are :"<<endl;
				cout<<"Rank"<<setw(20)<<"Percentage"<<endl;
				obj.Top5();
				break;
			}
			default :
				cout<<"Error : Invalid Choice. "<<endl;
				break;
		}
	return 0;
}