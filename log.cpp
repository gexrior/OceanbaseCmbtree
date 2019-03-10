#include "log.h"
#include <stdint.h>
#ifdef __linux__
#include <sys/syscall.h>
#include <unistd.h>
#endif

#define UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

char * current_time() {
  static __thread char buf[32];

  time_t t = ::time(NULL);
  tm * cur_time = localtime(&t);
  ::strftime(buf, 32, LOG_LOG_TIME_FORMAT, cur_time);
  return buf;
}

uint64_t get_tid() {
  static __thread uint64_t tid = UINT64_MAX;

#ifdef __linux__
  tid = syscall(__NR_gettid);
#else
  if( UINT64_MAX == tid ) {
    pthread_threadid_np(NULL, &tid);
  }
#endif
  return tid;
}
