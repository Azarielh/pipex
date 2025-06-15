#ifndef PIPEX_H
#define PIPEX_H

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "libft.h"

#define READ_END 0
#define WRITE_END 1

/**
 * @brief The t_pipex struc is meant to make your life easier while coding the so called function. You can store here every args separatly depending on what it is (infile, commands and outfile).
 * 
 * item :
 * -> infile      : The file we want to work with.
 * -> outfile     : The file we want the result in.
 * -> flags       : The flqgs to use while opening files.
 * -> infile_name : 
 */
typedef struct s_pipex
{
	int infile; 
	int outfile;
	int flags;
	char *infile_name;
} t_pipex;
/**
 * @brief This is an error printer function. It works with perror
 * 
 * @param msg The error message you wanna print
 * @param exit_code 
 */
void print_error(char *msg, int exit_code);
/**
 * @brief This function will do its own check before giving birth through the fork function. Dealing with dup2 to redirect properly the fd you're working with.
 * 
 * @param cmd This have to be a string corresponding to a tty command.
 * @param env You have to pass your env to this function. It won't work otherwise.
 */
 void create_child(char *arg, char **envp, int fd_in);
/**
 * @brief Execute une commande terminal avec execve
 * 
 * @param arg
 * @param envp
 */
void exec_cmd(char *arg, char **envp);
/**
 * @brief Build the full path for a command using env path
 * 
 * @param cmd
 * @param envp
 * 
 * @return The full path is returned as a string
 */
char *get_path(char *cmd, char **envp);
/**
 * @brief Perfect when you're looking for some specific in an environment passed in argument
 * 
 * @param env The environment you want to look in. It's usually yours for now but who knows later on.
 * @param key What it is you're looking for in that peculiar env?
 * 
 * @return It will get you the string you want for the work you're on. A path? A Cpu intel? Anything related to the key you write upthere.
 */
char **getent_env(char **env, char *key);
/**
 * @brief This function will free the content of the double pointer passed in argument
 * 
 * @param arr This is the bad guy you want to delete from existence
 */
void free_arr(char **arr);
/**
 * @brief A special version of split able to skip quotes and double quotes
 * 
 */
char **ft_split_v2(const char *str, char c);
void delete_tmp_file(char *infile_name);
void write_here_doc(char *limiter, char *infile_name);
int open_files(t_pipex *pipex, int argc, char **argv);
pid_t last_command(int argc, char **argv, char **envp, t_pipex pipex);

#endif