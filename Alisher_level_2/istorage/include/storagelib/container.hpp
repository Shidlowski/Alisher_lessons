//
// Created by alisher on 4/23/21.
//

#ifndef ISTORAGE_INCLUDE_STORAGELIB_CONTAINER_HPP_
#define ISTORAGE_INCLUDE_STORAGELIB_CONTAINER_HPP_

#include <queue>
#include <mutex>
#include <shared_mutex>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <condition_variable>
namespace storagelib {

template<class T>
class Queue {
 public:
  Queue() = default;

  ~Queue() = default;
  Queue(const Queue &queue) = default;
  Queue(Queue &&queue) noexcept = default;
  Queue &operator=(const Queue &queue) = default;
  Queue &operator=(Queue &&queue) noexcept = default;

  void push(const T &item) noexcept {
    std::unique_lock unique_lock(mutex_);
    queue_.push(item);
    unique_lock.unlock();
    cond_.notify_one();
  }

  T &front() noexcept {
    std::unique_lock unique_lock(mutex_);
    cond_.wait(unique_lock, [&] { return not queue_.empty(); });
    return queue_.front();
  }

  void pop() noexcept {
    std::unique_lock unique_lock(mutex_);
    cond_.wait(unique_lock, [&] { return not queue_.empty(); });
    queue_.pop();
  }

 protected:
  std::shared_mutex mutex_;
  std::queue<T> queue_;
  std::condition_variable_any cond_;
};
}

#endif //ISTORAGE_INCLUDE_STORAGELIB_CONTAINER_HPP_
