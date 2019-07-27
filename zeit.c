#include <ctype.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
	int hours;
	int minutes;
	int seconds;
} duration;

void handle_sigint(int);
duration to_duration(int);
char *retain_alnum(char *);

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

char *retain_alnum(char *str) {
	int n = strlen(str);
	char *buf = (char *)malloc(sizeof(char) * (n + 1));

	int w = 0;
	for (int i = 0; i < n; i++) {
		if (isalnum(str[i])) {
			buf[w++] = str[i];
		}
	}
	buf[w] = '\0';

	char *cleansed = (char *)malloc(sizeof(char) * (w + 1));
	strncpy(cleansed, buf, w);
	return cleansed;
}
