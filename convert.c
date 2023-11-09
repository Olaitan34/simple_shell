#include "shell.h"
/**
* long_to_string - Function that converts number to string.
* @number: variable of number to be converted into string.
* @string: buffer that saves the string the number was converted to.
* @base: this is a base to convert number
*
* Return: 0.
*/
void long_to_string(long number, char *string, int base)
{
int a = 0;
int nonNegative = 0;
long cociente = number;
char alph[] = {"0123456789abcdef"};
if (cociente == 0)
string[a++] = '0';
if (string[0] == '-')
nonNegative = 1;
while (cociente)
{
if (cociente < 0)
string[a++] = alph[-(cociente % base)];
else
string[a++] = alph[cociente % base];
cociente /= base;
}
if (nonNegative)
string[a++] = '-';
string[a] = '\0';
str_reverse(string);
}
/**
* _atoi - Function that changes string to number.
*
* @s: pointer to string.
* Return: nothing or int of string.
*/
int _atoi(char *s)
{
int simbol = 1;
unsigned int number = 0;
/*1- analisys sign*/
while (!('0' <= *s && *s <= '9') && *s != '\0')
{
if (*s == '-')
simbol *= -1;
if (*s == '+')
simbol *= +1;
s++;
}
/*2 - extract the number */
while ('0' <= *s && *s <= '9' && *s != '\0')
{
number = (number * 10) + (*s - '0');
s++;
}
return (number *simbol);
}
/**
* count_characters - this counts the coincidences of char in string.
*
* @string: this is a pointer to str origin.
* @character: this is string with  characters to be counted
* Return: nothing or int of string.
*/
int count_characters(char *string, char *character)
{
int a = 0, ctr = 0;
for (; string[a]; a++)
{
if (string[a] == character[0])
ctr++;
}
return (ctr);
}

