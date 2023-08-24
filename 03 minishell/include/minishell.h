/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:59:24 by bkarlida          #+#    #+#             */
/*   Updated: 2023/07/21 16:02:28 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../LIBFT/libft.h"

typedef struct z_list
{
	char			*content;
	char			flag;
	struct z_list	*next;
}				t_ink_list;

typedef struct a_list
{
	char			**str;
	int				f_in;
	char			flag;
	int				f_out;
	int				size;
}					t_pip;

struct s_var
{
	t_ink_list	*lst;
	t_pip		**cmds;
	int			lst_size;
	char		**str;
	char		**env;
	int			env_size;
	char		**export;
	int			export_size;
	int			ex_int;
	char		**cmd;
	char		**path_env;
	char		*acces;
	int			**pipe;
	pid_t		*pid;
	int			pipe_count;
	int			cmds_count;
	int			cmds_int;
	char		***help;
	int			pipe_cntv2;
	int			exit_status;
	int			path_flag;
	int			built_ctrl;
	int			echo_help;
	int			rdr_left;
	int			dolar;
	int			test;
	int			cmds_help;
	int			free_control;
	int			quit_flag;
}	g_var;

char		*ft_strjoin_v4(char const *s1, char const *s2);
void		rdirect_add(void);
void		all_free_add(char *mshell);
void		all_free_add_v2(char *mshell);
int			rdr_pipe_help(void);
void		waitpid_func(int id);
void		all_free_v2(char *mshell);
int			print_error(char *file, int i);
void		rdr_write_helper(char *line, int i);
void		dollar_help(char *str, int i);
char		*only_dolar(void);
int			pipe_help(void);
int			var_count(t_ink_list	*tmp);
void		ioctl_helper(void);
void		sigint_handler(int signal);
int			is_pipe(void);
int			check_quote(char *str);
void		rdirection_flag(void);
void		all_free(char *mshell);
void		null_init(int ac, char **av, char **envp);
void		env_export(char **envp);
void		env_malloc(char **envp);
void		command_prepare(void);
int			cmd_acces(int i);
char		**add_cmd(void);
char		*ft_strdup_v3(char *str, int *start, char end);
int			ft_strlen_v2(char *str, char q, int i);
char		*ft_strdup_v2(char *str, int start, int end);
char		*ft_strjoin_v3(char *s1, char *s2);
char		*get_env_var(char *str, char **env, int *i, int *j);
int			is_it_special(char c);
int			link_lstsize(t_ink_list *lst);
int			is_equal(char *str);
int			len_equal(char *str);
char		*cut_helper(const char *str);
int			ft_strcmpv3(char *s1, char *s2);
void		close_fd(t_pip *cmds);
void		close_func(void);
int			built_control(void);
int			command_built_v2(int i);
int			len_equal(char *str);
void		unlink_func(void);
void		free_func_three(char ***str);
void		free_func_int(int **str);
int			ft_strncmp_v3(const char *s1, const char *s2, size_t n);
int			start_parser(char *str);
char		*f_v2(char *find);
int			cmd_init(void);
int			file_handle(void);
void		ft_export(void);
void		close_file(void);
void		cmd_pipe(void);
int			path_splt(void);
void		exec_init(void);
char		*find_in_env(char *find);
void		free_func(char **str);
int			ft_strncmpv2(const char *s1, const char *s2, size_t n);
int			is_alphanum(char *str, int len);
int			splt_len(char **str);
int			arg_isdigit(char *a);
void		ft_unset(void);
void		ft_exit(void);
void		ft_pwd(void);
void		ft_env(void);
void		ft_echo(int k);
int			command_built(int i);
int			strequal(char *str, char *ptr);
void		link_lstadd_back(t_ink_list **lst, t_ink_list *new);
void		link_lstclear(t_ink_list **lst);
void		link_lstdelone(t_ink_list *lst);
t_ink_list	*link_lstlast(t_ink_list *lst);
t_ink_list	*link_lstnew(char *content, char flag);
int			link_lstsize(t_ink_list *lst);
int			cd_func(int i);
char		*get_pwd(char *path, int key);

#endif