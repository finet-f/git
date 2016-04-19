void	my_put_nbr(int nb)
{
  int	min;

  min = 0;
  if (nb < 0)
    {
      my_putchar('-');
      if (nb == -2147483648)
	{
	  nb = -2147483647;
	  min = 1;
	}
      nb = -nb;
    }
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48 + min);
    }
  else if (nb <= 9)
    my_putchar(nb % 10 + 48 + min);
}
