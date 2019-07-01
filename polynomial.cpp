#include <iostream>
#include<math.h>
using namespace std;

class polynomial
{
    int deg,exp;
    int coef[20];
public:
    polynomial()
    {
    for(int i=0;i<20;i++)
    coef[i]=0;
    }
   	 friend istream &operator >>(istream &in, polynomial &p)
   	{
        cout<<"Enter degree ";
        in>>p.deg;
        cout<<"Enter the coefficients from lowest to highest degree term :";
        for(int i=0;i<=p.deg;i++)
        in>>p.coef[i];
        return in;
        }
    			friend ostream &operator <<(ostream &out,polynomial &p)
   			 {
			int count=0;
		        for(int i=0;i<=p.deg;i++)
      			  {
      		  if(p.coef[i]!=0)
      		  cout<<p.coef[i]<<"x^"<<i;
			count++;
				if(count<=p.deg)
				{
				cout<<" + ";
				}
       			  }
        		return out;
   			 }
    void add(polynomial,polynomial);
    void mul(polynomial,polynomial);
    void eval();

}p[4];
	void polynomial::add(polynomial p1,polynomial p2)
	{
  	  deg=max(p1.deg,p2.deg);
   	 for(int i=0;i<=deg;i++)
	    {
	    coef[i]=p1.coef[i]+p2.coef[i];
 	   }
	}
		void polynomial::mul(polynomial p1,polynomial p2)
		{
  		  deg=p1.deg+p2.deg+1;
   		 for(int i=p1.deg;i>=0;i--)
  		  {
   		 for(int j=p2.deg;j>=0;j--)
  		  {
  		  coef[i+j]=coef[i+j]+(p1.coef[ i]*p2.coef[j]);
   		 }
  		  }
		}
void polynomial::eval()
{
int x,val=0;
cout<<"\nEnter some value of x : ";
cin>>x;
for(int i=0;i<=deg;i++)
{
coef[i]=coef[i]*pow(x,i);
val=val+coef[i];
}
cout<<"\nValue = "<<val;
}





int main()
{
polynomial p1,p2,p3,p4;
int ch,f=1;
cout<<"Enter two polynomials"<<"\n";
cout<<"For first Polynomial,";
cin>>p1;
cout<<"For second Polynomial,";
cin>>p2;
while(f!=0)
{
cout<<"\t\t\tEnter a choice :\n\t\t\t1.Add polynomials\n\t\t\t2.Multiply polynomials\n\t\t\t3.Evaluate polynomial for some x\t\n";
cin>>ch;

switch(ch)
{
case 1:
p3.add(p1,p2);
cout<<"\nAddition is : ";
cout<<p3;
break;
case 2:
p4.mul(p1,p2);
cout<<"\nMultiplication is : ";
cout<<p4;
break;
case 3:
p4.eval();
break;
default:
cout<<"INVALID CHOICE, TRY AGAIN :)"<<endl;
break;
}
cout<<"\nDo you want to continue? Press 1 to continue or 0 to terminate"<<endl;
cin>>f;
}
    return 0;
}

