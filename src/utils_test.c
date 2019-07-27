#include <assert.h>
#include <string.h>

#include "utils.h"

int main()
{
	char *input = ">a;b-c!d?e^f$g.";
	char *expected = "abcdefg";

	char *result = retain_alnum(input);

	assert(strcmp(expected, result) == 0);
}
