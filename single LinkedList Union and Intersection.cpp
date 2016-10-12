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

void findIntersection(struct node *head,struct node *tail)
{
	struct node *ptr=head;
	struct node *tmp;
	while(ptr!=NULL)
	{
		tmp=Find(ptr->item,&tail);
		if(tmp!=NULL)
		printf("%d ",ptr->item);
		ptr=ptr->link;
	}
	printf("\n");
}

void findUnion(struct node *head,struct node *tail)
{
	struct node *ptr=head;
	struct node *tmp;
	while(ptr!=NULL)
	{
		tmp=Find(ptr->item,&tail);
		if(tmp==NULL)
		printf("%d ",ptr->item);
		ptr=ptr->link;
	}
	
	ptr=tail;
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
	struct node *tail=NULL;
	while(1)
	{
		printf("1. Insert Data \n");
		printf("2. Delete \n");
		printf("3. isEmpty \n");
		printf("4. Traverse \n");
		printf("5. Union\n");
		printf("6. Intersecion\n");
		printf("7. Exit \n");
		printf("Enter the choice \n");
		int choice,ch;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: int n;
					printf("Enter data \n");
					scanf("%d",&n);
					printf("In which list you want to enter 1 or 2 :");
					scanf("%d",&ch);
					if(ch==1)
					Insert(n,&head);
					else
					Insert(n,&tail);
					break;
			case 2:
					printf("Enter the element to delete \n");
					scanf("%d",&n);
					printf("In which list you want to delete 1 or 2 :");
					scanf("%d",&ch);
					if(ch==1)
					Delete(n,&head);
					else
					Delete(n,&tail);
					break;
					
			case 3: printf("In which list you want to check 1 or 2 :");
					scanf("%d",&ch);
					if(ch==1)
					{
					if(isEmpty(&head))
					printf("List is empty\n");
					else
					printf("Not Empty\n");
					}
					else
					{
						if(isEmpty(&tail))
					printf("List is empty\n");
					else
					printf("Not Empty\n");
					}
					break;
			case 4:  printf("Which list you want to traverse 1 or 2 :");
					scanf("%d",&ch);
					if(ch==1)
					traverse(&head);
					else
					traverse(&tail);
					break;
			case 7: exit(1);
					break;
			
			case 5: findUnion(head,tail);
					break;
					
			case 6: findIntersection(head,tail);
					break;
					
		}
	}
	
}
