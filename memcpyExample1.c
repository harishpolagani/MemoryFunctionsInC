#include<stdio.h>
#include<string.h>
#define MAX 100

int main()
{

char data[]= "hello this is memcpy Example-1 ";
char *buffer;
buffer = malloc(strlen(data)*sizeof(data[0]));

memcpy(buffer,data,sizeof(data));
puts(buffer);

return 0;

}
