#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "macro.h"

/**
 * struct info- Function that is structure for the program's data
 * @program_name: This is the name of the executable
 * @input_line:This is the pointer to input read for _getline
 * @command_name: This is the pointer to first command typed by the user
 * @exec_counter: This is the number of excecuted comands
 * @file_descriptor: This is the file descriptor to input of commands
 * @tokens: This is the pointer to array of tokenized input
 * @env: This is the copy of the environ
 * @alias_list: This is array of pointers with aliases.
 * @data_struct: this is a character structure.
 */
typedef struct info
{
char *program_name;
char *input_line;
char data_struct;
char *command_name;
int exec_counter;
int file_descriptor;
char **tokens;
char **env;
char **alias_list;
} data_of_program;

/**
 * struct builtins - Function that is the structure for builtins
 * @builtin: This is the name of the builtin
 * @function: This is the associated function to be called for each builtin
 */

typedef struct builtins
{
	char *builtin;
	int (*function)(data_of_program *data);
} builtins;
int builtin_set_env(data_of_program *data);
int builtin_unset_env(data_of_program *data);

int builtin_env(data_of_program *data);

void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);
int builtin_cd(data_of_program *data);
int builtin_exit(data_of_program *data);
int set_work_directory(data_of_program *data, char *new_dir);
int builtin_help(data_of_program *data);
int builtin_alias(data_of_program *data);
void sisifo(char *prompt, data_of_program *data);
void initialize_data(data_of_program *data, int arc, char *argv[], char **env);
void handle_ctrl_c(int opr UNUSED);
int check_logic_ops(char *array_commands[], int i, char array_operator[]);
int _getline(data_of_program *data);
int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);
int print_alias(data_of_program *data, char *alias);
char *get_alias(data_of_program *data, char *alias);
int set_alias(char *alias_string, data_of_program *data);
void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);
void expand_variables(data_of_program *data);
void expand_alias(data_of_program *data);
int buffer_add(char *buffer, char *str_to_add);
char **tokenize_path(data_of_program *data);
int find_program(data_of_program *data);
int execute(data_of_program *data);
int builtins_list(data_of_program *data);
char *env_get_key(char *name, data_of_program *data);
int env_set_key(char *key, char *value, data_of_program *data);
int env_remove_key(char *key, data_of_program *data);
void print_environ(data_of_program *data);
void free_array_of_pointers(char **directories);
void free_recurrent_data(data_of_program *data);
void free_all_data(data_of_program *data);
int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, data_of_program *data);
void tokenize(data_of_program *data);
char *_strtok(char *line, char *delim);

#endif
