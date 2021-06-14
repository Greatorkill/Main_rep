/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:26:43 by kgeorgia          #+#    #+#             */
/*   Updated: 2021/04/23 16:26:44 by kgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str);
char *ft_strcpy(char *dst, char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
char	*ft_strdup(const char *str);

void check_strlen(void)
{
	char *str;

	printf("### FT_STRLEN ###\n");

	str = "123456789";
	printf("   strlen: %d   ", (int)strlen(str));
	printf("ft_strlen: %d\n", (int)ft_strlen(str));

	str = "";
	printf("   strlen: %d   ", (int)strlen(str));
	printf("ft_strlen: %d\n", (int)ft_strlen(str));

	str = "djiasjdnlkdlkwqndk;ld3a1d32sa1d231sad13w41e32q1e32wq1e212";
	printf("   strlen: %d   ", (int)strlen(str));
	printf("ft_strlen: %d\n", (int)ft_strlen(str));
	printf("_____________\n");
}

void check_strcpy(void)
{
	char *str1;
	char *str2;
	char dest[8];
	char *src;

	src = "bonjour";
	printf("\n\n");
	printf("### FT_STRCPY ###\n");
	str1 = strdup(dest);
	str2 = strdup(dest);
	str1 = strcpy(str1, src);
	str2 = ft_strcpy(str2, src);
	printf("   strcpy: %s   ", str1);
	printf("ft_strcpy: %s\n", str2);
	printf("_____________\n");
	printf("\n\n");
}

void check_strcmp(void)
{
	char abc[6] = "Hello";
	char bca[6] = "Hella";
	char ght[5] = "Hell";

	printf("### FT_STRCMP ###\n");
	int ret = strcmp(abc, abc);
	printf("ret    strcmp : %d   ", ret);
	ret = ft_strcmp(abc, abc);
	printf("ft_strcmp : %d\n", ret);
	ret = strcmp(abc, bca);
	printf("ret    strcmp : %d   ", ret);
	ret = ft_strcmp(abc, bca);
	printf("ft_strcmp : %d\n", ret);
	ret = strcmp(bca, abc);
	printf("ret    strcmp : %d   ", ret);
	ret = ft_strcmp(bca, abc);
	printf("ft_strcmp : %d\n", ret);
	ret = strcmp(abc, ght);
	printf("ret    strcmp : %d   ", ret);
	ret = ft_strcmp(abc, ght);
	printf("ft_strcmp : %d\n", ret);
	ret = strcmp("", "");
	printf("ret    strcmp : %d   ", ret);
	ret = ft_strcmp("", "");
	printf("ft_strcmp : %d\n", ret);
	printf("_____________\n");
}

void check_write(void)
{
	char *s1;
	char *s2;
	char *s3;
	printf("\n\n");
	s1 = "bonjour";
	s2 = "";
	s3 = "uqwhe1233213-992138|\n";
	printf("### FT_WRITE ###\n");
	printf(" =    write: %zd\n", write(1, s1, strlen(s1)));
	printf(" = ft_write: %zd\n\n", ft_write(1, s1, strlen(s1)));

	printf(" =    write: %zd\n", write(1, s2, strlen(s2)));
	printf(" = ft_write: %zd\n\n", ft_write(1, s2, strlen(s2)));

	printf(" =    write: %zd\n", write(1, s3, strlen(s3)));
	printf(" = ft_write: %zd\n\n", ft_write(1, s3, strlen(s3)));
	printf("_____________\n");

	printf("\n\n");
}

void check_read(void)
{
	printf("### FT_READ ###\n");
	char	buffer[33];
	char	buffer1[33];
	int		r;
	int		r1;
	int		fd;
	int		fd1;

	fd = open("test.txt", O_RDONLY);
	fd1 = open("test.txt", O_RDONLY);
	r = read(fd, buffer, 10);
	r1 = ft_read(fd1, buffer1, 10);
	buffer[r] = 0;
	buffer1[r1] = 0;
	printf("   read,  r : %d,  buffer : %s\n", r, buffer);
	printf("ft_read, r1 : %d, buffer1 : %s\n\n", r1, buffer1);
	r = read(fd, buffer, 10);
	r1 = ft_read(fd1, buffer1, 10);
	buffer[r] = 0;
	buffer1[r1] = 0;
	printf("   read,  r : %d,  buffer : %s\n", r, buffer);
	printf("ft_read, r1 : %d, buffer1 : %s\n\n", r1, buffer1);
	r = read(fd, buffer, 10);
	r1 = ft_read(fd1, buffer1, 10);
	buffer[r] = 0;
	buffer1[r1] = 0;
	printf("   read,  r : %d,  buffer : %s\n", r, buffer);
	printf("ft_read, r1 : %d, buffer1 : %s\n", r1, buffer1);
	r = read(fd, buffer, 10);
	r1 = ft_read(fd1, buffer1, 10);
	buffer[r] = 0;
	buffer1[r1] = 0;
	printf("   read,  r : %d,  buffer : %s\n", r, buffer);
	printf("ft_read, r1 : %d, buffer1 : %s\n", r1, buffer1);
	close(fd);
	close(fd1);
	printf("_____________\n");
}

void check_strdup(void)
{
	char *s1;

	printf("\n\n");
	s1 = "bonjour";
	printf("\n\n");
	printf("### FT_STRDUP ###\n");
	s1 = strdup(s1);
	s1 = ft_strdup(s1);
	printf("   strdup: %s\n", s1);
	printf("ft_strdup: %s\n", s1);
	printf("_____________\n");
}

int		main(void)
{
	check_strlen();
	check_strcpy();
	check_strcmp();
	check_write();
	check_read();
	check_strdup();
	return (0);
}
