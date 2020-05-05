/*
wrong-delete_before
*/
#include<stdio.h>
#include<conio.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
}*last,*start=NULL,*p;
void insertBeg()
{
	int item;
	printf("\n enter no.");
	scanf("%d",&item);
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	p->prev=NULL;
	p->next=start;
	start=p;
	printf("inserted %d",p->data);
}
/*--------------------------------------------------------------------*/
void insertEnd()
{
	int item;
	struct node *temp;
	printf("\n enter no.");
	scanf("%d",&item);
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	temp=start;
	while(temp->next!=NULL)
		temp=temp->next;
	p->prev=temp;
	temp->next=p;
	p->next=NULL;
	printf("inserted %d",p->data);
}
/*--------------------------------------------------------------------*/
void deleteSpecific()
{
       if(start==NULL)
		printf("\n underflow");
       else
       {
       int no;
       struct node *x,*temp,*loc;
       printf("\n enter the no. to delete");
       scanf("%d",&no);
       temp=start;
       while(temp->data!=no)
       {
	       //	printf("\n incrementing temp");
		loc=temp;
		temp=temp->next;
       }
       if(temp->data==no)
       {
	     //	printf("\n t->data==no..setting pointers");
		x=temp->next;
		loc->next=x;
		x->prev=loc;
		if(temp==start)
			x=start;
		printf("\n Deleted Element is:- %d",temp->data);
       }
       else
		printf("\n %d is not present",no);
       }
}


/*--------------------------------------------------------------------*/
void deleteAfter()
{
	struct node *temp,*x,*loc;
	int item,no;
	if(start==NULL)
		printf("\n underflow");
	else
	{
		printf("no. after which u want to delete");
		scanf("%d",&no);
	       /*	printf("enter the no. you want to insert");
		scanf("%d",&item);
		p=(struct node *)malloc(sizeof(struct node));
		p->data=item;  */
		temp=start;
		while(temp->data!=no &&temp->next!=NULL)
			temp=temp->next;
		if(temp->data==no)
		{
			x=temp->next;
			loc=temp->prev;
			loc->next=x;
			x->prev=loc;
			if(temp==start)
				start=x;
			printf("\n deleted element is %d",temp->data);

		}
		else //last node
			printf("\n element not available");
	}
}
/*--------------------------------------------------------------------*/
void insertAfter()
{
	struct node *temp,*loc;
	int item,no;
/*	if(start==NULL)
		printf("\n unerflow");
	else
	{ */
		printf("no. after which u want to insert");
		scanf("%d",&no);
		printf("enter the no. you want to insert");
		scanf("%d",&item);
		p=(struct node *)malloc(sizeof(struct node));
		p->data=item;
		temp=start;
		while(temp->data!=no &&temp->next!=NULL)
			temp=temp->next;
		if(temp->data==no)
		{
			loc=temp->prev;
			loc->next=p;
			temp->prev=p;
			p->prev=loc;
			p->next=temp;

			if(temp==start)
				start=p;
			printf("\n inserted element is %d",p->data);

		}
		else //last node
			printf("element not available");
	//}
}

/*--------------------------------------------------------------------*/


void insort()
{
	struct node *temp,*loc;
	int item;
	if(start==NULL)
		printf("\n underflow");
	else
	{
		printf("\n enter the no. you want to insert");
		scanf("%d",&item);
		p=(struct node *)malloc(sizeof(struct node));
		p->data=item;
		temp=start;
		while(temp->data<item &&temp->next!=NULL)
			temp=temp->next;
		if(temp->data>item)
		{
			loc=temp->prev;
			loc->next=p;
			temp->prev=p;
			p->prev=loc;
			p->next=temp;

			if(temp==start)
				start=p;
		}
		else //last node
		{
			temp->next=p;
			p->prev=temp;
			p->next=NULL;
			printf("\n inserted element is %d",p->data);
		}
	}
}
/*--------------------------------------------------------------------*/
void insertBefore()
{
	struct node *temp,*loc;
	int item,no;
	printf("enter no. before which u want to enter");
	scanf("%d",&no);
	printf("enter no. to enter");
	scanf("%d",&item);
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;
	temp=start;
	while(temp->next!=NULL || temp->data!=no)
		temp=temp->next;
	if(temp->data==no)
	{
		//loc to be deleted here
		// temp->p->loc
		loc=temp->next;
		temp->next=p;
		loc->prev=p;
		p->prev=temp;
		p->next=loc;
		if(p->prev==NULL)
		{ start=p;	}
		//x=loc->prev;
		printf("\n inserted element is %d",p->data);

		 //x->next=temp;
		//temp->prev=x;
		//you got to choose pace, i got to choose things
	}
	else
		printf("\n entered element doesnt exist");
}
/*--------------------------------------------------------------------*/
void deleteBefore()
{
	struct node *temp,*loc=NULL,*x=NULL;
	int no;
	printf("enter no. before which u want to delete");
	scanf("%d",&no);
	/*printf("enter no. to enter");
	scanf("%d",&item);
	p=(struct node *)malloc(sizeof(struct node));
	p->data=item;*/
	temp=start;
	while(temp->next!=NULL || temp->data!=no)
		temp=temp->next;
	if(temp->data==no)
	{
		//loc to be deleted here
		// x-->loc-->temp
		loc=temp->prev;
		x=loc->prev;
		x->next=temp;
		temp->prev=x;
		//loc->next=temp;
		if(loc==start)
			start=temp;
		printf("\n deleted element is %d",loc->data);

	}
	else
		printf("\n entered element doesnt exist");
}
/*--------------------------------------------------------------------*/
void display()
{
	struct node *temp;
	temp=start;

	if(start==NULL)
		printf("\n underflow");
	printf("\n");
	while(temp->next!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}
/*--------------------------------------------------------------------*/
void deleteBeg()
{
	struct node *temp;
	if(start==NULL)
		printf("underflow");
	else
	{
			//start;
		temp=start->next;
		temp->prev=NULL;
		start=temp;
		printf("\n deleted element is %d",start->data);

	}
}
/*--------------------------------------------------------------------*/
void deleteEnd()
{
	struct node *temp,*loc;
	if(start==NULL)
		printf("underflow");
	else
	{
		temp=start;
		while(temp->next!=NULL)
		{
			loc=temp;
			temp=temp->next;
		}
	       //loc=temp->prev
	       loc->next=NULL;
	       printf("\n deleted element is %d",temp->data);

	}

}
/*--------------------------------------------------------------------*/
void main()
{
	int i=1,x;
	clrscr();
	while(i==1)
	{
		printf("\n enter 1 to insert at begining");
		printf("\n enter 2 to display");
		printf("\n enter 3 to delete specific node");
		printf("\n enter 4 to insort");
		printf("\n enter 5 to insert at end");
		printf("\n enter 6 to insert after specific node");
		printf("\n enter 7 to insert before specific node");
		printf("\n enter 8 to delete after specific node");
		printf("\n enter 9 to delete before specific node");
		printf("\n enter 10 to delete at beginning");
		printf("\n enter 11 to delete at end");
		printf("\n enter 12 to exit");
		scanf("%d",&x);

		switch(x)
		{
			case 1:{ insertBeg();break;  }
			case 2:{ display(); break;}
			case 3:{ deleteSpecific();break;}
			case 4:{ insort(); break;}
			case 5:{ insertEnd();  break;}
			case 6:{ insertAfter();  break;}
			case 7:{ insertBefore();  break;}
			case 8:{ deleteAfter();  break;}
			case 9:{ deleteBefore();  break;}
			case 10:{ deleteBeg();  break;}
			case 11:{ deleteEnd();  break;}
			case 12:{ exit(0);  break;}

		}
		printf("\n Enter 1 to continue..");
		scanf("%d",&i);
	}
	getch();
}
