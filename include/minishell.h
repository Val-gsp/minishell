#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

// *** COLOR ***
# define BLA 		"\033[1;30m" 			// Bold Black
# define WHI 		"\033[1;37m" 			// Bold White
# define RED 		"\033[1;31m" 			// Bold Red
# define GRE 		"\033[1;32m" 			// Bold Green
# define BLU 		"\033[1;34m" 			// Bold Blue
# define CYA 		"\033[1;36m" 			// Bold Cyan
# define MAG 		"\033[1;35m" 			// Bold Magenta
# define YEL 		"\033[1;33m" 			// Bold Yellow
# define RES 		"\033[0m" 				// Reset (to default text)
# define BOLD 		"\e[0;36m" 				// Bold
# define ARROW 		"\033[32m➜\033[0m" 	   // Green Arrow

// *** STRUCT ***

typedef struct s_var // liste chainee pour les variables d environnement
{
    char *key;
    char *value;
}              t_var;

typedef struct s_var_data
{
    char **tab_var;         // tableau de tableau pour execve  (char **envp).
    struct s_var *start;    // start node debut
}              t_var;


struct s_data // structure generale
{
    struct s_var_data var_data;
    t_node *node_start;

}

typedef struct s_node // noeud pour le parsing de la ligne
{
    char *command; //commande non parse apres reception
    int in; // entree
    int out; //sortie
    char *builtin; // nom de la commande
    char **s_command;       // tableau split
    struct s_node *next; // pointeur sur la prochaine commande
    t_arg *arg; // les argument de la commande dans une liste chainee , pas sur de le garder
} t_node;



// *** FUNCTION PARSING ***

// *** FUNCTION COMMAND ***

// *** FUNCTION DBUG ***

#endif
