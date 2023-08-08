#include<cstdio>
#include<stdlib.h>
using namespace std;
#define size 5
class stack
{
int top;
int array[size];
public:
stack()
{
top=-1;
}
bool isfull()
{
if(top==size-1)
return true;
else
return false;
}
bool isempty()
{
if(top==-1)
return true;
else
return false;
}
void push(int num)
{
if(isfull())
printf("stack is full\n");
else
{
top=top+1;
array[top]=num;
}
}
void pop()
{
	int deep;
if(isempty())
printf("stack is empty\n");
else
{
deep=array[top];
array[top]=0;
top=top-1;
printf("%d",deep);
}
}
void peek()
{
if(isempty())
printf("stack is empty\n");
else
printf("current elements is %d",array[top]);
}
void digittext(int digit)
{
	int i=0;
	int a[5];
	while(digit!=0)
	{
		a[i]=digit%10;
		digit=digit/10;
		i++;
	}
	for(i=5;i>=0;i--)
	{
		if(a[i]==1)
		printf("one");
		if(a[i]==2)
		printf("two");
		if(a[i]==3)
		printf("three");
		if(a[i]==4)
		printf("four");
		if(a[i]==5)
		printf("five");
		if(a[i]==6)
		printf("six");
		if(a[i]==7)
		printf("seven");
		if(a[i]==8)
		printf("eight");
		if(a[i]==9)
		printf("nine");
	}
}
void palindromecheck()
{
	int n,temp,sum=0,r;
printf("enter the number\n");    
scanf("%d",&n);    
temp=n;    
while(n>0)    
{    
r=n%10;    
sum=(sum*10)+r;    
n=n/10;    
}    
if(temp==sum)    
printf("it is a palindrome number\n ");    
else    
printf("not palindrome\n");   
}
};


