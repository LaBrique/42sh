/*
** EPITECH PROJECT, 2017
** mysh
** File description:
** mysh
*/

#ifndef _MYSH_H_
#define _MYSH_H_

#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "my.h"

typedef struct node_s {
	short opt;
	char *str;
	struct node_s *left;
	struct node_s *right;
} node_t;

typedef struct builtin_s {
	char *str;
	char **(*ptr)(char **, char **);
} builtin_t;

#define D_P "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
#define BUILTIN_NB 5
#define PWD getcwd(NULL, 255)

short	get_opt(char *str);
node_t	*create_node(char *str);
node_t	*parse_command(char **blocks, char **envp);
char	choose_opt(short opt);
void	print_tree(node_t *tree);
int	get_input_fd(node_t *tree, int old);
int	get_output_fd(node_t *tree, int old);
int	execute_commands(node_t *tree, int fd[2], char ***envp, int waiter);
int	get_fd(int fd[2], int fd2[2], node_t *tree);
int	get_input(char **buffer);
int	cut_buffer(char *buffer);
char	*get_env(char *name, char **envp);
char	*get_env_value(char **envp, int i);
char	*get_full_path(char **paths, char *bin_name);
char	**get_command(char *command, char **envp);
int	argcounter(char **argv);
void	execute_binary(char *str, int fd[2], char **envp, int waiter);
char	*get_prompt(void);
char	*check_tilde(char *path);
void	append_history(char **history, int *i);
void	special_cd_sh(char *path, char **envp);
char	**cd(char **path, char **envp);
char	**exit_sh(char **arg, char **envp);
char	**env_sh(char **envp);
int	get_env_position(char *name, char **envp);
char	**envp_remove(char *name, char **envp);
char	**unsetenv_sh(char **arg, char **envp);
char	**envp_append(char *name, char *value, char **envp);
char	**setenv_sh(char **arg, char **envp);
int	check_builtins(char *com, int fd[2], char ***envp);
void	check_existence(void);
int	shell_prompt(char ***envp);
void	int_ign(int sig);
char	**echo_sh(char **argv, char **envp);
void	get_sig_status(int status);
int	main(int argc, char **argv, char **envp);

#endif /*_MYSH_H_*/
