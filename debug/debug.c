#include "../include/minishell.h"

// Fonction pour afficher les commandes (à des fins de débogage)
void dbug_print_commands(t_data *data) 
{
    t_node *current = data->commands;
    int i;

    i = 1;
    while (current != NULL) 
    {
        printf("Node %d: %s\n", i, current->command);
        current = current->next;
        i++;
    }
}