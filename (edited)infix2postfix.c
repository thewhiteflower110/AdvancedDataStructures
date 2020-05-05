/*
implementation of stack->infix to postfix
edited: 18/2/18-> edited that we include brackets, at the start and end of the equation 
*/
#include<conio.h>
#include<string.h>
#include<stdio.h>
#define size 6
int top=-1;
int y=-1;
char stack[size];
char infix[size];
char postfix[7];

void push(char n)
{
  //	int n;
 // int top;
	if(top==size-1)
	{
		printf("STACK OVERFLOW");
	}
	else
	{
	   /*	printf("Enter the no.");
		scanf("%d",&n);
					*/
		top=top+1;
		stack[top]=n;
	}
}
void add(char n)
{

	/*
	we add element in array
	*/y++;
	postfix[y]=n;
	//y++;
}

void pop(char n)
{ 	//int n;
	if(top==-1)
		printf("STACK UNDERFLOW");
	else
	{
	  //	printf("\n %d\t%d",top,s[top]);
		n=stack[top];
	   printf("Popped Element is %c \n",n);
		add(n);
	  //	//pushing n in postfix
		top--;
	}
}
/*
push(int a[size]);
pop();
priority();
 */

int priority(x)
{
	   if(x=='(' || x==')')
	   {
			return 3;
	   }
   else	if(x=='+' ||x=='-')
	{
		return 1;
	}
	else if(x=='/' || x=='*')
	{
		return 2;
	}
	else
	return 0;
}
void main()
{
	int i;
   //	top=-1;
	int x;
	clrscr();
	printf("expression:\n");
	//gets(infix);
	infix[0]='(';
    for(i=1;i<size-1;i++)
	{
		scanf("%c",&infix[i]);
	}
	x=sizeof(infix/infix[0]);
	infix[x]=')';
	
   /*	push();//)
	push();//( */
	
	for(i=0;i<size-1;i++)
	{
	   //printf(" scanning..%c \n",infix[i]);
		if( isalpha(infix[i]))
		{
			add(infix[i]);//adding infix[i] in postfix
		   //push(infix[i],postfix);//
		}
		else
		{
			char x;
			int z;
			x=priority(infix[i]);
			printf("priority assign %c \n ",infix[i]);
		 //   top=top+1;
			//int z;
			z= priority(stack[top]);
			if(x <=z )//lower
			{
				pop(stack[top]);//popping prev. operator
				push(infix[i]);//pushing the new operator in stack of i
			}
			else //higher
			{
				push(infix[i]);
				//top++;
			}
		}

	}
	while(top==0)
	{
		pop(stack[top]);
	}
	for(i=0;i<7;i++)
	{
		printf("%c \n",postfix[i]);
		
		if(postfix[i]=='\0')
		{
			printf("*");
		}

	}
   /*	*/
   getch();

}