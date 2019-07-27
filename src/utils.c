#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

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
	free(buf);

	return cleansed;
}
