#include "philosophers.h"

int     main(int argc, char **argv)
{
    my_simulation   simulation;
    memset(&simulation, 0, sizeof(my_simulation));
    if (argc < 5 || argc > 6)
    {
        write(2, "Error: wrong number of arguments\n", 33);
        return(1);
    }
    if (init_simulation(&simulation, argv, argc) != 0)
        return (1);
    launch_threads(&simulation);
    cleanup_simulation(&simulation, simulation.number_of_philo);
    return (0);
}