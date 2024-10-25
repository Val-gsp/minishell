#include "../include/minishell.h"


void    init_env(t_data *data, char **envp_system)
{
    int i;
    int j;

    i = 0;
    // compter le nbr de variable env
    while (envp_system[i] != NULL)
        i++;

    // memoire
    data->envp = malloc(sizeof(char *) * (i + 1));
    if (!data->envp)
    {
        perror("Error alloc memoire");
        exit(EXIT_FAILURE);
    }
    j = 0;
    while (j < i)
    {
        data->envp[j] = strdup(envp_system[j]);
        if  (!data->envp[j])
        {
            perror("Error lors de la dupli de la chaine");
            exit(EXIT_FAILURE);
        }
        j++;
    }
    data->envp[i] = NULL; 
}


void    ft_env(t_data *data)
{
    int i;

    i = 0;
    while (data->envp[i] != NULL)
    {
        printf("%s\n", data->envp[i]);
        i++;
    }
}

void    free_envp(t_data *data)
{
    int i;

    i = 0;
    while (data->envp[i] != NULL)
    {
        free(data->envp[i]);
        i++;
    }
    free(data->envp);
}


