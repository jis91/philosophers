#include "philosophers.h"

void    *philo_routine(void *arg)
{
    my_philosopher  *philo;

    philo = (my_philosopher *)arg;
    if (philo->simulation->number_of_philo == 1)
    {
        print_state(philo, "has taken a fork");
        usleep(philo->simulation->time_to_die * 1000);
        pthread_mutex_lock(&philo->simulation->simulation_mutex);
        philo->simulation->dead_stop = 1;
        pthread_mutex_unlock(&philo->simulation->simulation_mutex);
        print_death(philo);
        return (NULL);
    }
    if(philo->philo_id % 2 == 0)
        usleep(philo->simulation->time_to_eat * 1000);
    while (!is_simulation_stopped(philo->simulation))
    {
        take_forks(philo);
        if (eat(philo))
            break;
        sleep_and_think(philo);
    }
    return (NULL);
}

void    take_forks(my_philosopher *philo)
{
    if(philo->philo_id % 2 == 0)
        {
            pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
            print_state(philo, "has taken a fork");
            pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
            print_state(philo, "has taken a fork");
        }
        else
        {
            pthread_mutex_lock(&philo->simulation->forks[philo->right_fork]);
            print_state(philo, "has taken a fork");
            pthread_mutex_lock(&philo->simulation->forks[philo->left_fork]);
            print_state(philo, "has taken a fork");
        }
}

int     eat(my_philosopher *philo)
{
        print_state(philo, "is eating");
        pthread_mutex_lock(&philo->simulation->simulation_mutex);
        philo->last_meal_time = get_time_ms(); 
        philo->meal_count++;
        pthread_mutex_unlock(&philo->simulation->simulation_mutex);
        usleep(philo->simulation->time_to_eat * 1000);
        pthread_mutex_unlock(&philo->simulation->forks[philo->left_fork]);
        pthread_mutex_unlock(&philo->simulation->forks[philo->right_fork]);
        pthread_mutex_lock(&philo->simulation->simulation_mutex);
        if (philo->simulation->number_of_meals != -1 && philo->meal_count == philo->simulation->number_of_meals)
        {
            pthread_mutex_unlock(&philo->simulation->simulation_mutex);
            return (1) ;
        }
        pthread_mutex_unlock(&philo->simulation->simulation_mutex);
        return(0);
}

void    sleep_and_think(my_philosopher *philo)
{
    long    think_time;
    print_state(philo, "is sleeping");
    usleep(philo->simulation->time_to_sleep * 1000);
    print_state(philo, "is thinking");
    think_time = philo->simulation->time_to_die
        - philo->simulation->time_to_eat
        - philo->simulation->time_to_sleep;
    if (think_time <= 0)
        usleep(1000);
    else
        usleep((think_time / 2) * 1000);
}