#include<iostream>
using namespace std;

class Sparse
 {
	int sm[100][3];
	int NumberOfRow,NumberOfColumn;
	int noe;
	
	public:
	
	void GetData()
	 {
		cout<<"Enter no of elements u want to enter\n"; 	
		cin>>noe;
		cout<<"Enter no of Rows";
		cin>>NumberOfRow;
		cout<<"Enter no of Columns";
		cin>>NumberOfColumn;

		cout<<"\nEnter in the form : row column value\n";
		for(int i=0;i<noe;i++)			
		cin>>sm[i][0]>>sm[i][1]>>sm[i][2];
	 }	 

	void PutData()
	 {
			cout<<"\nRows\tColumns\tValues\n";
			for(int i=0;i<noe;i++)			
			cout<<sm[i][0]<<"\t"<<sm[i][1]<<"\t"<<sm[i][2]<<"\n";
	 } 

	void FastTranspose()
	 {	
		Sparse Trans;
		int *Start= new int[NumberOfColumn];
		int *Size= new int[NumberOfColumn];
		for(int i=0;i<noe;i++)
		Size[sm[i][1]]++;
		Start[0]=0;
		for(int i=1;i<NumberOfColumn;i++)
		Start[i]=Start[i-1]+Size[i-1];
		int j;
		for(int i=0;i<noe;i++)
		 {
			j=Start[sm[i][1]];
			Trans.sm[j][0]=sm[i][1];			
			Trans.sm[j][1]=sm[i][0];			
			Trans.sm[j][2]=sm[i][2];			
			Start[sm[i][1]]++;
		 }
			cout<<"\nTranspose is\n";
			cout<<"Rows\tColumns\tValues\n";
			for(int i=0;i<noe;i++)			
			 {
				cout<<Trans.sm[i][0]<<"\t"<<Trans.sm[i][1]<<"\t"<<Trans.sm[i][2]<<"\n";
			 }
	
	 }

	void Addition(Sparse x)
	 {
				
		Sparse add;
		if(noe>0&&x.noe>0)
		 {
			if(NumberOfRow!=x.NumberOfRow||NumberOfColumn!=x.NumberOfColumn)
			 {
				cout<<"Addition is not possible";
			 }
			else
			 {
			cout<<"\nAddtion of SPARSE Matrix is\n\n";
			int count=0,i=0,j=0,p;
			while ((i<noe)&&(j<x.noe))
			 {
				if(sm[i][0]==x.sm[j][0]&&sm[i][1]==x.sm[j][1])
				 {	p=sm[i][2]+x.sm[j][2];
				 
				if(p!=0)
				 {
					add.sm[count][0]=sm[i][0];
					add.sm[count][1]=sm[i][1];
					add.sm[count++][2]=p;
					i++;
					j++;
				 }
				 }
				else if (sm[i][0]==x.sm[j][0])
				 {
					if(sm[i][1]<x.sm[j][1])
					 {
					
						add.sm[count][0]=sm[i][0];
						add.sm[count][1]=sm[i][1];
						add.sm[count++][2]=sm[i][2];
					 	i++;
					 }
					else if(sm[i][1]>x.sm[j][1])
					 {
					
						add.sm[count][0]=x.sm[j][0];
						add.sm[count][1]=x.sm[j][1];
						add.sm[count++][2]=x.sm[j][2];
					 	j++;
					 }
				 }
				else if (sm[i][0]>x.sm[j][0])
				 {
						
						add.sm[count][0]=x.sm[j][0];
						add.sm[count][1]=x.sm[j][1];
						add.sm[count++][2]=x.sm[j][2];
					 	j++;
				 }
				else if(sm[i][0]<x.sm[j][0])
				 {
					add.sm[count][0]=sm[i][0];
					add.sm[count][1]=sm[i][1];
					add.sm[count++][2]=sm[i][2];
				 	i++;
				 }

			 }
			for(;i<noe;i++)
			 {	
				add.sm[count][0]=sm[i][0];
				add.sm[count][1]=sm[i][1];
				add.sm[count++][2]=sm[i][2];
			 }
			for(;j<x.noe;j++)
			 {	
				add.sm[count][0]=x.sm[j][0];
				add.sm[count][1]=x.sm[j][1];
				add.sm[count++][2]=x.sm[j][2];
			 }
			x.noe=count;
			cout<<"Rows\tColumns\tValues\n";
			for(int i=0;i<x.noe;i++)			
			cout<<add.sm[i][0]<<"\t"<<add.sm[i][1]<<"\t"<<add.sm[i][2]<<"\n";
			}
		 }
	 }
	
 };


int main()
 {
	Sparse s,Tra;	 
	s.GetData();	 
	s.PutData();
	s.FastTranspose();
//	Tra.PutData();
	Tra.GetData();
	Tra.PutData();
	Tra.Addition(s);	
 return 0;
 }

