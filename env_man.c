#include "shell.h"

/**
 * env_get_key - Function to get environmental variable
 * @key: The parameter carrying environmental variable of choice
 * @data: Variable whivh is the structure of the program's data
 * Return: returns a pointer to the value of the variable
 */


char *env_get_key(char *key, data_of_program *data)
{
int i, keySize = 0;

/*This will validate the arg */
if (key == NULL || data->env == NULL)
return (NULL);

/* This will obtain the len of the variable requested */
keySize = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this will loop through the environ and check for coincidence of the vame */
if (str_compare(key, data->env[i], keySize) &&
data->env[i][keySize] == '=')
{/* this will return the value of the key NAME=  when find it*/
return (data->env[i] + keySize + 1);
}
}
/* it will return NULL if key is not found */
return (NULL);
}



/**
 * env_set_key - Functuon to  overwrite the value of the env variable
 * or create if does not exist.
 * @key: variable to set
 * @value: variable of the new value
 * @data: This is the structure of the program's data
 * Return: return 1 if the parameters are NULL
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
int i, keySize = 0, newKey = 1;

/* this will validate the arg */
if (key == NULL || value == NULL || data->env == NULL)
return (1);

/* this will get the len of the variable requested */
keySize = str_length(key);

for (i = 0; data->env[i]; i++)
{/* this will loop through the environ and check for coincidence of the vame */
if (str_compare(key, data->env[i], keySize) &&
data->env[i][keySize] == '=')
{/* This checks if key exists */
newKey = 0;
/* this frees the entire variable, it is new created below */
free(data->env[i]);
break;
}
}
/* this is to make a string of the form key=value */
data->env[i] = str_concat(str_duplicate(key), "=");
data->env[i] = str_concat(data->env[i], value);

if (newKey)
{/*checks if the variable is new, it is create at end*/
data->env[i + 1] = NULL;
}
return (0);
}
