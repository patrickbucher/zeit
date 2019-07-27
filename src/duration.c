#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "duration.h"

timespan to_timespan(time_t start, time_t end)
{
	const char *datetimefmt = "%Y-%m-%d %H:%M:%S";
	const int datetimelen = strlen("2000-01-01 00:00:00") + 1;

	const char *datefmt = "%Y-%m-%d";
	const int datelen = strlen("2000-01-01") + 1;

	int diff = end - start;

	struct tm from, to, *tmp;
	tmp = localtime(&start);
	memcpy(&from, tmp, sizeof(*tmp));
	tmp = localtime(&end);
	memcpy(&to, tmp, sizeof(*tmp));

	char *start_date = (char *)malloc(datelen * sizeof(char));
	char *from_str = (char *)malloc(datetimelen * sizeof(char));
	char *to_str = (char *)malloc(datetimelen * sizeof(char));
	strftime(start_date, datelen, datefmt, &from);
	strftime(from_str, datetimelen, datetimefmt, &from);
	strftime(to_str, datetimelen, datetimefmt, &to);

	timespan span;
	span.start_date = start_date;
	span.from_datetime = from_str;
	span.to_datetime = to_str;
	span.dur = to_duration(diff);

	return span;
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
