#include<stdio.h>
#include<stdlib.h>

int main()
{
int m,i,j,p,q,num=0,temp,no=1;
int led[25],count=0;
FILE *fp;
char arr[100][25],t;

fp=fopen("file.txt","r");
if(fp=='\0')
{
printf("opening error:\n");
}
i=0;j=0;
led[no++]=1;
while(fscanf(fp,"%c",&t)!=EOF)
{
if(t=='\n')
{
arr[i][j]='\0';
j=0;
i++;
}
else
{
arr[i][j]=t;
j++;
}
}//end of while
arr[i][j]='\0';
for(p=0;p<i;p++)
{
for(q=0;arr[p][q]!='\0';q++)
{
printf("%c",arr[p][q]);
}
printf("\n");
}

for(p=0;p<i;p++)
{
for(q=0;arr[p][q]!='\0';q++)
{
if(arr[p][q]=='g' && arr[p][q+1]=='o' && arr[p][q+2]=='t' && arr[p][q+3]=='o')
{
q=q+5;

while(arr[p][q]!='\0')
{
temp=arr[p][q]-48;
num=num+temp;
if(arr[p][q+1]=='\0')
break;
else
{
num=num*10;
q++;
}
}

led[no++]=num;
led[no++]=p+2;
num=0;
}
}
}
for(p=1;p<no-1;p++)
{
for(q=p+1;q<no;q++)
{
if(led[p]>led[q])
{
temp=led[p];
led[p]=led[q];
led[q]=temp;
}
}
}

for(p=1;p<no-1;p++)
{
for(q=p+1;q<no;q++)
{

if(led[p]==led[q])
{
for(m=q;m<no-1;m++)
led[m]=led[m+1];
no--;
}
}
}
printf("LEADER\n");
for(p=1;p<no;p++)
printf("\t%d",led[p]);

q=1;
for(p=0;p<i;p++)
{
printf("\n\t: BLOCK%d:\n",count);
for(m=(led[q]-1);m<=(led[q+1]-2);m++)
{
printf("\n\t\t\t%s",arr[m]);
p++;
}
q=q+1;
count++;
}
}

