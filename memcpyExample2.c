/*
This is sample program to illustrate the memcpy of array of ints
*/


#include<stdio.h>
#include<string.h>
#define MAX 100

int main()
{

int data[]= {10,20,30,40,50};
int *buffer;
buffer = malloc(sizeof(data));

memcpy(buffer,data,sizeof(data));
int i=0;
int arrayLen = sizeof(data)/sizeof(data[0]);

while(i<arrayLen){
printf("%d ",buffer[i]);
i++;
}

return 0;

}

/*

output:
10 20 30 40 50 

*/
