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
	size_t num_line;

	getline(&line, &n, stdin);
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
	char *delim = " \t\r\n";

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
		perror("cisfun");
		exit(-1);
	}
	/* Add each word (command) to the array */
	tok = strtok(line_copy, delim);
	for (i = 0; tok != NULL; i++)
	{
		token = malloc(sizeof(char) * strlen(tok));
		if (token == NULL)
		{
			perror("cisfun");
			exit(-1);
		}
		strcpy(token, tok);
		tokens[i] = token;
		tok = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
