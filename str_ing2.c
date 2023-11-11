#include "shell.h"
/**
 * str_concat - Function that helps concatenates two strings.
 * @string1: The first string to be conc
 * @string2: second string to be conc
 *
 * Return: Returns a pointer to the array
 */

char *str_concat(char *string1, char *string2)
{
	char *outcome;
	int size1 = 0, size2 = 0;

	if (string1 == NULL)
		string1 = "";
	size1 = str_length(string1);

	if (string2 == NULL)
		string2 = "";
	size2 = str_length(string2);

	outcome = malloc(sizeof(char) * (size1 + size2 + 1));
	if (outcome == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	/* copy of the first str */
	for (size1 = 0; string1[size1] != '\0'; size1++)
		outcome[size1] = string1[size1];
	free(string1);

	/* copy of the second str*/
	for (size2 = 0; string2[size2] != '\0'; size2++)
	{
		outcome[size1] = string2[size2];
		size1++;
	}

	outcome[size1] = '\0';
	return (outcome);
}


/**
 * str_reverse - Function that helps to reverses a str.
 *
 * @string:  pointer to str.
 * Return: void.
 */

void str_reverse(char *string)
{

	int a = 0, size = str_length(string) - 1;
	char hld;

	while (a < size)
	{
		hld = string[a];
		string[a++]= string[size];
		string[size--] = hld;
	}
}
