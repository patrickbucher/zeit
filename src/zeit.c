#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "duration.h"
#include "utils.h"

void handle_sigint(int);

static volatile bool run = true;

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s [project]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *project = retain_alnum(argv[1]);

	time_t start = time(NULL);
	signal(SIGINT, handle_sigint);
	while (run) {
		pause();
	}
	time_t end = time(NULL);

	duration dur = to_duration(end - start);
	printf("\nworked %02d:%02d:%02d on %s\n",
			dur.hours, dur.minutes, dur.seconds, project);

	free(project);

	exit(EXIT_SUCCESS);
}

void handle_sigint(int sig)
{
	run = false;
}
