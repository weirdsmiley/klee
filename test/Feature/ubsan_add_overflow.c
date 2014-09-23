// RUN: %llvmgcc %s -fsanitize=unsigned-integer-overflow -emit-llvm -g -O0 -c -o %t.bc
// RUN: %klee %t.bc 2> %t.log
// RUN: grep -c "overflow on unsigned addition" %t.log
// RUN: grep -c "ubsan_add_overflow.c:16: overflow" %t.log

#include "klee/klee.h"

int main()
{
  unsigned int x;
  unsigned int y;
  volatile unsigned int result;

  klee_make_symbolic(&x, sizeof(x), "unsigned add 1");
  klee_make_symbolic(&y, sizeof(y), "unsigned add 2");
  result = x + y;

  return 0;
}