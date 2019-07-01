/*
 * string.cpp
 *
 *      Name: weirdgourmet

 *      Assignmaent 3 :Write C++ program with class for String. Write a function to :
• Copy, Concatenate, check substring, Equal, Reverse and Length.
• Frequency that determines the frequency of occurrence of particular character in the string.
• Delete that accepts two integers, start and length. The function computes a new string that is equivalent to the
original string, except that length characters being at start have been removed.
• Chardelete that accepts a character c. The function returns the string with all occurrences of c removed.
• Replace to make an in-place replacement of a substring w of a string by the string x. note that w may not be of same
size of x
• Palindrome to check whether given string is palindrome or not 
 */
#include <iostream>
using namespace std;
class String
{
	private :
	char str[20];
	public :
	String()
	{
		//str[0] = '\0';
	}
	String(char s[20])
	{
		empty(str);
		int i = 0;
		do
		{
			str[i] = s[i];
			i++;
		}
		while (s[i] != '\0');
		s[i] = '\0';
	}
	friend ostream& operator << (ostream &out, String &obj)
	{
		out<<obj.str;
	}
	void Read(char *A)
	{
		empty(str);
		int i = 0;
		do
		{
			str[i] = A[i];
			i++;
		}
		while (A[i] != '\0');
		str[i] = '\0';
	}
	String copy (String obj)
	{
		int i = 0;
		do
		{
			str[i] = obj.str[i];
			i++;
		}
		while (obj.str[i] != '\0');
		str[i] = '\0';
		return str;
	}
	string empty(char str1[20])
	{
		int i;
		for (i=0; i<20; i++)
			str1[i] = '\0';
			return str1;
	}
	String concatenate (String obj)
	{
		String constr;
		empty(constr.str);
		int j = 0,l=0;
		for(j=0; str[j] != '\0' ;j++)
		{
			constr.str[j] = str[j];
		}
		constr.str[j] = '\0';
		for(l=0; obj.str[l] != '\0' ; l++)
		{
			constr.str[j] = obj.str[l];
			j++;
		}
		constr.str[j] = '\0';
		return constr;
	}
	int equal(String obj)
	{
		int count = 0;
		for (int j=0; str[j] != '\0'; j++)
		{
			if (str[j] != obj.str[j])
				count++;
		}
		return count;
	}
	int frequency(char alp)
	{
		int count = 0;
		for(int j=0; str[j] != '\0' ; j++)
		{
			if (str[j] == alp)
				count++;
		}
		return count;
	}
	int length()
	{
		int i = 0;
		do
		{
			i++;
		}
		while(str[i]!='\0');
		return i;
	}
	void reverse ()
	{
		String obj;
		empty(obj.str);
		int i = length();
		int k=i;
		for (int j=0; j<i; j++)
		{
			obj.str[j] = str[k-1];
			k--;
		}
		for (int a=0; a<i; a++)
			str[a] = obj.str[a];
	}
	int palindrome ()
	{
		String obj;
		int i = length();
		int k;
		for (k=0; k<i; k++)
			obj.str[k] = str[k];
			obj.str[k] = '\0';
			obj.reverse();
			int count = equal(obj);
			return count;
	}
	String DeleteChar(char alp)
	{
		char newstr[20];
		empty(newstr);
		String obj(newstr);
		int i = length();
		int k = 0;
		for(int j=0;j<i;j++)
		{
			if(str[j] != alp)
			{
				obj.str[k] = str[j];
				k++;
			}
		}
		return obj;
	}
	String DeleteGroup(int l, int n)
	{
		char newstr[20];
		empty(newstr);
		String obj(newstr);
		int u = l+n;
		int i = length();
		int j;
		for (j=0; j<l-1; j++)
			obj.str[j] = str[j];
			for (int k=u-1; k<i; k++)
			{
				obj.str[j] = str[k];
				j++;
			}
			return obj;
	}
	int CheckSubstring(String obj)
	{
		int i = length();
		int k = obj.length();
		int j,m;
		int end = 0;
		int start = 0;
		if (k==1)
		{
			int a = frequency(obj.str[0]);
			if(a>=1)
				return 1;
			else
				return 0;
		}
		else
		{
			for (j=0; j<i ;j++)
			{
				if(str[j] == obj.str[0])
				{
					start = j;
					end = start;
					m = j;
					for(int l=1; l<k; l++)
					{
						if(obj.str[l] == str[m+1])
						{
							end++;
							m++;
						}
						else
							break;
					}
				}
				if (end - start == k-1)
					break;
			}
			if (end - start == k-1)
				return start+1;
			else
				return 0;
		}
	}
	void ReplaceSubstring (String objsub, String objrep)
	{
		int i = length();
		int k = objsub.length();
		int q = objrep.length();
		int start = CheckSubstring(objsub)-1;
		int end = start + k - 1;
		int w = 0, x = 0,y = 0,z = 0,a;
		char newstr[15];
		empty(newstr);
		String obj(newstr);
		for (x=0; x<start; x++)
			obj.str[x] = str[x];
			for (y=x; y<x+q; y++)
			{
				obj.str[y] = objrep.str[w];
				w++;
			}
			for (z=end+1; z<i; z++)
			{
				obj.str[y] = str[z];
				y++;
			}
			for (a=0; a<y; a++)
				str[a] = obj.str[a];
				str[a] = '\0';
	}

};
int main()
{
	char x[20];
	cout<<"Enter the string ";
	cin>>x;
	String word(x);
	cout<<"Press 1  to copy and display another string."<<endl;
	cout<<"Press 2  to concatenate and display the string."<<endl;
	cout<<"Press 3  to check if a substring belongs to the given string."<<endl;
	cout<<"Press 4  to check if a string is equal to the given string."<<endl;
	cout<<"Press 5  to display the given string in reverse."<<endl;
	cout<<"Press 6  to calculate the length of the given string."<<endl;
	cout<<"Press 7  to calculate the frequency of a character in the given string."<<endl;
	cout<<"Press 8  to display the given string after deletion of a group of characters."<<endl;
	cout<<"Press 9  to display the given string after deletion of all occurences of a character."<<endl;
	cout<<"Press 10 to display the given string after replacing a substring with a new substring (not necessarily of the same size)."<<endl;
	cout<<"Press 11 to check if the given string is palindrome or not."<<endl;
	int c;
	int choice;
	do
	{
		cout<<"Enter the number to perform required operation. ";
		cin>>c;
		switch (c)
		{
			case 1 :
			{
				cout<<"Enter the string to be copied ";
				cin>>x;
				String wordcpy;
				wordcpy.Read(x);
				word = word.copy(wordcpy);
				cout<<"After the copy operation, the string is "<<word<<endl;
				break;
			}
			case 2 :
			{
				cout<<"Enter the string to be concatenated ";
				cin>>x;
				String word2(x);
				String wordconcat;
				wordconcat = word.concatenate(word2);
				cout<<"After concatenation, the string is "<<wordconcat<<endl;
				break;
			}
			case 3 :
			{
				char substr[10];
				cout<<"Enter the substring ";
				cin>>substr;
				String wordcheck(substr);
				int check = word.CheckSubstring(wordcheck);
				int sublen = wordcheck.length();
				int end = check + sublen - 1;
				if (check == 0)
					cout<<"The given substring is not present in the word "<<word<<endl;
				else
				{
					cout<<"The given substring is present in the word "<<word<<endl;
					cout<<"Substring Location - Start : "<<check<<" End : "<<end<<endl;
				}
				break;
			}
			case 4 :
			{
				String wordequal;
				cout<<"Enter another string to check if it is same as the entered string ";
				cin>>x;
				wordequal.Read(x);
				int count = word.equal(wordequal);
				if (count == 0)
					cout<<"Both the strings are equal."<<endl;
				else
					cout<<"Both the strings are unequal."<<endl;
				break;
			}
			case 5 :
			{
				word.reverse();
				cout<<"The reversed string is "<<word<<endl;
				break;
			}
			case 6 :
			{
				cout<<"The length of the entered string "<<word<<" is "<<word.length()<<endl;
				break;
			}
			case 7 :
			{
				char alp;
				cout<<"Enter the alphabet whose frequency is to be calculated in the given string ";
				cin>>alp;
				cout<<"The frequency of "<<alp<<" in the string "<<word<<" is "<<word.frequency(alp)<<endl;
				break;
			}
			case 8 :
			{
				int lowerbound, noofchar, l;
				l = word.length();
				cout<<"Enter the start location ";
				cin>>lowerbound;
				cout<<"Enter the number of characters to be deleted ";
				cin>>noofchar;
				if (lowerbound+noofchar <= l+1)
				{
					String wordgrpdel = word.DeleteGroup(lowerbound,noofchar);
					cout<<"After deletion, the string "<<word<<" is "<<wordgrpdel<<endl;
				}
				else
					cout<<"Error : The group size exceeds the length of the string."<<endl;
				break;
			}
			case 9 :
			{
				char alp;
				cout<<"Enter the character to be deleted from the string ";
				cin>>alp;
				String wordchardel = word.DeleteChar(alp);
				cout<<"After deletion of character "<<alp<<", the string "<<word<<" is "<<wordchardel<<endl;
				break;
			}
			case 10 :
			{
				char substr[10];
				char RepStr[10];
				cout<<"Enter the substring to be replaced ";
				cin>>substr;
				cout<<"Enter the new substring for replacement ";
				cin>>RepStr;
				String wordsub(substr);
				String wordreplace(RepStr);
				int check = word.CheckSubstring(wordsub);
				if (check == 0)
					cout<<"Error : The given substring is not present."<<endl;
				else
				{
					word.ReplaceSubstring(wordsub,wordreplace);
					cout<<"After replacing the substring, the string is "<<word<<endl;
				}
				break;
			}
			case 11 :
			{
				int result = word.palindrome();
				if (result == 0)
					cout<<"The given string "<<word<<" is a palindrome."<<endl;
				else
					cout<<"The given string "<<word<<" is not a palindrome."<<endl;
				break;
			}
			default :
			{
				cout<<"Invalid choice."<<endl;
			}
		}
		cout<<"Press 1 to continue \t Press 0 to exit \t ";
		cin>>choice;
	}
	while(choice==1);
return 0;
}

/* OUTPUT :

Enter the string abcbcadefabcdef
Press 1  to copy and display another string.
Press 2  to concatenate and display the string.
Press 3  to check if a substring belongs to the given string.
Press 4  to check if a string is equal to the given string.
Press 5  to display the given string in reverse.
Press 6  to calculate the length of the given string.
Press 7  to calculate the frequency of a character in the given string.
Press 8  to display the given string after deletion of a group of characters.
Press 9  to display the given string after deletion of all occurences of a character.
Press 10 to display the given string after replacing a substring with a new substring (not necessarily of the same size).
Press 11 to check if the given string is palindrome or not.
Enter the number to perform required operation. 1
Enter the string to be copied abcbcadefabcdef
After the copy operation, the string is abcbcadefabcdef
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 2
Enter the string to be concatenated anant
After concatenation, the string is abcbcadefabcdefanant
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 3
Enter the substring abc
The given substring is present in the word abcbcadefabcdef
Substring Location - Start : 1 End : 3
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 4
Enter another string to check if it is same as the entered string abcbcadefxyzxyz
Both the strings are unequal.
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 5
The reversed string is fedcbafedacbcba
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 6
The length of the entered string fedcbafedacbcba is 15
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 7
Enter the alphabet whose frequency is to be calculated in the given string a
The frequency of a in the string fedcbafedacbcba is 3
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 8
Enter the start location 2
Enter the number of characters to be deleted 3
After deletion, the string fedcbafedacbcba is fbafedacbcba
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 9
Enter the character to be deleted from the string f
After deletion of character f, the string fedcbafedacbcba is edcbaedacbcba
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 10
Enter the substring to be replaced cb
Enter the new substring for replacement xyz
After replacing the substring, the string is fedxyzafedacbcba
Press 1 to continue 	 Press 0 to exit 	 1
Enter the number to perform required operation. 11
The given string fedxyzafedacbcba is not a palindrome.
Invalid choice.
Press 1 to continue 	 Press 0 to exit 	 0

 */





