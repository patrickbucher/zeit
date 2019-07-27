#include <assert.h>

#include "duration.h"

int main()
{
	int diff_seconds = 3600 + 120 + 3;

	duration result = to_duration(diff_seconds);

	assert(result.hours == 1);
	assert(result.minutes == 2);
	assert(result.seconds == 3);

	return 0;
}
