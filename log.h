#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdint.h>
#include <ctime>
#include <string>
#include <pthread.h>

#define LOG_LEVEL_OFF    1000
#define LOG_LEVEL_ERROR  500
#define LOG_LEVEL_WARN   400
#define LOG_LEVEL_INFO   300
#define LOG_LEVEL_DEBUG  200
#define LOG_LEVEL_TRACE  100
#define LOG_LEVEL_ALL    0

#ifndef LOG_LEVEL
    #if defined(DB_DEBUG)
        #define LOG_LEVEL LOG_LEVEL_DEBUG
    #elif defined(DB_TEST)
        #define LOG_LEVEL LOG_LEVEL_INFO
    #else
        #define LOG_LEVEL LOG_LEVEL_WARN
    #endif
#endif

#define LOG_BASE(level, format, ...) printf("[%s] %s %s:%d - " format "\n", current_time(), \
    level, __FILE__, __LINE__, ##__VA_ARGS__)
#define LOG_MORE(level, format, ...) printf("[%s] %s %s (%s:%d) [%lld] - " format "\n", current_time(), \
    level, __FUNCTION__, __FILE__, __LINE__, get_tid(), ## __VA_ARGS__)

#if LOG_LEVEL <= LOG_LEVEL_ERROR
  #define LOG_ERROR(format, ...) LOG_MORE("ERROR", format, ## __VA_ARGS__)
#else
  #define LOG_ERROR(...) ((void)0)
#endif

#if LOG_LEVEL <= LOG_LEVEL_WARN
  #define LOG_WARN(format, ...) LOG_MORE("WARN ", format, ## __VA_ARGS__)
#else
  #define LOG_WARN(...) ((void)0)
#endif

#if LOG_LEVEL <= LOG_LEVEL_INFO
  #define LOG_INFO(format, ...) LOG_BASE("INFO ", format, ## __VA_ARGS__)
#else
  #define LOG_INFO(...) ((void)0)
#endif

#if LOG_LEVEL <= LOG_LEVEL_DEBUG
  #define LOG_DEBUG(format, ...) LOG_BASE("DEBUG", format, ## __VA_ARGS__)
#else
  #define LOG_DEBUG(...) ((void)0)
#endif 

#if LOG_LEVEL <= LOG_LEVEL_TRACE
  #define LOG_TRACE(format, ...) LOG_BASE("TRACE", format, ## __VA_ARGS__)
#else
  #define LOG_TRACE(...) ((void)0)
#endif

#define LOG_LOG_TIME_FORMAT "%Y-%m-%d %H:%M:%S"

char * current_time();
uint64_t get_tid();
#endif
