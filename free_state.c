#include "main.h"
/**
 * free_state - <-- TODO -->
 *
 * @tokens: <-- TODO -->
 * @exe_path: <-- TODO -->
 *
 * Retrun: void
 */
void free_state(char **tokens, char *exe_path)
{
	int i;

	if (exe_path != NULL)
	{
		free(exe_path);
		exe_path = NULL;
	}

	if (tokens != NULL)
	{
		for (i = 0; tokens[i] != NULL; i++)
			free(tokens[i]);

		free(tokens);
		tokens = NULL;
	}

	printf("Memory freed\n");
}
