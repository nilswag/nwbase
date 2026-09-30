#pragma once
#include <string.h>

#ifdef _WIN32
/**
 * Macro that returns file base name
 */
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#else
/**
 * Macro that returns file base name
 */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif
