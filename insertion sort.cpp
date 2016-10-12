/* Insertion Sort */

#include<malloc.h>
#include<stdio.h>

int main()
{
	int array[15];
	int i=0;
	for(i=0 ; i<15 ; i++)
	{
		scanf("%d",&array[i]);
	}
	
	for(i=1 ; i<15 ;i++)
	{
		int temp=array[i];
		int j;
		for(j=i-1 ; j>=0 && array[j]>temp ;j--)
		array[j+1]=array[j];
		array[j+1]=temp;
	}
	
	for(i=0 ; i<15 ; i++)
	{
		printf("%d ",array[i]);
	}
	
}
