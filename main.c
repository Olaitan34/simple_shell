#include "shell.h"



/**
 * main - This initializes the vars of the program
 * @argc: This is the num of vals received from the command line
 * @argv: This is the val received from the command line
 * @env: This is the num of vals received from the command line
 * Return: returns 0 on succes.
 */

int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	initialize_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	sisifo(prompt, data);
	return (0);
}
