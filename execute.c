#include "shell.h"
/**
 * execute - Function that executes a command with its entire path var.
 * @data: pointer to the program's data
 * Return: If sucess returns 0.
 */

int execute(data_of_program *data)
{
	int RV = 0, waitstatus;
	pid_t pidd;

	RV = builtins_list(data);
	if (RV != -1)/* checks if the program was found in built ins */
		return (RV);
	RV = find_program(data);
	if (RV)
	{
		return (RV);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{ /* checks if the fork call failed */
			perror(data->command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{/* this is the child process, it executes the program*/
			RV = execve(data->tokens[0], data->tokens, data->env);
			if (RV == -1) /* if error when execve*/
				perror(data->command_name), exit(EXIT_FAILURE);
		}
		else
		{/* This is the father process, it waits and check the exit status */
			wait(&waitstatus);
			if (WIFEXITED(waitstatus))
				errno = WEXITSTATUS(waitstatus);
			else if (WIFSIGNALED(waitstatus))
				errno = 128 + WTERMSIG(waitstatus);
		}
	}
	return (0);
}
