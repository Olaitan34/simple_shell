#include "shell.h"

int check_file(char *full_path);



/**
 * find_program - Func to find a program in path
 * @data: Pointer to the program's data
 * Return: 0 if successful, otherwise errcode
 */

int find_program(data_of_program *data)
{
	int a = 0, Rcode = 0;
	char **dir;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (check_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_concat(str_duplicate("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	dir = tokenize_path(data);/* search in the PATH */

	if (!dir || !dir[0])
	{
		errno = 127;
		return (127);
	}
	for (a = 0; dir[a]; a++)
	{/* this adds the function_name to path */
		dir[a] = str_concat(dir[a], data->tokens[0]);
		Rcode = check_file(dir[a]);
		if (Rcode == 0 || Rcode == 126)
		{/* checks if the file was found, is not a directory*/
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_duplicate(dir[a]);
			free_array_of_pointers(dir);
			return (Rcode);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_array_of_pointers(dir);
	return (Rcode);
}


/**
 * tokenize_path - this is to tokenize the path in directories
 * @data: this is the pointer to the program's data
 * Return: this returns array of path directories
 */

char **tokenize_path(data_of_program *data)
{
	int a = 0;
	int ctr_dir = 2;
	char **tkn = NULL;
	char *PATH;
	/* this is to get the PATH value*/
	PATH = env_get_key("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{/*this checks if path is not found*/
		return (NULL);
	}

	PATH = str_duplicate(PATH);

	/* get the number of directories in the PATH */
	for (a = 0; PATH[a]; a++)
	{
		if (PATH[a] == ':')
			ctr_dir++;
	}

	/* this is a reserve space for the array of pointers */
	tkn = malloc(sizeof(char *) * ctr_dir);

	/*this is to tokenize and duplicate each token of path*/
	a = 0;
	tkn[a] = str_duplicate(_strtok(PATH, ":"));
	while (tkn[a++])
	{
		tkn[a] = str_duplicate(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tkn);

}


/**
 * check_file - Function to checks if a file exists, if
 * if it has exec permisions.
 * @full_path: Pointer to the full file name
 * Return: 0 on success.
 */
int check_file(char *full_path)
{
	struct stat sb;

	if (stat(full_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(full_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	/* checks if file does not exist*/
	errno = 127;
	return (127);
}
