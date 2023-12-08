#include <thread>
#include <vector>
#include <atomic>
#include <queue>
#include "thread_safe_queue.h"

typedef std::function<void()> Task;

class ThreadPool
{
public:
  ThreadPool(int threadNum);
  void Submit(Task&& task);
  void EndWork();
  ~ThreadPool();

private:
  void Worker();

private:
  std::atomic<bool> thread_pool_done_;
  ThreadSafeQueue<Task> task_queue_; 
  std::vector<std::thread> threads_; // threads 必须在 bool值和task_queue_后面声明，后声明的先销毁
};