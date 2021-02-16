#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct	s_info
{
	int		width;
	int		precision;
	int		ret;
	char	type;
	char	*str;
}				t_info;

va_list		g_ap;
t_info		g_info;

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_info.ret++;
}

void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}

int		ft_strlen(char *s)
{
	int i = 0;
	while (s && s[i]) i++;
	return (i);
}

int		ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\f' || c == '\r' || c == '\v');
}

int		ft_isdigit(char c)
{
	return ('0' <= c && c <= '9');
}

int		ft_atoi(const char *s)
{
	int		ret = 0;
	int		neg = 1;

	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
		neg = ((*s++) == '-') ? -1 : 1;
	while (ft_isdigit(*s))
		ret = ret * 10 + (*s++) - '0';
	return (ret * neg);
}

char	*ft_utoa(unsigned long long num, int base_len)
{
	unsigned long long	temp = num;
	int					len = 1;
	char				*ret = 0;
	char				*base = (base_len == 10) ? "0123456789" : "0123456789abcdef";

	while (temp /= base_len)
		len++;
	ret = malloc(len + 1);
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = base[(num % base_len)];
		num /= base_len;
	}
	return (ret);
}

char	*string_pad(char c, int len)
{
	char	*ret = malloc(len + 1);

	ret[len] = 0;
	while(--len >= 0)
		ret[len] = c;
	return (ret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	int		i = 0;

	while (*s1)
		ret[i++] = *s1++;
	while (*s2)
		ret[i++] = *s2++;
	ret[i] = 0;
	return (ret);
}

char	*ft_substr(char *s, int len)
{
	char	*ret = malloc(len + 1);
	int		i = 0;

	while (i < len)
		ret[i++] = *s++;
	ret[i] = 0;
	return (ret);
}

void	reset(void)
{
	g_info.width = 0;
	g_info.precision = -1;
	g_info.type = 0;
}

void	read_width(const char **fmt)
{
	char f = **fmt;

	if (ft_isdigit(f) || f == '-')
	{
		g_info.width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt) || **fmt == '-')
			(*fmt)++;
	}
	else if (f == '*')
	{
		g_info.width = va_arg(g_ap, int);
		(*fmt)++;
	}
}

void	read_precision(const char **fmt)
{
	char f = 0;

	if (**fmt != '.') return ;
	(*fmt)++;
	f = **fmt;

	if (ft_isdigit(f))
	{
		g_info.precision = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
	else if (f == '*')
	{
		g_info.precision = va_arg(g_ap, int);
		(*fmt)++;
	}
	else
		g_info.precision = 0;
}

void	pad(int count)
{
	char	*left = 0;
	char	*right = 0;

	if (g_info.width < 0)
	{
		left = g_info.str;
		right = string_pad(' ', count);
	}
	else
	{
		left = string_pad(' ', count);
		right = g_info.str;
	}
	g_info.str = ft_strjoin(left, right);
	free(right);
	free(left);
}

void	conv_s(void)
{
	int		count = 0;
	int		width_temp = g_info.width < 0 ? (g_info.width * -1) : g_info.width;

	g_info.str = va_arg(g_ap, char*);
	if (!g_info.str)
		g_info.str = "(null)";
	if (g_info.precision > -1)
		g_info.str = ft_substr(g_info.str, g_info.precision);
	else
		g_info.str = ft_strjoin(g_info.str, "");
	count = width_temp - ft_strlen(g_info.str);
	if (count > 0)
		pad(count);
}

void	conv_d(void)
{
	int		num = va_arg(g_ap, int);
	int		is_neg = (num < 0);
	int		count = 0;
	int		width_temp = g_info.width < 0 ? (g_info.width * -1) : g_info.width;
	char	*zero = 0;
	char	*temp = 0;

	g_info.str = is_neg ? ft_utoa(-(long)num, 10) : ft_utoa(num, 10);
	if (num == 0 && g_info.precision == 0)
		g_info.str[0] = 0;
	count = g_info.precision - ft_strlen(g_info.str);
	if (g_info.precision > -1 && count > 0)
	{
		temp = g_info.str;
		zero = string_pad('0', count);
		g_info.str = ft_strjoin(zero, g_info.str);
		free(zero);
		free(temp);
	}
	if (is_neg)
	{
		temp = g_info.str;
		g_info.str = ft_strjoin("-", g_info.str);
		free(temp);
	}
	count = width_temp - ft_strlen(g_info.str);
	if (count > 0)
		pad(count);
}

void	conv_x(void)
{
	unsigned int	num = va_arg(g_ap, unsigned int);
	int				count = 0;
	int				width_temp = g_info.width < 0 ? (g_info.width * -1) : g_info.width;
	char			*zero = 0;
	char			*temp = 0;

	g_info.str = ft_utoa((unsigned int)num, 16);
	if (num == 0 && g_info.precision == 0)
		g_info.str[0] = 0;
	count = g_info.precision - ft_strlen(g_info.str);
	if (g_info.precision > -1 && count > 0)
	{
		temp = g_info.str;
		zero = string_pad('0', count);
		g_info.str = ft_strjoin(zero, g_info.str);
		free(zero);
		free(temp);
	}
	count = width_temp - ft_strlen(g_info.str);
	if (count > 0)
		pad(count);
}

void	send_conv(char f)
{
	if (f == 's')
		conv_s();
	else if (f == 'd')
		conv_d();
	else if (f == 'x')
		conv_x();
}

void	parse(const char *fmt)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			reset();
			fmt++;
			read_width(&fmt);
			read_precision(&fmt);
			if ((!(g_info.type = *fmt)))
				break ;
			send_conv(*fmt);
			ft_putstr(g_info.str);
			free(g_info.str);
		}
		else
			ft_putchar(*fmt);
		fmt++;
	}
}

int		ft_printf(const char *fmt, ...)
{
	g_info.ret = 0;
	reset();
	va_start(g_ap, fmt);
	parse(fmt);
	va_end(g_ap);
	return (g_info.ret);
}
