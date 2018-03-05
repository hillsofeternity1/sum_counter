// Maximum performance with optimal count of forks.
// HOW TO BUILD
// gcc summ.c -lpthread
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#define SEMAPHORES 1

static long *main_result;
static long *finished;

long sumumatoru_kun (long start, long end)
{
  long num, digit, sum = 0;
  while (end > start)
  {
    num = end;
    while (num > 0)
    {
      digit = num % 10;
      sum  = sum + digit;
      num /= 10;
    }
    end--;
  }
  return sum;
}

int main(int argc, char *argv[])
{
  long end, start, first, last, shift, i, temp;
  int p_pid = getpid();
  long f_count = 2 * get_nprocs_conf();
  pid_t pid;
  main_result = mmap(NULL, sizeof *main_result,
    PROT_READ | PROT_WRITE,
    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  finished = mmap(NULL, sizeof *finished,
    PROT_READ | PROT_WRITE,
    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  sem_t *semaphore = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE,
             MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *main_result = 0;
  *finished = 0;
  start = 0;
  sem_init (semaphore, 1, 1);
  printf("This system has %d processors configured. Going to spawn %ld forks.\n",
    get_nprocs_conf(), f_count);
  if (argc < 2)
  {
    return 228;
  }
  end = strtoll(argv[1], NULL, 0);
  if(f_count >= end)
  {
    f_count = 1;
  }
  shift = end / f_count;
  i = 0;
  while(i < f_count)
  {
    if(pid == 0){break;}
    pid = fork();
    if(i + 1 == f_count)
    {
      last = end;
    }
    else
    {
      last = (start + shift*i) + shift;
    }
    first = start + shift*i;
    i++;
  }
    if(pid == 0)
    {
      printf("Child %d was started. My job is \t%ld \t%ld\n",
        getpid(),
        first,
        last);
      temp = sumumatoru_kun(first, last);
      if (SEMAPHORES)
        sem_wait(semaphore);
      *main_result = *main_result + temp;
      if (SEMAPHORES)
        sem_post(semaphore);
    }
    else
    {
      i = f_count;
    }
  *finished = *finished + 1;
  if(p_pid == getpid()){
    while(*finished < f_count + 1)
    {
      usleep(10 * 1000);
    }
      if (SEMAPHORES)
        sem_wait(semaphore);
    printf("%d - Sumumatoru kun handled %ld forks and got result %ld\n",
      getpid(), 
      f_count,
      *main_result);
  }
  return 0;
}
