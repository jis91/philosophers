*This project has been created as part of the 42 curriculum by jstrasse*

# Philosophers | 42 Lausanne
made by Jefferson Strasser (jstrasse@student.42lausanne.ch)

## Description

Philosophers is a classic concurrency problem (the dining philosophers problem)
implemented in C using threads and mutexes.

A number of philosophers sit around a round table with a bowl of spaghetti in
the middle and one fork between each pair of philosophers. Each philosopher
repeatedly thinks, eats, and sleeps. To eat, a philosopher must pick up both
the fork on their left and the fork on their right. The simulation stops as
soon as a philosopher dies of starvation (has not started eating in time) or,
if the optional argument is given, once every philosopher has eaten enough
times.

The goal of the project is to synchronize the philosophers' threads so that
no philosopher starves, no two neighbors use the same fork at the same time,
and no data race occurs, while keeping the state-change logs perfectly timed
and non-overlapping.

The bonus part reproduces the same behavior using processes and semaphores
instead of threads and mutexes. [À COMPLÉTER : précise si tu l'as fait ou non
— je retire cette section sinon]

## Instructions

I only did the mandatory part

To compile it :

make

Usage:
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

- number_of_philosophers: the number of philosophers and forks
- time_to_die (ms): time after which a philosopher dies if they haven't started eating
- time_to_eat (ms): time it takes a philosopher to eat
- time_to_sleep (ms): time a philosopher spends sleeping
- number_of_times_each_philosopher_must_eat (optional): simulation stops once every philosopher has eaten this many times

Example:
./philo 5 800 200 200
./philo 4 410 200 200 7

## Resources

man pages for mutexes and threads.

I consulted the man pages for every function used in this project:
pthread_create(3), pthread_join(3), pthread_detach(3), pthread_mutex_init(3),
pthread_mutex_lock(3), pthread_mutex_unlock(3), gettimeofday(2), usleep(3).

I used AI (Claude) throughout this project as a guided tutor. Rather than
generating code automatically, I used it to understand concepts step by step:
- understanding thread creation and how pthread_create/pthread_join/pthread_detach work together
- understanding what a mutex actually protects and why fork state needs locking
- understanding how to avoid deadlock when picking up two forks
- understanding how to time and format the state-change logs without overlap
- debugging race conditions and reasoning about death-detection timing

All code was written by me after understanding each concept through guided
explanation and pseudo-code hints. Claude did not generate any code for me.

Overall I did not find this project difficult. It just presents new concepts like mutexes and threads.
Thank you for reading, I hope you enjoy my work. Cheers ! Jefferson