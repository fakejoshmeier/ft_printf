#include "ft_printf.h"

void	int_cast(va_list arg)
{
	int				output;

	output = va_arg(arg, int);
	ft_putnbr(output);
}

void	oct_cast(va_list arg)
{
	int				output;

	output = va_arg(arg, int);
	ft_putnbr_base(output, 8);
}

void	hex_cast(va_list arg)
{
	int				output;

	output = va_arg(arg, int);
	ft_putnbr_base(output, 12);
}

void	uint_cast(va_list arg)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	ft_putunbr_base(output, 10);
}

void	char_cast(va_list arg)
{
	char			*output;

	output = va_arg(arg, char*);
	ft_putstr(output);
}
