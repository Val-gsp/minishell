#include "include/minishell.h"

int	main(int argc, char **argv)
{
    t_data	data;
    char    *line;

    (void)argv;
    (void)argc;
    data.commands = NULL;

    while (1)
    {
        line = readline("minishell> ");
        if (!line)
            break; // Gérer Ctrl+D
        
        add_history(line);
        parse_line(&data, line);
        dbug_print_commands(&data);
        free(line);
        free_nodes(data.commands);
        data.commands = NULL;
    }
    return (0);
}
