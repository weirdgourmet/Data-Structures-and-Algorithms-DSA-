/*
* icecream.cpp
	Name: weirdgourmet

*  Assignment 6: Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students
  like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display vi. Set of
  students who like either vanilla or butterscotch or both vii. Set of students who like both vanilla and butterscotch
  viii. Set of students who like only vanilla not butterscotch ix. Set of students who like only butterscotch not
  vanilla x. Number of students who like neither vanilla nor butterscotch.
 */

#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class node
	{
	private:
		char name[20];
		int Roll_No;
		node *next;
	public:
		node()
		{
			name[0] = '\0';
			Roll_No = 0;
			next = NULL;
		}
		node(char* s, int p)
		{
			strcpy(name,s);
			Roll_No = p;
			next = NULL;
		}
		friend class List;

	};
	class List
	{
	private:
		node *head;
	public:
		List()
		{
			head = NULL;
		}
		void InsertStudent (char *s, int p)
		{
			if (head == NULL)
			{
				node *n = new node(s,p);
				n->next = NULL;
				head = n;
			}
			else
			{
				node *n = new node(s,p);
				node *h = head;
				head = n;
				n->next = h;
			}
		}
		void DisplayList ()
		{
			cout<<setw(20)<<"Roll. No."<<setw(20)<<"Name"<<endl;
			node *q = head;
			while (q != NULL)
			{
				cout<<setw(20)<<q->Roll_No<<setw(20)<<q->name<<"\n";
				q = q->next;
			}
		}
		List Union (List l)
		{
			List U;
			node *h = head;
			while (h != NULL)
			{
				U.InsertStudent(h->name,h->Roll_No);
				h = h->next;
			}
			int flag;
			node *q = l.head;
			for (q=l.head; q != NULL; q=q->next)
			{
				flag = 0;
				for (h=head; h != NULL; h=h->next)
				{
					if(q->Roll_No == h->Roll_No)
					{
						flag = flag + 1;
						break;
					}
				}
				if(flag == 0)
					U.InsertStudent(q->name,q->Roll_No);
			}
			return U;
		}
		List Intersection (List l)
		{
			List I;
			int flag;
			node *h = head;
			node *q = l.head;
			for (q=l.head; q != NULL; q=q->next)
			{
				flag = 0;
				for (h=head; h != NULL; h=h->next)
				{
					if(q->Roll_No == h->Roll_No)
					{
						flag = flag + 1;
						break;
					}
				}
				if(flag != 0)
					I.InsertStudent(q->name,q->Roll_No);
			}
			return I;
		}
		List AnegB (List l)
		{
			List Diff;
			int flag;
			node *h = head;
			node *q = l.head;
			for (h=head; h != NULL; h=h->next)
			{
				flag = 0;
				for (q=l.head; q != NULL; q=q->next)
				{
					if(q->Roll_No == h->Roll_No)
					{
						flag = flag + 1;
						break;
					}
				}
				if(flag == 0)
					Diff.InsertStudent(h->name,h->Roll_No);
			}
			return Diff;
		}
		List BnegA (List l)
		{
			List Diff;
			int flag;
			node *h = head;
			node *q = l.head;
			for (q=l.head; q != NULL; q=q->next)
			{
				flag = 0;
				for (h=head; h != NULL; h=h->next)
				{
					if(q->Roll_No == h->Roll_No)
					{
						flag = flag + 1;
						break;
					}
				}
				if(flag == 0)
					Diff.InsertStudent(q->name,q->Roll_No);
			}
			return Diff;
		}

		int TotalMembers()
		{
			node *n = head;
			int count = 0;
			while (n != NULL)
			{
				count++;
				n = n->next;
			}
			return count;
		}
	};
	int main()
	{
		int TotalStud, StudVan, StudBS;
		int i,j,k,roll;
		char s[20];
		cout<<"Enter the total number of students: ";
		cin>>TotalStud;
		cout<<"Enter the number of students who like VANILLA: ";
		cin>>StudVan;
		cout<<"Enter the number of students who like BUTTERSCOTCH: ";
		cin>>StudBS;
		if (StudVan > TotalStud || StudBS > TotalStud)
		{
			cout<<"Error : Number of students exceeds the total number of students. "<<endl;
			return 0;
		}
		List Vanilla;
		List Butterscotch;
		for (i = 0; i<StudVan; i++)
		{
			cout<<endl<<"Vanilla : Enter details for Student "<<i+1<<": \n";
			cout<<"Enter name: ";
			cin>>s;
			cout<<"Enter Roll No: ";
			cin>>roll;
			Vanilla.InsertStudent(s,roll);
		}
		for (i = 0; i<StudBS; i++)
		{
			cout<<endl<<"Butterscotch : Enter details for Student "<<i+1<<": \n";
			cout<<"Enter name: ";
			cin>>s;
			cout<<"Enter Roll No: ";
			cin>>roll;
			Butterscotch.InsertStudent(s,roll);
		}
		List U = Vanilla.Union(Butterscotch);
		int a = U.TotalMembers();
		if (a > TotalStud)
		{
			cout<<"Error : Number of students in union exceeds the total number of students. "<<endl;
                        return 0;
		}
		int choice;
		int menu;
		do{
			cout<<endl<<"Menu : "<<endl;
			cout<<"Press 1 to display the set of students who like either vanilla or butterscotch or both."<<endl;
			cout<<"Press 2 to display the set of students who like both vanilla and butterscotch."<<endl;
			cout<<"Press 3 to display the set of students who like only vanilla and not butterscotch."<<endl;
			cout<<"Press 4 to display the set of students who like only butterscotch and not vanilla."<<endl;
			cout<<"Press 5 to compute the number of students who like neither vanilla nor butterscotch. \t";
			cin>>menu;
			switch(menu)
			{
				case 1 :
				{
					/*cout<<endl<<"The set of students who like VANILLA :"<<endl;
					Vanilla.DisplayList();
					cout<<endl<<"The set of students who like BUTTERSCOTCH : "<<endl;
					Butterscotch.DisplayList();
					List U = Vanilla.Union(Butterscotch);
					int a = U.TotalMembers();
					if (a > TotalStud)
					{
						cout<<"Error : Number of students in union exceeds the total number of students. "<<endl;
						return 0;
					}*/
					cout<<endl<<"The set of students who like either VANILLA or BUTTERSCOTCH or both :"<<endl;
					U.DisplayList();
					break;
				}
				case 2 :
				{
					/*cout<<endl<<"The set of students who like VANILLA :"<<endl;
					Vanilla.DisplayList();
					cout<<endl<<"The set of students who like BUTTERSCOTCH : "<<endl;
					Butterscotch.DisplayList();*/
					List I = Vanilla.Intersection(Butterscotch);
					cout<<endl<<"The set of students who like both VANILLA and BUTTERSCOTCH :"<<endl;
					I.DisplayList();
					break;
				}
				case 3 :
				{
					/*cout<<endl<<"The set of students who like VANILLA :"<<endl;
					Vanilla.DisplayList();
					cout<<endl<<"The set of students who like BUTTERSCOTCH : "<<endl;
					Butterscotch.DisplayList();*/
					List A = Vanilla.AnegB(Butterscotch);
					cout<<endl<<"The set of students who like only VANILLA and not BUTTERSCOTCH :"<<endl;
					A.DisplayList();
					break;
				}
				case 4 :
				{
					/*cout<<endl<<"The set of students who like VANILLA :"<<endl;
					Vanilla.DisplayList();
					cout<<endl<<"The set of students who like BUTTERSCOTCH : "<<endl;
					Butterscotch.DisplayList();*/
					List A = Vanilla.BnegA(Butterscotch);
					cout<<endl<<"The set of students who like only BUTTERSCOTCH and not VANILLA :"<<endl;
					A.DisplayList();
					break;
				}
				case 5 :
				{
					List U = Vanilla.Union(Butterscotch);
					int a = U.TotalMembers();
					int b = TotalStud - a;
					//cout<<endl<<"The total number of students is "<<TotalStud<<endl;
					//cout<<"The number of students who like either vanilla or butterscotch or both are "<<a<<endl;
					cout<<"The number of students who like neither vanilla nor butterscotch are "<<b<<endl;
					break;
				}
				default :
				{
					cout<<"Error : Invalid Choice!"<<endl;
				}
			}
		cout<<"Press 0 to EXIT. \t Press 1 to CONTINUE. \t ";
		cin>>choice;
		}while (choice == 1);

return 0;
}

/*
  OUTPUT :

Enter the total number of students: 5
Enter the number of students who like VANILLA: 3
Enter the number of students who like BUTTERSCOTCH: 3

Vanilla : Enter details for Student 1:
Enter name: aalok
Enter Roll No: 1

Vanilla : Enter details for Student 2:
Enter name: abizer
Enter Roll No: 2

Vanilla : Enter details for Student 3:
Enter name: anuj
Enter Roll No: 4

Butterscotch : Enter details for Student 1:
Enter name: aalok
Enter Roll No: 1

Butterscotch : Enter details for Student 2:
Enter name: abizer
Enter Roll No: 2

Butterscotch : Enter details for Student 3:
Enter name: adeep
Enter Roll No: 3

Menu :
Press 1 to display the set of students who like either vanilla or butterscotch or both.
Press 2 to display the set of students who like both vanilla and butterscotch.
Press 3 to display the set of students who like only vanilla and not butterscotch.
Press 4 to display the set of students who like only butterscotch and not vanilla.
Press 5 to compute the number of students who like neither vanilla nor butterscotch. 	1

The set of students who like VANILLA :
           Roll. No.                Name
                   4                anuj
                   2              abizer
                   1               aalok

The set of students who like BUTTERSCOTCH :
           Roll. No.                Name
                   3               adeep
                   2              abizer
                   1               aalok

The set of students who like either VANILLA or BUTTERSCOTCH or both :
           Roll. No.                Name
                   3               adeep
                   1               aalok
                   2              abizer
                   4                anuj
Press 0 to EXIT 	 Press 1 to CONTINUE 	 1

Menu :
Press 1 to display the set of students who like either vanilla or butterscotch or both.
Press 2 to display the set of students who like both vanilla and butterscotch.
Press 3 to display the set of students who like only vanilla and not butterscotch.
Press 4 to display the set of students who like only butterscotch and not vanilla.
Press 5 to compute the number of students who like neither vanilla nor butterscotch. 	2

The set of students who like VANILLA :
           Roll. No.                Name
                   4                anuj
                   2              abizer
                   1               aalok

The set of students who like BUTTERSCOTCH :
           Roll. No.                Name
                   3               adeep
                   2              abizer
                   1               aalok

The set of students who like both VANILLA and BUTTERSCOTCH :
           Roll. No.                Name
                   1               aalok
                   2              abizer
Press 0 to EXIT 	 Press 1 to CONTINUE 	 1

Menu :
Press 1 to display the set of students who like either vanilla or butterscotch or both.
Press 2 to display the set of students who like both vanilla and butterscotch.
Press 3 to display the set of students who like only vanilla and not butterscotch.
Press 4 to display the set of students who like only butterscotch and not vanilla.
Press 5 to compute the number of students who like neither vanilla nor butterscotch. 	3

The set of students who like VANILLA :
           Roll. No.                Name
                   4                anuj
                   2              abizer
                   1               aalok

The set of students who like BUTTERSCOTCH :
           Roll. No.                Name
                   3               adeep
                   2              abizer
                   1               aalok

The set of students who like only VANILLA and not BUTTERSCOTCH :
           Roll. No.                Name
                   4                anuj
Press 0 to EXIT 	 Press 1 to CONTINUE 	 1

Menu :
Press 1 to display the set of students who like either vanilla or butterscotch or both.
Press 2 to display the set of students who like both vanilla and butterscotch.
Press 3 to display the set of students who like only vanilla and not butterscotch.
Press 4 to display the set of students who like only butterscotch and not vanilla.
Press 5 to compute the number of students who like neither vanilla nor butterscotch. 	4

The set of students who like VANILLA :
           Roll. No.                Name
                   4                anuj
                   2              abizer
                   1               aalok

The set of students who like BUTTERSCOTCH :
           Roll. No.                Name
                   3               adeep
                   2              abizer
                   1               aalok

The set of students who like only BUTTERSCOTCH and not VANILLA :
           Roll. No.                Name
                   3               adeep
Press 0 to EXIT 	 Press 1 to CONTINUE 	 1

Menu :
Press 1 to display the set of students who like either vanilla or butterscotch or both.
Press 2 to display the set of students who like both vanilla and butterscotch.
Press 3 to display the set of students who like only vanilla and not butterscotch.
Press 4 to display the set of students who like only butterscotch and not vanilla.
Press 5 to compute the number of students who like neither vanilla nor butterscotch. 	5

The total number of students is 5
The number of students who like either vanilla or butterscotch or both are 4
The number of students who like neither vanilla nor butterscotch are 1
Press 0 to EXIT 	 Press 1 to CONTINUE 	 0

*/
