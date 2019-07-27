#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

char *retain_alnum(const char *str) {
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
	free(buf);

	return cleansed;
}

char *get_workdir_path(const char *dirname)
{
	char *homedir = getenv("HOME");
	if (homedir == NULL) {
		fprintf(stderr, "$HOME is not set");
		return NULL;
	}

	int len = strlen(homedir) + 1 + strlen(dirname) + 1;
	char *workdir = (char *)malloc(sizeof(char) * len);
	snprintf(workdir, len, "%s/%s", homedir, dirname);

	return workdir;
}

bool dir_exists(const char *dirpath)
{
	DIR *dir = opendir(dirpath);
	if (dir) {
		closedir(dir);
		return true;
	} else {
		return false;
	}
}
