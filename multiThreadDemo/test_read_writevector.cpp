#include <stdio.h>
#include <vector>
#include <thread>
#include <condition_variable>

std::condition_variable ready_notify;

void WriteData(std::vector<int>& data) {
  for (int i = 0; i < 10; i++) {
    data.push_back(i);
  }
  printf("%d, write done!\n", std::this_thread::get_id());
  ready_notify.notify_all();
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void ReadData(std::vector<int>& data) {
  std::mutex mu;
  std::unique_lock<std::mutex> lock(mu);
  // ready_notify.wait_for(lock,std::chrono::seconds(1), [data](){  //等待通知数据准备好了，通知到了后检查下数据如果不为空就继续执行，否则继续等通知。
  //   return !data.empty();
  // });
  ready_notify.wait(lock, [data](){  //等待通知数据准备好了，通知到了后检查下数据如果不为空就继续执行，否则继续等通知。
    return !data.empty();
  });
  lock.unlock();
  for (int i = 0; i < data.size(); i++) {
    printf("%d, read %d\n", std::this_thread::get_id(), data[i]);
  }
}

int main(){
  std::vector<int> datas;
  std::thread writer(WriteData, std::ref(datas));
  std::thread reader1(ReadData, std::ref(datas));
  std::thread reader2(ReadData, std::ref(datas));

  writer.join();
  reader1.join();
  reader2.join();
}
