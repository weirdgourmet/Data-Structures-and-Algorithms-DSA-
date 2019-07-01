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
	
	void Quicksort (int left, int right)
	{
		if(left < right)
		{
			float pivot = Percentage[right];
			int i = left-1;
			for (int j = left; j<= right-1; j++)
			{
				if(Percentage[j] <= pivot)
				{
					i++;
					swap(Percentage[i],Percentage[j]);
				}
			}
			swap(Percentage[i+1],Percentage[right]);
			int p = i+1;
			Quicksort (left, p-1);
			Quicksort (p+1, right);
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
	cout<<endl<<"The percentages of students : "<<endl;
	obj.Display();
	int pos = 0;
	obj.Quicksort(pos,num-1);
	cout<<"The students who topped are :"<<endl;
	cout<<"Rank"<<setw(20)<<"Percentage"<<endl;
	obj.Top5();
	return 0;
}