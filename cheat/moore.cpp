#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;

char moore[100][100][10];

int main()
{
	
	int initial,state;
	int temp;
	FILE *f;
	char str[100];
	char outstr[100];
	int row=0,col=0,maxrow=0,maxcol=0;
	
	f = fopen("moore_input.txt","r");
	
	//read initial state
	fscanf(f,"%s",str);
	initial = atoi(str);
	// cout<<initial;
	char c;
	int k=0;
	c = getc(f);
		
	while(!feof(f))
	{
			c = getc(f);
			if(c == ' ' || c == '\n')
			{
				str[k] = '\0';
				strcpy(moore[row][col],str);
				k=0;
				if(c == ' ')
				{
					col++;
					maxcol = max(col,maxcol);
				}
				else
				{
					col=0;
					row++;
					maxrow = max(row,maxrow);
				}
			}
			else
				str[k++] = c;	
	}
	
	for(int i=0;i<maxrow+1;i++)
	{
		for(int j=0;j<maxcol+1;j++)
			cout << moore[i][j] << " ";
		cout << endl;
	}


	cout<< "Enter the input string" << endl;
	cin>>str;
	int i=0;
	int l=strlen(str);
	char output[100];
	state = initial;
	strcpy(output,moore[initial][maxcol]);
	while(i<l)
	{
		temp = str[i]-48;
	    state = atoi(moore[state][temp]);
	    if(state==-1)
	    {
	    	strcpy(output,"Error");
	    	break;
	    }	
		 strcat(output,moore[state][maxcol]);
	    i++;	
	}	
	 
	cout << output << endl; 
	

}
