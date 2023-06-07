/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:37:26 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/06/06 18:58:46 by bkarlida         ###   ########.fr       */
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
# include "LIBFT/libft.h"

typedef struct z_list
{
	char			*content;
	char			flag;// pipe rdirect ve tırnak varsa gösterir yoksa 'b' yazar
	int				extra_flag;//kullanım dışı
	struct z_list	*next;
}					link_list;

struct s_var
{
	int		lparse_int_value;//beklemede
	link_list	*lst;
	char	quot_flag;// tırnak flagleri
	char	*cont; // parser kısmında kullanılan geçici değişken
	char	rdr_flag;//oluşturulan listelere flag ataması yapılır
	int		extra_rdr_flag;//beklemede
	int		lst_size; // parserdan sonra oluşan listenin uzunluğu
	char	**str; // bütün lst->contentlerinin toplandığı double array
	char	**env; // mainden env çekildi
	int		env_size; // envsize
	char	*pwd_new; // değişen pwd nin yeni yolunu env eklemek için
	char	**export; // export
	int		export_size; // export uzunluğu
	int		ex_int; // export
	char	**cmd; // execve için
	char	**path_env; // execve için path ayrılmış hali
	
}	g_var;

void		ft_export(void);
void		path_splt(void);
void		exec_init(void);
char		*find_in_env(char *find);
void    	free_func(char **str);
int			ft_strncmpv2(const char *s1, const char *s2, size_t n);
int			is_alphanum(char *str, int len);
void		start_parser(char *line);
int			splt_len(char **str);
int			arg_isdigit(char *a);
void    	ft_unset(char *str);
void		ft_exit(void);
void		ft_env(void);
void		ft_pwd(void);
int			ft_echo_is_null(char *str);
void		ft_echo(int	k);
int			command_built(void);
int			strequal(char *str, char *ptr); // özel fonksiyon
void		quot_parser(char *line, int *i);
void		rdr_parser(char *line, int *i);
void		consecutive_rdr_parser(char *line, int *i);
void		link_lstadd_back(link_list **lst, link_list *new);
void		link_lstclear(link_list **lst);
void		link_lstdelone(link_list *lst);
link_list	*link_lstlast(link_list *lst);
link_list	*link_lstnew(char *content, char flag);
int			link_lstsize(link_list *lst);
int			cd_func(int i);
char		*cut_helper_test(const char *str);

#endif