/*
 * stack.cpp
   Assignment 7 : In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].
   Write C++ program using stack to check whether given expression is well parenthesized or not.
 * Name: weirdgourmet
 */

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

	class stack
	{
	private :
		char c[100];
		int max,top;
	public :
		stack(int m)
		{
			if (m > 1)
				max = m;
			else
			{
				cout<<"Capacity should be a positive natural number.";
				return;
			}
			top = -1;
		}
		void push(char a)
		{
			if (top == -1)
			{
				c[0] = a;
				top = 0;
			}
			else
			{
				if(top < max-1)
				{
					top = top + 1;
					c[top] = a;
				}
				//else
				//	cout<<"Error : Capacity full!"<<endl;
			}
		}
		char pop ()
		{
			if (top == -1)
			{
				//cout<<"Error : The stack is empty.";
				char b = '#';
				return b;
			}
			else
			{
				if (top < max)
				{
					char t = c[top];
					c[top] = '\0';
					top = top - 1;
					return t;
				}
				/*if (top == 0 || top == max+1)
				{
					cout<<"Error : The stack is empty."<<endl;
				}*/
			}
		}
		char topelement ()
		{
			if (top == -1)
			{
				//cout<<"Error : The stack is empty.";
				char b = '#';
				return b;
			}
			char t = c[top];
			return t;
		}
		int isempty()
		{
			if(top == -1)
			{
				return 1;
			}
			else
				return 0;
		}
		int isfull()
		{
			if(top == max-1)
			{
				return 1;
			}
			else
				return 0;
		}
		void display()
		{
			int a = top;
			if (a == -1)
			{
				cout<<"Error : The stack is empty."<<endl;
				return;
			}
			while (a != -1)
			{
				cout<<c[a]<<"\n";
				a = a - 1;
			}
		}
	};
	class expression
	{
		char expr[50];

	public :
		expression()
		{
			expr[0] = '\0';
		}
		expression(char *s)
		{
			strcpy(expr,s);
		}
		int IsValid()
		{
			int i, c1 = 0, c2 = 0, c3 = 0;
			stack exp(50);
			for (i = 0; expr[i] != '\0'; i++)
			{
				if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
				{
					exp.push(expr[i]);
					if (expr[i] == '(')
						c1++;
					if (expr[i] == '[')
						c2++;
					if (expr[i] == '{')
						c3++;
				}
				if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
				{
					exp.pop();
					if (expr[i] == ')')
						c1--;
					if (expr[i] == ']')
						c2--;
					if (expr[i] == '}')
						c3--;
				}
			}
			int a = exp.isempty();
			if (a == 0)
			{
				cout<<"Error : Number of brackets in the expression.\n";
			}
			if (c1 != 0)
			{
				cout<<"Error : Round Bracket '()'.\n";
				return -1;
			}
			else if (c2 != 0)
			{
				cout<<"Error : Square Bracket '[]'.\n";
				return -1;
			}
			else if (c3 != 0)
			{
				cout<<"Error : Curly Bracket '{}'.\n";
				return -1;
			}
			else
				return 0;


		}


	};
	int main ()
	{
		char e[50];
		int choice;
		do{
		cout<<"Enter the expression : ";
		cin>>e;
		expression obj(e);
		int result = obj.IsValid();
		if (result == 0)
			cout<<"The expression is balanced. No Errors!\n";
		cout<<"Press 0 to exit \t Press 1 to continue \t ";
		cin>>choice;
		}while (choice == 1);
		return 0;
	}

/*
  OUTPUT :


*/
 */
