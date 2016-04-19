void	my_put_nbr_long(long nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * -1;
    }
  if (nb > 9)
    {
      my_put_nbr_long(nb / 10);
    }
  my_putchar(nb % 10 + 48);
}
