/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 01:43:49 by gada-sil          #+#    #+#             */
/*   Updated: 2025/09/01 03:51:21 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_unchangeable(const char *key)
{
	if (!ft_strcmp(key, "?") || !ft_strcmp(key, "$"))
		return (1);
	return (0);
}

int	unset_env_if(t_env **envs, const char *target_key)
{
	t_env	*temp;

	if (!*envs || !envs)
		return (0);
	if (is_unchangeable(target_key))
		return (0);
	temp = *envs;
	if (!(ft_strcmp(target_key, (const char *)(*envs)->key)))
	{
		*envs = temp->next;
		free(temp->key);
		free(temp->value);
		free(temp);
		unset_env_if(envs, target_key);
	}
	else
	{
		temp = *envs;
		unset_env_if(&temp->next, target_key);
	}
	return (0);
}

int	ft_env(t_env *env, char **matrix)
{
	t_env	*temp;

	temp = env;
	if (!env)
		return (1);
	if (ft_len_matrix(matrix) > 1)
	{
		write(2, "env: ‘", 9);
		write(2, matrix[1], ft_strlen(matrix[1]));
		ft_putendl_fd("’: No such file or directory", 2);
		return (127);
	}
	while (temp)
	{
		if (!is_unchangeable(temp->key))
		{
			printf("%s", temp->key);
			printf("=");
			printf("%s\n", temp->value);
		}
		temp = temp->next;
	}
	return (0);
}
