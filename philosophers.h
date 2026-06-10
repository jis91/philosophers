#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philosopher    my_philosopher;
typedef struct s_simulation     my_simulation;

typedef struct s_simulation
{
    int     number_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     number_of_meals;
    long    start_time;
    int     dead_stop;
    pthread_mutex_t    *forks;
    my_philosopher  *philo;
    pthread_mutex_t     simulation_mutex;
    pthread_mutex_t     print_mutex;

}       my_simulation;

typedef struct s_philosopher
{
        pthread_t     thread_id;
        int     philo_id;
        long    last_meal_time;
        int     meal_count;
        int     left_fork;
        int     right_fork;
        my_simulation       *simulation;
}       my_philosopher;

// INIT FUNCTIONS

int     parse_args(my_simulation *sim, char **argv, int argc);
int     init_philos(my_simulation *sim);
int     init_forks_mutex(my_simulation *sim);
int     init_simulation(my_simulation *sim, char **argv, int argc);

// UTILS FUNCTIONS

int    ft_atoi(const char *nptr);
void    cleanup_simulation(my_simulation *sim, int forks_initialized);
long    get_time_ms(void);
int     is_simulation_stopped(my_simulation *sim);
void    print_state(my_philosopher *philo, char *state);

// UTILS2 FUNCTIONS

int     launch_threads(my_simulation *sim);
void	ft_putnbr_fd(long n, int fd);
void    ft_putstr_fd(char *s, int fd);

// PHILO ROUTINE FUNCTIONS

void    *philo_routine(void *arg);
void    take_forks(my_philosopher *philo);
int     eat(my_philosopher *philo);
void    sleep_and_think(my_philosopher *philo);

// MONITOR ROUTINE FUNCTIONS

void    *monitor_routine(void *arg);
int     check_death(my_simulation *sim, int philo);
int     check_all_ate(my_simulation *sim);
void    print_death(my_philosopher *philo);


#endif