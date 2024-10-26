#include "include/minishell.h"

int	main(int argc, char **argv, char **envp)
{
    t_data	data;
    char    *line;

    (void)argc;
    (void)argv;
    init_env(&data, envp);
    while (1)
    {
        line = readline("minishell> ");
        if (!line)
            break; // Gérer Ctrl+D
        
        add_history(line);

        // Vérifie si la commande est "env"
        if (strcmp(line, "env") == 0)
            ft_env(&data); // Affiche les variables d'environnement
        else if (strcmp(line, "export") == 0)
            ft_export(&data);
        else
        {
            // Ici, tu pourras ajouter des vérifications pour d'autres commandes
            printf("Commande inconnue : %s\n", line);
        }

        free(line);
    }

    free_envp(&data);
    return (0);
}
