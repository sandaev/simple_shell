#include "main.h"
/**
* read_line - Function reads a line of code
*
* Return: line
*
*/

char *read_line(void)
{
	char *line;
	size_t n = 0;
	ssize_t num_line;

	num_line = getline(&line, &n, stdin);
	if (num_line == -1)
	{
		return (NULL);
	}
	return (line);
}
/**
 * split_line - splits string into array of words
 *
 * @line: Pointer to string to split
 *
 * Return: Adress of pointer to array of words
 */
char **split_line(char *line)
{
	char **tokens = NULL;
	char *line_copy;
	char *token = NULL;
	char *tok;
	int num_toks = 0;
	int i;
	char *delim = "\n";

	line_copy = strdup(line);
	/* Get number of words (commanda) in string */
	tok = strtok(line, delim);
	while (tok != NULL)
	{
		num_toks++;
		tok = strtok(NULL, delim);
	}
	num_toks++;
	/* Allocate memory to hold number of tokens */
	tokens = malloc(sizeof(char *) * num_toks);
	if (tokens == NULL)
	{
		perror("./shell");
		exit(0);
	}
	/* Add each word (command) to the array */
	tok = strtok(line_copy, delim);
	for (i = 0; tok != NULL; i++)
	{
		token = malloc(sizeof(char) * strlen(tok));
		if (token == NULL)
		{
			perror("./shell");
			exit(0);
		}
		strcpy(token, tok);
		tokens[i] = token;
		tok = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	free(line_copy);
	return (tokens);
}

/**
 * execute- Function executes commands in the shell
 * @args: Double pointer parameter
 * Description: Executes commands entered in the shell
 *
 * Return: the output of the command and cisfun if error is encountered
 */
void execute(char **args)
{
	pid_t child_pid = fork();
	int stat;
	extern char *environ;

	if (child_pid == 0)
	{
		if (args[0] != NULL)
		{
		execve(args[0], args, &environ);
		perror("./shell");
		exit(0);

		}
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &stat, WUNTRACED);
		} while (!WIFEXITED(stat) && !WIFSIGNALED(stat));
	}
	else
	{
		perror("./shell");
	}
}
