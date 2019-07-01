#include<iostream>
using namespace std;
class matrix
{
int a[10][10],b[10][10],c[10][10],d[10][10],r1,c1,r2,c2,i,j,k;
public:
void getsize()
{
cout<<"Enter the number of rows and columns of first matrix  ";
cin>>r1>>c1;
cout<<"Enter the number of rows and coloumns of second matrix ";
cin>>r2>>c2;
}

void getdata()
{
cout<<endl<<"Enter the elements of matrix 1 : ";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cin>>a[i][j];
}}

cout<<endl<<"Enter the elements of matrix 2 : ";
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
{
cin>>b[i][j];
}}

}

void display()
{
cout<<endl<<"Matrix 1 is : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cout<<a[i][j]<<"\t";
}
cout<<"\n";
}

cout<<endl<<"Matrix 2 is : \n";
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
{
cout<<b[i][j]<<"\t";
}
cout<<"\n";
}
}

void addition()
{
if(r1==r2 || c1==c2)
{
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{

c[i][j]=a[i][j]+b[i][j];
}
}
cout<<"\nAddition of two matrices is : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cout<<c[i][j]<<"\t";
}
cout<<"\n";
}
}
else
cout<<endl<<"Addition is not possible as order is not same!!!\n\n";
}

void sub()
{
if(r1==r2 || c1==c2)
{
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{

c[i][j]=a[i][j]-b[i][j];
}
}
cout<<"\nSubstraction of two matrices is : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
cout<<c[i][j]<<"\t";
}
cout<<"\n";
}
}
else
cout<<endl<<"Substraction is not possible as order is not same!!!\n\n";
}

void multi()
{
if(c1==r2)
{
int sum;
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{
sum=0;
for(k=0;k<c1;k++)
{  sum=sum+ a[i][k]*b[k][j];
}c[i][j]=sum;

}
}

cout<<"\nMultiplication of two matrices is : \n";
for(i=0;i<r1;i++)
{
for(j=0;j<c2;j++)
{
cout<<c[i][j]<<"\t";
}
cout<<"\n";
}
}
else
cout<<endl<<"Multiplication is not possible as coloumns of first matrix are not same as rows of second matrix!!!\n\n";
}

void transpose()
{
int input,temp;
cout<<"Choose the matrix for transpose : 1.Matrix A\n2.Matrix B";
cin>>input;
switch(input)
{
case 1:
for(i=0;i<r1;i++)
{
for(j=0;j<c1;j++)
{ d[j][i]=a[i][j];
}
}

cout<<"\nTranspose of matrix is : \n";
for(j=0;j<r1;j++)
{
for(i=0;i<c1;i++)
{
cout<<d[j][i]<<"\t";
}
cout<<"\n";
}
break;
case 2:
for(i=0;i<r2;i++)
{
for(j=0;j<c2;j++)
{ d[j][i]=b[i][j];
}
}

cout<<"\nTranspose of matrix is : \n";
for(j=0;j<r2;j++)
{
for(i=0;i<c2;i++)
{
cout<<d[j][i]<<"\t";
}
cout<<"\n";
}
break;
default:
cout<<"\nCheck your INPUT!!!";

}
}

void triangular()
{
int c=0;
for(i=0;i<r1;i++)
	{
	for(j=0;j<c1;j++)

		if(i>j)
		{
			if(a[i][j]==0)
			{
			c=c+1;
}
}
}
if(c==(r1*(r1-1))/2)
{
cout<<"matrix A is an upper triangular matrix"<<endl;
}
else
cout<<"Matrix A is not an upper triangular matrix"<<endl; 
}
void trace()
{
int tr=0;
for(i=0;i<r1;i++)
	{
	for(j=0;j<c1;j++)
{
	if(i==j)
{
	tr=tr+a[i][j];
}
}
}
cout<<"Trace of matrix A is : "<<tr<<endl;
}
bool saddle()
{
  // Process all rows one by one
    for (int i = 0; i < r1; i++)
    {
        // Find the minimum element of row i.
        // Also find column index of the minimum element
        int min_row = a[i][0], col_ind = 0;
        for (int j = 1; j < c1; j++)
        {
            if (min_row > a[i][j])
            {
                min_row = a[i][j];
                col_ind = j;
            }
        }
 
        // Check if the minimum element of row is also
        // the maximum element of column or not
        int k;
        for (k = 0; k < c1; k++)
 
            // Note that col_ind is fixed
            if (min_row < a[k][col_ind])
                break;
 
        // If saddle point is present in this row then
        // print it
        if (k == r1)
        {
           cout << min_row<<" is minimum in its row "<<i+1<<" and maximum in its column "<<col_ind+1<<"\n";
return true;
        }
    }
 
    return false;
}
};

int main()
{
int in,a;
matrix x;
x.getsize();
x.getdata();
x.display();
m:cout<<"Select the Operation :\n1.Addition of two matrices\n2.Substraction of two matrices\n3.Multiplication of two matrices\n4.Transpose of matrix\n5.Check if UT or not\n6.Calculate Trace of matrix A\n7.saddle point of First matrix\n";
cin>>in;
switch(in)
{
case 1:
x.addition();
break;
case 2:
x.sub();
break;
case 3:
x.multi();
break;
case 4:
x.transpose();
break;
case 5:
x.triangular();
break;
case 6:
x.trace();
break;
case 7:
if(x.saddle()==false)
    cout << "No Saddle Point ";
break;
default:
cout<<endl<<"Check your INPUT!!!";
}
cout<<"-------------------------------------------------\n";
cout<<"continue?(1 or 0)";
cin>>a;
if(a==1)
goto m;
return 0;
}

