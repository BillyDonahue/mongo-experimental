
#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int quitFlag; /* set nonzero by thread */
sigset_t mask;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t waitloc = PTHREAD_COND_INITIALIZER;

void* thread(void* arg) {
    for (;;) {
        int sig;
        int err;
        if ((err = sigwait(&mask, &sig))) {
            fprintf(stderr, "sigwait: %s\n", strerror(err));
            exit(-1);
        }
        switch (sig) {
            case SIGINT:
                fprintf(stderr, "SIGINT\n");
                break;
            case SIGQUIT:
                fprintf(stderr, "SIGQUIT\n");
                pthread_mutex_lock(&lock);
                quitFlag = 1;
                pthread_mutex_unlock(&lock);
                pthread_cond_signal(&waitloc);
                return NULL;
        }
    }
    return NULL;
}

void dumpSigset(sigset_t* set) {
    fprintf(stderr, "sigset: {");
    const char* sep = "";
    for (int i = 1; i < NSIG; ++i) {
        if (sigismember(set, i)) {
            fprintf(stderr, "%s%d", sep, i);
            sep = ",";
        }
    }
    fprintf(stderr, "}\n");
}

int main() {
    {
        struct sigaction sa;
        sigemptyset(&sa.sa_mask);
        if (sigaction(SIGQUIT, NULL, &sa)) {
            perror("sigaction");
            return -1;
        }
        dumpSigset(&sa.sa_mask);
        sigemptyset(&sa.sa_mask);
    }
    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);

    sigset_t oldmask;

    int err;

    if ((err = pthread_sigmask(SIG_BLOCK, &mask, &oldmask)) != 0) {
        fprintf(stderr, "pthread_sigmask: %s\n", strerror(err));
        exit(-1);
    }

    pthread_t thr;
    if ((err = pthread_create(&thr, NULL, &thread, 0))) {
        fprintf(stderr, "pthread_create: %s", strerror(err));
        return -1;
    }

    sleep(1);
    kill(getpid(), SIGINT);
    sleep(1);
    kill(getpid(), SIGQUIT);

    pthread_mutex_lock(&lock);
    while (quitFlag == 0)
        pthread_cond_wait(&waitloc, &lock);
    pthread_mutex_unlock(&lock);

    if ((err = pthread_join(thr, NULL))) {
        fprintf(stderr, "pthread_join: %s", strerror(err));
        return -1;
    }
    fprintf(stderr, "restore progmask\n");
    if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) {
        fprintf(stderr, "sigprocmask: %s\n", strerror(err));
        exit(-1);
    }
    return 0;
}
