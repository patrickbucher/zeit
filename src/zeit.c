#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "duration.h"
#include "utils.h"

void handle_sigint(int);

static volatile bool run = true;

const char *dirname = ".zeit";

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s [project]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	char *project = retain_alnum(argv[1]);
	if (strlen(project) == 0) {
		fprintf(stderr, "only alpha-numeric characters allowed for project\n");
		exit(EXIT_FAILURE);
	}

	char *workdir = get_workdir_path(dirname);
	if (!dir_exists(workdir)) {
		if (mkdir(workdir, 0700) == -1) {
			fprintf(stderr, "create dir %s: %s\n", workdir, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	time_t start, end;
	time(&start);
	signal(SIGINT, handle_sigint);
	while (run) {
		pause();
	}
	time(&end);

	timespan ts = to_timespan(start, end);
	char *dur_str = (char *)malloc(sizeof(char) * 9);
	snprintf(dur_str, 9, "%02d:%02d:%02d",
			ts.dur.hours, ts.dur.minutes, ts.dur.seconds);
	printf("\nfrom %s to %s worked %s on %s\n",
			ts.from_datetime, ts.to_datetime, dur_str, project);

	char *filepath = get_file_path(workdir, ts.start_date, "csv");
	FILE *file = fopen(filepath, "a+");
	if (!file) {
		fprintf(stderr, "unable to open %s for appending\n", filepath);
		exit(EXIT_FAILURE);
	}
	fprintf(file, "%s,%s,%s,%s\n", ts.from_datetime, ts.to_datetime,
			dur_str, project);
	fclose(file);

	free(project);
	free(workdir);
	free(dur_str);
	free(ts.start_date);
	free(ts.from_datetime);
	free(ts.to_datetime);
	free(filepath);

	return EXIT_SUCCESS;
}

void handle_sigint(int sig)
{
	run = false;
}
