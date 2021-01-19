#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "./philo.hpp"

using namespace std;

int main()
{
  int tab[NO_PHILO] = {0, 1, 2, 3, 4};
  printf("Problem filozofow. Rozwiazanie z lokajem.\n");
  printf("Liczba filozofow: %d\n", NO_PHILO);

  struct sigaction sa;
  sa.sa_sigaction = sighandler;
  sigaction(SIGINT, &sa, NULL);

  create_sem();
  set_sem(semid);

  thread first(philosopherJob, tab[0]);
  thread second(philosopherJob, tab[1]);
  thread third(philosopherJob, tab[2]);
  thread fourth(philosopherJob, tab[3]);
  thread fifth(philosopherJob, tab[4]);

  first.join();
  second.join();
  third.join();
  fourth.join();
  fifth.join();

  while (1)
    ;
}