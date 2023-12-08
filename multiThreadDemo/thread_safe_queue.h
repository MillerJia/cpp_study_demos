#include <mutex>
#include <queue>

template<typename Data>
class ThreadSafeQueue
{
public:
  int Size() {
    std::lock_guard<std::mutex> lock(queue_op_mutex_);
    return queue_.size();
  }
  void Push(Data&& data) {
    std::lock_guard<std::mutex> lock(queue_op_mutex_);
    queue_.push(std::forward(data));
  }
  void Push(Data& data) {
    std::lock_guard<std::mutex> lock(queue_op_mutex_);
    queue_.push(data);
  }
  bool Pop(Data& data) {
    std::lock_guard<std::mutex> lock(queue_op_mutex_);
    if (queue_.size() == 0) {
      return false;
    }
    data = queue_.front();
    queue_.pop();
    return true;
  }
  
private:
  std::mutex queue_op_mutex_;
  std::queue<Data> queue_;
};