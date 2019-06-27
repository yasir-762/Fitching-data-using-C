/*	Assignment 1: Set B
        (b) Read the data from file emp.txt and sort on name using insertion sort(using strcmp)  */

#include<ctype.h>
#include<stdio.h>
#include<string.h>
typedef struct
{
	char name[30];
	int age;
}record;
record emp[100];

int readfile(record*);
void sort(record*,int);
main()
{
	int n;
	n=readfile(emp);
	sort(emp,n);
}

int readfile(record *a) 
{
	int i=0;
	FILE *fp;
	if((fp=fopen("abc","r"))!=NULL)
	while(!feof(fp))
	{
		fscanf(fp,"%s %d",a[i].name,&a[i].age);
		i++;
	}
//printf("%d",i);
return i-1;
fclose(fp);
}

void sort(record *a,int n )
{
	record temp[100];
	int i,j;
	for(i=0;i<n;i++)
	{
		temp[0]=a[i];
		for(j=(i-1);j>=0;j--)
		{	
			if(strcmp(a[i].name,a[j].name)<0)
			{
				a[j+1]=a[j];
				a[j]=temp[0];
			}
		}
	}
	printf("\n The Sorted list is:\n");   
	for(i=0;i<n;i++)
	{
		printf("%s %d\n",a[i].name,a[i].age);
	}
}
