#include "philosophers.h"

int    ft_atoi(const char *nptr)
{
    int    i;
    int        result;

    result = 0;
    i = 0;
    if (!nptr || nptr[0] == '\0')
        return (-1);
    while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
    {
        if (result > (INT_MAX - (nptr[i] - '0')) / 10)
            return (-1);
        result = result * 10 + (nptr[i] - '0');
        i++;
    }
    if (nptr[i] != '\0')
        return (-1);
    if (result <= 0)
        return (-1);
    return (result);
}

void    cleanup_simulation(my_simulation *sim, int forks_initialized)
{
    int     i;

    i = 0;
    while (i < forks_initialized)
    {
        pthread_mutex_destroy(&sim->forks[i]);
        i ++;
    }
    if (forks_initialized == sim->number_of_philo)
    {
        pthread_mutex_destroy(&sim->print_mutex);
        pthread_mutex_destroy(&sim->simulation_mutex);
    }
    free(sim->forks);
    free(sim->philo);
}

long    get_time_ms(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int     is_simulation_stopped(my_simulation *sim)
{
    int     stop;

    pthread_mutex_lock(&sim->simulation_mutex);
    stop = sim->dead_stop;
    pthread_mutex_unlock(&sim->simulation_mutex);
    return (stop);
}

void    print_state(my_philosopher *philo, char *state)
{
    long    time;

    time = get_time_ms() - philo->simulation->start_time;
    pthread_mutex_lock(&philo->simulation->print_mutex);
    if (!is_simulation_stopped(philo->simulation))
    {
        ft_putnbr_fd(time, 1);
        ft_putstr_fd(" ", 1);
        ft_putnbr_fd(philo->philo_id, 1);
        ft_putstr_fd(" ", 1);
        ft_putstr_fd(state, 1);
        ft_putstr_fd("\n", 1);
    }
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}