#include "shell.h"
/**
* str_length - Function that calculates the length of a string.
* @string: The input string.
* Return: The length of the string.
*/
int str_length(char *string)
{
int length = 0;
while (string[length] != '\0')
{
length++;
}
return (length);
}

