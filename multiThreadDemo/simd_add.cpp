#include <immintrin.h>
#include <iostream>
#include <chrono>

#define MAX_ARRAY_SIZE (8 * 10000000)

void vectorAdd(float* result, const float* a, const float* b, int size)
{
    int numIterations = size / 4;  // 每次迭代处理4个浮点数

    __m128 xmmA, xmmB, xmmResult;

    for (int i = 0; i < numIterations; i++)
    {
        xmmA = _mm_load_ps(a + 4 * i);  // 从内存加载4个浮点数到xmmA
        xmmB = _mm_load_ps(b + 4 * i);  // 从内存加载4个浮点数到xmmB

        xmmResult = _mm_add_ps(xmmA, xmmB);  // 执行SIMD加法操作

        _mm_store_ps(result + 4 * i, xmmResult);  // 将结果存储回内存
    }
}

int main()
{
  float* a = new float[MAX_ARRAY_SIZE];
  float* b = new float[MAX_ARRAY_SIZE];
  float* c = new float[MAX_ARRAY_SIZE];
  for (int i = 0; i < MAX_ARRAY_SIZE; i++ ) {
    a[i] = i;
    b[i] = i;
  }

  auto startTime = std::chrono::high_resolution_clock::now();
  vectorAdd(c, a, b, MAX_ARRAY_SIZE);
  auto endTime = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
  // 输出消耗时间
  std::cout << "vector spend time " << duration.count() << " milliseconds." << std::endl;

  startTime = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < MAX_ARRAY_SIZE; i ++) {
    c[i] = a[i] + b[i];
  }
  endTime = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
  // 输出消耗时间
  std::cout << "pure add time " << duration.count() << " milliseconds." << std::endl;
}