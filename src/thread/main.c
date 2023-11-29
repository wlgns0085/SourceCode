#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *thread_1_task(void *);

int main(int argc, char **argv) {
  
  int data = 3;

  // init
  pthread_t thread_1;
  if((pthread_create(&thread_1, NULL, thread_1_task, (void*)&data))!=0)
  {
    perror("thread create fail\n");
  }

  // loop
  while(1)
  {
    printf("main) loop...\n");
    sleep(1);
  }

  // clean up
  printf("thread clean\n");
  pthread_join(thread_1, NULL);
  
  return 0;
}

void *thread_1_task(void *arg)
{
  void *ret = NULL;
  int data = *(int*) arg;

	int i=1;
	while(i<=data){
		sleep(2);
		printf("thread) counting... (%d/%d)\n",i,data);
		i++;
	}

  printf("thread) done\n");
  return ret;
}