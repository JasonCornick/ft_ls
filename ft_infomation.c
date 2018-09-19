/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infomation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornick <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 17:18:18 by jcornick          #+#    #+#             */
/*   Updated: 2018/09/17 17:19:34 by jcornick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char			get_file_type(mode_t octal)
{
	octal = (octal & S_IFMT);
	if (S_ISREG(octal))
		return ('-');
	else if (S_ISDIR(octal))
		return ('d');
	else if (S_ISLNK(octal))
		return ('1');
	else if (S_ISBLK(octal))
		return ('b');
	else if (S_ISCHR(octal))
		return ('c');
	else if (S_ISSOCK(octal))
		return ('s');
	else if (S_ISFIFO(octal))
		return ('p');
	return ('-');
}

char				*truncate_time(char *string)
{
	int				a;
	int				i;
	char			ret[13];

	a = 0;
	i = 4;
	while (a < 12)
	{
		ret[a] = string[i];
		i++;
		a++;
	}
	ret[a] = '\0';
	return (ft_strdup(ret));
}

void				more_info(t_list *head, struct stat buf)
{
	struct passwd	*password;
	struct group	*gname;
	char			*time;
	int				i;

	i = 0;
	password = getpwuid(buf.st_uid);
	gname = getgrgid(buf.st_gid);
	head->data.user = password->pw_name;
	head->data.group = gname->gr_name;
	head->data.links = (unsigned int)buf.st_nlink;
	head->data.size = (unsigned int)buf.st_size;
	head->data.blocks = buf.st_blocks;
	head->data.tno = buf.st_mtime;
	time = truncate_time(ctime(&buf.st_mtime));
	while (i < 13)
	{
		head->data.time[i] = time[i];
		i++;
	}
	free(time);
}

void				get_file_permisions(t_list *head)
{
	struct stat		buf;
	mode_t			octal;

	stat(head->data.name, &buf);
	octal = buf.st_mode;
	head->data.permisions[0] = get_file_type(octal);
	head->data.permisions[1] = (S_IRUSR & octal) ? 'r' : '-';
	head->data.permisions[2] = (S_IWUSR & octal) ? 'w' : '-';
	head->data.permisions[3] = (S_IXUSR & octal) ? 'x' : '-';
	head->data.permisions[4] = (S_IRGRP & octal) ? 'r' : '-';
	head->data.permisions[5] = (S_IWGRP & octal) ? 'w' : '-';
	head->data.permisions[6] = (S_IXGRP & octal) ? 'x' : '-';
	head->data.permisions[7] = (S_IROTH & octal) ? 'r' : '-';
	head->data.permisions[8] = (S_IWOTH & octal) ? 'w' : '-';
	head->data.permisions[9] = (S_IXOTH & octal) ? 'x' : '-';
	head->data.permisions[10] = '\0';
	more_info(head, buf);
}

void				get_file_permisions_two(t_list *head, char *name)
{
	struct stat		buf;
	mode_t			octal;
	char			*str;
	char			*strr;

	strr = ft_strjoin(name, "/");
	str = ft_strjoin(strr, head->data.name);
	stat(str, &buf);
	free(strr);
	free(str);
	octal = buf.st_mode;
	head->data.permisions[0] = get_file_type(octal);
	head->data.permisions[1] = (S_IRUSR & octal) ? 'r' : '-';
	head->data.permisions[2] = (S_IWUSR & octal) ? 'w' : '-';
	head->data.permisions[3] = (S_IXUSR & octal) ? 'x' : '-';
	head->data.permisions[4] = (S_IRGRP & octal) ? 'r' : '-';
	head->data.permisions[5] = (S_IWGRP & octal) ? 'w' : '-';
	head->data.permisions[6] = (S_IXGRP & octal) ? 'x' : '-';
	head->data.permisions[7] = (S_IROTH & octal) ? 'r' : '-';
	head->data.permisions[8] = (S_IWOTH & octal) ? 'w' : '-';
	head->data.permisions[9] = (S_IXOTH & octal) ? 'x' : '-';
	head->data.permisions[10] = '\0';
	more_info(head, buf);
}
