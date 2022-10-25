#ifndef _MSG_QUEUE_H_
#define _MSG_QUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

#define MAX_MSG_QUEUE_SIZE 20

template <typename T>
class MsgQueue {
public:
    bool Push(T data) {
        std::unique_lock<std::mutex> lg(mutxt_);
        if (data_.size() > MAX_MSG_QUEUE_SIZE) {
            return false;
        }
        data_.push(data);
        cv_.notify_one();
    }

    T Pop() {
        std::unique_lock<std::mutex> lg(mutxt_);
        while(data_.empty()) {
            cv_.wait(lg);
        }
        auto ret = std::move(data_.front());
        std::cout << ret << std::endl;
        data_.pop();
        return ret;
    }
private:
    std::queue<T> data_;
    std::condition_variable cv_;
    std::mutex mutxt_;
};

#endif