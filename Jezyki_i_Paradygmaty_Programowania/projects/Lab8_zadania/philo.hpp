#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>

#define WAITER 5

#define NO_PHILO 5

using namespace std;

int semid;
int new_thread;
int join_thread;
int valOfWaiter;
pthread_t tid;

typedef struct wskaznik
{
  int number;
} wskaznik;

void thinking()
{
  printf("Mysle wiec jestem... Moj tid: %ld\n", pthread_self());
}

void eating(int id)
{
  printf("Filozof o id: %d. Zglodnialem... Moj tid: %ld\n", id, pthread_self());
}

void create_sem()
{
  key_t key = ftok(".", 3);
  semid = semget(key, 6, IPC_CREAT | 0600);
  if (semid == -1)
  {
    perror("Semget");
    printf("[Program glowny] Nie udalo sie utworzyc semaforow");
    exit(3);
  }
}

void set_sem(int semafor)
{
  int ustaw_sem;
  for (int i = 0; i < 5; i++)
  {
    ustaw_sem = semctl(semafor, i, SETVAL, 1);
    if (ustaw_sem == -1)
    {
      perror("Semctl");
      printf("[Program glowny] Nie mozna ustawic semafora.\n");
      exit(EXIT_FAILURE);
    }
  }
  ustaw_sem = semctl(semafor, WAITER, SETVAL, 4);
  if (ustaw_sem == -1)
  {
    perror("Semctl");
    printf("[Program glowny] Nie mozna ustawic semafora.\n");
    exit(EXIT_FAILURE);
  }
}

void delete_sem(int k)
{
  int sem;
  sem = semctl(k, 0, IPC_RMID);
  if (sem == -1)
  {
    perror("Semctl");
    printf("[Program glowny] Nie mozna usunac semafora \n");
    exit(EXIT_FAILURE);
  }
}

void sighandler(int signum, siginfo_t *info, void *ptr)
{
  if (signum == 2)
  {
    printf("[Program glowny] Sygnal SIGINT!\n");
    delete_sem(semid);
    exit(0);
  }
}

static void sem_wait(int nr)
{
  int zmien_sem;
  struct sembuf bufor_sem;
  bufor_sem.sem_num = nr;
  bufor_sem.sem_op = -1;
  bufor_sem.sem_flg = SEM_UNDO;
  zmien_sem = semop(semid, &bufor_sem, 1);
  if (zmien_sem == -1)
  {
    if (errno == EINTR)
    {
      sem_wait(nr);
      errno = 0;
    }
    else
    {
      perror("Semop");
      printf("[Filozof] Nie moglem zamknac semafora. \n");
      exit(EXIT_FAILURE);
    }
  }
}

static void sem_sig(int nr)
{
  int zmien_sem;
  struct sembuf bufor_sem;
  bufor_sem.sem_num = nr;
  bufor_sem.sem_op = 1;
  bufor_sem.sem_flg = SEM_UNDO;
  zmien_sem = semop(semid, &bufor_sem, 1);
  if (zmien_sem == -1)
  {
    if (errno == EINTR)
    {
      sem_sig(nr);
      errno = 0;
    }
    else
    {
      perror("Semop");
      printf("[Filozof] Nie moglem otworzyc semafora. \n");
      exit(EXIT_FAILURE);
    }
  }
}
void philosopherJob(int id)
{
  srand(time(0) + pthread_self());
  int test = 0;

  while (1)
  {
    valOfWaiter = semctl(semid, WAITER, GETVAL);
    if (valOfWaiter >= 0 && test == 0)
    {
      cout << "Nie ma miejsca dla filozofa o id: " << id << endl;
      test = 1;
    }
    if (valOfWaiter > 0)
    {
      test = 0;
      thinking();
      sem_wait(WAITER);
      sem_wait(id);
      sem_wait((id + 1) % 5);
      eating(id);
      sleep(rand() % 3);
      sem_sig(id);
      sem_sig((id + 1) % 5);
      sem_sig(WAITER);
    }
  }

  pthread_exit(0);
}
