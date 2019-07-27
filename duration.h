#ifndef __DURATION_H
#define __DURATION_H

typedef struct {
	int hours;
	int minutes;
	int seconds;
} duration;

duration to_duration(int diff_seconds);

#endif
