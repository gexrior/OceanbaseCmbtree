/*
 * (C) 2007-2010 Taobao Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 *
 * Version: $Id$
 *
 * Authors:
 *   duolong <duolong@taobao.com>
 *
 */

#ifndef TBSYS_LOG_H
#define TBSYS_LOG_H

#include <stdarg.h>
#include <time.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <deque>
#include <string>
#include <pthread.h>
#include <sys/time.h>
#include "log.h"
#define TBSYS_LOG_LEVEL_ERROR 0
#define TBSYS_LOG_LEVEL_USER_ERROR  1
#define TBSYS_LOG_LEVEL_WARN  2
#define TBSYS_LOG_LEVEL_INFO  3
#define TBSYS_LOG_LEVEL_TRACE 4
#define TBSYS_LOG_LEVEL_DEBUG 5
#define TBSYS_LOG_LEVEL(level) TBSYS_LOG_LEVEL_##level, __FILE__, __LINE__, __FUNCTION__, pthread_self()
#define TBSYS_LOG_NUM_LEVEL(level) level, __FILE__, __LINE__, __FUNCTION__, pthread_self()
//#define TBSYS_LOGGER tbsys::CLogger::getLogger()
#define TBSYS_PRINT(level, ...) //TBSYS_LOGGER.logMessage(TBSYS_LOG_LEVEL(level), __VA_ARGS__)
#define TBSYS_LOG_BASE(level, ...) //(TBSYS_LOG_LEVEL_##level>TBSYS_LOGGER._level) ? (void)0 : TBSYS_PRINT(level, __VA_ARGS__)
//#define TBSYS_LOG(level, _fmt_, args...) //((TBSYS_LOG_LEVEL_##level>TBSYS_LOGGER._level) ? (void)0 : TBSYS_LOG_BASE(level,_fmt_, ##args))
#define TBSYS_LOG_US(level, _fmt_, args...) //\
//  ((TBSYS_LOG_LEVEL_##level>TBSYS_LOGGER._level) ? (void)0 : TBSYS_LOG_BASE(level, "[%ld][%ld][%ld] " _fmt_, \
//                                                            pthread_self(), tbsys::CLogger::get_cur_tv().tv_sec, \
//                                                            tbsys::CLogger::get_cur_tv().tv_usec, ##args))

#define TBSYS_LOG(level, _fmt_, ...) LOG_ ## level (_fmt_, ## __VA_ARGS__)

#endif
