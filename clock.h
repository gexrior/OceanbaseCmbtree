/*
 * clock.h
 *
 *  Created on: Dec 5, 2014
 *      Author: tzhu
 */

#ifndef CLOCK_H_
#define CLOCK_H_
#include <stdint.h>
#include <sys/time.h>

namespace common {

  inline uint64_t cpu_cycle() {
    uint64_t hi, lo;
    __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
    return ((uint64_t) lo) | (((uint64_t) hi) << 32);
  }

  inline int64_t local_time(){

    struct timeval val;
    gettimeofday(&val, NULL);
    return val.tv_sec * 1000000 + val.tv_usec;
  }

}
#endif /* CLOCK_H_ */
