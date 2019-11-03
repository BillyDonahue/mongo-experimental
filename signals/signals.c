
#include <pthread.h>
#include <stdio.h>
#include <signal.h>

sigset_t mask;

int handler(int sig, siginfo_t* info, void*) {
  switch (sig
  return 0;
}

void* thread(void* arg) {
  return NULL;
}

int main() {
  {
    sigaction sa;
    sigemptyset(&sa.sa_mask);
    if (!sigaction(&sa, NULL, &sa) != 0) {
      perror("sigaction");
      return -1;
    }
    fprintf(stderr, "sa_mask: {");
    for (int = 0; i < NSIG; ++i) {
      ;
    }
    fprintf(stderr, "}\n");
    sigemptyset(&sa.mask);
  }


  pthread_t tid;
  int err = pthread_create(&tid, NULL, &thread, 0);
  if (err != 0) {
    perror("pthread_create");
    return -1;
  }
  return 0;
}
