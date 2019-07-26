#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} duration;

void handle_sigint(int sig);

duration to_duration(int diff_seconds);

static volatile bool run = true;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s [project]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *project = argv[1];

    time_t start = time(0);
    signal(SIGINT, handle_sigint);
    while (run) {
        pause();
    }
    time_t end = time(0);

    duration dur = to_duration(end - start);
    printf("\nworked %02d:%02d:%02d on %s\n",
            dur.hours, dur.minutes, dur.seconds, project);

    exit(EXIT_SUCCESS);
}

void handle_sigint(int sig)
{
    run = false;
}

duration to_duration(int diff_seconds)
{
    duration dur;
    
    dur.hours = diff_seconds / (60 * 60);
    diff_seconds -= dur.hours * 60 * 60;

    dur.minutes = diff_seconds / 60;
    diff_seconds -= dur.minutes * 60;

    dur.seconds = diff_seconds;

    return dur;
}
