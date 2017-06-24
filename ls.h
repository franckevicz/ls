/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrankev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 19:22:58 by mfrankev          #+#    #+#             */
/*   Updated: 2017/06/15 19:29:13 by mfrankev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <stdio.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

# define NOT_CURRENT (ft_strcmp(crawler->folder_name, "."))
# define NOT_PREV (ft_strcmp (crawler->folder_name, ".."))
# define N_PR (NOT_CURRENT && NOT_PREV)
# define SPACES 2
# define GR_LEN ft_strlen(getgrgid(crawler->stat->st_gid)->gr_name)

typedef struct	s_args {
	unsigned char	double_dash;
	t_list			*folders;
	t_list			*files;
}				t_args;

typedef struct	s_ls_list {
	char				*folder_name;
	char				*link_val;
	struct stat			*stat;
	int					exp_attr;
	struct s_ls_list	*next;
	struct s_ls_list	*prev;
}				t_ls_list;

typedef	struct	s_struct {
	DIR				*dir;
	struct dirent	*dirent;
	struct stat		stat;
	char			link_val[1024];
	t_ls_list		*queue;
	char			*name;
	int				exp_attr;
}				t_struct;

typedef struct	s_out_lengths {
	size_t		own_len;
	size_t		group_len;
	size_t		block_count;
	size_t		filename_len;
	int			file_size_len;
	int			link_len;
	int			rights_len;
	int			columns;
}				t_out_lengths;

typedef struct	s_output {
	char			rights[15];
	int				links_count;
	char			owner[15];
	char			group[15];
	char			size[20];
	char			date[20];
	char			filename[2050];
}				t_output;

void			read_args_ls(t_args *args, int argc, char **argv);
void			proceed_files(t_args *args);
void			proceed_folders(t_args *args);
void			quicksort_dlist(struct s_ls_list *head);
void			print_dlist(t_ls_list **head, t_args *info, t_struct *args);
void			print_line(t_ls_list *node, t_out_lengths *len);
void			del_ls_struct(t_struct *struc);
void			del_ls_list(t_ls_list **head);
void			finding_length(t_out_lengths *len, t_ls_list *head);
int				len_of_st(size_t num);
void			dlist_add(t_struct *args);
void			expanded_attr(char *path, t_struct *args);
void			print_color_file(struct stat *st, char *file, int width);

void			specify_filetype(t_output *out, struct stat *stat);
void			recirsion_open_folders(t_list **head, t_args *info, \
													t_struct *args);
long			cmp_creation_date(struct s_ls_list *first, \
									struct s_ls_list *second);
void			print_columns(t_ls_list *node, t_out_lengths *len);
void			color_output(t_ls_list *node, t_out_lengths *len, \
							t_output *out);

char			*construct_full_name(const char *folder, const char *path);
int				is_folder(const char *name);
void			device_nums_parse(t_output *out, struct stat *st);
void			parse_filesize_devnums(t_output *out, struct stat *st);
void			error_open_fold(t_struct *args);
void			wrong_flag(char c);
void			print_color_file(struct stat *st, char *file, int width);

unsigned char	g_flag_a;
unsigned char	g_flag_l;
unsigned char	g_flag_r;
unsigned char	g_flag_big_r;
unsigned char	g_flag_t;
unsigned char	g_flag_f;
unsigned char	g_flag_big_g;
unsigned char	g_flag_u;
unsigned char	g_flag_big_u;
unsigned char	g_flag_1;

#endif
