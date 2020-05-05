/*
				conversion of infix to postfix using stack
				author: juhi kamdar
				created on: 2/1/2018
				last edited on:
*/
//eqn.=a+b -->ab+

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define size 6

//global declaration
char s[6];	//operator stack
char pexp[6];	//postfix expression array
int top=-1; //pointer to top of operator stack
int top2=-1; //pointer to top of postfix stack


/****************to swap values of array***************/
/* void sttr(int arr1[6], int x, int arr2[6], int y)
//transfer of data in stack function
{
	int t;
	// arr1->arr2;
	t=arr1[x];
	arr1[x]=arr2[y];
	arr2[y]=t;
}*/


/****************to set priority of the operands***************/
int priority()
{
	if(s[top]=='(' || s[top]==')')
	return 0;
	else if(s[top]=='*' || s[top]=='/')
	return 1;
	else if(s[top]=='+' || s[top]=='-')
	return 2;
	else
	return 0;
}


/****************to push the characters in operand and postfix stack according to need***************/
void push(char n)
{

	if(top==size-1)
	{
		printf("STACK OVERFLOW");
	}
	else
	{
	      /* printf("Enter the no.");
		scanf("%c",&n); */
		top=top+1;
		s[top]=n;
		printf("\n pushed one value");
	}
}


/****************to pop out characters and store them in postfix expression stack***************/
void pop(char n) //poping and storing in postfix expression
{
	if(top==-1)
		printf("STACK UNDERFLOW");
	else
	{
	       //printf("\n %d\t%d",top,s[top]);
		pexp[top2]=n; //s[top]
		printf("\n Popped Element is %c ",n);
		top--;
	}
}


/****************to pop out characters until the opening bracket arives***************/
void check(char n)
{
	int x,y;
	//n-->pased value
	if(isalnum(n))// if operand->pexp else, if an operand then,put it in operator stack
	{
		pexp[top2]=n;
		top2++;
		//break;
	}
	else if(n=='('|| n==')')
	{
		if(n=='(')
		push(n);

		else
		{
			s[top]=n;
			top++;
			while(s[top]=='(')
			{
				pop(s[top]);
			}
		}
	       //break;
	}
     /*	else if(n==')')
	{

		//break;
	}*/
	else //operator, then...
	{       //check priority and then push in operator stack
		x=priority(s[top]);
		y=priority(n);
		if(x==y || x>y)
		{
			pop(s[top]);
			push(n);
		}
	       //break;
	}
}


void display()
{
	int i;
	printf("\n inside display function");

	for(i=0;i<pexp[top2];i++)
	{
		printf("%c",pexp[i]);
	}
}
void main()
{

	//dynamic allocation of expression
	clrscr();
       //	push('(');
	printf("\n we r adding (");
	check('(');
       //	push('a');
	printf("\n we r adding a");
	check('a');
       //	push('+');
       printf("\n we r adding +");
	check('+');
       //	push('b');
       printf("\n we r adding b");
	check('b');
	/*char exp[10]; 	//infix expression
	gets(exp);*/
       //	push(')');
       printf("\n we r adding )");
	check(')');
	printf("\n calling display function");

	/*
	we will make a stack of operator and another one of postfix operands
	*/
	display();
	getch();

}