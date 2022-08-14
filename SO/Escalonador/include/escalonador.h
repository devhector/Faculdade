#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include "libft.h"

typedef struct s_data
{
	char	*name;
	int		time;
} t_data;

typedef struct s_core
{
	char	*name;
	int		time;
	t_list	*data;
} t_core;

#define BUFFER_SIZE 1024

#endif