#include "../include/minishell.h"

// idee export

// changer strtok en split


void    bubble_sort_env(char **env)
{
    int     i;
    int     sorted;
    char    *temp;

    sorted = 0;
    while (!sorted)
    {
        sorted = 1;
        i = 0;
        while (env[i + 1] != NULL)
        {
            if (strcmp(env[i], env[i + 1]) > 0)
            {
                temp = env[i];
                env[i] = env[i + 1];
                env[i + 1] = temp;
                sorted = 0;
            }
            i++;
        }
    }
}

void ft_export(t_data *data) 
{
    int i;
    
    i = 0;
    // Trie les variables d'environnement par ordre ASCII
    bubble_sort_env(data->envp);

    // Affiche chaque variable sous la forme `declare -x NOM="VALEUR"`
    while (data->envp[i] != NULL) 
    {
        char *name = strtok(strdup(data->envp[i]), "=");    //changer strtok
        char *value = strtok(NULL, "=");                    //changer strtok

        if (value != NULL)
            printf("declare -x %s=\"%s\"\n", name, value);
        else
            printf("declare -x %s\n", name);

        free(name);
        i++;
    }
}