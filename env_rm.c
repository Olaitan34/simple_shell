#include "shell.h"


/**
 * env_remove_key - Function that removes environmental key
 * @key: Variable of key to be removed
 * @data: The structure if tge program data
 * Return: return 1 at success
 */

int env_remove_key(char *key, data_of_program *data)
{
int i;
int keySize = 0;

if (key == NULL || data->env == NULL)
return (0);

/* this will obtain the len of the variable requested */
keySize = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this loops through the environ and checks for coincidences */
if (str_compare(key, data->env[i], keySize) &&
data->env[i][keySize] == '=')
{/* this will remove the key if already exists */
free(data->env[i]);
/* this will move the other key down in one position */
i++;
for (; data->env[i]; i++)
{
data->env[i - 1] = data->env[i];
}
/* put the NULL value at the new end of the list */
data->env[i - 1] = NULL;
return (1);
}
}
return (0);
}


/**
 * print_environ - Function to print current encuronment
 * @data: variable which is the structure for the program's data
 * Return: 0
 */

void print_environ(data_of_program *data)
{
int a;

for (a = 0; data->env[a]; a++)
{
_print(data->env[a]);
_print("\n");
}
}
