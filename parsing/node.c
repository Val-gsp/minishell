#include "../include/minishell.h"

// Fonction pour créer un nouveau nœud
t_node *create_node(char *command) 
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->command = strdup(command);
    new_node->next = NULL;
    return new_node;
}

// Fonction pour ajouter un nœud à la fin de la liste chaînée
void add_node(t_node **head, char *command) 
{
    t_node *new_node = create_node(command);
    if (*head == NULL)
        *head = new_node;
    else 
    {
        t_node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

// Fonction pour libérer la mémoire des nœuds
void free_nodes(t_node *head) 
{
    t_node *temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp->command);
        free(temp);
    }
}

// Fonction pour découper la ligne et remplir la liste de commandes
void parse_line(t_data *data, char *line) 
{
    char *token = strtok(line, "|");
    while (token != NULL) 
    {
        // Ajouter chaque segment (ce qui est entre deux pipes) dans la liste des commandes
        add_node(&data->commands, token);
        token = strtok(NULL, "|");
    }
}

