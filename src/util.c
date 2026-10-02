#include <string.h>
#include <stdlib.h>

#include "nwbase/util.h"
#include "nwbase/log.h"

char** split(char* str, const char* delimiter, size_t* count)
{
	size_t capacity = 16;
	*count = 0;

	char** result = malloc(capacity * sizeof(char*));
	if (result == NULL)
		FATAL("Unable to allocate memory for resulting string split");

	char* token = strtok(str, delimiter);
	while (token != NULL)
	{
		if (*count >= capacity)
		{
			capacity *= 2;
			char** tmp = realloc(result, capacity * sizeof(char*));
			if (tmp == NULL)
				FATAL("Unable to allocate memory for resulting string split");
			result = tmp;
		}

		result[*count] = token;
		token = strtok(NULL, delimiter);

		(*count)++;
	}

	char** tmp = realloc(result, *count * sizeof(char*));
	if (tmp == NULL)
		FATAL("Unable to allocate memory for resulting string split");
	result = tmp;

	return result;
}