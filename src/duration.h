#ifndef __DURATION_H
#define __DURATION_H

typedef struct {
	int hours;
	int minutes;
	int seconds;
} duration;

typedef struct {
	duration dur;
	char *start_date;
	char *from_datetime;
	char *to_datetime;
} timespan;

timespan to_timespan(time_t start, time_t end);
duration to_duration(int diff_seconds);

#endif
