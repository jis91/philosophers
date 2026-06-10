#include "philosophers.h"

void	ft_putnbr_fd(long n, int fd)
{
	unsigned long	num;
    char    c;
    char    nb;

    c = '-';
	if (n < 0)
	{
		write(fd, &c, 1);
		num = -n;
	}
	else
		num = n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
    nb = (num % 10) + '0';
	write(fd, &nb, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    int     i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

int     launch_threads(my_simulation *sim)
{
    int         i;
    pthread_t   monitor;

    i = 0;
    while (i < sim->number_of_philo)
    {
        if (pthread_create(&sim->philo[i].thread_id, NULL, philo_routine, &sim->philo[i]) != 0)
            return (1);
        i++;
    }
    if (pthread_create(&monitor, NULL, monitor_routine, sim) != 0)
        return (1);
    pthread_join(monitor, NULL);
    i = 0;
    while (i < sim->number_of_philo)
    {
        pthread_join(sim->philo[i].thread_id, NULL);
        i++;
    }
    return (0);
}