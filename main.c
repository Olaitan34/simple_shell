#include "shell.h"
/**
 * main - The Function which is tge entry ooint of the entire shell
 * @argc: The variable which is tye argument count
 * @argv: The variable that recieves argument from the command line
 * @env: Pointer to the string of the environment
 * Return: Returns 0 (zero) on success.
 */
int main(int argc, char *argv[], char *env[])
{
	data_of_program data_struct = {STDIN_FILENO}; 
	data_of_program *data = &data_struct;

	initialize_data(data, argc, argv, env);

		signal(SIGINT, handle_ctrl_c);

		if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
		{
			errno = 2;
		}
		errno = 0;

		sisifo(data);

	return (0);
}
