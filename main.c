#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *prompt = "cisfun$ ";
	char *line;
	char **tokens = NULL;
	size_t n = 0;
	int i;
	int status = 1;
	(void) n;
	(void) i;

	while (status)
	{
		printf("%s", prompt);
		line = read_line();
		tokens = split_line(line);
		execute(tokens);
	}
	free(line);
	free(tokens);
	return (0);
}
