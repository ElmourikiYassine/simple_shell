#include "main.h"
/**
 * handle_env_command - <--TODO-->
 * @tokens: <--TODO-->
 * @env: <--TODO-->
 * Return: <--TODO-->
 * 
*/
    extern char **environ;

int handle_env_command(char **env)
{
    int i = 0;
    env = environ;

    while (env[i])
    {
        printf("%s\n", env[i]);
        i++;
    }

    return 1;
    
}