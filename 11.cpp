Name: weirdgourmet

#include<iostream>
#include<string>
using namespace std;

class student
{
	private :
		int *Roll_No;
		int max;
	public :
		student (int m)
		{
			Roll_No = new int[m];
			max = m;
		}
		inline void Store (int pos, int r)
		{
			Roll_No[pos] = r; 
		}
		void Display()
		{
			cout<<"The students who attended training program are : "<<endl;
			for (int j=0; j<max ; j++)
				cout<<Roll_No[j]<<endl;
		}
		int LSearch (int n, int ele)
		{
			int i;
			for(i = 0; i<n; i++)
			{
				if(ele == Roll_No[i])
					return i+1;
			}
			return -1;
		}
		int SSearch (int n, int ele)
		{
			int i;
			Roll_No[n] = ele;
			for(i = 0; ; i++)
				if(ele == Roll_No[i])
				{
					if(i != n)
						return i+1;
					return -1;
				}
		}
};

int main ()
{
	int num,r,menu,choice;
	cout<<"Enter the number of students who attended training program : ";
	cin>>num;
	if(num<1)
	{
		cout<<"Error : Number of students should be positive integer."<<endl;
		return 0;
	}
	student obj(num);
	cout<<"Enter the Roll Number of students : "<<endl;
	for(int i=0; i<num; i++)
	{
		cout<<"Student "<<i+1<<": ";
		cin>>r;
		obj.Store(i,r);
	}
	obj.Display();
	do{
		cout<<"Press 1 for Linear Search.\nPress 2 for Sentinal Search. \t";
		cin>>menu;
		switch(menu)
		{
			case 1 :
			{
				cout<<"Enter the Roll Number : ";
				cin>>r;
				int pos = obj.LSearch(num,r);
				if(pos != -1)
					cout<<"The student has attended the seminar. Sr.No. : "<<pos<<".\n";
				else
					cout<<"The student has not attended the seminar.\n";
				break;
			}
			case 2 :
			{
				cout<<"Enter the Roll Number : ";
				cin>>r;
				int pos = obj.SSearch(num,r);
				if(pos != -1)
					cout<<"The student has attended the seminar. Sr.No. : "<<pos<<".\n";
				else
					cout<<"The student has not attended the seminar.\n";
				break;
			}
			default :
				cout<<"Error : Invalid Choice. "<<endl;
				break;
		}
		cout<<"Press 1 to continue \t Press 0 to exit \t";
		cin>>choice;
	}while(choice == 1);
}