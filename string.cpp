#include <iostream>
#include <string>
using namespace std;
int i;
class str
{
	char a[20];
public:
	str()
	{
		for(i=0;a[i]!='\0';i++)
			a[i]=0;
	}

	str operator=(str x)
	{
	    str temp;
		for(i=0;x.a[i]!='\0';i++)
			temp.a[i]=x.a[i];
			return temp;
	}
	void getstring()
	{
		cout<<"\nEnter a string : ";
		cin>>a;
		int m=0;
		for(i=0;a[i]!='\0';i++)
			{
				m++;
			}
	}
	void getstring1( str &b)
	{


	    cin>>b.a;

	}
	void display();
	void copy(str);
	int substring(str);
	void concatenate(str);
	int equal(str);
	void reverse();
	int length();
	int freq(char);
	void chardel(char);
	void replace(int p);
	int palindrome();
	int substring();
	void delsub(int,int);
};

void str::display()
{
	cout<<"\nString is : ";
	for(i=0;a[i]!='\0';i++)
		cout<<a[i];
		cout<<"\n";

}

void str::copy(str b)
{
	for(i=0;b.a[i]!='\0';i++)
	{
		a[i]=b.a[i];
	}
	cout<<"\nCopied string is : ";
	for(i=0;b.a[i]!='\0';i++)
	{
		cout<<a[i];
	}
	cout<<"\n";
}
void str::concatenate(str b)
{
    str c;
	int n=0,m=0;

	for(i=0;b.a[i]!='\0';i++)
	{
		n++;
	}
	for(i=0;a[i]!='\0';i++)
	{
		m++;
	}
	for(i=0;a[i]!='\0';i++)
	{
		c.a[i]=a[i];
	}
	c.a[i]=' ';
	for(i=0;i<n;i++)
	{
		c.a[m+i]=b.a[i];
	}
	c.a[m+i]='\0';
	cout<<"\nConcatenated string is : ";
    for(i=0;c.a[i]!='\0';i++)
	{
		cout<<c.a[i];
	}

}
int str::equal(str B)
{
	int n=0,m=0,l;

	for(i=0;B.a[i]!='\0';i++)
	{
		n++;
	}
	for(i=0;a[i]!='\0';i++)
	{
		m++;
	}
	if(m==n)
	{
		for(i=0;a[i]!='\0';i++)
		{

			if(a[i]==B.a[i])
				l++;
			else if(a[i]!=B.a[i])
				return 0;

		}
	}
	else if(m!=n)
        return 0;

	if(l==n)
		return 1;

}

void str::reverse()
{
	char temp;
	int i=0,j;
	j=length()-1;
	while(i<j)
	{
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		i++;
		j--;

	}
	for(i=0;a[i]!='\0';i++)
			{
				cout<<a[i];
			}


	/*char d[20];

	for(i=0;a[i]!='\0';i++)
		{
			d[i]=a[m-i-1];
		}
	cout<<"\nReverse is : ";

	cout<<"\n";*/
}
int str::length()
{
	int m=0;
	for(i=0;a[i]!='\0';i++)
		m++;
	return m;
}
int str::freq(char c)
{
    int n=0;

	for(i=0;a[i]!='\0';i++)
		{
			if(a[i]==c)
				n++;
            else
                continue;
		}
	cout<<"\nFrequency of character "<<c<<" in string : ";
	return n;
}
int str::palindrome()
{
   int i,j,l,c=1;


   for(i=0;a[i]!='\0';i++);
	   l=i;
   	   i--;
   for(j=0;j<(l/2);j++)
   {
	   if(a[j]!=a[i])
		   c=0;
	   i--;
   }
   return c;


	/*for(i=0;i<m;i++)
		{
		if(i<=m-i-1)
		{
			if(a[i]!=a[m-i-1])
			{
				break;
			}
		}

		}
		cout<<"\nString is a palindrome\n";

	if(i<=m-i-1)
	{
		cout<<"\nString is not a palindrome\n";
	}*/
}
void str::chardel(char c)
{

	cout<<"\nString after deletion of character : ";
	for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=c)
        {
            cout<<a[i];
        }
        else
            continue;
    }


	cout<<"\n";
}
void str::replace(int p)
{
	char d[10];
	int n=0;
	cout<<"\nEnter string to replace : ";
	cin>>d;
	for(i=0;d[i]!='\0';i++)
		{
			n++;
		}
	for(i=0;i<n;i++)
		{
			a[p+i-1]=d[i];
		}
	cout<<"\nString after replacement : ";
	for(i=0;a[i]!='\0';i++)
		{
			cout<<a[i];
		}
}

int str::substring(str sub)
		{

			int j,i,c=0,n,t=0;
			for(i=0;sub.a[i]!='\0';i++);
			n=i;

			for(j=0;a[j]!='\0';j++)
			{
				t=0;
				for(i=0;i<n;i++)
				{
					if(a[j]!=sub.a[i])
					{
						t=1;
						break;
					}
					else
					j++;

				}
				if(t==0)
				c++;
			}
			return c;
		}

void str::delsub(int st,int l)
{

    for(i=0;a[i]!='\0';i++)
	{
		if((i+1)==st)
		{
			i=i+l;
		}
		cout<<a[i];
	}
}

int main()
{
    str o,b,B,c,sub;
    char ans;
    o.getstring();
    o.display();
    do
    {

    int ch;

    cout<<"\nEnter your choice.\n"<<endl<<"\t1.Copy the string."<<endl<<"\t2.Concatenate another string."<<endl<<"\t3.Find the sub string in given string."<<endl<<"\t4.Compare two strings."<<endl<<"\t5.Reverse the string."<<endl<<"\t6.Find the frequency of character."<<endl<<"\t7.To delete character."<<endl<<"\t8.To check whether the string is palindrome is not."<<endl<<"\t9.Length of string."<<endl<<"\t10.Replace a character."<<endl<<"\t11.Display string."<<endl<<"\t12.Delete sub-string."<<endl;
    cin>>ch;


    switch(ch)
    {
    case 1:
        cout<<"\nEnter any string to copy : ";
        o.getstring1(c);
        o.copy(c);
        break;
    case 2:
        cout<<"\nEnter any string to concatenate : ";
        o.getstring1(b);
        o.concatenate(b);
	    cout<<"\n";
        break;
    case 3:
    	int z;
    	cout<<"Enter sub string : ";
    	o.getstring1(sub);
    	z=o.substring(sub);
    	if(z==0)
    		cout<<"\nSub-string not present.\n";
    	else
    		cout<<"\nSub-string is pesent "<<z<< " times."<<"\n";

        break;
    case 4:
    	int s;
    	cout<<"\nEnter any string to compare : ";
    	o.getstring1(B);
        s=o.equal(B);

         if(s==0)
        	cout<<"\nStrings are not equal\n";
        else
            cout<<"\nStrings are equal\n";

        break;
    case 5:
        o.reverse();
        break;
    case 6:
    	int r;
    	char ch;

	cout<<"\nEnter any character to check frequency : ";
	cin>>ch;
        r=o.freq(ch);
        cout<<r<<endl;
        break;
    case 7:
        	char c;
	cout<<"\nEnter which character you want to delete : ";
	cin>>c;
        o.chardel(c);
        break;
    case 8:
    	int b;
        b=o.palindrome();
        if(b==1)
        	cout<<"\nString is palindrome\n";
        else if(b==0)
        	cout<<"\nStrings is not palindrome\n";
        break;
    case 9:
    	int q;
        q=o.length();
        cout<<"\nLength is : "<<q<<endl;

        break;
    case 10:
        int p;
        cout<<"enter position where you want replace\n";
        cin>>p;
        o.replace(p);
        break;
    case 11:
    	o.display();
    	break;
    case 12:
           int st,l;
    cout<<"\n enter starting point and length of sub-string to be deleted. ";
	cin>>st>>l;
        o.delsub(st,l);
        break;
    default:
        cout<<"\n\tEnter valid choice.\n";

    }

    cout<<"\n\tDo you want to continue?(y/n) ";
    cin>>ans;
    }

    while(ans=='y');


	return 0;
}

