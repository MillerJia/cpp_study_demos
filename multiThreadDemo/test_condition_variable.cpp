#include <mutex>
#include <iostream>
#include <condition_variable>
#include <deque>
#include <thread>

std::condition_variable cv_data;
std::mutex mutex;

class Consumer {
public:
  explicit Consumer(std::shared_ptr<std::deque<int> > pData) : 
    p_data_(pData) {
  }
  void Cosume() {
    while(true) {
      ConsumeOne();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }

private:
  void ConsumeOne() {
    std::unique_lock<std::mutex> lock_data(mutex);
    cv_data.wait(lock_data, [=](){
      return !(*p_data_).empty();
    });
    // std::cout<<"--consume--begin--"<<std::endl;
    // for (int i=0;i<(*p_data_).size();i++){
    //   std::cout << (*p_data_).at(i) << " ";
    // }
    // std::cout << std::endl;
    // std::cout<<"--consume--end--"<<std::endl;
    int data = (*p_data_).front();
    (*p_data_).pop_front();
    lock_data.unlock();
  }

private:
  std::shared_ptr<std::deque<int> > p_data_;
};

class Producer {
public:
  explicit Producer(std::shared_ptr<std::deque<int> > pData) : 
    p_data_(pData) {
  }

  void Produce() {
    while (true) {
      ProduceOne();
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  }

private:
  void ProduceOne() {
    std::lock_guard<std::mutex> lock_data(mutex);
    // std::cout<<"--produce--begin--"<<std::endl;
    // for (int i=0;i<(*p_data_).size();i++){
    //   std::cout << (*p_data_).at(i) << " ";
    // }
    // std::cout << std::endl;
    // std::cout<<"--produce--end--"<<std::endl;
    (*p_data_).push_back(1);
    cv_data.notify_one();
  }

private:
  std::shared_ptr<std::deque<int> > p_data_;
};

int main()
{
  std::mutex deal_data_mutex;
  std::deque<int> data = {1, 2, 3};
  std::shared_ptr<std::deque<int> > p_data = std::make_shared<std::deque<int> >(data);
  Consumer consumer(p_data);
  Producer producer(p_data);
  std::thread consumer_thread(&Consumer::Cosume, &consumer);
  std::thread producer_thread(&Producer::Produce, &producer);
  consumer_thread.join();
  producer_thread.join();
}