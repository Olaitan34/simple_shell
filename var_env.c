#include "shell.h"


/**
 * builtin_env - Display the environment in which the shell is running.
 *
 * @data: The program's data structure.
 * Return: 0 if the function is successful.
 */

int builtin_env(data_of_program *data)
{
	int i;
	char cpName[50] = {'\0'};

	char *varCP = NULL;

	if (data->tokens[1] == NULL)
		print_environ(data);
	else
	{
	for (i = 0; data->tokens[1][i]; i++)
	{
	if (data->tokens[1][i] == '=')
	{
		varCP = str_duplicate(env_get_key(cpName, data));
		if (varCP != NULL)
			env_set_key(cpName, data->tokens[1] + i + 1, data);

		print_environ(data);
		if (env_get_key(cpName, data) == NULL)
		{
			_print(data->tokens[1]);
			_print("\n");
		}
		else
		{
			env_set_key(cpName, varCP, data);
			free(varCP);
		}
		return (0);
	}
	cpName[i] = data->tokens[1][i];
	}
	errno = 2;
	perror(data->command_name);
	errno = 127;
	}
	return (0);
}

/**
 * builtin_unset_env - Unset environment variables.
 *
 * @data: The program's data structure.
 * Return: The specific return value should be described in this comment.
 */

int builtin_unset_env(data_of_program *data)
{
	/* validate args */
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_remove_key(data->tokens[1], data);

	return (0);
}

/**
 * builtin_set_env - Set environment variables.
 *
 * @data: The program's data structure.
 * Return: 0 if the function is successful.
 */

int builtin_set_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}
