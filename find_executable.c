#include "main.h"

int find_executable(char **env, char *exe, char *exe_path_name)
{
    int i = 0;
    char *path_unparsed = NULL;
    char *path_parsed = NULL;
    char path_parsed_cat[1024];
    struct stat file_stat;


    while (env[i] != NULL) {
        if (strcmp(strtok(env[i], "="), "PATH") == 0)
            break;

        i++;
    }

    path_unparsed = strtok(NULL, "=");

    /* the path_unparsed looks like this :
     * /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
     *
     * we need to parse it again
     **/

    path_parsed = strtok(path_unparsed, ":");

    while (path_parsed != NULL)
	{
	    strcpy(path_parsed_cat, path_parsed);
	    strcat(path_parsed_cat, "/");
	    strcat(path_parsed_cat, exe);

	    printf("Checking path: %s\n", path_parsed_cat);

	    if (stat(path_parsed_cat, &file_stat) == 0)
	    {
		strcpy(exe_path_name, path_parsed_cat);
		printf("Executable path found: %s\n", exe_path_name);
		return (1);
	    }

	    path_parsed = strtok(NULL, ":");
	}

	printf("I'm here outside\n");

	return (0);
}

