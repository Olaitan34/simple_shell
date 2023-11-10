#include "shell.h"


/**
 * set_work_directory - Functiont thato set the work directory
 * @data: Pointer structure for the program's data
 * @new_dir: path to be set as work directory
 * Return: return 0  of successful.
 */


int set_work_directory(data_of_program *data, char *new_dir)
{
char prev_dir[128] = {0};
int err_code = 0;

getcwd(prev_dir, 128);

if (!str_compare(prev_dir, new_dir, 0))
{
err_code = chdir(new_dir);
if (err_code == -1)
{
errno = 2;
return (3);
}
env_set_key("PWD", new_dir, data);
}
env_set_key("OLDPWD", prev_dir, data);
return (0);
}



/**
 * builtin_help - Function that shows the environment where the shell will run
 * @data: structure Pointing to the program's data
 * Return: returns 0 at  success.
 */

int builtin_help(data_of_program *data)
{
int size = 0;
int a;
char *alert[6] = {NULL};


for (a = 0; alert[a]; a++)
for (a = 0; alert[a]; a++)

alert[0] = HELP_MSG;

if (data->tokens[1] == NULL)
{
_print(alert[0] + 6);
return (1);
}
if (data->tokens[2] != NULL)
{
errno = E2BIG;
perror(data->command_name);
return (5);
}
alert[1] = HELP_EXIT_MSG;
alert[2] = HELP_ENV_MSG;
alert[3] = HELP_SETENV_MSG;
alert[4] = HELP_UNSETENV_MSG;
alert[5] = HELP_CD_MSG;

for (a = 0; alert[a]; a++)
{
size = str_length(data->tokens[1]);
if (str_compare(data->tokens[1], alert[a], size))
{
_print(alert[a] + size + 1);

return (1);
}
}
errno = EINVAL;
perror(data->command_name);
return (0);
}

/**
 * builtin_alias - Function tgat appends aliases
 * @data: Pointer to the program's data
 * Return: Returns 0 at sucess,
 */


int builtin_alias(data_of_program *data)
{
int a = 0;

if (data->tokens[1] == NULL)
return (print_alias(data, NULL));

while (data->tokens[++a])
{
if (count_characters(data->tokens[a], "="))
set_alias(data->tokens[a], data);
else
print_alias(data, data->tokens[a]);
}

return (0);
}
