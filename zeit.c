#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int sig);

static volatile bool run = true;

int main()
{
    signal(SIGINT, handle_sigint);
    printf("waiting for Ctrl-C\n");
    while (run) {
        pause();
    }
    printf("Ctrl-C pressed, finished\n");


    return 0;
}

void handle_sigint(int sig)
{
    run = false;
}
