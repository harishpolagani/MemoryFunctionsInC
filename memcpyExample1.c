#include<stdio.h>
#include<string.h>
#define MAX 100

int main()
{

char data[]= "hello this is memcpy Example1 ";
char *buffer;
buffer = malloc(strlen(data)*sizeof(char));

memcpy(buffer,data,sizeof(data));
puts(buffer);

return 0;

}
