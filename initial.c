#include "shell.h"

/**
 * handle_ctrl_c - Funvtion that prints the prompt in a new line
 * @UNUSED: The option of the prototype, itbis an integer variable
 */

void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print("$ ");
}


/**
 * initialize_data - Function that initializes the structs
 * @data: variable which is a pointer to the struct of data
 * @argv: variable which is an array of arg passed to the program execution
 * @env: variable which is environ passed to the program execution
 * @argc: this is the num of values received from the command line
 */

void initialize_data(data_of_program *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
	{
		data->file_descriptor = STDIN_FILENO;
	}
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_printe(data->program_name);
			_printe(": 0: Can't open ");
			_printe(argv[1]);
			_printe("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
