#include "shell.h"
/**
* expand_variables - this is used to expand vars
* @data: this is the pointer to the structure of the program's data
*
* Return: 0, but sets errno.
*/
void expand_variables(data_of_program *data)
{
int i, j;
char input[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;
if (data->input_line == NULL)
return;
buffer_add(input, data->input_line);
for (i = 0; input[i]; i++)
if (input[i] == '#')
input[i--] = '\0';
else if (input[i] == '$' && input[i + 1] == '?')
{
input[i] = '\0';
long_to_string(errno, expansion, 10);
buffer_add(input, expansion);
buffer_add(input, data->input_line + i + 2);
}
else if (input[i] == '$' && input[i + 1] == '$')
{
input[i] = '\0';
long_to_string(getpid(), expansion, 10);
buffer_add(input, expansion);
buffer_add(input, data->input_line + i + 2);
}
else if (input[i] == '$' && (input[i + 1] == ' ' || input[i + 1] == '\0'))
continue;
else if (input[i] == '$')
{
for (j = 1; input[i + j] && input[i + j] != ' '; j++)
expansion[j - 1] = input[i + j];
temp = env_get_key(expansion, data);
input[i] = '\0', expansion[0] = '\0';
buffer_add(expansion, input + i + j);
temp ? buffer_add(input, temp) : 1;
buffer_add(input, expansion);
}
if (!str_compare(data->input_line, input, 0))
{
free(data->input_line);
data->input_line = str_duplicate(input);
}
}
/**
* expand_alias - this expands aliases
* @data: this is a pointer to the structure of the program's data
*
* Return: 0, but sets errno.
*/
void expand_alias(data_of_program *data)
{
int i, j, was_expanded = 0;
char input[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;
if (data->input_line == NULL)
return;
buffer_add(input, data->input_line);
for (i = 0; input[i]; i++)
{
for (j = 0; input[i + j] && input[i + j] != ' '; j++)
expansion[j] = input[i + j];
expansion[j] = '\0';
temp = get_alias(data, expansion);
if (temp)
{
expansion[0] = '\0';
buffer_add(expansion, input + i + j);
input[i] = '\0';
buffer_add(input, temp);
input[str_length(input)] = '\0';
buffer_add(input, expansion);
was_expanded = 1;
}
break;
}
if (was_expanded)
{
free(data->input_line);
data->input_line = str_duplicate(input);
}
}
/**
* buffer_add - function to add string to the end of the buffer
* @buffer: this is the buffer to be filled
* @str_to_add: this is the string to be copied in the buffer
* Return: 0, but sets errno.
*/
int buffer_add(char *buffer, char *str_to_add)
{
int length, i;
length = str_length(buffer);
for (i = 0; str_to_add[i]; i++)
{
buffer[length + i] = str_to_add[i];
}
buffer[length + i] = '\0';
return (length + i);
}

