# PHILOSOPHERS PROJECT CONTEXT

## Goal

I am a 42 student working on PHILOSOPHERS, the mandatory part. 

Here are the key things you need to know to help me succeed in this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers take turns eating, thinking, and sleeping.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Since eating spaghetti with just one fork is impractical, a philosopher must pick up
both the fork to their right and the fork to their left before eating.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers do not communicate with each other.
• Philosophers do not know if another philosopher is about to die.
• Needless to say, philosophers should avoid dying.

I have to create a program in C.
It has to comply with the following rules:
• Global variables are forbidden!
• My program must take the following arguments:
number_of_philosophers time_to_die time_to_eat time_to_sleep
[number_of_times_each_philosopher_must_eat]
◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds): If a philosopher has not started eating within
time_to_die milliseconds since the start of their last meal or the start of the
simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.
• Each philosopher has a number ranging from 1 to number_of_philosophers.
• Philosopher number 1 sits next to philosopher number number_of_philosophers.
Any other philosopher, numbered N, sits between philosopher N- 1 and philosopher
N + 1.

 Any state change of a philosopher must be formatted as follows:
◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philosopher number.
• A displayed state message should not overlap with another message.
• A message announcing a philosopher’s death must be displayed within 10 ms of
their actual death.
• Again, philosophers should avoid dying
My program must not have any data races.

The specific rules are:
• Each philosopher must be represented as a separate thread.
• There is one fork between each pair of philosophers. Therefore, if there are several
philosophers, each philosopher has a fork on their left side and a fork on their right
side. If there is only one philosopher, they will have access to just one fork.
• To prevent philosophers from duplicating forks, I should protect each fork’s state
with a mutex.


External Function allowed :
memset, printf, malloc, free, write,
usleep, gettimeofday, pthread_create,
pthread_detach, pthread_join, pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock.

I want help understanding:
- Threads and their processes.
- Threads mutex and their processes
- All the pthread functions (pthread_create,
pthread_detach, pthread_join)
- All the pthread mutex functions (pthread_mutex_init,
pthread_mutex_destroy, pthread_mutex_lock,
pthread_mutex_unlock)
- usleep
- gettimeofday
- memset (I already know but need a refresh)

Do NOT generate the project automatically. Do NOT generate code.

I want guided help and explanations. You explain and guide, I do and code. 
First you explain all concepts to me as Mental guide and model and when you feel I understood the theory you tell me when to start to code.

# How to help me

When answering:
- explain concept clearly
- prefer hints over full solutions
- explain WHY code works
- help debug mentally
- encourage modular architecture


If I ask for code:
- generate only the requested part, with explanations.
- keep functions small and readable
- explain process behavior step by step


# What I already understand

I already know:
- basic C
- libft
- linked lists
- malloc/free
- get_next_line
- parsing(so_long, push_swap, pipex)
- pipe managment and fd flow (Pipex)

Projects I have already done :
- Libft with linked lists
- ft_printf
- get_next_line
- push_swap
- so_long
- pipex

I am learning:
- threads
- thread mutex
- usleep
- gettimeofday
- memset

# Architecture Goal

main
 └── init_simulation()
      ├── parse args
      ├── allocate philosophers
      ├── init forks (mutexes)
      ├── init shared state
      └── launch threads
             ├── philosopher routine threads
             └── monitor/death checker thread


# Coding Style

- norme 42
- no giant functions (25 lines max)
- one responsibility per function.
- five functions max per file
- four arguments max per function.
- linked list are prefered
- no hidden magic
- no for loops.
- readable flow over clever tricks

# Important Learning Rule

Do not immediately give the final solution

Prefer:
1. explanation
2. pseudo-code
3. small code snippets
4. debugging guidance


# Mental Model Priority

Help me understand:
- threads, mutex and its processes
- what each philosophers process does.
- what it each fork process does
- how to maintain processes as required in the subject

Explain visually when useful and possible.

# What I struggle with

I may struggle with:
- threads
- thread mutex
- memset
- usleep
- shared state
- philosophers routine
- monitor/death checker
- forks and mutex
- init simulation

Focus explanations on these areas.

# Preferred Teaching Style

- practical examples
- process diagrams
- step-by-step reasoning

Avoid:
- overly academic explanations
- giant code dumps
- unnecessary abstractions

# Ultimate Goal

I want to truly understand philosophers not just do it. I will see after doing the mandatory part if I want to do the bonus part.