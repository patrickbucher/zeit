#include "duration.h"

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
