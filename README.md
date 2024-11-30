# Dining Philosophers

This repository contains an implementation of the **Dining Philosophers problem**, a classic synchronization problem that demonstrates the challenges of resource sharing in concurrent programming. The problem is solved using **threads** and **mutexes** in C.

## What is a Thread?  
A thread is the smallest unit of a program that can execute independently. Multiple threads can run in parallel, sharing the same process's memory space, which makes them lightweight compared to processes.

## What is a Mutex?  
A **mutex** (short for mutual exclusion) is a synchronization primitive used to prevent multiple threads from accessing a shared resource at the same time. By locking and unlocking mutexes, we can ensure only one thread can access a critical section at a time.

## What is a Data Race?  
A **data race** occurs when two or more threads access the same shared memory location concurrently, and at least one of the accesses is a write operation. This can lead to undefined behavior and bugs in the program. Mutexes help prevent data races by ensuring synchronized access to shared resources.

## How It Works  
In this implementation:
- Philosophers are represented as threads.
- Forks (resources) are represented as mutexes.
- Mutexes ensure that only one philosopher can pick up a fork at a time, avoiding data races and deadlocks.

## Usage  

### Compilation  
Compile the program using `make` or your preferred compiler:  
```bash
make
```
### Running the Program
Execute the program with the following arguments:
```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
### Arguments:
1. number_of_philosophers: The number of philosophers sitting at the table.
2. time_to_die: Time (in milliseconds) a philosopher can live without eating before dying.
3. time_to_eat: Time (in milliseconds) a philosopher takes to eat.
4. time_to_sleep: Time (in milliseconds) a philosopher spends sleeping.
5. [number_of_times_each_philosopher_must_eat] (optional): The number of times each philosopher must eat. If not provided, the simulation runs indefinitely.

### Example
Run a simulation with 5 philosophers:
```bash
./philo 5 800 200 200
```
Run a simulation where each philosopher eats at least 7 times:
```bash
./philo 5 800 200 200 7
```
