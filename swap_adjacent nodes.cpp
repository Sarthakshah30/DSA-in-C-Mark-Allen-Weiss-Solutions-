#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node 
{
	int item;
	struct node *link;
};



int isEmpty(struct node **head)
{
	return *head==NULL;
}

int isLast(struct node *ptr,struct node **head)
{
	return ptr->link==NULL;
}

struct node * Find(int x,struct node **head)
{
	struct node *ptr;
	ptr=*head;
	while(ptr!=NULL && ptr->item!=x)
	ptr=ptr->link;
	
	return ptr;
}




struct node * FindPrevious(int x,struct node **head)
{
	struct node *ptr;
	ptr=*head;
	while(ptr->link!=NULL && ptr->link->item!=x)
	ptr=ptr->link;
	
	return ptr;
}

void Delete(int x,struct node **head)
{
	struct node *ptr,*tmp;
	ptr=*head;
	if(ptr->item==x)
	{
		*head=ptr->link;
		return;
	}
	ptr=FindPrevious(x,head);
	if(!isLast(ptr,head))
	{
		printf("Deleting %d\n",ptr->link->item);
		tmp=ptr->link;
		ptr->link=tmp->link;
		free(tmp);
	}
}
void Insert(int x,struct node **head)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->item=x;
	if(*head==NULL)
	{
		*head=tmp;
	}
	
	else
	{
		struct node *ptr=*head;
		while(ptr->link!=NULL)
		ptr=ptr->link;
		ptr->link=tmp;
		
	}
	tmp->link=NULL;
}

void swap(struct node **head)
{
	if(*head==NULL || (*head)->link==NULL)
	return;
	struct node *ptr,*qtr,*tmp;
	ptr=*head;
	qtr=ptr->link;
	ptr->link=qtr->link;
	qtr->link=ptr;
	tmp=ptr;
	*head=qtr;
	qtr=ptr->link;
	while(qtr!=NULL &&qtr->link!=NULL)
	{
		ptr=qtr;
		qtr=qtr->link;
		ptr->link=qtr->link;
		qtr->link=ptr;
		tmp->link=qtr;
		qtr=ptr->link;
		tmp=ptr;
	}
}

void traverse(struct node **head)
{
	struct node *ptr;
	ptr=*head;
	while(ptr!=NULL)
	{
	printf("%d ",ptr->item);
	ptr=ptr->link;

}
	printf("\n");
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
		printf("5. Swap \n");
		printf("6. Exit \n");
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
			case 6: exit(1);
			
			case 5: swap(&head);
					break;
					
					
		}
	}
	
}
