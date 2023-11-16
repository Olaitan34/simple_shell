#include "shell.h"

/**
 * set_alias - Function to set or override an alias.
 *
 * This function is used to add or override an alias in the program.
 *
 * @alias_string: The alias string to be set in the specified format.
 * @data: The data structure for the program's data.
 * Return: It returns zero on success.
 */

int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);

	for (i = 0; alias_string[i]; i++)
		if (alias_string[i] != '=')
			buffer[i] = alias_string[i];
		else
		{
			temp = get_alias(data, alias_string + i + 1);
			break;
		}

	for (j = 0; data->alias_list[j]; j++)
		if (str_compare(buffer, data->alias_list[j], i) &&
			data->alias_list[j][i] == '=')
		{
			free(data->alias_list[j]);
			break;
		}

	if (temp)
	{
		buffer_add(buffer, "=");
		buffer_add(buffer, temp);
		data->alias_list[j] = str_duplicate(buffer);
	}
	else
		data->alias_list[j] = str_duplicate(alias_string);
	return (0);
}



/**
 * get_alias - Perform operations to add, remove, or display aliases.
 *
 * This function allows you to manage aliases, including adding, removing,
 * or displaying them based on the provided parameters.
 *
 * @data: The data structure for the program's data.
 * @name: The name of the requested alias.
 * Return: Returns 0 on success or a different number if an error occurs.
 */

char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	/* this is to validate the args */
	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i = 0; data->alias_list[i]; i++)
	{/* this loops through the environ and check for coincidence of the varname */
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[i][alias_length] == '=')
		{/* this returns the val of the key when found */
			return (data->alias_list[i] + alias_length + 1);
		}
	}

	return (NULL);

}


/**
 * print_alias - Display the specified alias.
 *
 * This function is used to display the contents of a specific alias.
 *
 * @data: The data structure for the program's data.
 * @alias: The name of the alias to be printed.
 * Return: Returns 0 on success or a different number if an error occurs.
 */

int print_alias(data_of_program *data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data->alias_list[i]; i++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
			&&      data->alias_list[i][alias_length] == '='))
			{
				for (j = 0; data->alias_list[i][j]; j++)
				{
					buffer[j] = data->alias_list[i][j];
					if (data->alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data->alias_list[i] + j + 1);
				buffer_add(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}
