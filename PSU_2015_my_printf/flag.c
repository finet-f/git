#include <stdarg.h>

void	print_d_i(va_list ap)
{
  my_put_nbr(va_arg(ap, int));
}

void	print_c(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

void	print_s(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

void	print_b(va_list ap)
{
  dec_to_bin(va_arg(ap, int));
}

void	print_S(va_list ap)
{
  my_printf_S(va_arg(ap, char *));
}
