
#include <algorithm>
#include <array>
#include <future>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
using namespace std;


template<typename T>
class BlockingQueue
{
private:
    queue<T> mQueue;
    size_t mMaxSize;
    mutex mMutex;
    condition_variable mConditionVariable;
public:
    BlockingQueue(size_t maxSize):mMaxSize(maxSize){}
    void push(T const& item);
    T pop();
    size_t size();
    void clear();
};

template<typename T>
void BlockingQueue<T>::push(T const& item)
{
    unique_lock<mutex> uniqueLock(mMutex);
    if(mQueue.size()>=mMaxSize)
    {
        mConditionVariable.wait(uniqueLock,[this](){return mQueue.size() < mMaxSize;});
    }
    mQueue.push(item);
    mConditionVariable.notify_one();
}

template<typename T>
T BlockingQueue<T>::pop()
{
    unique_lock<mutex> uniqueLock(mMutex);
    if(mQueue.empty())
    {
        mConditionVariable.wait(uniqueLock,[this](){return !mQueue.empty();});
    }
    T val = queue.front();
    queue.pop();
    mConditionVariable.notify_one();
    return val;
}

int main()
{

    return 0;
}
