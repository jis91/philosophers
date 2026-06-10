#include "philosophers.h"

int     parse_args(my_simulation *sim, char **argv, int argc)
{
    sim->number_of_philo = ft_atoi(argv[1]);
    sim->time_to_die = ft_atoi(argv[2]);
    sim->time_to_eat = ft_atoi(argv[3]);
    sim->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        sim->number_of_meals = ft_atoi(argv[5]);
    else 
        sim->number_of_meals = -1;
    if ((argc == 6 && sim->number_of_meals == -1) || 
                    sim->number_of_philo == -1 || sim->time_to_die == -1 || 
                    sim->time_to_eat == -1 || sim->time_to_sleep == -1 )
    {
        write(2, "Error: invalid arguments\n", 25);
        return (1);
    }
    return (0);

}

int     init_philos(my_simulation *sim)
{
    my_philosopher    *philosophers;
    int     i;

    philosophers = malloc(sizeof(my_philosopher) * sim->number_of_philo);
    if (!philosophers)
        return (-1);
    sim->philo = philosophers;
    i = 0;
    while (i < sim->number_of_philo)
    {
        philosophers[i].philo_id = i + 1;
        philosophers[i].left_fork = i;
        philosophers[i].right_fork = (i + 1) % sim->number_of_philo;
        philosophers[i].meal_count     = 0;
        philosophers[i].last_meal_time = sim->start_time;
        philosophers[i].simulation     = sim;
        i++;
    }
    return (0);
}

int     init_forks_mutex(my_simulation *sim)
{
    pthread_mutex_t     *forks;
    int     i;

    i = 0;
    forks = malloc(sizeof(pthread_mutex_t) * sim->number_of_philo);
    if (!forks)
        return(1);
    sim->forks = forks;
    while (i < sim->number_of_philo)
    {
        if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
        {
            cleanup_simulation(sim, i);
            return (1);
        }
        i++;
    }
    if ((pthread_mutex_init(&sim->simulation_mutex, NULL) != 0) || 
                    pthread_mutex_init(&sim->print_mutex, NULL) != 0)
    {    
        cleanup_simulation(sim, sim->number_of_philo);
        return(1);
    }
    
    return (0);
}

int     init_simulation(my_simulation *sim, char **argv, int argc)
{
    if (parse_args(sim, argv, argc) != 0)
    {    
        cleanup_simulation(sim, 0);
        return (1);
    }
    sim->start_time = get_time_ms();
    if (init_philos(sim) != 0)
    {
        cleanup_simulation(sim, 0);
        return (1);
    }
    if(init_forks_mutex(sim) != 0)
        return (1);
    return (0);
}