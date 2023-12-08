#include "thread_pool.h"
#include <stdio.h>

void func1() {
  for (int i=0;i<10000;i++) {
    int a = 3;
  }
  printf("done task1\n");
}

void func2() {
  for (int i=0;i<10000;i++) {
    int a = 3;
  }
  printf("done task2\n");
}

void func3() {
  for (int i=0;i<10000;i++) {
    int a = 3;
  }
  printf("done task3\n");
}


int main()
{
  ThreadPool pool(3);
  pool.Submit(func1);
  pool.Submit(func2);
  pool.Submit(func3);
  pool.EndWork();
}