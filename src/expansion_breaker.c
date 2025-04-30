/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_breaker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:43:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/09 11:44:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_sign_special_cases_exp(char cmd, t_ms **ms)
{
	char	*tmp;

	if (cmd == '?')
	{
		tmp = ft_itoa((*ms)->exit_status);
		(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, tmp);
		ft_free_gnl(&tmp);
	}
	else if (cmd == '0')
		(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, "minishell");
}

void	handle_dollar_sign_exp(char *cmd, t_ms **ms, int *i)
{
	char	*cmd_execute;

	cmd_execute = ft_strndup(cmd + 1, ft_strlen_dolar(cmd + 1));
	if (cmd[1] && (cmd[1] == '?' || cmd[1] == '$' || cmd[1] == '0'))
	{
		handle_sign_special_cases_exp(cmd[1], ms);
		(*i)++;
	}
	else if (cmd_execute && is_valid_env_var_name(cmd_execute))
	{
		handle_env_var_echo_exp(cmd_execute, ms);
		(*i) += ft_strlen(cmd_execute);
	}
	else if (cmd[0] == '$' && ((!cmd_execute)))
		(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '$');
	else if (!is_valid_env_var_name(cmd_execute))
		(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '$');
	ft_free_gnl(&cmd_execute);
}

int	handle_env_var_echo_exp(char *cmd, t_ms **ms)
{
	char	*env_var;

	env_var = get_env_var_value(ms, cmd);
	if (env_var)
	{
		if (env_var[0] == '\\')
			(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, \
			env_var + 1);
		else
			(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, env_var);
		return (free(env_var), 1);
	}
	return (0);
}

void	handle_tilde_exp(char *input, int i, t_ms **ms)
{
	if ((i == 0 && (input[i + 1] == '\0' || ft_isspace(input[i + 1]))) || \
		(ft_isspace(input[i - 1]) && (input[i + 1] == '\0' \
			|| ft_isspace(input[i + 1]))))
		(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, (*ms)->home);
}
