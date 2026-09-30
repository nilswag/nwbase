#pragma once

#include "defines.h"
#include "util.h"

typedef enum 
{
	LOG_LEVEL_TRACE = 0,
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFO,
	LOG_LEVEL_WARN,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_FATAL,
	LOG_LEVEL_N
} LogLevel;

/**
 * General function for logging
 * @param level Log level
 * @param file Filename where log is called
 * @param line Line where log is called
 * @param fmt Formatting string used for fprintf
 * @param ... Variadic arguments
 */
void log(LogLevel level, 
		 const char* file, 
		 int line, 
		 const char* fmt, ...);

/**
 * Log trace 
 * @param ... Variadic arguments 
 */
#define TRACE(...) log(LOG_LEVEL_TRACE, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * Log debug 
 * @param ... Variadic arguments 
 */
#define DEBUG(...) log(LOG_LEVEL_DEBUG, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * Log info 
 * @param ... Variadic arguments 
 */
#define INFO(...)  log(LOG_LEVEL_INFO, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * Log warning 
 * @param ... Variadic arguments 
 */
#define WARN(...)  log(LOG_LEVEL_WARN, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * Log error 
 * @param ... Variadic arguments 
 */
#define ERROR(...) log(LOG_LEVEL_ERROR, __FILENAME__, __LINE__, __VA_ARGS__)

/**
 * Log fatal 
 * @param ... Variadic arguments 
 */
#define FATAL(...) STMT( log(LOG_LEVEL_FATAL, __FILENAME__, __LINE__, __VA_ARGS__); abort(); )