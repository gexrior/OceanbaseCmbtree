/*
 * Copyright (C) 2012-2013 Taobao Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Description here
 *
 * Version: $Id$
 *
 * Authors:
 *   Fusheng Han <yanran.hfs@taobao.com>
 *     - Thread ID encapsulation
 */
#ifndef OCEANBASE_COMMON_CMBTREE_BTREE_TID_H_
#define OCEANBASE_COMMON_CMBTREE_BTREE_TID_H_

#include <sys/syscall.h>
#include <unistd.h>
#include <stdint.h>
#include "log.h"

namespace oceanbase
{
  namespace common
  {
    namespace cmbtree
    {
      class BtreeTID
      {
        public:
          static inline int gettid()
          {
            static __thread int tid = -1;
            if (UNLIKELY(tid == -1))
            {
#ifdef __APPLE_CC__
              //tid = getpid(); 
              uint64_t id;
              pthread_threadid_np(NULL, &id);
              tid = (int)(id & INT32_MAX);
              LOG_DEBUG("tid: %d", tid);
#else
              tid = static_cast<int>(syscall(__NR_gettid));
#endif
            }
            return tid;
          }
      };

    } // end namespace cmbtree
  } // end namespace common
} // end namespace oceanbase

#endif // OCEANBASE_COMMON_CMBTREE_BTREE_TID_H_
