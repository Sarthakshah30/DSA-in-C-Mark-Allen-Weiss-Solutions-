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
		free(ptr);
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

struct node * findAtPos(struct node *head,int pos)
{
	struct node *ptr = head;
	struct node *tmp=ptr;
	int count=0;
	while(count!=pos && tmp!=NULL)
	{
		count++;
		tmp=ptr;
		if(tmp==NULL)
		return tmp;
		ptr=ptr->link;
	}
	return tmp;
}
void PrintLots(struct node *head,struct node *tail)
{
	struct node * ptr = tail;
	while(ptr!=NULL)
	{
		struct node * tmp = findAtPos(head,ptr->item);
		if(tmp==NULL)
		return;
		else
		{
			printf("%d ",tmp->item);
		}
		ptr=ptr->link;
	}
	printf("\n");
}

void swap(struct node *a, struct node *b)
{
    int temp = a->item;
    a->item = b->item;
    b->item = temp;
}

void sort(struct node ** head)
{
	int swapped, i;
    struct node *ptr1=*head;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = *head;
 
        while (ptr1->link != lptr)
        {
            if (ptr1->item > ptr1->link->item)
            { 
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    }
    while (swapped);
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
		printf("5. PrintLots\n");
		printf("6. Exit \n");
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
			case 6: exit(1);
					break;
			
			case 5: sort(&tail);
					PrintLots(head,tail);
					break;
					
		}
	}
	
}
