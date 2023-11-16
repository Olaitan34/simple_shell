#include "shell.h"
/**
 * free_recurrent_data - Function that frees the field
 * @data: Pointer to the data variable
 * Return: 0
 */
void free_recurrent_data(data_of_program *data)
{
	if (data->tokens)
		free_array_of_pointers(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}
/**
 * free_all_data - Function that frees all field of data
 * @data: pointer tontye data variable
 * Return: 0
 */
void free_all_data(data_of_program *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data->env);
	free_array_of_pointers(data->alias_list);
}

/**
 * free_array_of_pointers - Function that frees pointer of array.
 * @array: array of pointers.
 * Return: 0.
 */
void free_array_of_pointers(char **array)
{
	int a;

	if (array != NULL)
	{
		for (a = 0; array[a]; a++)
			free(array[a]);

		free(array);
		array = NULL;
	}
}
