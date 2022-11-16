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
