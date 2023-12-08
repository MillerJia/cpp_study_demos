#include <thread>
#include <vector>
#include <atomic>
#include <queue>
#include <memory>
#include <iostream>
//#include "thread_safe_queue.h"

class FunctionWrapper
{
  struct impl_base {
    virtual void call() = 0;
    virtual ~impl_base(){}
  };

  std::unique_ptr<impl_base> impl_;

  template<typename F>
  struct impl_type : impl_base
  {
    F f;
    impl_type(F&& fparam): f(std::move(fparam)) {}
    void call() {
      f();
    }
  };

public:
  void operator()() {
    impl_->call();
  }
  FunctionWrapper() {
    std::cout << "default" << std::endl;
  }

  template<typename F>
  FunctionWrapper(F&& f): impl_(std::make_unique<impl_type<F> >(std::move(f))) {
    std::cout << "constructor F&& f" << std::endl;
  }

  FunctionWrapper(FunctionWrapper&& other) : impl_(std::move(other.impl_)) {
    std::cout << "constructor FunctionWrapper&& other" << std::endl;
  }

  FunctionWrapper& operator=(FunctionWrapper&& other) {
    std::cout << "operator = " << std::endl;
    impl_ = std::move(other.impl_);
    return *this;
  }

  FunctionWrapper(const FunctionWrapper&) = delete;
  FunctionWrapper(FunctionWrapper&) = delete;
  FunctionWrapper& operator=(FunctionWrapper&) = delete;
};

// class ThreadPool
// {
// public:
//   ThreadPool(int threadNum);
//   void Submit(Task&& task);
//   void EndWork();
//   ~ThreadPool();

// private:
//   void Worker();

// private:
//   std::atomic<bool> thread_pool_done_;
//   ThreadSafeQueue<Task> task_queue_; 
//   std::vector<std::thread> threads_; // threads 必须在 bool值和task_queue_后面声明，后声明的先销毁
// };