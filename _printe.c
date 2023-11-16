#include "shell.h"


/**
 * _print -  Write an array of characters to standard output.
 *
 * This function is responsible for writing the provided array of
 * characters to the standard output.
 * @string: A pointer to the array of characters to be written.
 *Return: The number of bytes written on success. On error,
 *it returns -1, and sets the appropriate errno.
 */

int _print(char *string)
{
	return (write(STDOUT_FILENO, string, str_length(string)));
}


/**
 *_printe -  Write an array of characters to the standard error stream.
 *
 * This function is used to write the provided array of
 *characters to the standard error stream.
 * @string: A pointer to the array of characters to be written.
 * Return:The number of bytes written on success. On error,
 *it returns -1, and sets the appropriate errno.
 */

int _printe(char *string)
{
	return (write(STDERR_FILENO, string, str_length(string)));
}


/**
 * _print_error - this will write an array of character in the std error
 * @data: this is a pointer to the program's data'
 * @errorcode: this is the error code to print
 * Return: this will return the number of bytes writed
 * On error, return -1, and errno is set appropriately.
 */

int _print_error(int errorcode, data_of_program *data)
{
	char conv_string[10] = {'\0'};

	long_to_string((long) data->exec_counter, conv_string, 10);

	if (errorcode == 2 || errorcode == 3)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(conv_string);
		_printe(": ");
		_printe(data->tokens[0]);
		if (errorcode == 2)
			_printe(": Illegal number: ");
		else
			_printe(": can't cd to ");
		_printe(data->tokens[1]);
		_printe("\n");
	}
	else if (errorcode == 127)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(conv_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": not found\n");
	}
	else if (errorcode == 126)
	{
		_printe(data->program_name);
		_printe(": ");
		_printe(conv_string);
		_printe(": ");
		_printe(data->command_name);
		_printe(": Permission denied\n");
	}
	return (0);
}
