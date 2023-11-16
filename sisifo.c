#include "shell.h"
/**
 * sisifo - Function which is an infinite loop that shows the prompt
 *
 * @data: variable carrying an infinite loop that shows the prompt
 */

void sisifo(char *prompt, data_of_program *data)
{
	int error = 0;
	int len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);

		error = len = _getline(data);

		if (error == EOF)
		{
			free_all_data(data);
			exit(errno);
		}
		if (len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);
			if (data->tokens[0])
			{
				error = execute(data);
				if (error != 0)
					_print_error(error, data);
			}
			free_recurrent_data(data);
		}
	}
}
