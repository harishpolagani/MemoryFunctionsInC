#include<stdio.h>
#include<string.h>
#define MAX 20

#define LOG_ENABLE_FLAG 1 
#define printVal(x) if(LOG_ENABLE_FLAG) printf("%d \n",x)
#define printString(name) if(LOG_ENABLE_FLAG) printf("%s:",#name)
	
int printArray(int src[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("%d ",src[i]);
	}
	printf("\n");
	return 0;
}
int arraySize(int array[])
{
	return (sizeof(array)/sizeof(array[0]));
}

int main()
{
	int src[] ={10,20,30,40,50};
	int new[]={60,70,80,90,100};
	int *buffer;
	//[MAX]={110,120,130,140,150};
	
	int arrayLen = sizeof(src)/sizeof(src[0]);
	printVal(arrayLen);
	printString(src);
	printArray(src,arrayLen);
	
	//memcpy
	puts("memcpy: ");
	buffer = malloc(sizeof(src));
	memcpy(buffer,src,sizeof(src));
	
	printString(src);
	printArray(src,arrayLen);
	printString(buffer);
	printArray(buffer,arrayLen);
	
	//memmove
	puts("memmove: ");
	buffer = malloc(sizeof(src));
	memmove(buffer,new,sizeof(src));
	
	printString(new);
	printArray(new,arrayLen);
	printString(buffer);
	printArray(buffer,arrayLen);
	
	//memcmp: 
	puts("memcmp: ");
	if(!memcmp(new,buffer,sizeof(new)))
	{	
		puts("match found");
	}
	else
		puts("oops! match not found");
	

	puts("memchr: ");
	int *ret = memchr(buffer,80,sizeof(new));
	if(ret)
		printf("value found: %d @ %p\n",*ret,&ret);
	else
		puts("value not found");
	
	//memset:
	puts("memset: ");
	
	//if value 90 is found clear that particular vale to zero.
	puts("clear only match found value:");
	ret = memchr(buffer,90,sizeof(new));
	if(ret)
	{
		printf("value found: %d @ %p\n",*ret,ret);
		memset(ret,0,sizeof(int));
		printString(buffer);
		printArray(buffer,arrayLen);
	}	
	else
		puts("value not found");
		
	
	//clear entire buffer
	puts("clear entire buffer");
	memset(buffer,0,sizeof(src));
	printString(buffer);
	printArray(buffer,arrayLen);
	
	return 0;
}


/*
output:
5
src:10 20 30 40 50
memcpy:
src:10 20 30 40 50
buffer:10 20 30 40 50
memmove:
new:60 70 80 90 100
buffer:60 70 80 90 100
memcmp:
match found
memchr:
value found: 80 @ 0x7ffea519b8b0
memset:
clear only match found value:
value found: 90 @ 0x12f744c
buffer:60 70 80 0 100
clear entire buffer
buffer:0 0 0 0 0

*/
