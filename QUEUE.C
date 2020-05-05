/*
write a program to implement queue using arraysthat perform following
operations
A.insert
B. delete
C. display
*/
#include<stdio.h>
#include<conio.h>
#define size 10
int q[size];
int front=-1,rear=-1;
void insert();
void remove1();
void display();

void main()
{
	//int n;
	//int a[10];
	int i,x;
	 int p=1;
	///int start,end;
	clrscr();
	//printf("\n thank you");
	while(p==1)
	{
		printf("\n enter 1-->for insert");
		printf("\n enter 2-->for delete");
		printf("\n enter 3-->for display");
       //printf("\n enter 4-->for quick sort");
		printf("\n enter 5-->for exiting\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1:{insert(); break;}
			case 2:{remove1();break;}
			case 3:{display(); break;}
		       //case 4:{quickSort(a,start,end);break;}
			case 5:{exit(0);}
			default: {printf("try again.. invalid choice"); break;}
		}
		printf("\n press 1 to cont..");
		scanf("%d",&p);
	       //	printf("\n");
	}
	getch();
}
void insert()
{
	int a;
	if(rear==size-1)
	{
		 printf("\n queue overflow");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;rear=0;
		}
		else
		{
		rear++;
		}
		printf("\n enter value");
		scanf("%d",&a);
		q[rear]=a;

	}
}
void remove1()
{
	int r;
	if(front>rear || front==-1)
	{
		printf("\n queue underflow");
	}
	else
	{
		r=q[front];
		front++;
		printf("\n deleted element is: %d",r);
	}
}
void display()
{
	int i;
	if(front==-1 || front>rear)
		printf("\n queue underflow");
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("\n %d",q[i]);
		}
	}
}