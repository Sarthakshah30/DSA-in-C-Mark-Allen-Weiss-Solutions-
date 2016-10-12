#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct poly
{
	int coeff;
	int exp;
	struct poly * next;
};

void swap(struct poly *a, struct poly *b)
{
    int temp = a->exp;
    a->exp = b->exp;
    b->exp = temp;
    
    temp = a->coeff;
    a->coeff = b->coeff;
    b->coeff=temp;
}

void sort(struct poly ** head)
{
	int swapped, i;
    struct poly *ptr1=(*head);
    struct poly *lptr = NULL;
 
    if (ptr1 == NULL)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = *head;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->exp < ptr1->next->exp)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}


void traverse(struct poly * head)
{
	struct poly *ptr=head;
	while(ptr!=NULL)
	{
		printf("Coefficient = %d Exponent = %d\n",ptr->coeff,ptr->exp);
		ptr=ptr->next;
	}
	printf("\n");
}

void Insert(struct poly **head)
{
	struct poly * tmp = (struct poly *)malloc(sizeof(struct poly));
	int coefficient;
	int exponent;
	printf("Enter coefficient and exponent :");
	scanf("%d%d",&coefficient,&exponent);
	tmp->coeff=coefficient;
	tmp->exp=exponent;
	if(*head==NULL)
	{
		*head=tmp;
	}
	else
	{
		struct poly * ptr= *head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=tmp;
	}
	tmp->next=NULL;
}

struct poly * Find(int exponent,struct poly *head)
{
	struct poly *ptr=head;
	while(ptr!=NULL && ptr->exp!=exponent)
	{
		ptr=ptr->next;
	}
	return ptr;
}

void Addition(struct poly *head1,struct poly *head2)
{
	struct poly *result=NULL;
	struct poly *ptr=head1,*qtr;
	while(ptr!=NULL)
	{
		struct poly * tmp = (struct poly *)malloc(sizeof(struct poly)); 
		qtr=Find(ptr->exp,head2);
		if(qtr==NULL)
		{
			tmp->exp=ptr->exp;
			tmp->coeff=ptr->coeff;
		}
		else
		{
			tmp->exp=ptr->exp;
			tmp->coeff=ptr->coeff+qtr->coeff;
		}
		if(result==NULL)
		{
			result=tmp;
		}
		else
		{
			qtr= result;
			while(qtr->next!=NULL)
			{
				qtr=qtr->next;
			}
			qtr->next=tmp;
		}
		tmp->next=NULL;
		ptr=ptr->next;
	}
	ptr=head2;
	while(ptr!=NULL)
	{
		struct poly * tmp = (struct poly *)malloc(sizeof(struct poly)); 
		qtr=Find(ptr->exp,head1);
		if(qtr==NULL)
		{
			tmp->exp=ptr->exp;
			tmp->coeff=ptr->coeff;
			if(result==NULL)
			{
				result=tmp;
			}
			else
			{
				qtr= result;
				while(qtr->next!=NULL)
				{
					qtr=qtr->next;
				}
				qtr->next=tmp;
		
			}
		tmp->next=NULL;
		}
		
		ptr=ptr->next;
	}
	sort(&result);
	traverse(result);
	
}




int main()
{
	struct poly *head1,*head2;
	head1=head2=NULL;
	while(1)
	{
		printf("1. Insert\n");
		printf("2. Traverse\n");
		printf("3. Addition\n");
		printf("9. Exit\n");
		int choice,n;
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the polynomial number 1 or 2 \n");
					scanf("%d",&n);
					if(n==1)
					Insert(&head1);
					else
					Insert(&head2);
					break;
			case 2: 
					printf("Enter the polynomial number 1 or 2 \n");
					scanf("%d",&n);
					if(n==1)
					traverse(head1);
					else
					traverse(head2);
					break;
			case 3: 
					Addition(head1,head2);
					break;
			case 9: exit(1);
		}
	}
}
