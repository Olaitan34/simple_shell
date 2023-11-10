#include "shell.h"
<<<<<<< HEAD
/**
* str_length - This function returns the length of a string
* @string: Pointing to tye sring whose length will be checked
* Return: return the length of string at success
*/
int str_length(char *string)
{
int len = 0;
if (string == NULL)
return (0);
while (string[len++] != '\0')
{
}
return (--len);
}
/**
* str_duplicate - Function that duplucates the string
* @string: pointer to tye string that should be duplicated
* Return: This is the pointer to an array
*/
char *str_duplicate(char *string)
{
char *cpy;
int len, a;
if (string == NULL)
return (NULL);
len = str_length(string) + 1;
cpy = malloc(sizeof(char) * len);
if (cpy == NULL)
{
errno = ENOMEM;
perror("Error");
return (NULL);
}
for (a = 0; a < len ; a++)
{
cpy[a] = string[a];
}
return (cpy);
}
/**
* str_compare - function that compares two strings
* @string1: The pointer to the first string to be compared
* @string2: The pointer to the second string to be compared
* @number: this is the num of chars to be compared, 0 if infinite
* Return: returns 1 if the str are equals,and 0 if the str are different
*/
int str_compare(char *string1, char *string2, int number)
{
int iterate;
if (string1 == NULL && string2 == NULL)
return (1);
if (string1 == NULL || string2 == NULL)
return (0);
if (number == 0)
{
if (str_length(string1) != str_length(string2))
return (0);
for (iterate = 0; string1[iterate]; iterate++)
{
if (string1[iterate] != string2[iterate])
return (0);
}
return (1);
}
else /* this checks if there is a number of characters to be compared */
{
for (iterate = 0; iterate < number ; iterate++)
{
if (string1[iterate] != string2[iterate])
return (0);
}
return (1);
}
}

=======


/**
 * str_length - This function returns the length of a string
 * @string: Pointing to tye sring whose length will be checked
 * Return: return the length of string at success
 */

int str_length(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);

	while (string[len++] != '\0')
	{
	}
	return (--len);
}



/**
 * str_duplicate - Function that duplucates the string
 * @string: pointer to tye string that should be duplicated
 * Return: This is the pointer to an array
 */

char *str_duplicate(char *string)
{
	char *cpy;
	int len, a;

	if (string == NULL)
		return (NULL);

	len = str_length(string) + 1;

	cpy = malloc(sizeof(char) * len);

	if (cpy == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (a = 0; a < len ; a++)
	{
		cpy[a] = string[a];
	}

	return (cpy);
}

/**
 * str_compare - function that compares two strings
 * @string1: The pointer to the first string to be compared
 * @string2: The pointer to the second string to be compared
 * @number: this is the num of chars to be compared, 0 if infinite
 * Return: returns 1 if the str are equals,and 0 if the str are different
 */


int str_compare(char *string1, char *string2, int number)
{
	int iterate;

	if (string1 == NULL && string2 == NULL)
		return (1);

	if (string1 == NULL || string2 == NULL)
		return (0);

	if (number == 0)
	{
		if (str_length(string1) != str_length(string2))
			return (0);
		for (iterate = 0; string1[iterate]; iterate++)
		{
			if (string1[iterate] != string2[iterate])
				return (0);
		}
		return (1);
	}
	else /* this checks if there is a number of characters to be compared */
	{
		for (iterate = 0; iterate < number ; iterate++)
		{
			if (string1[iterate] != string2[iterate])
			return (0);
		}
		return (1);
	}
}
>>>>>>> 9656c011f88a68123be082c9389745f1cfc00c9e
