#include <stdarg.h>

void	print_x(va_list ap)
{
  dec_to_hex(va_arg(ap, int), 'x');
}

void	print_X(va_list ap)
{
  dec_to_hex(va_arg(ap, int), 'X');
}

void	print_o(va_list ap)
{
  dec_to_oct(va_arg(ap, int));
}

void	print_u(va_list ap)
{
  my_printf_u(va_arg(ap, int));
}

void	print_p(va_list ap)
{
  my_print_p(va_arg(ap, int));
}
