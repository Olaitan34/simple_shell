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
/**
* sisifo - Function which is an infinite loop that shows the prompt
* @prompt: variable carrying the prompt to be printed
* @data: variable carrying an infinite loop that shows the prompt
*/
void sisifo(data_of_program *data)
{
int error = 0;
int len = 0;
while (++(data->exec_counter))
{
_print("$ ");
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

