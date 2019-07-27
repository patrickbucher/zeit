#ifndef __DURATION_H
#define __DURATION_H

typedef struct {
	int hours;
	int minutes;
	int seconds;
} duration;

typedef struct {
	duration dur;
	char *from_date;
	char *to_date;
} timespan;

timespan to_timespan(time_t start, time_t end);
duration to_duration(int diff_seconds);

#endif
