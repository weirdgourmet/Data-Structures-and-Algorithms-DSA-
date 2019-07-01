#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class stack
{
char st[100];
int top;
public:
stack()
{
top=-1;
}
void push(char a)
{
	st[top] = a;
	top++;
}
void pop()
{
if (top == -1)

	{
		cout<<"expression is Not well Parenthesized!\n";
			exit(0);
	}
else
	{
		top--;
	}

}
void find_top()
{
	if (top == -1)

		cout<<"\nExpression is well Parenthesized!\n";

	else

		cout<<"Expression is not well Parenthesized!!!\n";

}
};
int main()
{
	int i;
	char a[100];
stack s;
mmm:cout<<"Enter expression\n";
cin.getline(a,100);
	for (i = 0; a[i] != '\0';i++)
	{
		if (a[i] == '(')
		{
			s.push(a[i]);

		}

		else if (a[i] == ')')

		{

			s.pop();

		}

	}

	s.find_top();
	
cout<<"\n-----------------THANK YOU!------------------\n";

return 0;
}

