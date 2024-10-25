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

# define INPUT		1	//"<"
# define HEREDOC	2	//"<<"
# define TRUNC		3	//">"
# define APPEND		4	//">>"
# define PIPE		5	//"|"
# define CMD		6	//"|"
# define ARG		7	//"|"

// *** STRUCT ***

typedef struct s_var // liste chainee pour les variables d environnement
{
    char *key;
    char *value;
    struct s_var *next;
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
    int type;
    char *command; //commande non parse apres reception
    t_fd *fd_tab; //sortie
    char *builtin; // nom de la commande
    char **s_command;       // tableau split
    struct s_node *next; // pointeur sur la prochaine commande 
} t_node;



// *** FUNCTION PARSING ***

// *** FUNCTION COMMAND ***

// *** FUNCTION DBUG ***

#endif
