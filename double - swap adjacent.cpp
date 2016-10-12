#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int item;
	struct node *prev;
	struct node *next;
};

int isEmpty(struct node **head)
{
	return *head==NULL;
}

void Insert(int n,struct node **head)
{
	struct node *tmp=(struct node *)malloc(sizeof(struct node));
	tmp->item=n;
	tmp->next=NULL;
	if(*head==NULL)
	{
		tmp->prev=NULL;
		*head=tmp;
	}
	else
	{
		struct node *ptr;
		ptr=*head;
		while(ptr->next!=NULL)
		ptr=ptr->next;
		tmp->prev=ptr;
		ptr->next=tmp;
	}
}

void Delete(int x,struct node **head)
{
	if(*head==NULL)
	return;
	struct node *ptr,*tmp;
	ptr=*head;
	if(ptr->item==x)
	{
		*head=ptr->next;
		if(*head!=NULL)
		ptr->next->prev=NULL;
		free(ptr);
	}
	else
	{
		while(ptr->next!=NULL && ptr->next->item!=x)
		ptr=ptr->next;
		if(ptr->next!=NULL)
		{
			struct node *tmp=ptr->next;
			ptr->next=tmp->next;
			if(ptr->next!=NULL)
			tmp->next->prev=ptr;
			free(tmp);
		}
	}
	
}

void traverse(struct node **head)
{
	if(*head!=NULL)
	{
		struct node *ptr=*head;
		while(ptr!=NULL)
		{
			printf("%d ",ptr->item);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

void reverset(struct node **head)
{
	if(*head!=NULL)
	{
		struct node *ptr=*head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		while(ptr!=NULL)
		{
			printf("%d ",ptr->item);
			ptr=ptr->prev;
		}
		printf("\n");
	}
}

void swap(struct node **head)
{
	if(*head==NULL || (*head)->next==NULL)
	{
		return;
	}
	
	struct node *ptr,*qtr,*tmp;
	ptr=*head;
	qtr=ptr->next;
	ptr->next=qtr->next;
	qtr->next=ptr;
	ptr->prev=qtr;
	*head=qtr;
	tmp=ptr;
	qtr->prev=NULL;
	qtr=ptr->next;
	while(qtr!=NULL)
	{
		if(qtr->next==NULL)
		{
			qtr->prev=ptr;
			return;
		}
		qtr->prev=ptr;
		ptr=qtr;
		qtr=qtr->next;
		ptr->next=qtr->next;
		qtr->next=ptr;
		qtr->prev=ptr->prev;
		ptr->prev=qtr;
		tmp->next=qtr;
		qtr=ptr->next;
		tmp=ptr;
	}
}
int main()
{
	struct node *head=NULL;
	while(1)
	{
		printf("1. Insert Data \n");
		printf("2. Delete \n");
		printf("3. isEmpty \n");
		printf("4. Traverse \n");
		printf("5. Reverse Traverse\n");
		printf("6. Swap Adjacent \n");
		printf("7. Exit \n");
		printf("Enter the choice \n");
		int choice;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: int n;
					printf("Enter data \n");
					scanf("%d",&n);
					Insert(n,&head);
					break;
			case 2:
					printf("Enter the element to delete \n");
					scanf("%d",&n);
					Delete(n,&head);
					break;
			case 3: if(isEmpty(&head))
					printf("List is empty\n");
					else
					printf("Not Empty\n");
					break;
			case 4: traverse(&head);
					break;
			case 5:
					reverset(&head);
					break;
					
			case 6: swap(&head);
					break;		
			
			case 7: exit(1);
					
					
		}
	}
}
