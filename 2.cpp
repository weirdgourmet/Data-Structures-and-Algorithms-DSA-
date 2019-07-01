//============================================================================
// Name        : Matrix.cpp
// Author      : weirdgourmet
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
public:
	int a[10][10],b[10][10],c[10][10];
	int i,j,k,p,q,r,s,sum=0,small[10],big[10],min,max,count=0;
	void input(int p,int q,int r,int s)
	{
		for(i=0;i<p;i++)
				{
				    for(j=0;j<q;j++)
				    {
				    	cout<<"enter the element of a "<<i+1<<j+1<<endl;
				        cin>>a[i][j];
				    }
				}
				for( i=0;i<r;i++)
				{
				    for( j=0;j<s;j++)
				    {
				    	cout<<"enter the element of b "<<i+1<<j+1<<endl;
				        cin>>b[i][j];
				    }
				}
	};
	void output(int p,int q)
	{
		  for(i=0;i<p;i++)
		  {
			  cout<<endl;
			  for(j=0;j<q;j++)
			  {
				  cout<<c[i][j]<<"\t"<<endl;
			  }
		  }
	};
	void add(int p,int q,int r,int s)
	{
		if(p==r&&q==s)
		{
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		  for(i=0;i<p;i++)
		  {
			  cout<<endl;
			  for(j=0;j<q;j++)
			  {
				  cout<<c[i][j]<<"\t";
			  }
			  cout<<endl;
		  }
	}
	else
		cout<<"addition is not possible"<<endl;
	};
	void sub(int p,int q,int r,int s)
	{
		if(p==r&&q==s)
		{
		for(i=0;i<p;i++)
				{
					for(j=0;j<q;j++)
					{
						c[i][j]=a[i][j]-b[i][j];
					}
				}
		  for(i=0;i<p;i++)
		  {
			  cout<<endl;
			  for(j=0;j<q;j++)
			  {
				  cout<<c[i][j]<<"\t";
			  }
			  cout<<endl;
		  }
		}
		else
			cout<<"subtraction is not possible "<<endl;
	};
	void mul(int p,int q,int r, int s)
	{
		if(q==r)
		{
		c[i][j]=0;
		for(i=0;i<p;i++)
		{
			for(j=0;j<s;j++)
			{
				for(k=0;k<q;k++)
				{
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
				}
			}
		}
		  for(i=0;i<p;i++)
		  {
			  cout<<endl;
			  for(j=0;j<s;j++)
			  {
				  cout<<c[i][j]<<"\t";
			  }
			  cout<<endl;
		  }
		}
		else
			cout<<"multiplication is not possible"<<endl;
	};
	void transpose(int p,int q)
	{
		for(i=0;i<p;i++)
		{
			for(j=0;j<q;j++)
			{
				a[j][i]=a[i][j];
			}
		}
		for(i=0;i<p;i++)
		{
			cout<<endl;
			for(j=0;j<p;j++)
			{
				cout<<a[i][j]<<"\t";
			}
			cout<<endl;
		}
	};
   void trace(int p, int q)
    {
    	if(p==q)
    	{
    	for(i=0;i<p;i++)
    	{
    		for(j=0;j<q;j++)
    		{
        			if(i==j)
        			{
    				sum=sum+a[i][j];
        			}
    		}
    	}
    	cout<<"Trace of matrix is "<<sum<<endl;
    	}
    	else
    		cout<<"not a square matrix "<<endl;
    };
   void saddle(int p,int q)
   {
	    for(i=0;i<p;i++)
	    {
	    	small[i]=a[i][0];
	    	for(j=0;j<q;j++)
	    	{
	    		if(small[i]>a[i][j])
	    			small[i]=a[i][j];
	    	}
	    }
	    for(i=0;i<q;i++)
	    {
	    	big[i]=a[0][i];
	    	for(j=0;j<p;j++)
	    	{
	    		if(big[i]<a[j][i])
	    			big[i]=a[j][i];
	    	}
	    }
	    max=small[0];
	    for(i=0;i<p;i++)
	  	{
	    	if(max<small[i])
	    		max=small[i];
	    }
	    min=big[0];
	    for(i=0;i<q;i++)
	    {
	    	if(min>big[i])
	    		min=big[i];
	    }
	    	if(min==max)
	    		cout<<"saddle point is"<<max<<endl;
	    	else
	    		cout<<"Not saddle point"<<endl;
   };
   void upper(int p,int q)
   {
   for(i=1;i<p;i++)
   {
	   for(j=0;j<i;j++)
	   {
		   if(a[i][j]==0)
			  count++;
	   }
   }
   if(count==3)
	   cout<<endl<<"matrix is upper triangular"<<endl;
   };
};
int main()
{
	int m1,n1,m2,n2;
	cout<<"Enter the rows and column of matrix 1"<<endl;
			cin>>m1>>n1;
	cout<<"Enter the rows and column of matrix 2"<<endl;
				cin>>m2>>n2;
 matrix mat;
 mat.input(m1,n1,m2,n2);
 mat.add(m1,n1,m2,n2);
 cout<<endl;
 mat.sub(m1,n1,m2,n2);
 cout<<endl;
 mat.mul(m1,n1,m2,n2);
 cout<<endl;
 mat.transpose(m1,n1);
 cout<<endl;
 mat.trace(m1,n1);
 cout<<endl;
 mat.saddle(m1,n1);
 cout<<endl;
 mat.upper(m1,n1);
 cout<<endl;
 return 0;
}
