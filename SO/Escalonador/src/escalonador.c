#include "escalonador.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int	count_space(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	is_number(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	create_data(t_list *data, char *str)
{
	char	**tmp;
	t_data	*new;
	if (count_space(str) == 1)
	{
		tmp = ft_strsplit(str, ' ');
		new = (t_data *)malloc(sizeof(t_data));
		new->name = ft_strdup(tmp[0]);
		if (is_number(tmp[1]))
			new->time = ft_atoi(tmp[1]);
		else
			new->time = 0;
		ft_lstadd_back(&data, ft_lstnew(new));
		free_array(tmp);
	}
}

int	bubble_sort(t_list *data)
{
	t_list	*aux;
	t_data	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = data;
	while (aux->next)
	{
		while (aux->next)
		{
			if (((t_data *)aux->content)->time > ((t_data *)aux->next->content)->time)
			{
				tmp = (t_data *)aux->content;
				aux->content = aux->next->content;
				aux->next->content = tmp;
			}
			aux = aux->next;
		}
		aux = data;
	}
	return (0);
}

t_list	*shortest_job_first(t_list *data, int core)
{
	

}

int	escalonador(char **splited, int core)
{
	int		i;
	t_list	*data;

	i = 0;
	data = NULL;
	while(splited[i])
	{
		create_data(data, splited[i]);
		i++;
	}
	bubble_sort(data);
}