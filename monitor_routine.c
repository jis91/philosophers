#include "philosophers.h"

void    *monitor_routine(void *arg)
{
    my_simulation   *sim;
    int             i;
    
    sim = (my_simulation *)arg;
    while (1)
    {
        i = 0;
        while (i < sim->number_of_philo)
        {
            if (check_death(sim, i))
                return (NULL);
            i++;
        }
        if (check_all_ate(sim))
            return (NULL);
        usleep(500);
    }
    return (NULL);
}

int     check_death(my_simulation *sim, int philo)
{
    long    elapsed_time;

    pthread_mutex_lock(&sim->simulation_mutex);
    elapsed_time = get_time_ms() - sim->philo[philo].last_meal_time;
    if (elapsed_time >= sim->time_to_die)
    {
        sim->dead_stop = 1;
        pthread_mutex_unlock(&sim->simulation_mutex);
        print_death(&sim->philo[philo]);
        return (1);
    }
    pthread_mutex_unlock(&sim->simulation_mutex);
    return (0);
}

int     check_all_ate(my_simulation *sim)
{
    int     i;
    int     has_eaten;

    i = 0;
    has_eaten = 0;
    if (sim->number_of_meals == -1)
        return (0);
    pthread_mutex_lock(&sim->simulation_mutex);
    while (i < sim->number_of_philo)
    {
        if (sim->philo[i].meal_count == sim->number_of_meals)
            has_eaten++;
        i++;
    }
    if (sim->number_of_philo == has_eaten)
    {
        sim->dead_stop = 1;
        pthread_mutex_unlock(&sim->simulation_mutex);
        return (1);
    }
    pthread_mutex_unlock(&sim->simulation_mutex);
    return (0);
}


void    print_death(my_philosopher *philo)
{
    long    time;

    time = get_time_ms() - philo->simulation->start_time;
    pthread_mutex_lock(&philo->simulation->print_mutex);
    ft_putnbr_fd(time, 1);
    ft_putstr_fd(" ", 1);
    ft_putnbr_fd(philo->philo_id, 1);
    ft_putstr_fd(" died\n", 1);
    pthread_mutex_unlock(&philo->simulation->print_mutex);
}