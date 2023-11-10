#include "shell.h"
/**
* tokenize - this func separates the str using a designated delimiter
* @data: This is a pointer to the program's data
* Return: This returns an array of the different parts of the str
*/
void tokenize(data_of_program *data)
{
char *delimiter = " \t";
int i, j, counter = 2, length;
length = str_length(data->input_line);
if (length)
{
if (data->input_line[length - 1] == '\n')
data->input_line[length - 1] = '\0';
}
for (i = 0; data->input_line[i]; i++)
{
for (j = 0; delimiter[j]; j++)
{
if (data->input_line[i] == delimiter[j])
counter++;
}
}
data->tokens = malloc(sizeof(char *) * counter);
if (data->tokens == NULL)
{
perror(data->program_name);
exit(errno);
}
i = 0;
data->tokens[i] = str_duplicate(_strtok(data->input_line, delimiter));
data->command_name = str_duplicate(data->tokens[0]);
while (data->tokens[i++])
{
data->tokens[i] = str_duplicate(_strtok(NULL, delimiter));
}
}

