#include <iostream>
#include <omp.h>

void func(int t) {
  std::cout << t << std::endl;
}

int main()
{
    const int N = 10;
    int sum = 0;
    sum==0? func(1) : func(2);

#pragma omp parallel for schedule(static) num_threads(2)
    for (int i = 0; i < N; ++i)
 
  {
        int thread_id = omp_get_thread_num();
        // std::cout << "线程 " << thread_id << " 处理元素 " << i << std::endl;
    printf("线程 %d 处理元素 %d \n", thread_id, i);

#pragma omp atomic
        sum += i;
     
  }

    std::cout << "总和为: " << sum << std::endl;

    return 0;
}