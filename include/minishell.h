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


/* Elements mis de côté pour réflexion
-------------------------------------------------------------------------
# define INPUT		1	//"<"
# define HEREDOC	2	//"<<"
# define TRUNC		3	//">"
# define APPEND		4	//">>"
# define PIPE		5	//"|"
# define CMD		6	//"|"
# define ARG		7	//"|"

typedef struct s_var // liste chainee pour les variables d environnement
{
    char *key;
    char *value;
    struct s_var *next;
}              t_var;

typedef struct s_node // noeud pour le parsing de la ligne
{
    int type;
    t_fd *fd_tab; //sortie
    struct s_node *next; // pointeur sur la prochaine commande
    // char *command; //commande non parse apres reception
    // char *builtin; // nom de la commande
    // char **s_command;       // tableau split
} t_node;

typedef struct s_var_data
{
    char **tab_var;         // tableau de tableau pour execve  (char **envp).
    struct s_var *start;    // start node debut
}              t_var;
-------------------------------------------------------------------------
*/

// *** STRUCT ***

typedef enum e_tokentype
{
	QUOTE,      // Simple quote
	DQUOTE,     // Double quote
	REDIN,      // Redirection d'entrée
	REDOUT,     // Redirection de sortie
	HDOC,       // Heredoc
	APPEND,     // Append
	PIPE,       // Pipe
	CMD,        // Commande (execution par execve)
	ARG         // Argument (Si commande à arguments)
}	t_tokentype;

typedef struct s_token
{
	t_tokentype			type;		// Type de token
	int	        		id;			// Position dans la ligne de commande
	char				*arg;		// Si commande à arguments*
    //t_fd				*fd_tab;	// Gestion des fd
	struct s_token		*head;		// Pointeur vers le premier élément
	struct s_token		*next;		// Pointeur vers le prochain élément
} t_token;

typedef struct s_data // structure generale
{
    char	*input;             // Commande entrée
    char    **envp;             // "NOM=VALEUR"
    char    **expt;
	t_token		token_list;     // Référencement des tokens
   // struct s_var_data var_data;
   // t_node *node_start;

}   t_data;


// *** INITIALISATION ***

    t_data	*init_data(t_data *data);

// *** FUNCTION VARIABLE ENV ***

void    init_env(t_data *data, char **envp_system);
void    ft_env(t_data *data);
void    free_envp(t_data *data);


// *** FUNCTION PARSING ***

// *** FUNCTION COMMAND ***

// *** FUNCTION DBUG ***

// *** FREE & QUIT ***


void	free_data(t_data *data);

#endif
