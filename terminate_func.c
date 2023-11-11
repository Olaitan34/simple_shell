#include "shell.h"

/**
 * builtin_exit - Function to terminate the program with a specified status code.
 *
 * This function is responsible for gracefully terminating the program with the specified exit status code.
 *
 * @param data - The program's data structure.
 * @return 0 if the function successfully terminates the program, otherwise, it returns an error code.
 */

int builtin_exit(data_of_program *data)
{
int a;

if (data->tokens[1] != NULL)
{
for (a = 0; data->tokens[1][a]; a++)
if ((data->tokens[1][a] < '0' || data->tokens[1][a] > '9')
&& data->tokens[1][a] != '+')
{
errno = 2;
return (2);
}
errno = _atoi(data->tokens[1]);
}
free_all_data(data);
exit(errno);
}

/**
 * builtin_cd - Function to change the current working directory
 * @data: Parameter which is the struct for the program's data
 * Return: 0 at success.
 */

int builtin_cd(data_of_program *data)
{
	char *home = env_get_key("HOME", data), *dirOld = NULL;
	char oldDir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dirOld = env_get_key("OLDPWD", data);
			if (dirOld)
				error_code = set_work_directory(data, dirOld);
			_print(env_get_key("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (set_work_directory(data, data->tokens[1]));
		}
	}
	else
	{
		if (!home)
			home = getcwd(oldDir, 128);

		return (set_work_directory(data, home));
	}
	return (0);
}

                                                                                                     /**
 * Search for a match and execute the associated built-in command.
 *
 * @data - The program's data structure.                                                              * return The return value of the executed function, or -1 if no match is found.
 */

int builtins_list(data_of_program *data)
{
        int iterate;
        builtins options[] = {
        {"exit", builtin_exit},
        {"help", builtin_help},
        {"cd", builtin_cd},
        {"alias", builtin_alias},                                                                            {"env", builtin_env},
        {"setenv", builtin_set_env},
        {"unsetenv", builtin_unset_env},
        {NULL, NULL}};
        for (iterate = 0; options[iterate].builtin != NULL; iterate++)
        {
                if (str_compare(options[iterate].builtin, data->command_name, 0))
                {
                        return (options[iterate].function(data));
                }
        }
        return (-1);
}
