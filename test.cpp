#include "btree_base.h"
#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <sys/syscall.h>

using namespace std;
using namespace oceanbase::common::cmbtree;
typedef oceanbase::common::cmbtree::BtreeBase<int, int> itree;

///void testGetTid() {
///
///  std::cout << "getpid()=" << getpid() << std::endl;
///
///  std::cout << "pthread_self()=" << pthread_self() << std::endl;
///  uint64_t tid;
///  pthread_threadid_np(NULL, &tid);
///  std::cout << "pthread_threadid_np()=" << tid << std::endl;
///  //std::cout << "syscall(SYS_thread_selfid)=" << syscall(SYS_thread_selfid) << std::endl;
///}

int main() {
  //cout << common::local_time() << endl;
  //testGetTid();
  itree tree;
  tree.init();
  int r;
  for(int i = 1; i <= 10; ++i) {
    r = rand();
    if( ERROR_CODE_OK ==  tree.put(i, r) ) 
      printf("put %d = %d\n", i, r);
    else 
      printf("put %d failed\n", i);
  }

  for(int i = 1; i <= 20; ++i) {
    if( ERROR_CODE_OK == tree.get(i, r) )
      printf("get %d = %d\n", i, r);
    else 
      printf("get %d failed\n", i);
  }
  return 0;
}
