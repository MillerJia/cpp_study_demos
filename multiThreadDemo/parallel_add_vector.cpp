#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <numeric>
#include <functional>

#define MIN_THREAD_NUM 16

template<typename Iterator, typename T>
struct AccumulateBlock
{
  void operator()(Iterator begin, Iterator end, T& result) {
    result = std::accumulate(begin, end, result);
  }
};

// 不考虑溢出
template<typename Iterator, typename T>
T ParallelAdd(Iterator begin, Iterator end, T& result) {
  int length = std::distance(begin, end);
  if (!length) {
    return result;
  }
  int hardware_threads = std::thread::hardware_concurrency();
  std::cout << "hardware_threads: " << hardware_threads << std::endl;
  int num_threads = std::min(length + MIN_THREAD_NUM - 1 / MIN_THREAD_NUM ,
                              hardware_threads);
  std::cout << "num_threads: " << num_threads << std::endl;
  
  unsigned long const block_size = length / num_threads;
  Iterator block_start = begin;

  std::vector<std::thread> calculate_threads;
  std::vector<T> results(num_threads);
  for (auto i = 0; i < num_threads - 1; i++) {
    Iterator block_end = block_start;
    std::advance(block_end, block_size);
    calculate_threads.emplace_back(std::thread(AccumulateBlock<Iterator, T>(), block_start, block_end, std::ref(results[i])));
    block_start = block_end;
  }
  calculate_threads.emplace_back(std::thread(AccumulateBlock<Iterator, T>(), block_start, end, std::ref(results[num_threads - 1])));
  
  std::for_each(calculate_threads.begin(), calculate_threads.end(), std::mem_fn(&std::thread::join));
  result = std::accumulate(results.begin(), results.end(), result);
  return result;
}

int main() {
  std::vector<int> data_source;
  for (int i = 0; i < 10; i++) {
    data_source.push_back(i);
  }
  int result = 0;
  std::cout << ParallelAdd(data_source.begin(), data_source.end(), result);
}

